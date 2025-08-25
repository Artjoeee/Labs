using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_04
{
    abstract class Plant : ICloneable
    {
        public string Name { get; set; }

        // Абстрактный метод
        public abstract bool DoClone();

        // Виртуальный метод
        public virtual string Describe()
        {
            return $"Это растение по имени {Name}.";
        }

        // Переопределение метода ToString()
        public override string ToString()
        {
            return $"Растение: {Name}";
        }

        // Переопределение метода Equals()
        public override bool Equals(object obj)
        {
            // Проверяем, является ли переданный объект цветком и совпадают ли имена
            if (obj is Flower otherFlower)
                return Name == otherFlower.Name;

            return false;
        }

        // Переопределение метода GetHashCode()
        public override int GetHashCode()
        {
            return Name.GetHashCode();
        }
    }

    // Класс Bush, наследуемый от Plant
    class Bush : Plant
    {
        public string Type { get; set; } // Свойство для типа куста

        public override bool DoClone()
        {
            return true;
        }

        public override string ToString()
        {
            return $"Куст: {Name}, Вид: {Type}";
        }
    }

    // Класс Flower, наследуемый от Plant
    class Flower : Plant, ICloneable
    {
        public string Color { get; set; } // Свойство для хранения цвета цветка

        // Реализация метода DoClone() из интерфейса
        bool ICloneable.DoClone()
        {
            Console.WriteLine("Клонирование через интерфейс ICloneable.");
            return true;
        }

        // Реализация абстрактного метода DoClone()
        public override bool DoClone()
        {
            Console.WriteLine("Клонирование через абстрактный класс Plant.\n");

            return true;
        }

        // Переопределение метода Describe()
        public override string Describe()
        {
            return $"Это цветок по имени {Name}, цвет которого — {Color}.\n";
        }

        public override string ToString()
        {
            return $"Цветок: {Name}, Цвет: {Color}";
        }
    }

    // Класс Rose, наследуется от Flower
    class Rose : Flower
    {
        public int ThornCount { get; set; } // Свойство для хранения количества шипов

        public override bool DoClone()
        {
            return true;
        }

        // Переопределение метода ToString()
        public override string ToString()
        {
            return $"Роза: {Name}, Цвет: {Color}, Количество шипов: {ThornCount}";
        }
    }

    // Класс Gladiolus, наследуется от Flower
    class Gladiolus : Flower
    {
        public int PetalCount { get; set; } // Свойство для хранения количества лепестков

        public override bool DoClone()
        {
            return true;
        }

        // Переопределение метода ToString()
        public override string ToString()
        {
            return $"Гладиолус: {Name}, Цвет: {Color}, Количество лепестков: {PetalCount}";
        }
    }

    // Класс Cactus, запрещает дальнейшее наследование
    sealed class Cactus : Plant
    {
        public int NeedleCount { get; set; } // Свойство для хранения количества шипов

        public override bool DoClone()
        {
            return true;
        }

        public override string ToString()
        {
            return $"Кактус: {Name}, Количество шипов: {NeedleCount}";
        }
    }

    // Класс Paper, представляющий бумагу
    class Paper
    {
        public string Material { get; set; }

        public override string ToString()
        {
            return $"Бумага: {Material}";
        }
    }

    // Класс Bouquet, включает композицию объектов Flower и Paper
    class Bouquet
    {
        public List<Flower> Flowers { get; set; } = new List<Flower>(); // Список цветов в букете

        public Paper Wrapper { get; set; } // Обертка из бумаги для букета

        public override string ToString()
        {
            string flowersInfo = string.Join(", ", Flowers); // Получение строки с описанием всех цветов

            return $"Букет: {flowersInfo}, Завернут в {Wrapper}";
        }
    }

    // Класс Printer с методом IAmPrinting, принимающим объект типа Plant
    class Printer
    {
        // Метод IAmPrinting, который выводит информацию о переданном объекте Plant
        public void IAmPrinting(Plant obj)
        {
            Console.WriteLine(obj.ToString());
        }
    }
}
