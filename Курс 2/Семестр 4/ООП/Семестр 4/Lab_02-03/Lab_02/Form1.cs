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
using System.Text.Json;
using System.Text.Json.Serialization;
using Newtonsoft.Json;
using System.ComponentModel.DataAnnotations;

namespace Lab_02
{
    public partial class EducationDepartmentForm : Form
    {
        public List<string> SearchResult { get; set; }
        public List<string> SortResult { get; set; }

        public EducationDepartmentForm()
        {
            Program.f1 = this;
            InitializeComponent();
        }

        private void save_Click(object sender, EventArgs e)
        {
            string ageGroup = "";
            string complexity = "";
            string type = "";

            List<string> list = listOfReferences.CheckedItems.Cast<string>().ToList();

            if (beginner.Checked == true)
            {
                complexity = beginner.Text;
            }
            else if (advanced.Checked == true)
            {
                complexity = advanced.Text;
            }
            else if (professional.Checked == true)
            {
                complexity = professional.Text;
            }

            if (exam.Checked == true)
            {
                type = exam.Text;
            }
            else if (test.Checked == true)
            {
                type = test.Text;
            }

            if (age.Text == "18 - 25" | age.Text == "26 - 35"
                | age.Text == "36 - 50" | age.Text == "51 и более")
            {
                ageGroup = age.Text;
            }

            Data data = new Data
            {
                Name = course.Text,
                Age = ageGroup,
                Complexity = complexity,
                LecturesCount = lectures.Text,
                LabsCount = labs.Text,
                TypeOfControl = type,
                Teacher = teacher.Text,
                ListOfReferences = list
            };

            var context = new ValidationContext(data);
            var results = new List<ValidationResult>();

            if (!Validator.TryValidateObject(data, context, results, true))
            {
                foreach (var error in results)
                {
                    MessageBox.Show(error.ErrorMessage);
                }
            }
            else
            {
                last.Text = "Добавлен объект";
                File.WriteAllText("statham.json", JsonConvert.SerializeObject(data, Formatting.Indented));
            }
        }

        private void read_Click(object sender, EventArgs e)
        {
            BudgetForm newForm = new BudgetForm();
            newForm.Show();
        }

        private void EducationDepartmentForm_Load(object sender, EventArgs e)
        {
            List<Teacher> listOfData = JsonConvert.DeserializeObject<List<Teacher>>(File.ReadAllText("listOfData.json"));

            foreach (Teacher item in listOfData)
            {
                teacher.Items.Add(item.Info);
            }

            List<References> references = JsonConvert.DeserializeObject<List<References>>(File.ReadAllText("references.json", Encoding.UTF8));

            foreach (References item in references)
            {
                listOfReferences.Items.Add(item.BookInfo);
            }

            List<Courses> listOfCourses = JsonConvert.DeserializeObject<List<Courses>>(File.ReadAllText("listOfCourses.json"));

            objectCount.Text = listOfCourses.Count().ToString();
            last.Text = "Произведен запуск";
            date.Text = DateTime.Now.ToString();
        }

        private void teacherButton_Click(object sender, EventArgs e)
        {
            TeacherForm newForm = new TeacherForm();
            newForm.Show();
        }

        private void listOfReferencesButton_Click(object sender, EventArgs e)
        {
            ListOfReferencesForm newForm = new ListOfReferencesForm();
            newForm.Show();
        }

        private void searchButton_Click(object sender, EventArgs e)
        {
            SearchForm searchForm = new SearchForm();
            searchForm.Show();
        }

        private void sortButton_Click(object sender, EventArgs e)
        {
            SortForm sortForm = new SortForm();
            sortForm.Show();
        }

        private void saveButton_Click(object sender, EventArgs e)
        {
            File.WriteAllText("search.json", JsonConvert.SerializeObject(SearchResult, Formatting.Indented));
            File.WriteAllText("sort.json", JsonConvert.SerializeObject(SortResult, Formatting.Indented));
            last.Text = "Данные о поиске и сортировке сохранены";
        }

        private void infoButton_Click(object sender, EventArgs e)
        {
            InfoForm infoForm = new InfoForm();
            infoForm.Show();
        }

        private void searh_Click(object sender, EventArgs e)
        {
            SearchForm searchForm = new SearchForm();
            searchForm.Show();
        }

        private void sort_Click(object sender, EventArgs e)
        {
            SortForm sortForm = new SortForm();
            sortForm.Show();
        }

        private void clear_Click(object sender, EventArgs e)
        {
            course.ClearSelected();
            age.Text = "";
            beginner.Checked = false;
            advanced.Checked = false;
            professional.Checked = false;
            exam.Checked = false;
            test.Checked = false;
            lectures.Value = 0;
            labs.Value = 0;
            teacher.ClearSelected();

            while (listOfReferences.CheckedIndices.Count > 0)
            {
                listOfReferences.SetItemChecked(listOfReferences.CheckedIndices[0], false);
            }

            last.Text = "Произведена очистка";
        }
    }
}
