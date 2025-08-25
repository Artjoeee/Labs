using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab_02
{
    public partial class SortForm: Form
    {
        public SortForm()
        {
            InitializeComponent();
        }

        private void SortForm_Load(object sender, EventArgs e)
        {
            List<Courses> listOfCourses = JsonConvert.DeserializeObject<List<Courses>>(File.ReadAllText("listOfCourses.json"));

            foreach (Courses item in listOfCourses)
            {
                sortBox.Items.Add($"{item.Name} - {item.Age} - {item.Budget}");
            }
        }

        private void sortButton_Click(object sender, EventArgs e)
        {
            List<string> list = new List<string>();

            foreach (string item in sortBox.Items)
            {
                list.Add(item);
            }

            var sortedTeachers = list.OrderBy(p => 
                p.Split(new string[] { "-" }, StringSplitOptions.RemoveEmptyEntries)[1]);

            sortBox.Items.Clear();

            foreach (string item in sortedTeachers)
            {
                sortBox.Items.Add(item);
            }

            list.Clear();

            foreach (string item in sortBox.Items)
            {
                list.Add(item);
            }

            Program.f1.SortResult = list;
            Program.f1.last.Text = "Произведена сортировка";
        }

        private void saveButton_Click(object sender, EventArgs e)
        {
            List<string> list = new List<string>();

            foreach (string item in sortBox.Items)
            {
                list.Add(item);
            }

            File.WriteAllText("sort.json", JsonConvert.SerializeObject(list, Formatting.Indented));

            Close();
        }

        private void sortPrice_Click(object sender, EventArgs e)
        {
            List<string> list = new List<string>();

            foreach (string item in sortBox.Items)
            {
                list.Add(item);
            }

            var sortedTeachers = list.OrderBy(p =>
                p.Split(new string[] { "-" }, StringSplitOptions.RemoveEmptyEntries)[1]);

            sortBox.Items.Clear();

            foreach (string item in sortedTeachers)
            {
                sortBox.Items.Add(item);
            }

            list.Clear();

            foreach (string item in sortBox.Items)
            {
                list.Add(item);
            }

            Program.f1.SortResult = list;
            Program.f1.last.Text = "Произведена сортировка";
        }
    }
}
