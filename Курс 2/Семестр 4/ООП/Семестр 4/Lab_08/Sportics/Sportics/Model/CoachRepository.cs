using Sportics.Model.Data;
using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sportics.Model
{
    public static class CoachRepository
    {
        public static async Task AddCoachAsync(string name, string specialization, string phoneNumber, string email, string information, byte[] photo)
        {
            using (var connection = DbConnectionFactory.CreateConnection())
            {
                await connection.OpenAsync();

                using (var transaction = connection.BeginTransaction())
                {
                    try
                    {
                        using (var checkCmd = new SqlCommand("SELECT COUNT(*) FROM Coaches WHERE Email = @Email", connection, transaction))
                        {
                            checkCmd.Parameters.AddWithValue("@Email", email);
                            int exists = (int)await checkCmd.ExecuteScalarAsync();

                            if (exists == 0)
                            {
                                using (var cmd = new SqlCommand(@"
                                INSERT INTO Coaches (Name, Specialization, PhoneNumber, Email, Information, Photo) 
                                VALUES (@Name, @Specialization, @PhoneNumber, @Email, @Information, @Photo)", connection, transaction))
                                {
                                    cmd.Parameters.AddWithValue("@Name", name);
                                    cmd.Parameters.AddWithValue("@Specialization", specialization);
                                    cmd.Parameters.AddWithValue("@PhoneNumber", phoneNumber);
                                    cmd.Parameters.AddWithValue("@Email", email);
                                    cmd.Parameters.AddWithValue("@Information", information);
                                    cmd.Parameters.AddWithValue("@Photo", photo ?? (object)DBNull.Value);

                                    await cmd.ExecuteNonQueryAsync();
                                }
                            }
                        }

                        transaction.Commit();
                    }
                    catch
                    {
                        transaction.Rollback();
                        throw;
                    }
                }
            }
        }

        public static async Task EditCoachAsync(Coach oldCoach, string name, string email, string phoneNumber, string specialization, string information, byte[] photo)
        {
            using (var connection = DbConnectionFactory.CreateConnection())
            {
                await connection.OpenAsync();

                using (var transaction = connection.BeginTransaction())
                {
                    try
                    {
                        using (var cmd = new SqlCommand(@"
                        UPDATE Coaches SET 
                            Name = @Name,
                            Email = @Email,
                            PhoneNumber = @PhoneNumber,
                            Specialization = @Specialization,
                            Information = @Information,
                            Photo = @Photo
                        WHERE Id = @Id", connection, transaction))
                        {
                            cmd.Parameters.AddWithValue("@Name", name);
                            cmd.Parameters.AddWithValue("@Email", email);
                            cmd.Parameters.AddWithValue("@PhoneNumber", phoneNumber);
                            cmd.Parameters.AddWithValue("@Specialization", specialization);
                            cmd.Parameters.AddWithValue("@Information", information);
                            cmd.Parameters.AddWithValue("@Photo", photo ?? (object)DBNull.Value);
                            cmd.Parameters.AddWithValue("@Id", oldCoach.Id);

                            await cmd.ExecuteNonQueryAsync();
                        }

                        transaction.Commit();
                    }
                    catch
                    {
                        transaction.Rollback();
                        throw;
                    }
                }
            }
        }

        public static void DeleteCoach(Coach coach)
        {
            using (var connection = DbConnectionFactory.CreateConnection())
            {
                connection.Open();

                using (var cmd = new SqlCommand("DELETE FROM Coaches WHERE Id = @Id", connection))
                {
                    cmd.Parameters.AddWithValue("@Id", coach.Id);
                    cmd.ExecuteNonQuery();
                }
            }
        }

        public static List<Coach> GetAllCoaches()
        {
            var coaches = new Dictionary<int, Coach>();

            using (var connection = DbConnectionFactory.CreateConnection())
            {
                connection.Open();

                using (var cmd = new SqlCommand("GetAllCoachesWithSchedules", connection))
                {
                    cmd.CommandType = CommandType.StoredProcedure;

                    using (var reader = cmd.ExecuteReader())
                    {
                        while (reader.Read())
                        {
                            int coachId = (int)reader["CoachId"];

                            if (!coaches.ContainsKey(coachId))
                            {
                                coaches[coachId] = new Coach
                                {
                                    Id = coachId,
                                    Name = reader["Name"].ToString(),
                                    Specialization = reader["Specialization"].ToString(),
                                    PhoneNumber = reader["PhoneNumber"].ToString(),
                                    Email = reader["Email"].ToString(),
                                    Information = reader["Information"].ToString(),
                                    Photo = reader["Photo"] == DBNull.Value ? null : (byte[])reader["Photo"],
                                    Schedules = new List<Schedule>()
                                };
                            }

                            if (reader["ScheduleId"] != DBNull.Value)
                            {
                                var schedule = new Schedule
                                {
                                    Id = (int)reader["ScheduleId"],
                                    Category = reader["ScheduleCategory"].ToString(),
                                    Date = (DateTime)reader["Date"],
                                    Time = (TimeSpan)reader["Time"],
                                    Status = reader["ScheduleStatus"].ToString(),
                                    CoachId = (int)reader["ScheduleCoachId"]
                                };

                                coaches[coachId].Schedules.Add(schedule);
                            }
                        }
                    }
                }
            }

            return coaches.Values.ToList();
        }

    }
}
