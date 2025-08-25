using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab_01
{
    public partial class Calculator : Form
    {
        public Calculator()
        {
            InitializeComponent();
        }

        private void replaceSubstring_Click(object sender, EventArgs e)
        {
            try
            {
                if (textBoxForOperations.Text.Length == 0)
                {
                    throw new EmptySubstringException();
                }

                resultOfOperations.Text = receivedText.Text.Replace(textBoxForOperations.Text, textBoxForReplacing.Text);
            }
            catch (EmptySubstringException ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void removeSubstring_Click(object sender, EventArgs e)
        {
            try
            {
                if (textBoxForOperations.Text.Length == 0)
                {
                    throw new EmptySubstringException();
                }

                resultOfOperations.Text = receivedText.Text.Replace(textBoxForOperations.Text, "");
            }
            catch (EmptySubstringException ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void getSymbolByIndex_Click(object sender, EventArgs e)
        {
            try
            {
                if (textBoxForOperations.Text.Length == 0)
                {
                    throw new EmptySubstringException();
                }

                if (Regex.Matches(textBoxForOperations.Text, @"[0123456789]", RegexOptions.IgnoreCase).Count == 0 
                    && textBoxForOperations.Text.Length != 0)
                {
                    throw new WrongIndexException();
                }

                char[] substrings = receivedText.Text.ToCharArray();

                int i = int.Parse(textBoxForOperations.Text);

                if (substrings.Length <= i || i < 0)
                {
                    throw new WrongIndexException();
                }

                resultOfOperations.Text = substrings[i].ToString();
            }
            catch (WrongIndexException ex) 
            {
                MessageBox.Show(ex.Message);
            }
            catch (EmptySubstringException ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void getStringLength_Click(object sender, EventArgs e)
        {
            resultOfOperations.Text = receivedText.Text.Length.ToString();
        }

        private void getNumberOfVowels_Click(object sender, EventArgs e)
        {
            int count = Regex.Matches(receivedText.Text, @"[aeyuioауоыиэяюёе]", RegexOptions.IgnoreCase).Count;
            resultOfOperations.Text = count.ToString();
        }

        private void getNumberOfConsonants_Click(object sender, EventArgs e)
        {
            int count = Regex.Matches(receivedText.Text, @"[qwrtpsdfghjklzxcvbnmйцкнгшщзхъфвпрлджчсмтьб]", RegexOptions.IgnoreCase).Count;
            resultOfOperations.Text = count.ToString();
        }

        private void getNumberOfSentences_Click(object sender, EventArgs e)
        {
            try
            {
                int punctCount = receivedText.Text.Split(new string[] { ". ", "? ", "! "}, StringSplitOptions.RemoveEmptyEntries).Length;

                int wrongPunctCount = receivedText.Text.Split(new string[] { ".!", ".?", "!.", "?.", " . "}, StringSplitOptions.RemoveEmptyEntries).Length;

                if (wrongPunctCount > 1)
                {
                    throw new WrongPunctuationException();
                }

                resultOfOperations.Text = punctCount.ToString();
            }
            catch (WrongPunctuationException ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void getNumberOfWords_Click(object sender, EventArgs e)
        {
            string[] words = receivedText.Text.Split(new char[] { ' ', '.', '!', '?', ';', ',', ':', '-' }, StringSplitOptions.RemoveEmptyEntries);
            resultOfOperations.Text = words.Length.ToString();
        }

        private void sendText_Click(object sender, EventArgs e)
        {
            try
            {
                receivedText.Text = textToSend.Text;

                if (receivedText.Text.Length == 0)
                {
                    throw new EmptyStringException();
                }
            }
            catch (EmptyStringException ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
    }
}
