using DAL_Celebrity_MSSQL;

namespace DAL_Celebrity_MSSQL_Test
{
    internal class Test
    {
        private static void Main(string[] args)
        {
            string CS = @"Server=(localdb)\mssqllocaldb; Database=CELEBRITIES; Trusted_Connection=True;";

            Init init = new Init(CS);
            Init.Execute(delete: true, create: true);

            Func<Celebrity, string> printC = (c) => $"Id = {c.Id}, FullName = {c.FullName}, Nationality = {c.Nationality}, RegPhotoPath = {c.ReqPhotoPath}";
            Func<LifeEvent, string> printL = (l) => $"Id = {l.Id}, CelebrityId = {l.CelebrityId}, Date = {l.Date}, Description = {l.Description}, RegPhotoPath = {l.ReqPhotoPath}";
            Func<string, string> puri = (string f) => $"{f}"; // для задания пути к файлам

            using (IRepository repo = Repository.Create(CS))
            {
                {
                    Console.WriteLine("//1--- GetAllCelebrities() --- ");
                    repo.GetAllCelebrities().ForEach(celebrity => Console.WriteLine(printC(celebrity)));
                }
                {
                    Console.WriteLine("//2--- GetAllLifeevents() --- ");
                    repo.GetAllLifeEvents().ForEach(life => Console.WriteLine(printL(life)));
                }
                {
                    Console.WriteLine("//3--- AddCelebrity() --- ");
                    Celebrity c1 = new Celebrity { FullName = "Albert Einstein", Nationality = "DE", ReqPhotoPath = puri("Einstein.jpg") };
                    if (repo.AddCelebrity(c1)) Console.WriteLine($"OK: AddCelebrity: {printC(c1)}");
                    else Console.WriteLine($"ERROR: AddCelebrity: {printC(c1)}");
                }
                {
                    Console.WriteLine("//4--- AddCelebrity() --- ");
                    Celebrity c2 = new Celebrity { FullName = "Samuel Huntington", Nationality = "US", ReqPhotoPath = puri("Huntington.jpg") };
                    if (repo.AddCelebrity(c2)) Console.WriteLine($"OK: AddCelebrity: {printC(c2)}");
                    else Console.WriteLine($"ERROR: AddCelebrity: {printC(c2)}");
                }
                {
                    Console.WriteLine("//5--- DelCelebrity() --- ");
                    int id = 0;
                    if ((id = repo.GetCelebrityIdByName("Einstein")) > 0)
                    {
                        if (repo.DelCelebrity(id)) Console.WriteLine($"OK: DelCelebrity: {id}");
                        else Console.WriteLine($"ERROR: DelCelebrity {id}");
                    }
                    else Console.WriteLine($"ERROR: GetCelebrityIdByName");
                }
                {
                    Console.WriteLine("//6--- UpdCelebrity() --- ");
                    int id = 0;
                    if ((id = repo.GetCelebrityIdByName("Huntington")) > 0)
                    {
                        Celebrity? c = repo.GetCelebrityById(id);
                        c.FullName = "Samuel Phillips Huntington";
                        if (c != null)
                        {//
                            if (repo.UpdCelebrity(id, c)) Console.WriteLine($"OK: UpdCelebrity: {id}, {printC(c)}");
                            else Console.WriteLine($"ERROR: UpdCelebrity: {id} , {printC(c)}");
                        }
                        else Console.WriteLine($"ERROR: GetCelebrityById: {id}");
                    }
                    else Console.WriteLine($"ERROR: GetCelebrityIdByName");
                }
                {
                    Console.WriteLine("//7--- AddLifeevent() --- ");
                    int id = 0;
                    if ((id = repo.GetCelebrityIdByName("Huntington")) > 0)
                    {//
                        Celebrity? c = repo.GetCelebrityById(id);
                        if (c != null)
                        {
                            LifeEvent? l1 = new LifeEvent {CelebrityId = id, Date = new DateTime(1927, 04, 18), Description = "Дата рождения", ReqPhotoPath = null };
                            if (repo.AddLifeEvent(l1)) Console.WriteLine($"OK: AddLifeEvent, {printL(l1)}");
                            else Console.WriteLine($"ERROR: AddLifeEvent, {printL(l1)}");
                            LifeEvent? l2 = new LifeEvent { CelebrityId = id, Date = new DateTime(1927, 04, 18), Description = "Дата рождения", ReqPhotoPath = null };
                            if (repo.AddLifeEvent(l2)) Console.WriteLine($"OK: AddLifeEvent, {printL(l2)}");
                            else Console.WriteLine($"ERROR: AddLifeEvent, {printL(l2)}");
                            LifeEvent? l3 = new LifeEvent { CelebrityId = id, Date = new DateTime(2008, 12, 24), Description = "Дата рождения", ReqPhotoPath = null };
                            if (repo.AddLifeEvent(l3)) Console.WriteLine($"OK: AddLifeEvent, {printL(l3)}");
                            else Console.WriteLine($"ERROR: AddLifeEvent, {printL(l3)}");
                        }
                        else Console.WriteLine($"ERROR: GetCelebrityById: {id}");
                    }
                    else Console.WriteLine($"ERROR: GetCelebrityIdByName");
                }
                {
                    Console.WriteLine("//8--- DelLifeEvent() --- ");
                    int id = 22;
                    if (repo.DelLifeEvent(id)) Console.WriteLine($"OK: DelLifeEvent: {id}");
                    else Console.WriteLine($"ERROR: DelLifeEvent: {id}");
                }
                {
                    Console.WriteLine("//9--- UpdLifeEvent() --- ");
                    int id = 23;
                    LifeEvent? l1;
                    if ((l1 = repo.GetLifeEventById(id)) != null)
                    {
                        l1.Description = "Дата смерти";
                        if (repo.UpdLifeEvent(id, l1)) Console.WriteLine($"OK: UpdLifeEvent {id}, {printL(l1)}");
                        else Console.WriteLine($"ERROR: UpdLifeEvent {id}, {printL(l1)}");
                    }
                }
                {
                    Console.WriteLine("//10--- GetLifeEventsByCelebrityId --- ");
                    int id = 0;
                    if ((id = repo.GetCelebrityIdByName("Huntington")) > 0)
                    {
                        Celebrity? c = repo.GetCelebrityById(id);
                        if (c != null) repo.GetLifeEventsByCelebrityId(c.Id).ForEach(l => Console.WriteLine($"OK: GetLifeEventsByCelebrityId, {id}, {printL(l)}"));
                        else Console.WriteLine($"ERROR: GetLifeEventsByCelebrityId: {id}");
                    }
                    else Console.WriteLine($"ERROR: GetCelebrityIdByName");
                }
                {
                    Console.WriteLine("//11--- GetCelebrityByLifeEventId --- ");
                    int id = 23;
                    Celebrity? c;
                    if ((c = repo.GetCelebrityByLifeEventId(id)) != null) Console.WriteLine($"OK: {printC(c)}");
                    else Console.WriteLine($"ERROR: GetCelebrityByLifeEventId, {id}");
                }
                Console.WriteLine("--->"); Console.ReadKey();
            }
        }
    }
}