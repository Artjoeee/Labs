using Sportics.Model.Data;
using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sportics.Model
{
    public static class MembershipOrderRepository
    {
        public static List<MembershipOrder> GetAllMembershipOrders()
        {
            var orders = new List<MembershipOrder>();

            using (var connection = DbConnectionFactory.CreateConnection())
            {
                connection.Open();
                string query = @"
                SELECT mo.Id, mo.ClientName, mo.ClientId, mo.Category, mo.MembershipName,
                       mo.MembershipId, mo.PurchaseDate, mo.EndDate,
                       cs.Id AS ClientSessionId, cs.ScheduleId
                FROM MembershipOrders mo
                LEFT JOIN ClientSessionRecords cs ON cs.MembershipOrderId = mo.Id";

                using (var command = new SqlCommand(query, connection))
                using (var reader = command.ExecuteReader())
                {
                    while (reader.Read())
                    {
                        var order = new MembershipOrder
                        {
                            Id = (int)reader["Id"],
                            ClientName = reader["ClientName"].ToString(),
                            ClientId = (int)reader["ClientId"],
                            Category = reader["Category"].ToString(),
                            MembershipName = reader["MembershipName"].ToString(),
                            MembershipId = (int)reader["MembershipId"],
                            PurchaseDate = (DateTime)reader["PurchaseDate"],
                            EndDate = (DateTime)reader["EndDate"],
                            ClientSession = reader["ClientSessionId"] != DBNull.Value
                            ? new List<ClientSessionRecord>
                            {
                                new ClientSessionRecord
                                {
                                    Id = (int)reader["ClientSessionId"],
                                    ScheduleId = (int)reader["ScheduleId"]
                                }
                            }
                            : new List<ClientSessionRecord>()

                        };

                        orders.Add(order);
                    }
                }
            }

            return orders;
        }

        public static List<MembershipOrder> GetUserMembershipOrders(int userId)
        {
            var orders = new List<MembershipOrder>();

            using (var connection = DbConnectionFactory.CreateConnection())
            {
                connection.Open();
                string query = @"
                SELECT mo.Id, mo.ClientName, mo.ClientId, mo.Category, mo.MembershipName,
                       mo.MembershipId, mo.PurchaseDate, mo.EndDate,
                       m.Id AS MembershipId, m.Category AS MembershipCategory
                FROM MembershipOrders mo
                LEFT JOIN Memberships m ON mo.MembershipId = m.Id
                WHERE mo.ClientId = @UserId";

                using (var command = new SqlCommand(query, connection))
                {
                    command.Parameters.AddWithValue("@UserId", userId);

                    using (var reader = command.ExecuteReader())
                    {
                        while (reader.Read())
                        {
                            var order = new MembershipOrder
                            {
                                Id = (int)reader["Id"],
                                ClientName = reader["ClientName"].ToString(),
                                ClientId = (int)reader["ClientId"],
                                Category = reader["Category"].ToString(),
                                MembershipName = reader["MembershipName"].ToString(),
                                MembershipId = (int)reader["MembershipId"],
                                PurchaseDate = (DateTime)reader["PurchaseDate"],
                                EndDate = (DateTime)reader["EndDate"],
                                Membership = reader["MembershipId"] != DBNull.Value ? new Membership
                                {
                                    Id = (int)reader["MembershipId"],
                                    Category = reader["MembershipCategory"].ToString()
                                } : null
                            };

                            orders.Add(order);
                        }
                    }
                }
            }

            return orders;
        }

        public static void SaveOrder(int userId, string clientName, int membershipId, string membershipName, DateTime endDate)
        {
            using (var connection = DbConnectionFactory.CreateConnection())
            {
                connection.Open();

                // Получение категории абонемента
                string getCategoryQuery = "SELECT Category FROM Memberships WHERE Id = @MembershipId";
                string category = null;

                using (var getCategoryCmd = new SqlCommand(getCategoryQuery, connection))
                {
                    getCategoryCmd.Parameters.AddWithValue("@MembershipId", membershipId);
                    category = getCategoryCmd.ExecuteScalar()?.ToString();
                }

                if (category == null)
                    throw new Exception("Абонемент не найден.");

                // Вставка нового заказа
                string insertQuery = @"
                INSERT INTO MembershipOrders (ClientName, ClientId, Category, MembershipName, MembershipId, PurchaseDate, EndDate)
                VALUES (@ClientName, @ClientId, @Category, @MembershipName, @MembershipId, @PurchaseDate, @EndDate)";

                using (var insertCmd = new SqlCommand(insertQuery, connection))
                {
                    insertCmd.Parameters.AddWithValue("@ClientName", clientName);
                    insertCmd.Parameters.AddWithValue("@ClientId", userId);
                    insertCmd.Parameters.AddWithValue("@Category", category);
                    insertCmd.Parameters.AddWithValue("@MembershipName", membershipName);
                    insertCmd.Parameters.AddWithValue("@MembershipId", membershipId);
                    insertCmd.Parameters.AddWithValue("@PurchaseDate", DateTime.Now);
                    insertCmd.Parameters.AddWithValue("@EndDate", endDate);

                    insertCmd.ExecuteNonQuery();
                }
            }
        }

        public static void DeleteOrder(int orderId)
        {
            using (var connection = DbConnectionFactory.CreateConnection())
            {
                connection.Open();
                string deleteQuery = "DELETE FROM MembershipOrders WHERE Id = @OrderId";

                using (var deleteCmd = new SqlCommand(deleteQuery, connection))
                {
                    deleteCmd.Parameters.AddWithValue("@OrderId", orderId);
                    deleteCmd.ExecuteNonQuery();
                }
            }
        }

        public static void DeleteExpiredOrders()
        {
            using (var connection = DbConnectionFactory.CreateConnection())
            {
                connection.Open();
                string deleteQuery = "DELETE FROM MembershipOrders WHERE EndDate < @CurrentDate";

                using (var deleteCmd = new SqlCommand(deleteQuery, connection))
                {
                    deleteCmd.Parameters.AddWithValue("@CurrentDate", DateTime.Now);
                    deleteCmd.ExecuteNonQuery();
                }
            }
        }
    }

    public class MembershipOrderRepositoryWrapper : IMembershipOrderRepository
    {
        public void Add(MembershipOrder order)
        {
            MembershipOrderRepository.SaveOrder(
                order.ClientId,
                order.ClientName,
                order.MembershipId,
                order.MembershipName,
                order.EndDate);
        }
    }

}
