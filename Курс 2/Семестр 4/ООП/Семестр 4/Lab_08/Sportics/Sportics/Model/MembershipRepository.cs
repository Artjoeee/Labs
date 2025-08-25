using System;
using System.Collections.Generic;
using System.Data;
using Sportics.Model.Data;
using System.Data.SqlClient;

namespace Sportics.Model
{
    public class MembershipRepository
    {
        public static void AddMembership(string fullName, string shortName, string category, string description, decimal price, byte[] photo, int durationInDays)
        {
            using (var connection = DbConnectionFactory.CreateConnection())
            {
                connection.Open();

                using (var checkCmd = new SqlCommand("SELECT COUNT(*) FROM Memberships WHERE FullName = @FullName", connection))
                {
                    checkCmd.Parameters.AddWithValue("@FullName", fullName);
                    int exists = (int)checkCmd.ExecuteScalar();

                    if (exists == 0)
                    {
                        using (var cmd = new SqlCommand(@"
                        INSERT INTO Memberships 
                            (FullName, ShortName, Category, Description, Price, Photo, DurationInDays, IsWeeklyOffer)
                        VALUES 
                            (@FullName, @ShortName, @Category, @Description, @Price, @Photo, @DurationInDays, 0)", connection))
                        {
                            cmd.Parameters.AddWithValue("@FullName", fullName);
                            cmd.Parameters.AddWithValue("@ShortName", shortName);
                            cmd.Parameters.AddWithValue("@Category", category);
                            cmd.Parameters.AddWithValue("@Description", description);
                            cmd.Parameters.AddWithValue("@Price", price);
                            cmd.Parameters.AddWithValue("@Photo", photo ?? (object)DBNull.Value);
                            cmd.Parameters.AddWithValue("@DurationInDays", durationInDays);

                            cmd.ExecuteNonQuery();
                        }
                    }
                }
            }
        }

        public static void DeleteMembership(Membership membership)
        {
            using (var connection = DbConnectionFactory.CreateConnection())
            {
                connection.Open();

                using (var cmd = new SqlCommand("DELETE FROM Memberships WHERE Id = @Id", connection))
                {
                    cmd.Parameters.AddWithValue("@Id", membership.Id);
                    cmd.ExecuteNonQuery();
                }
            }
        }

        public static void EditMembership(Membership oldMembership, string fullName, string shortName,
            string description, string category, decimal price, byte[] photo, int durationInDays)
        {
            using (var connection = DbConnectionFactory.CreateConnection())
            {
                connection.Open();

                using (var cmd = new SqlCommand(@"
                UPDATE Memberships SET 
                    FullName = @FullName,
                    ShortName = @ShortName,
                    Description = @Description,
                    Category = @Category,
                    Price = @Price,
                    Photo = @Photo,
                    DurationInDays = @DurationInDays
                WHERE Id = @Id", connection))
                {
                    cmd.Parameters.AddWithValue("@FullName", fullName);
                    cmd.Parameters.AddWithValue("@ShortName", shortName);
                    cmd.Parameters.AddWithValue("@Description", description);
                    cmd.Parameters.AddWithValue("@Category", category);
                    cmd.Parameters.AddWithValue("@Price", price);
                    cmd.Parameters.AddWithValue("@Photo", photo ?? (object)DBNull.Value);
                    cmd.Parameters.AddWithValue("@DurationInDays", durationInDays);
                    cmd.Parameters.AddWithValue("@Id", oldMembership.Id);

                    cmd.ExecuteNonQuery();
                }
            }
        }

        public static void UpdateMembership(Membership membership)
        {
            using (var connection = DbConnectionFactory.CreateConnection())
            {
                connection.Open();

                using (var cmd = new SqlCommand(@"
                UPDATE Memberships SET 
                    FullName = @FullName,
                    ShortName = @ShortName,
                    Description = @Description,
                    Category = @Category,
                    Price = @Price,
                    Photo = @Photo,
                    DurationInDays = @DurationInDays,
                    IsWeeklyOffer = @IsWeeklyOffer
                WHERE Id = @Id", connection))
                {
                    cmd.Parameters.AddWithValue("@FullName", membership.FullName);
                    cmd.Parameters.AddWithValue("@ShortName", membership.ShortName);
                    cmd.Parameters.AddWithValue("@Description", membership.Description);
                    cmd.Parameters.AddWithValue("@Category", membership.Category);
                    cmd.Parameters.AddWithValue("@Price", membership.Price);
                    cmd.Parameters.AddWithValue("@Photo", membership.Photo ?? (object)DBNull.Value);
                    cmd.Parameters.AddWithValue("@DurationInDays", membership.DurationInDays);
                    cmd.Parameters.AddWithValue("@IsWeeklyOffer", membership.IsWeeklyOffer);
                    cmd.Parameters.AddWithValue("@Id", membership.Id);

                    cmd.ExecuteNonQuery();
                }
            }
        }

        public static List<Membership> GetAllMemberships()
        {
            var memberships = new List<Membership>();

            using (var connection = DbConnectionFactory.CreateConnection())
            {
                connection.Open();

                using (var cmd = new SqlCommand("SELECT * FROM Memberships", connection))
                using (var reader = cmd.ExecuteReader())
                {
                    while (reader.Read())
                    {
                        memberships.Add(new Membership
                        {
                            Id = (int)reader["Id"],
                            FullName = reader["FullName"].ToString(),
                            ShortName = reader["ShortName"].ToString(),
                            Description = reader["Description"].ToString(),
                            Category = reader["Category"].ToString(),
                            Price = (decimal)reader["Price"],
                            Photo = reader["Photo"] == DBNull.Value ? null : (byte[])reader["Photo"],
                            DurationInDays = (int)reader["DurationInDays"],
                            IsWeeklyOffer = (bool)reader["IsWeeklyOffer"]
                        });
                    }
                }
            }

            return memberships;
        }

        public static Membership SelectMembership(byte[] photo, string shortName, int price)
        {
            using (var connection = DbConnectionFactory.CreateConnection())
            {
                connection.Open();

                using (var cmd = new SqlCommand(@"
                SELECT TOP 1 * FROM Memberships 
                WHERE ShortName = @ShortName AND Price = @Price", connection))
                {
                    cmd.Parameters.AddWithValue("@ShortName", shortName);
                    cmd.Parameters.AddWithValue("@Price", price);

                    using (var reader = cmd.ExecuteReader())
                    {
                        if (reader.Read())
                        {
                            return new Membership
                            {
                                Id = (int)reader["Id"],
                                FullName = reader["FullName"].ToString(),
                                ShortName = reader["ShortName"].ToString(),
                                Description = reader["Description"].ToString(),
                                Category = reader["Category"].ToString(),
                                Price = (decimal)reader["Price"],
                                Photo = reader["Photo"] == DBNull.Value ? null : (byte[])reader["Photo"],
                                DurationInDays = (int)reader["DurationInDays"],
                                IsWeeklyOffer = (bool)reader["IsWeeklyOffer"]
                            };
                        }
                    }
                }
            }

            return null;
        }
    }

    public class MembershipRepositoryWrapper : IMembershipRepository
    {
        public void Add(Membership membership)
        {
            MembershipRepository.AddMembership(
                membership.FullName,
                membership.ShortName,
                membership.Category,
                membership.Description,
                membership.Price,
                membership.Photo,
                membership.DurationInDays);
        }
    }
}
