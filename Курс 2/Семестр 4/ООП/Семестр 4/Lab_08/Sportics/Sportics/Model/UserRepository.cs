using Sportics.Helper;
using Sportics.Model;
using Sportics.Model.Data;
using Sportics.ViewModel;
using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;

namespace Sportics.Model
{
    public class UserRepository
    {
        public static List<User> GetAllUsers()
        {
            var clients = new List<User>();

            using (var connection = DbConnectionFactory.CreateConnection())
            {
                connection.Open();

                var command = new SqlCommand("SELECT * FROM Users WHERE Role = N'Клиент'", connection);
                using (var reader = command.ExecuteReader())
                {
                    while (reader.Read())
                    {
                        clients.Add(MapUser(reader));
                    }
                }
            }

            return clients;
        }

        public static void AddUser(string name, string email, string phoneNumber, string password)
        {
            using (var connection = DbConnectionFactory.CreateConnection())
            {
                connection.Open();

                var checkCommand = new SqlCommand("SELECT COUNT(*) FROM Users WHERE Email = @Email", connection);
                checkCommand.Parameters.AddWithValue("@Email", email);

                int count = (int)checkCommand.ExecuteScalar();
                if (count > 0) return;

                string salt;
                string hashedPassword = HashHelper.HashPassword(password, out salt);

                var command = new SqlCommand(@"
                    INSERT INTO Users (Name, Email, PhoneNumber, PasswordHash, PasswordSalt, Role, Balance, Status) 
                    VALUES (@Name, @Email, @PhoneNumber, @PasswordHash, @PasswordSalt, N'Клиент', 0, N'Активен')", connection);

                command.Parameters.AddWithValue("@Name", name);
                command.Parameters.AddWithValue("@Email", email);
                command.Parameters.AddWithValue("@PhoneNumber", phoneNumber);
                command.Parameters.AddWithValue("@PasswordHash", hashedPassword);
                command.Parameters.AddWithValue("@PasswordSalt", salt);

                command.ExecuteNonQuery();
            }
        }

        public static void UpdateUser(User user)
        {
            if (user == null) return;

            using (var connection = DbConnectionFactory.CreateConnection())
            {
                connection.Open();

                var command = new SqlCommand(@"
                    UPDATE Users SET Name = @Name, Email = @Email, PhoneNumber = @PhoneNumber, Status = @Status
                    WHERE Id = @Id", connection);

                command.Parameters.AddWithValue("@Id", user.Id);
                command.Parameters.AddWithValue("@Name", user.Name);
                command.Parameters.AddWithValue("@Email", user.Email);
                command.Parameters.AddWithValue("@PhoneNumber", user.PhoneNumber);
                command.Parameters.AddWithValue("@Status", user.Status);

                command.ExecuteNonQuery();
            }
        }

        public static void DeleteUser(User user)
        {
            if (user == null) return;

            using (var connection = DbConnectionFactory.CreateConnection())
            {
                connection.Open();

                var command = new SqlCommand("DELETE FROM Users WHERE Id = @Id", connection);
                command.Parameters.AddWithValue("@Id", user.Id);
                command.ExecuteNonQuery();
            }
        }

        public static bool CheckUser(string email, string password)
        {
            using (var connection = DbConnectionFactory.CreateConnection())
            {
                connection.Open();

                var command = new SqlCommand("SELECT * FROM Users WHERE Email = @Email", connection);
                command.Parameters.AddWithValue("@Email", email);
                using (var reader = command.ExecuteReader())
                {
                    if (reader.Read())
                    {
                        string salt = reader["PasswordSalt"].ToString();
                        string hash = reader["PasswordHash"].ToString();
                        return HashHelper.VerifyPassword(password, salt, hash);
                    }
                }
            }
            return false;
        }

        public static User SelectUser(string email, string password)
        {
            using (var connection = DbConnectionFactory.CreateConnection())
            {
                connection.Open();

                var command = new SqlCommand("SELECT * FROM Users WHERE Email = @Email", connection);
                command.Parameters.AddWithValue("@Email", email);
                using (var reader = command.ExecuteReader())
                {
                    if (reader.Read())
                    {
                        string salt = reader["PasswordSalt"].ToString();
                        string hash = reader["PasswordHash"].ToString();
                        if (HashHelper.VerifyPassword(password, salt, hash))
                        {
                            return MapUser(reader);
                        }
                    }
                }
            }
            return null;
        }

        public static bool CheckEmailAndPhoneNumber(string email, string phoneNumber)
        {
            using (var connection = DbConnectionFactory.CreateConnection())
            {
                connection.Open();

                var command = new SqlCommand("SELECT COUNT(*) FROM Users WHERE Email = @Email OR PhoneNumber = @PhoneNumber", connection);
                command.Parameters.AddWithValue("@Email", email);
                command.Parameters.AddWithValue("@PhoneNumber", phoneNumber);
                int count = (int)command.ExecuteScalar();
                return count == 0;
            }
        }

        public static void AddBalance(int userId, decimal amount)
        {
            using (var connection = DbConnectionFactory.CreateConnection())
            {
                connection.Open();

                var command = new SqlCommand("UPDATE Users SET Balance = Balance + @Amount WHERE Id = @Id", connection);
                command.Parameters.AddWithValue("@Amount", amount);
                command.Parameters.AddWithValue("@Id", userId);
                command.ExecuteNonQuery();
            }
        }

        public static bool DeductBalance(int userId, decimal amount)
        {
            using (var connection = DbConnectionFactory.CreateConnection())
            {
                connection.Open();

                var command = new SqlCommand("SELECT Balance FROM Users WHERE Id = @Id", connection);
                command.Parameters.AddWithValue("@Id", userId);
                decimal balance = (decimal)command.ExecuteScalar();
                if (balance >= amount)
                {
                    var updateCommand = new SqlCommand("UPDATE Users SET Balance = Balance - @Amount WHERE Id = @Id", connection);
                    updateCommand.Parameters.AddWithValue("@Amount", amount);
                    updateCommand.Parameters.AddWithValue("@Id", userId);
                    updateCommand.ExecuteNonQuery();
                    return true;
                }
                return false;
            }
        }

        private static User MapUser(SqlDataReader reader)
        {
            return new User
            {
                Id = Convert.ToInt32(reader["Id"]),
                Name = reader["Name"].ToString(),
                Email = reader["Email"].ToString(),
                PhoneNumber = reader["PhoneNumber"].ToString(),
                PasswordHash = reader["PasswordHash"].ToString(),
                PasswordSalt = reader["PasswordSalt"].ToString(),
                Role = reader["Role"].ToString(),
                Balance = Convert.ToDecimal(reader["Balance"]),
                Status = reader["Status"].ToString()
            };
        }

        public static bool CancelUserSchedule(int userId, int scheduleId)
        {
            using (var connection = DbConnectionFactory.CreateConnection())
            {
                connection.Open();

                string query = "DELETE FROM ClientSessionRecords WHERE ClientId = @ClientId AND ScheduleId = @ScheduleId";
                using (SqlCommand command = new SqlCommand(query, connection))
                {
                    command.Parameters.AddWithValue("@ClientId", userId);
                    command.Parameters.AddWithValue("@ScheduleId", scheduleId);

                    int rowsAffected = command.ExecuteNonQuery();
                    return rowsAffected > 0;
                }
            }
        }

        public static List<UserMembershipInfo> GetUserMemberships(User user)
        {
            List<UserMembershipInfo> memberships = new List<UserMembershipInfo>();

            using (var connection = DbConnectionFactory.CreateConnection())
            {
                connection.Open();

                string query = @"SELECT M.Id, M.FullName, M.Description, M.DurationInDays, M.Price, M.IsWeeklyOffer, M.ShortName, M.Category, M.Photo, MO.EndDate
                                 FROM MembershipOrders MO
                                 JOIN Memberships M ON MO.MembershipId = M.Id
                                 WHERE MO.ClientId = @ClientId";

                using (SqlCommand command = new SqlCommand(query, connection))
                {
                    command.Parameters.AddWithValue("@ClientId", user.Id);

                    using (SqlDataReader reader = command.ExecuteReader())
                    {
                        while (reader.Read())
                        {
                            var membership = new Membership
                            {
                                Id = reader.GetInt32(0),
                                FullName = reader.GetString(1),
                                Description = reader.GetString(2),
                                DurationInDays = reader.GetInt32(3),
                                Price = reader.GetDecimal(4),
                                IsWeeklyOffer = reader.GetBoolean(5),
                                ShortName = reader.GetString(6),
                                Category = reader.GetString(7),
                                Photo = reader.IsDBNull(8) ? null : (byte[])reader[8]
                            };

                            memberships.Add(new UserMembershipInfo
                            {
                                Membership = membership,
                                EndDate = reader.GetDateTime(9)
                            });
                        }
                    }
                }
            }

            return memberships;
        }

        public static List<Schedule> LoadUserSchedules(int userId)
        {
            List<Schedule> schedules = new List<Schedule>();
            DateTime now = DateTime.Now;

            using (var connection = DbConnectionFactory.CreateConnection())
            {
                connection.Open();

                string query = @"SELECT S.Id, S.Date, S.Time, S.Category, S.Status, C.Id, C.Name, C.Email, C.PhoneNumber, C.Specialization, C.Information, C.Photo
                                 FROM ClientSessionRecords CSR
                                 JOIN Schedules S ON CSR.ScheduleId = S.Id
                                 JOIN Coaches C ON S.CoachId = C.Id
                                 WHERE CSR.ClientId = @ClientId
                                 AND (S.Date > @Today OR (S.Date = @Today AND S.Time >= @NowTime))";

                using (SqlCommand command = new SqlCommand(query, connection))
                {
                    command.Parameters.AddWithValue("@ClientId", userId);
                    command.Parameters.AddWithValue("@Today", now.Date);
                    command.Parameters.AddWithValue("@NowTime", now.TimeOfDay);

                    using (SqlDataReader reader = command.ExecuteReader())
                    {
                        while (reader.Read())
                        {
                            Schedule schedule = new Schedule
                            {
                                Id = reader.GetInt32(0),
                                Date = reader.GetDateTime(1),
                                Time = reader.GetTimeSpan(2),
                                Category = reader.GetString(3),
                                Status = reader.GetString(4),
                                Coach = new Coach
                                {
                                    Id = reader.GetInt32(5),
                                    Name = reader.GetString(6),
                                    Email = reader.GetString(7),
                                    PhoneNumber = reader.GetString(8),
                                    Specialization = reader.GetString(9),
                                    Information = reader.GetString(10),
                                    Photo = reader.IsDBNull(11) ? null : (byte[])reader[11]
                                }
                            };
                            schedules.Add(schedule);
                        }
                    }
                }
            }

            return schedules;
        }

        public static bool HasActiveMembership(int userId, int membershipId)
        {
            using (var connection = DbConnectionFactory.CreateConnection())
            {
                connection.Open();

                string query = @"SELECT COUNT(*) FROM MembershipOrders
                                 WHERE ClientId = @ClientId AND MembershipId = @MembershipId AND EndDate >= @Today";

                using (SqlCommand command = new SqlCommand(query, connection))
                {
                    command.Parameters.AddWithValue("@ClientId", userId);
                    command.Parameters.AddWithValue("@MembershipId", membershipId);
                    command.Parameters.AddWithValue("@Today", DateTime.Today);

                    int count = (int)command.ExecuteScalar();
                    return count > 0;
                }
            }
        }
    }
}
