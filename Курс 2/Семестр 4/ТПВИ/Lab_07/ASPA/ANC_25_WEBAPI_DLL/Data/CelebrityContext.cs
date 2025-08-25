using DAL_Celebrity_MSSQL;
using Microsoft.EntityFrameworkCore;

namespace ASPA007.Data
{
    public class CelebrityContext : DbContext
    {
        public CelebrityContext(DbContextOptions<CelebrityContext> options)
            : base(options) { }

        public DbSet<Celebrity> Celebrities { get; set; }
        public DbSet<LifeEvent> LifeEvents { get; set; }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            // Конфигурация для Celebrity
            modelBuilder.Entity<Celebrity>(entity =>
            {
                entity.HasKey(e => e.Id);
                entity.Property(e => e.FullName)
                    .IsRequired()
                    .HasMaxLength(100);
                entity.Property(e => e.Nationality)
                    .IsRequired()
                    .HasMaxLength(2);
                entity.Property(e => e.ReqPhotoPath)
                    .HasMaxLength(255);

                // Навигационное свойство для LifeEvents
                entity.HasMany<LifeEvent>()
                    .WithOne()
                    .HasForeignKey(le => le.CelebrityId)
                    .OnDelete(DeleteBehavior.Cascade);
            });

            // Конфигурация для LifeEvent
            modelBuilder.Entity<LifeEvent>(entity =>
            {
                entity.HasKey(e => e.Id);
                entity.Property(e => e.Description)
                    .IsRequired();
                entity.Property(e => e.ReqPhotoPath)
                    .HasMaxLength(255);

                // Связь с Celebrity (уже настроена на стороне Celebrity)
                entity.HasOne<Celebrity>()
                    .WithMany()
                    .HasForeignKey(le => le.CelebrityId);
            });
        }
    }
}