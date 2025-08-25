namespace Lab_01
{
    partial class Calculator
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.replaceSubstring = new System.Windows.Forms.Button();
            this.resultOfOperations = new System.Windows.Forms.Label();
            this.textBoxForOperations = new System.Windows.Forms.TextBox();
            this.textToSend = new System.Windows.Forms.TextBox();
            this.sendText = new System.Windows.Forms.Button();
            this.removeSubstring = new System.Windows.Forms.Button();
            this.getNumberOfVowels = new System.Windows.Forms.Button();
            this.getNumberOfConsonants = new System.Windows.Forms.Button();
            this.getSymbolByIndex = new System.Windows.Forms.Button();
            this.getStringLength = new System.Windows.Forms.Button();
            this.getNumberOfSentences = new System.Windows.Forms.Button();
            this.getNumberOfWords = new System.Windows.Forms.Button();
            this.receivedText = new System.Windows.Forms.Label();
            this.textBoxForReplacing = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // replaceSubstring
            // 
            this.replaceSubstring.Location = new System.Drawing.Point(48, 278);
            this.replaceSubstring.Name = "replaceSubstring";
            this.replaceSubstring.Size = new System.Drawing.Size(107, 45);
            this.replaceSubstring.TabIndex = 0;
            this.replaceSubstring.Text = "Заменить";
            this.replaceSubstring.UseVisualStyleBackColor = true;
            this.replaceSubstring.Click += new System.EventHandler(this.replaceSubstring_Click);
            // 
            // resultOfOperations
            // 
            this.resultOfOperations.AutoSize = true;
            this.resultOfOperations.Location = new System.Drawing.Point(391, 211);
            this.resultOfOperations.Name = "resultOfOperations";
            this.resultOfOperations.Size = new System.Drawing.Size(0, 16);
            this.resultOfOperations.TabIndex = 1;
            // 
            // textBoxForOperations
            // 
            this.textBoxForOperations.Location = new System.Drawing.Point(80, 211);
            this.textBoxForOperations.Name = "textBoxForOperations";
            this.textBoxForOperations.Size = new System.Drawing.Size(102, 22);
            this.textBoxForOperations.TabIndex = 2;
            // 
            // textToSend
            // 
            this.textToSend.Location = new System.Drawing.Point(80, 60);
            this.textToSend.Name = "textToSend";
            this.textToSend.Size = new System.Drawing.Size(224, 22);
            this.textToSend.TabIndex = 3;
            // 
            // sendText
            // 
            this.sendText.Location = new System.Drawing.Point(343, 56);
            this.sendText.Name = "sendText";
            this.sendText.Size = new System.Drawing.Size(92, 30);
            this.sendText.TabIndex = 4;
            this.sendText.Text = "Отправить";
            this.sendText.UseVisualStyleBackColor = true;
            this.sendText.Click += new System.EventHandler(this.sendText_Click);
            // 
            // removeSubstring
            // 
            this.removeSubstring.Location = new System.Drawing.Point(161, 278);
            this.removeSubstring.Name = "removeSubstring";
            this.removeSubstring.Size = new System.Drawing.Size(110, 45);
            this.removeSubstring.TabIndex = 5;
            this.removeSubstring.Text = "Удалить";
            this.removeSubstring.UseVisualStyleBackColor = true;
            this.removeSubstring.Click += new System.EventHandler(this.removeSubstring_Click);
            // 
            // getNumberOfVowels
            // 
            this.getNumberOfVowels.Location = new System.Drawing.Point(48, 337);
            this.getNumberOfVowels.Name = "getNumberOfVowels";
            this.getNumberOfVowels.Size = new System.Drawing.Size(107, 42);
            this.getNumberOfVowels.TabIndex = 6;
            this.getNumberOfVowels.Text = "Количество гласных";
            this.getNumberOfVowels.UseVisualStyleBackColor = true;
            this.getNumberOfVowels.Click += new System.EventHandler(this.getNumberOfVowels_Click);
            // 
            // getNumberOfConsonants
            // 
            this.getNumberOfConsonants.Location = new System.Drawing.Point(161, 337);
            this.getNumberOfConsonants.Name = "getNumberOfConsonants";
            this.getNumberOfConsonants.Size = new System.Drawing.Size(110, 42);
            this.getNumberOfConsonants.TabIndex = 7;
            this.getNumberOfConsonants.Text = "Количество согласных";
            this.getNumberOfConsonants.UseVisualStyleBackColor = true;
            this.getNumberOfConsonants.Click += new System.EventHandler(this.getNumberOfConsonants_Click);
            // 
            // getSymbolByIndex
            // 
            this.getSymbolByIndex.Location = new System.Drawing.Point(277, 278);
            this.getSymbolByIndex.Name = "getSymbolByIndex";
            this.getSymbolByIndex.Size = new System.Drawing.Size(111, 45);
            this.getSymbolByIndex.TabIndex = 8;
            this.getSymbolByIndex.Text = "Получить";
            this.getSymbolByIndex.UseVisualStyleBackColor = true;
            this.getSymbolByIndex.Click += new System.EventHandler(this.getSymbolByIndex_Click);
            // 
            // getStringLength
            // 
            this.getStringLength.Location = new System.Drawing.Point(394, 278);
            this.getStringLength.Name = "getStringLength";
            this.getStringLength.Size = new System.Drawing.Size(102, 45);
            this.getStringLength.TabIndex = 9;
            this.getStringLength.Text = "Длина строки";
            this.getStringLength.UseVisualStyleBackColor = true;
            this.getStringLength.Click += new System.EventHandler(this.getStringLength_Click);
            // 
            // getNumberOfSentences
            // 
            this.getNumberOfSentences.Location = new System.Drawing.Point(277, 337);
            this.getNumberOfSentences.Name = "getNumberOfSentences";
            this.getNumberOfSentences.Size = new System.Drawing.Size(111, 42);
            this.getNumberOfSentences.TabIndex = 10;
            this.getNumberOfSentences.Text = "Количество предложений";
            this.getNumberOfSentences.UseVisualStyleBackColor = true;
            this.getNumberOfSentences.Click += new System.EventHandler(this.getNumberOfSentences_Click);
            // 
            // getNumberOfWords
            // 
            this.getNumberOfWords.Location = new System.Drawing.Point(394, 337);
            this.getNumberOfWords.Name = "getNumberOfWords";
            this.getNumberOfWords.Size = new System.Drawing.Size(102, 42);
            this.getNumberOfWords.TabIndex = 11;
            this.getNumberOfWords.Text = "Количество слов";
            this.getNumberOfWords.UseVisualStyleBackColor = true;
            this.getNumberOfWords.Click += new System.EventHandler(this.getNumberOfWords_Click);
            // 
            // receivedText
            // 
            this.receivedText.AutoSize = true;
            this.receivedText.Location = new System.Drawing.Point(77, 108);
            this.receivedText.Name = "receivedText";
            this.receivedText.Size = new System.Drawing.Size(0, 16);
            this.receivedText.TabIndex = 12;
            // 
            // textBoxForReplacing
            // 
            this.textBoxForReplacing.Location = new System.Drawing.Point(202, 211);
            this.textBoxForReplacing.Name = "textBoxForReplacing";
            this.textBoxForReplacing.Size = new System.Drawing.Size(102, 22);
            this.textBoxForReplacing.TabIndex = 13;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(80, 24);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(102, 16);
            this.label1.TabIndex = 14;
            this.label1.Text = "Введите текст";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(54, 181);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(128, 16);
            this.label2.TabIndex = 15;
            this.label2.Text = "Подстрока/индекс";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(202, 180);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(57, 16);
            this.label4.TabIndex = 17;
            this.label4.Text = "Замена";
            // 
            // Calculator
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.textBoxForReplacing);
            this.Controls.Add(this.receivedText);
            this.Controls.Add(this.getNumberOfWords);
            this.Controls.Add(this.getNumberOfSentences);
            this.Controls.Add(this.getStringLength);
            this.Controls.Add(this.getSymbolByIndex);
            this.Controls.Add(this.getNumberOfConsonants);
            this.Controls.Add(this.getNumberOfVowels);
            this.Controls.Add(this.removeSubstring);
            this.Controls.Add(this.sendText);
            this.Controls.Add(this.textToSend);
            this.Controls.Add(this.textBoxForOperations);
            this.Controls.Add(this.resultOfOperations);
            this.Controls.Add(this.replaceSubstring);
            this.Name = "Calculator";
            this.Text = "Текстовый калькулятор";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button replaceSubstring;
        private System.Windows.Forms.Label resultOfOperations;
        private System.Windows.Forms.TextBox textBoxForOperations;
        private System.Windows.Forms.TextBox textToSend;
        private System.Windows.Forms.Button sendText;
        private System.Windows.Forms.Button removeSubstring;
        private System.Windows.Forms.Button getNumberOfVowels;
        private System.Windows.Forms.Button getNumberOfConsonants;
        private System.Windows.Forms.Button getSymbolByIndex;
        private System.Windows.Forms.Button getStringLength;
        private System.Windows.Forms.Button getNumberOfSentences;
        private System.Windows.Forms.Button getNumberOfWords;
        private System.Windows.Forms.Label receivedText;
        private System.Windows.Forms.TextBox textBoxForReplacing;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label4;
    }
}

