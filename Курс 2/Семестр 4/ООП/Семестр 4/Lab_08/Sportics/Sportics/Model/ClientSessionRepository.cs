using Sportics.Model.Data;
using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sportics.Model
{
    public static class ClientSessionRepository
    {
        public static List<ClientSessionRecord> GetAllClientSessionRecords()
        {
            var result = new List<ClientSessionRecord>();

            using (var connection = DbConnectionFactory.CreateConnection())
            {
                connection.Open();

                string query = @"
            SELECT r.Id, r.ClientId, r.ScheduleId, r.Category, r.Time, r.Date,
                   u.Id AS UserId, u.Name AS UserName, u.Email AS UserEmail,
                   s.Id AS ScheduleId, s.Category AS ScheduleCategory, s.Date AS ScheduleDate, s.Time AS ScheduleTime, s.Status,
                   c.Id AS CoachId, c.Name AS CoachName
            FROM ClientSessionRecords r
            JOIN Users u ON r.ClientId = u.Id
            JOIN Schedules s ON r.ScheduleId = s.Id
            JOIN Coaches c ON s.CoachId = c.Id";

                using (var command = new SqlCommand(query, connection))
                using (var reader = command.ExecuteReader())
                {
                    while (reader.Read())
                    {
                        result.Add(new ClientSessionRecord
                        {
                            Id = (int)reader["Id"],
                            ClientId = (int)reader["ClientId"],
                            ScheduleId = (int)reader["ScheduleId"],
                            Category = reader["Category"].ToString(),
                            Time = (TimeSpan)reader["Time"],
                            Date = (DateTime)reader["Date"],
                            Client = new User
                            {
                                Id = (int)reader["UserId"],
                                Name = reader["UserName"].ToString(),
                                Email = reader["UserEmail"].ToString()
                            },
                            Schedule = new Schedule
                            {
                                Id = (int)reader["ScheduleId"],
                                Category = reader["ScheduleCategory"].ToString(),
                                Date = (DateTime)reader["ScheduleDate"],
                                Time = (TimeSpan)reader["ScheduleTime"],
                                Status = reader["Status"].ToString(),
                                Coach = new Coach
                                {
                                    Id = (int)reader["CoachId"],
                                    Name = reader["CoachName"].ToString()
                                }
                            }
                        });
                    }
                }
            }

            return result;
        }

        public static void SaveClientSessionRecord(ClientSessionRecord record)
        {
            using (var connection = DbConnectionFactory.CreateConnection())
            {
                connection.Open();

                var query = @"
            INSERT INTO ClientSessionRecords (ClientId, ScheduleId, Category, Time, Date, MembershipOrderId, MembershipId)
            VALUES (@ClientId, @ScheduleId, @Category, @Time, @Date, @MembershipOrderId, @MembershipId)";

                using (var command = new SqlCommand(query, connection))
                {
                    command.Parameters.AddWithValue("@ClientId", record.ClientId);
                    command.Parameters.AddWithValue("@ScheduleId", record.ScheduleId);
                    command.Parameters.AddWithValue("@Category", record.Category);
                    command.Parameters.AddWithValue("@Time", record.Time);
                    command.Parameters.AddWithValue("@Date", record.Date);
                    command.Parameters.AddWithValue("@MembershipOrderId", record.MembershipOrderId);
                    command.Parameters.AddWithValue("@MembershipId", record.MembershipId);

                    command.ExecuteNonQuery();
                }
            }
        }

        public static void DeleteClientSessionRecord(ClientSessionRecord record)
        {
            if (record == null) return;

            using (var connection = DbConnectionFactory.CreateConnection())
            {
                connection.Open();

                var query = "DELETE FROM ClientSessionRecords WHERE Id = @Id";

                using (var command = new SqlCommand(query, connection))
                {
                    command.Parameters.AddWithValue("@Id", record.Id);
                    command.ExecuteNonQuery();
                }
            }
        }

    }
}
