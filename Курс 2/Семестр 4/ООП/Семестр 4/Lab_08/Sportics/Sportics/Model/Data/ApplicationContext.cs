using System;
using System.Configuration;
using System.Data.SqlClient;

namespace Sportics.Model.Data
{
    public static class DbConnectionFactory
    {
        private static bool _databaseChecked = false;

        public static SqlConnection CreateConnection()
        {
            EnsureDatabaseAndTables();

            string connectionString = ConfigurationManager.ConnectionStrings["DefaultConnection"].ConnectionString;
            return new SqlConnection(connectionString);
        }

        private static void EnsureDatabaseAndTables()
        {
            if (_databaseChecked)
                return;

            _databaseChecked = true;

            var originalBuilder = new SqlConnectionStringBuilder(ConfigurationManager.ConnectionStrings["DefaultConnection"].ConnectionString);
            string databaseName = originalBuilder.InitialCatalog;

            // Подключаемся к master
            var masterBuilder = new SqlConnectionStringBuilder(originalBuilder.ConnectionString)
            {
                InitialCatalog = "master"
            };

            using (var masterConnection = new SqlConnection(masterBuilder.ConnectionString))
            {
                masterConnection.Open();

                // Проверка существования БД
                var checkDbCmd = new SqlCommand($"SELECT db_id('{databaseName}')", masterConnection);
                var result = checkDbCmd.ExecuteScalar();

                if (result == DBNull.Value || result == null)
                {
                    var createDbCmd = new SqlCommand($"CREATE DATABASE [{databaseName}]", masterConnection);
                    createDbCmd.ExecuteNonQuery();
                    Console.WriteLine($"База данных '{databaseName}' создана.");
                }
            }

            
            using (var dbConnection = new SqlConnection(originalBuilder.ConnectionString))
            {
                dbConnection.Open();

                string createTablesSql = @"
                IF NOT EXISTS (SELECT * FROM sysobjects WHERE name='Users' AND xtype='U')
                CREATE TABLE Users (
                    Id INT IDENTITY PRIMARY KEY,
                    Name NVARCHAR(255),
                    Email NVARCHAR(255),
                    PhoneNumber NVARCHAR(50),
                    PasswordHash NVARCHAR(255),
                    PasswordSalt NVARCHAR(255),
                    Role NVARCHAR(50),
                    Balance DECIMAL(18,2),
                    Status NVARCHAR(50)
                );

                IF NOT EXISTS (SELECT * FROM sysobjects WHERE name='Memberships' AND xtype='U')
                CREATE TABLE Memberships (
                    Id INT IDENTITY PRIMARY KEY,
                    FullName NVARCHAR(255),
                    ShortName NVARCHAR(100),
                    Category NVARCHAR(100),
                    Description NVARCHAR(MAX),
                    Price DECIMAL(18,2),
                    Photo VARBINARY(MAX),
                    DurationInDays INT,
                    IsWeeklyOffer BIT
                );

                IF NOT EXISTS (SELECT * FROM sysobjects WHERE name='MembershipOrders' AND xtype='U')
                CREATE TABLE MembershipOrders (
                    Id INT IDENTITY PRIMARY KEY,
                    MembershipId INT,
                    MembershipName NVARCHAR(255),
                    ClientId INT,
                    ClientName NVARCHAR(255),
                    Category NVARCHAR(100),
                    PurchaseDate DATETIME,
                    EndDate DATETIME
                );

                IF NOT EXISTS (SELECT * FROM sysobjects WHERE name='Coaches' AND xtype='U')
                CREATE TABLE Coaches (
                    Id INT IDENTITY PRIMARY KEY,
                    Name NVARCHAR(255),
                    Email NVARCHAR(255),
                    PhoneNumber NVARCHAR(50),
                    Specialization NVARCHAR(255),
                    Information NVARCHAR(MAX),
                    Photo VARBINARY(MAX)
                );

                IF NOT EXISTS (SELECT * FROM sysobjects WHERE name='Schedules' AND xtype='U')
                CREATE TABLE Schedules (
                    Id INT IDENTITY PRIMARY KEY,
                    Category NVARCHAR(100),
                    CoachId INT,
                    Time TIME,
                    Date DATE,
                    Status NVARCHAR(50)
                );

                IF NOT EXISTS (SELECT * FROM sysobjects WHERE name='ClientSessionRecords' AND xtype='U')
                CREATE TABLE ClientSessionRecords (
                    Id INT IDENTITY PRIMARY KEY,
                    ClientId INT,
                    ScheduleId INT,
                    Category NVARCHAR(100),
                    Time TIME,
                    Date DATE,
                    MembershipOrderId INT,
                    MembershipId INT
                );

                IF NOT EXISTS (SELECT * FROM sysobjects WHERE name='CoachReviews' AND xtype='U')
                CREATE TABLE CoachReviews (
                    Id INT IDENTITY PRIMARY KEY,
                    CoachId INT,
                    UserId INT,
                    Rating INT,
                    Comment NVARCHAR(MAX),
                    Date DATETIME,
                    AdminReply NVARCHAR(MAX)
                );

                IF NOT EXISTS (SELECT * FROM sysobjects WHERE name='SessionReviews' AND xtype='U')
                CREATE TABLE SessionReviews (
                    Id INT IDENTITY PRIMARY KEY,
                    ScheduleId INT,
                    UserId INT,
                    Rating INT,
                    Comment NVARCHAR(MAX),
                    Date DATETIME,
                    AdminReply NVARCHAR(MAX)
                );
                ";
                var createCommand = new SqlCommand(createTablesSql, dbConnection);
                createCommand.ExecuteNonQuery();
            }
        }
    }
}
