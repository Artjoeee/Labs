using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.ComponentModel.DataAnnotations;
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
    public partial class ListOfReferencesForm : Form
    {
        public ListOfReferencesForm()
        {
            InitializeComponent();
        }

        private void add_Click(object sender, EventArgs e)
        {
            string bookInfo = $"{book.Text} - {author.Text} - {year.Text}";

            References reference = new References
            {
                Book = book.Text,
                Author = author.Text,
                Year = year.Text,
                BookInfo = bookInfo
            };

            var context = new ValidationContext(reference);
            var results = new List<ValidationResult>();

            if (!Validator.TryValidateObject(reference, context, results, true))
            {
                foreach (var error in results)
                {
                    MessageBox.Show(error.ErrorMessage);
                }
            }
            else
            {
                Program.f1.listOfReferences.Items.Add(reference.BookInfo);
                Program.f1.last.Text = "Добавлена книга";

                List<References> listOfReferences = JsonConvert.DeserializeObject<List<References>>(File.ReadAllText("references.json"));

                listOfReferences.Add(reference);

                File.WriteAllText("references.json", JsonConvert.SerializeObject(listOfReferences, Formatting.Indented));
            }

            Close();
        }
    }
}
