using Microsoft.EntityFrameworkCore;

namespace DAL_Celebrity_MSSQL
{
    public class Context : DbContext
    {
        public string? ConnectionString { get; private set; } = null;

        public Context(string connString) : base()
        {
            this.ConnectionString = connString;
        }

        public Context() : base() { }

        public DbSet<Celebrity> Celebrities { get; set; }
        public DbSet<LifeEvent> LifeEvents { get; set; }

        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            if (this.ConnectionString is null) ConnectionString = @"Server=(localdb)\mssqllocaldb; Database=CELEBRITIES; Trusted_Connection=True;"; // Initial catalog? 
            optionsBuilder.UseSqlServer(ConnectionString);
        }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {   
            //e == entity
            modelBuilder.Entity<Celebrity>(e =>
            {
                e.ToTable("Celebrities").HasKey(p => p.Id);
                e.Property(p => p.FullName).IsRequired().HasMaxLength(50);
                e.Property(p => p.Nationality).IsRequired().HasMaxLength(2);
                e.Property(p => p.ReqPhotoPath).HasMaxLength(200);
            });// Celebrity configuration

            modelBuilder.Entity<LifeEvent>(e =>
            {
                e.ToTable("LifeEvents").HasKey(p => p.Id);
                e.HasOne<Celebrity>().WithMany().HasForeignKey(p => p.CelebrityId);
                e.Property(p => p.Description).HasMaxLength(256);
                e.Property(p => p.ReqPhotoPath).HasMaxLength(256);
            });// LifeEvent configuration

            base.OnModelCreating(modelBuilder);
        }
    }
}
