namespace DAL_Celebrity_MSSQL
{
    public class Repository : IRepository
    {
        Context context;

        public Repository() { this.context = new Context(); }
        public Repository(string connectionString) { this.context = new Context(connectionString); }

        public static IRepository Create() { return new Repository(); }
        public static IRepository Create(string connectionString) { return new Repository(connectionString); }

        public List<Celebrity> GetAllCelebrities() { return this.context.Celebrities.ToList<Celebrity>(); }
        public Celebrity? GetCelebrityById(int Id) { return this.context.Celebrities.FirstOrDefault(c => c.Id == Id); }

        public bool AddCelebrity(Celebrity celebrity)
        {
            try { context.Celebrities.Add(celebrity); return context.SaveChanges() > 0; }
            catch { return false; }
        }

        public bool DelCelebrity(int id)
        {
            Celebrity? celebrity = GetCelebrityById(id);
            if (celebrity == null) return false;
            try { context.Celebrities.Remove(celebrity); return context.SaveChanges() > 0; }
            catch { return false; }
        }

        public bool UpdCelebrity(int id, Celebrity celebrity)
        {
            Celebrity? existingCelebrity = GetCelebrityById(id);
            if (existingCelebrity == null) return false;
            try { existingCelebrity.Update(celebrity); return context.SaveChanges() > 0; }//>= ?
            catch { return false; }
        }

        public List<LifeEvent> GetAllLifeEvents() { return this.context.LifeEvents.ToList<LifeEvent>(); }
        public LifeEvent? GetLifeEventById(int Id) { return this.context.LifeEvents.FirstOrDefault(l => l.Id == Id); }

        public bool AddLifeEvent(LifeEvent lifeEvent)
        {
            try { context.LifeEvents.Add(lifeEvent); return context.SaveChanges() > 0; }
            catch { return false; }
        }

        public bool DelLifeEvent(int id)
        {
            LifeEvent? liveEvent = GetLifeEventById(id);
            if (liveEvent == null) return false;
            try { context.LifeEvents.Remove(liveEvent); return context.SaveChanges() > 0; }
            catch { return false; }
        }

        public bool UpdLifeEvent(int id, LifeEvent lifeEvent)
        {
            LifeEvent? existingLiveEvent = GetLifeEventById(id);
            if (existingLiveEvent == null) return false;
            try { existingLiveEvent.Update(lifeEvent); return context.SaveChanges() > 0; }
            catch { return false; }
        }

        public List<LifeEvent> GetLifeEventsByCelebrityId(int celebrityId) { return this.context.LifeEvents.Where(l => l.CelebrityId == celebrityId).ToList(); }

        public Celebrity? GetCelebrityByLifeEventId(int lifeEventId)
        {
            LifeEvent? l = GetLifeEventById(lifeEventId);
            if (l == null) return null;
            return this.GetCelebrityById(l.CelebrityId);
        }

        public int GetCelebrityIdByName(string name)
        {
            var celebrity = context.Celebrities.FirstOrDefault(c => c.FullName.Contains(name));
            return celebrity?.Id ?? -1;
        }

        public void Dispose() => context?.Dispose(); //?
    }
}
