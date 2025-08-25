using Sportics.Model.Data;
using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sportics.Model
{
    public static class CoachReviewRepository
    {
        public static List<CoachReview> LoadCoachReviews()
        {
            var reviews = new List<CoachReview>();

            using (var connection = DbConnectionFactory.CreateConnection())
            {
                connection.Open();
                var command = new SqlCommand(@"
                SELECT r.Id, r.UserId, r.CoachId, r.Comment, r.Rating, r.Date, r.AdminReply,
                       u.Id, u.Name,
                       c.Id, c.Name
                FROM CoachReviews r
                INNER JOIN Users u ON r.UserId = u.Id
                INNER JOIN Coaches c ON r.CoachId = c.Id", connection);

                using (var reader = command.ExecuteReader())
                {
                    while (reader.Read())
                    {
                        reviews.Add(new CoachReview
                        {
                            Id = reader.GetInt32(0),
                            UserId = reader.GetInt32(1),
                            CoachId = reader.GetInt32(2),
                            Comment = reader.GetString(3),
                            Rating = reader.GetInt32(4),
                            Date = reader.GetDateTime(5),
                            AdminReply = reader.IsDBNull(6) ? null : reader.GetString(6),
                            User = new User
                            {
                                Id = reader.GetInt32(7),
                                Name = reader.GetString(8)
                            },
                            Coach = new Coach
                            {
                                Id = reader.GetInt32(9),
                                Name = reader.GetString(10)
                            }
                        });
                    }
                }
            }

            return reviews;
        }

        public static void SaveCoachReview(CoachReview review)
        {
            using (var connection = DbConnectionFactory.CreateConnection())
            {
                connection.Open();
                var command = new SqlCommand(@"
                INSERT INTO CoachReviews (UserId, CoachId, Comment, Rating, Date, AdminReply)
                VALUES (@UserId, @CoachId, @Comment, @Rating, @Date, @AdminReply)", connection);

                command.Parameters.AddWithValue("@UserId", review.UserId);
                command.Parameters.AddWithValue("@CoachId", review.CoachId);
                command.Parameters.AddWithValue("@Comment", review.Comment);
                command.Parameters.AddWithValue("@Rating", review.Rating);
                command.Parameters.AddWithValue("@Date", review.Date);
                command.Parameters.AddWithValue("@AdminReply", review.AdminReply != null ? (object)review.AdminReply : DBNull.Value);

                command.ExecuteNonQuery();
            }
        }

        public static bool HasUserReviewedCoach(int userId, int coachId)
        {
            using (var connection = DbConnectionFactory.CreateConnection())
            {
                connection.Open();
                var command = new SqlCommand("SELECT COUNT(*) FROM CoachReviews WHERE UserId = @UserId AND CoachId = @CoachId", connection);
                command.Parameters.AddWithValue("@UserId", userId);
                command.Parameters.AddWithValue("@CoachId", coachId);

                int count = (int)command.ExecuteScalar();
                return count > 0;
            }
        }

        public static void UpdateCoachReview(CoachReview review)
        {
            using (var connection = DbConnectionFactory.CreateConnection())
            {
                connection.Open();
                var command = new SqlCommand(@"
                UPDATE CoachReviews
                SET Comment = @Comment, Rating = @Rating, AdminReply = @AdminReply
                WHERE Id = @Id", connection);

                command.Parameters.AddWithValue("@Comment", review.Comment);
                command.Parameters.AddWithValue("@Rating", review.Rating);
                command.Parameters.AddWithValue("@AdminReply", review.AdminReply != null ? (object)review.AdminReply : DBNull.Value);
                command.Parameters.AddWithValue("@Id", review.Id);

                command.ExecuteNonQuery();
            }
        }

        public static bool DeleteCoachReview(int reviewId)
        {
            using (var connection = DbConnectionFactory.CreateConnection())
            {
                connection.Open();
                var command = new SqlCommand("DELETE FROM CoachReviews WHERE Id = @Id", connection);
                command.Parameters.AddWithValue("@Id", reviewId);

                int rowsAffected = command.ExecuteNonQuery();
                return rowsAffected > 0;
            }
        }

        public static bool SaveAdminCoachReply(int reviewId, string reply)
        {
            using (var connection = DbConnectionFactory.CreateConnection())
            {
                connection.Open();
                var command = new SqlCommand(@"
                UPDATE CoachReviews SET AdminReply = @Reply WHERE Id = @Id", connection);

                command.Parameters.AddWithValue("@Reply", reply);
                command.Parameters.AddWithValue("@Id", reviewId);

                return command.ExecuteNonQuery() > 0;
            }
        }
    }
}
