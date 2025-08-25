using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab_02
{
    public partial class SearchForm: Form
    {
        public SearchForm()
        {
            InitializeComponent();
        }

        private void SearchForm_Load(object sender, EventArgs e)
        {
            List<Courses> listOfCourses = JsonConvert.DeserializeObject<List<Courses>>(File.ReadAllText("listOfCourses.json"));

            foreach (Courses item in listOfCourses)
            {
                teachersForSearch.Items.Add($"{item.Name} - {item.Age} - {item.Budget}");
            }
        }

        private void searchButton_Click(object sender, EventArgs e)
        {
            string teacher = searchBox.Text;
            string pattern = $@"\w*{teacher}\w*";

            List<string> list = new List<string>();

            foreach (string item in teachersForSearch.Items)
            {
                if (Regex.IsMatch(item, pattern, RegexOptions.IgnoreCase))
                {
                    list.Add(item);
                }
            }

            Program.f1.SearchResult = list;
            Program.f1.last.Text = "Произведен поиск";

            if (list.Count != 0)
            {
                teachersForSearch.Items.Clear();

                foreach (string item in list)
                {
                    teachersForSearch.Items.Add(item);
                }
            }
        }

        private void saveButton_Click(object sender, EventArgs e)
        {
            List<string> list = new List<string>();

            foreach (string item in teachersForSearch.Items)
            {
                list.Add(item);
            }

            File.WriteAllText("search.json", JsonConvert.SerializeObject(list, Formatting.Indented));

            Close();
        }
    }
}
