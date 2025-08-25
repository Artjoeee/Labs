using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ex1
{
    public class Student
    {
        public string Name { get; set; }
        public int Age { get; set; }
        public List<int> Grades { get; set; }

        public Student(string name, int age, List<int> grades) 
        {
            Name = name;
            Age = age;
            Grades = grades;
        }


        public static int Mid(Student student)
        {
            int sum = student.Grades.Sum();

            int mid = sum / 3;

            return mid;
        }
    }
}
