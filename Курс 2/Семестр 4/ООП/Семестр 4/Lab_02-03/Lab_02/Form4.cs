using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.Json;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab_02
{
    public partial class BudgetForm : Form
    {
        public BudgetForm()
        {
            InitializeComponent();
        }

        private void BudgetForm_Load(object sender, EventArgs e)
        {
            Data data = JsonConvert.DeserializeObject<Data>(File.ReadAllText("statham.json"));

            name.Text = data.Name;
            age.Text = data.Age;
            complexity.Text = data.Complexity;
            typeOfControl.Text = data.TypeOfControl;
            teacher.Text = data.Teacher;
            lectures.Text = data.LecturesCount;
            labs.Text = data.LabsCount;

            foreach (var item in data.ListOfReferences)
            {
                listOfReferences.Text += item + ", ";
            }

            List<string> list = data.ListOfReferences.ToList();

            double ageCoeff;
            double complexityCoeff;

            if(age.Text == "18 - 25")
            {
                ageCoeff = 1.2;
            }
            else if (age.Text == "26 - 35")
            {
                ageCoeff = 1.4;
            }
            else if (age.Text == "36 - 50")
            {
                ageCoeff = 1.6;
            }
            else if (age.Text == "51 и более")
            {
                ageCoeff = 1.8;
            }
            else
            {
                ageCoeff = 0;
            }

            if (complexity.Text == "Новичок")
            {
                complexityCoeff = 1.6;
            }
            else if (complexity.Text == "Продвинутый")
            {
                complexityCoeff = 1.4;
            }
            else
            {
                complexityCoeff = 1.2;
            }

            double budgetOfGroup = (30 * int.Parse(lectures.Text) + 30 * int.Parse(labs.Text)) * complexityCoeff * ageCoeff;

            budget.Text = budgetOfGroup.ToString();

            Courses course = new Courses
            {
                Name = data.Name,
                Age = data.Age,
                Complexity = data.Complexity,
                LecturesCount = data.LecturesCount,
                LabsCount = data.LabsCount,
                TypeOfControl = data.TypeOfControl,
                Teacher = data.Teacher,
                ListOfReferences = data.ListOfReferences,
                Budget = budgetOfGroup.ToString()
            };

            List<Courses> datas = JsonConvert.DeserializeObject<List<Courses>>(File.ReadAllText("listOfCourses.json"));
            datas.Add(course);
            File.WriteAllText("listOfCourses.json", JsonConvert.SerializeObject(datas, Formatting.Indented));
        }
    }
}
