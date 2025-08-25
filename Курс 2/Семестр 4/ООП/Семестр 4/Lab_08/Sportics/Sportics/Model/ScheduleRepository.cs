using Sportics.Model.Data;
using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sportics.Model
{
    public static class ScheduleRepository
    {
        public static List<Schedule> GetAllSchedules()
        {
            var schedules = new List<Schedule>();

            using (var connection = DbConnectionFactory.CreateConnection())
            {
                connection.Open();

                string query = @"
                SELECT s.Id, s.Category, s.Date, s.Time, s.Status, s.CoachId,
                       c.Id AS CoachId, c.Name, c.Specialization, c.PhoneNumber, c.Email, c.Information, c.Photo
                FROM Schedules s
                JOIN Coaches c ON s.CoachId = c.Id";

                using (var command = new SqlCommand(query, connection))
                using (var reader = command.ExecuteReader())
                {
                    while (reader.Read())
                    {
                        var schedule = new Schedule
                        {
                            Id = (int)reader["Id"],
                            Category = reader["Category"].ToString(),
                            Date = (DateTime)reader["Date"],
                            Time = (TimeSpan)reader["Time"],
                            Status = reader["Status"].ToString(),
                            CoachId = (int)reader["CoachId"],
                            Coach = new Coach
                            {
                                Id = (int)reader["CoachId"],
                                Name = reader["Name"].ToString(),
                                Specialization = reader["Specialization"].ToString(),
                                PhoneNumber = reader["PhoneNumber"].ToString(),
                                Email = reader["Email"].ToString(),
                                Information = reader["Information"].ToString(),
                                Photo = reader["Photo"] as byte[]
                            }
                        };

                        schedules.Add(schedule);
                    }
                }
            }

            return schedules;
        }

        public static void AddSchedule(string category, DateTime date, TimeSpan time, string coachFullName)
        {
            using (var connection = DbConnectionFactory.CreateConnection())
            {
                connection.Open();

                string getCoachIdQuery = "SELECT Id FROM Coaches WHERE Name = @Name";
                int coachId;

                using (var cmd = new SqlCommand(getCoachIdQuery, connection))
                {
                    cmd.Parameters.AddWithValue("@Name", coachFullName);
                    coachId = (int?)cmd.ExecuteScalar() ?? 0;
                }

                if (coachId > 0)
                {
                    string insertQuery = @"
                    INSERT INTO Schedules (Category, Date, Time, CoachId, Status)
                    VALUES (@Category, @Date, @Time, @CoachId, 'Ожидается')";

                    using (var cmd = new SqlCommand(insertQuery, connection))
                    {
                        cmd.Parameters.AddWithValue("@Category", category);
                        cmd.Parameters.AddWithValue("@Date", date.Date);
                        cmd.Parameters.AddWithValue("@Time", time);
                        cmd.Parameters.AddWithValue("@CoachId", coachId);
                        cmd.ExecuteNonQuery();
                    }
                }
            }
        }

        public static List<string> GetCoachNames()
        {
            var names = new List<string>();

            using (var connection = DbConnectionFactory.CreateConnection())
            {
                connection.Open();
                string query = "SELECT Name FROM Coaches";

                using (var cmd = new SqlCommand(query, connection))
                using (var reader = cmd.ExecuteReader())
                {
                    while (reader.Read())
                    {
                        names.Add(reader.GetString(0));
                    }
                }
            }

            return names;
        }

        public static Coach GetCoachByName(string name)
        {
            using (var connection = DbConnectionFactory.CreateConnection())
            {
                connection.Open();
                string query = "SELECT * FROM Coaches WHERE Name = @Name";

                using (var cmd = new SqlCommand(query, connection))
                {
                    cmd.Parameters.AddWithValue("@Name", name);

                    using (var reader = cmd.ExecuteReader())
                    {
                        if (reader.Read())
                        {
                            return new Coach
                            {
                                Id = (int)reader["Id"],
                                Name = reader["Name"].ToString(),
                                Specialization = reader["Specialization"].ToString(),
                                PhoneNumber = reader["PhoneNumber"].ToString(),
                                Email = reader["Email"].ToString(),
                                Information = reader["Information"].ToString(),
                                Photo = reader["Photo"] as byte[]
                            };
                        }
                    }
                }
            }

            return null;
        }

        public static void DeleteSchedule(int scheduleId)
        {
            using (var connection = DbConnectionFactory.CreateConnection())
            {
                connection.Open();
                string query = "DELETE FROM Schedules WHERE Id = @Id";

                using (var cmd = new SqlCommand(query, connection))
                {
                    cmd.Parameters.AddWithValue("@Id", scheduleId);
                    cmd.ExecuteNonQuery();
                }
            }
        }

        public static void EditSchedule(int scheduleId, string category, int coachId, DateTime date, TimeSpan time)
        {
            using (var connection = DbConnectionFactory.CreateConnection())
            {
                connection.Open();
                string query = @"
                UPDATE Schedules
                SET Category = @Category, CoachId = @CoachId, Date = @Date, Time = @Time
                WHERE Id = @Id";

                using (var cmd = new SqlCommand(query, connection))
                {
                    cmd.Parameters.AddWithValue("@Category", category);
                    cmd.Parameters.AddWithValue("@CoachId", coachId);
                    cmd.Parameters.AddWithValue("@Date", date);
                    cmd.Parameters.AddWithValue("@Time", time);
                    cmd.Parameters.AddWithValue("@Id", scheduleId);

                    cmd.ExecuteNonQuery();
                }
            }
        }

        public static void UpdateSchedule(Schedule schedule)
        {
            using (var connection = DbConnectionFactory.CreateConnection())
            {
                connection.Open();

                string query = @"
                UPDATE Schedules
                SET Category = @Category, CoachId = @CoachId, Date = @Date, Time = @Time, Status = @Status
                WHERE Id = @Id";

                using (var cmd = new SqlCommand(query, connection))
                {
                    cmd.Parameters.AddWithValue("@Category", schedule.Category);
                    cmd.Parameters.AddWithValue("@CoachId", schedule.CoachId);
                    cmd.Parameters.AddWithValue("@Date", schedule.Date);
                    cmd.Parameters.AddWithValue("@Time", schedule.Time);
                    cmd.Parameters.AddWithValue("@Status", schedule.Status);
                    cmd.Parameters.AddWithValue("@Id", schedule.Id);

                    cmd.ExecuteNonQuery();
                }
            }
        }

        public static void CleanupOldSchedules()
        {
            using (var connection = DbConnectionFactory.CreateConnection())
            {
                connection.Open();
                var now = DateTime.Now;

                string deleteClientSessions = @"
                DELETE FROM ClientSessionRecords
                WHERE ScheduleId IN (
                    SELECT Id FROM Schedules
                    WHERE Date < @CutoffDate AND DATEADD(SECOND, DATEDIFF(SECOND, 0, Time), Date) < @CutoffDateTime
                )";

                string deleteSchedules = @"
                DELETE FROM Schedules
                WHERE Date < @CutoffDate AND DATEADD(SECOND, DATEDIFF(SECOND, 0, Time), Date) < @CutoffDateTime";

                using (var cmd = new SqlCommand(deleteClientSessions, connection))
                {
                    cmd.Parameters.AddWithValue("@CutoffDate", now.Date.AddDays(-1));
                    cmd.Parameters.AddWithValue("@CutoffDateTime", now.AddDays(-1));
                    cmd.ExecuteNonQuery();
                }

                using (var cmd = new SqlCommand(deleteSchedules, connection))
                {
                    cmd.Parameters.AddWithValue("@CutoffDate", now.Date.AddDays(-1));
                    cmd.Parameters.AddWithValue("@CutoffDateTime", now.AddDays(-1));
                    cmd.ExecuteNonQuery();
                }
            }
        }
    }

}
