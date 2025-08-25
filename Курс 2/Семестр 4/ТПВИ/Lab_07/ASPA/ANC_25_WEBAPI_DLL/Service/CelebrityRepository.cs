using ASPA007.Data;
using Microsoft.EntityFrameworkCore;

namespace DAL_Celebrity_MSSQL
{
    public class CelebrityRepository : IRepository
    {
        private readonly CelebrityContext _context;

        public CelebrityRepository(CelebrityContext context)
        {
            _context = context;
        }

        public bool AddCelebrity(Celebrity celebrity)
        {
            _context.Celebrities.Add(celebrity);
            return _context.SaveChanges() > 0;
        }

        public List<Celebrity> GetAllCelebrities() => _context.Celebrities.ToList();

        public Celebrity? GetCelebrityById(int id) => _context.Celebrities.Find(id);

        public bool DelCelebrity(int id)
        {
            var celeb = _context.Celebrities.Find(id);
            if (celeb == null) return false;
            _context.Celebrities.Remove(celeb);
            return _context.SaveChanges() > 0;
        }

        public bool UpdCelebrity(int id, Celebrity celebrity)
        {
            var existing = _context.Celebrities.Find(id);
            if (existing == null) return false;

            if (existing.Update(celebrity))
                return _context.SaveChanges() > 0;

            return false;
        }

        public int GetCelebrityIdByName(string name)
        {
            return _context.Celebrities.FirstOrDefault(c => c.FullName.Contains(name))?.Id ?? 0;
        }

        public List<LifeEvent> GetAllLifeevents() => _context.LifeEvents.ToList();

        public LifeEvent? GetLifeeventbyId(int id) => _context.LifeEvents.Find(id);

        public bool DelLifeEvent(int id)
        {
            var evt = _context.LifeEvents.Find(id);
            if (evt == null) return false;
            _context.LifeEvents.Remove(evt);
            return _context.SaveChanges() > 0;
        }

        public bool AddLifeevent(LifeEvent lifeevent)
        {
            _context.LifeEvents.Add(lifeevent);
            return _context.SaveChanges() > 0;
        }

        public bool UpdLifeEvent(int id, LifeEvent lifeevent)
        {
            var existing = _context.LifeEvents.Find(id);
            if (existing == null) return false;

            if (existing.Update(lifeevent))
                return _context.SaveChanges() > 0;

            return false;
        }

        public List<LifeEvent> GetLifeEventsByCelebrityId(int celebrityId)
        {
            return _context.LifeEvents.Where(le => le.CelebrityId == celebrityId).ToList();
        }

        public Celebrity? GetCelebrityByLifeeventId(int lifeeventId)
        {
            var evt = _context.LifeEvents.Find(lifeeventId);
            if (evt == null) return null;
            return _context.Celebrities.Find(evt.CelebrityId);
        }

        public void Dispose()
        {
            _context.Dispose();
        }

        public Celebrity? GetCelebrityByLifeEventId(int lifeEventId)
        {
            throw new NotImplementedException();
        }

        public List<LifeEvent> GetAllLifeEvents()
        {
            throw new NotImplementedException();
        }

        public LifeEvent? GetLifeEventById(int Id)
        {
            throw new NotImplementedException();
        }

        public bool AddLifeEvent(LifeEvent lifeEvent)
        {
            throw new NotImplementedException();
        }
    }
}