using Sportics.Model.Data;
using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sportics.Model
{
    public static class SessionReviewRepository
    {
        public static List<SessionReview> LoadSessionReviews()
        {
            var reviews = new List<SessionReview>();

            using (var connection = DbConnectionFactory.CreateConnection())
            {
                connection.Open();
                var command = new SqlCommand(@"
                SELECT sr.*, u.Id AS UserId, u.Name, s.Id AS ScheduleId, s.Category
                FROM SessionReviews sr
                JOIN Users u ON sr.UserId = u.Id
                JOIN Schedules s ON sr.ScheduleId = s.Id", connection);

                using (var reader = command.ExecuteReader())
                {
                    while (reader.Read())
                    {
                        var review = new SessionReview
                        {
                            Id = reader.GetInt32(reader.GetOrdinal("Id")),
                            UserId = reader.GetInt32(reader.GetOrdinal("UserId")),
                            ScheduleId = reader.GetInt32(reader.GetOrdinal("ScheduleId")),
                            Rating = reader.GetInt32(reader.GetOrdinal("Rating")),
                            Comment = reader.GetString(reader.GetOrdinal("Comment")),
                            Date = reader.GetDateTime(reader.GetOrdinal("Date")),
                            AdminReply = reader.IsDBNull(reader.GetOrdinal("AdminReply")) ? null : reader.GetString(reader.GetOrdinal("AdminReply")),
                            User = new User
                            {
                                Id = reader.GetInt32(reader.GetOrdinal("UserId")),
                                Name = reader.GetString(reader.GetOrdinal("Name"))
                            },
                            Schedule = new Schedule
                            {
                                Id = reader.GetInt32(reader.GetOrdinal("ScheduleId")),
                                Category = reader.GetString(reader.GetOrdinal("Category"))
                            }
                        };

                        reviews.Add(review);
                    }
                }
            }

            return reviews;
        }

        public static void SaveSessionReview(SessionReview review)
        {
            using (var connection = DbConnectionFactory.CreateConnection())
            {
                connection.Open();
                var command = new SqlCommand(@"
                INSERT INTO SessionReviews (UserId, ScheduleId, Rating, Comment, Date, AdminReply)
                VALUES (@UserId, @ScheduleId, @Rating, @Comment, @Date, @AdminReply)", connection);

                command.Parameters.AddWithValue("@UserId", review.UserId);
                command.Parameters.AddWithValue("@ScheduleId", review.ScheduleId);
                command.Parameters.AddWithValue("@Rating", review.Rating);
                command.Parameters.AddWithValue("@Comment", review.Comment);
                command.Parameters.AddWithValue("@Date", review.Date);
                command.Parameters.AddWithValue("@AdminReply", review.AdminReply ?? (object)DBNull.Value);

                command.ExecuteNonQuery();
            }
        }

        public static bool HasUserReviewedSession(int userId, int scheduleId)
        {
            using (var connection = DbConnectionFactory.CreateConnection())
            {
                connection.Open();
                var command = new SqlCommand(@"
                SELECT COUNT(*) FROM SessionReviews
                WHERE UserId = @UserId AND ScheduleId = @ScheduleId", connection);

                command.Parameters.AddWithValue("@UserId", userId);
                command.Parameters.AddWithValue("@ScheduleId", scheduleId);

                var count = (int)command.ExecuteScalar();
                return count > 0;
            }
        }

        public static bool SaveAdminReply(int reviewId, string reply)
        {
            using (var connection = DbConnectionFactory.CreateConnection())
            {
                connection.Open();
                var command = new SqlCommand(@"
                UPDATE SessionReviews SET AdminReply = @Reply WHERE Id = @Id", connection);

                command.Parameters.AddWithValue("@Reply", reply);
                command.Parameters.AddWithValue("@Id", reviewId);

                return command.ExecuteNonQuery() > 0;
            }
        }

        public static bool DeleteSessionReview(int reviewId)
        {
            using (var connection = DbConnectionFactory.CreateConnection())
            {
                connection.Open();
                var command = new SqlCommand("DELETE FROM SessionReviews WHERE Id = @Id", connection);
                command.Parameters.AddWithValue("@Id", reviewId);

                return command.ExecuteNonQuery() > 0;
            }
        }
    }

}
