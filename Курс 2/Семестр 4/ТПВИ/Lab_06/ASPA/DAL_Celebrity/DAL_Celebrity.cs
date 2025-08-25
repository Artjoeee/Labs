namespace DAL_Celebrity
{
    public interface IRepository<T1, T2> : IMix<T1, T2>, ICelebrity<T1>, ILifeEvent<T2> { }

    public interface IMix<T1, T2>
    {
        List<T2> GetLifeEventsByCelebrityId(int celebrityId); // получить все События по Id Знаменитости
        T1? GetCelebrityByLifeEventId(int lifeEventId); // получить Знаменитость по Id События
    }

    public interface ICelebrity<T> : IDisposable
    {
        List<T> GetAllCelebrities(); // получить все Знаменитости
        T? GetCelebrityById(int Id); // получить Знаменитость по Id
        bool DelCelebrity(int id); // удалить Знаменитость по Id
        bool AddCelebrity(T celebrity); // добавить Знаменитость
        bool UpdCelebrity(int id, T celebrity); // изменить Знаменитость по Id
        int GetCelebrityIdByName(string name); // получить первый Id по вхождению подстроки
    }

    public interface ILifeEvent<T> : IDisposable
    {
        List<T> GetAllLifeEvents(); // получить все События
        T? GetLifeEventById(int Id); // получить Событие по Id
        bool DelLifeEvent(int id); // удалить Событие по Id
        bool AddLifeEvent(T lifeEvent); // добавить Событие
        bool UpdLifeEvent(int id, T lifeEvent); // изменить Событие по Id
    }
}
