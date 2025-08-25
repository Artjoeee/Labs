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
using static System.Windows.Forms.VisualStyles.VisualStyleElement;
using System.Xml.Linq;
using Newtonsoft.Json;
using System.ComponentModel.DataAnnotations;

namespace Lab_02
{
    public partial class TeacherForm : Form
    {
        public TeacherForm()
        {
            InitializeComponent();
        }

        private void add_Click(object sender, EventArgs e)
        {
            string classroomNumber = "";
            string department = "";

            if (pi.Checked == true)
            {
                department = pi.Text;
            }
            else if (isit.Checked == true)
            {
                department = isit.Text;
            }
            else if (cd.Checked == true)
            {
                department = cd.Text;
            }

            if (classroom.Text == "100" | classroom.Text == "101"
                | classroom.Text == "102" | classroom.Text == "103")
            {
                classroomNumber = classroom.Text;
            }

            string info = $"{fullName.Text} - {department} - {classroomNumber}";

            Teacher newTeacher = new Teacher
            {
                Department = department,
                Auditorium = classroomNumber,
                FullName = fullName.Text,
                Info = info
            };

            var context = new ValidationContext(newTeacher);
            var results = new List<ValidationResult>();

            if (!Validator.TryValidateObject(newTeacher, context, results, true))
            {
                foreach (var error in results)
                {
                    MessageBox.Show(error.ErrorMessage);
                }
            }
            else
            {
                Program.f1.teacher.Items.Add(newTeacher.Info);
                Program.f1.last.Text = "Добавлен преподаватель";

                List<Teacher> listOfData = JsonConvert.DeserializeObject<List<Teacher>>(File.ReadAllText("listOfData.json"));

                listOfData.Add(newTeacher);

                File.WriteAllText("listOfData.json", JsonConvert.SerializeObject(listOfData, Formatting.Indented));
            }

            Close();
        }
    }
}
