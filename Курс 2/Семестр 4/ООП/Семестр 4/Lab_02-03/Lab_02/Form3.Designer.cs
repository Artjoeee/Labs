namespace Lab_02
{
    partial class ListOfReferencesForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.book = new System.Windows.Forms.TextBox();
            this.author = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.add = new System.Windows.Forms.Button();
            this.year = new System.Windows.Forms.NumericUpDown();
            ((System.ComponentModel.ISupportInitialize)(this.year)).BeginInit();
            this.SuspendLayout();
            // 
            // book
            // 
            this.book.Location = new System.Drawing.Point(52, 76);
            this.book.Multiline = true;
            this.book.Name = "book";
            this.book.Size = new System.Drawing.Size(157, 35);
            this.book.TabIndex = 0;
            // 
            // author
            // 
            this.author.Location = new System.Drawing.Point(270, 76);
            this.author.Multiline = true;
            this.author.Name = "author";
            this.author.Size = new System.Drawing.Size(161, 35);
            this.author.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(49, 57);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(73, 16);
            this.label1.TabIndex = 3;
            this.label1.Text = "Название";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(267, 57);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(47, 16);
            this.label2.TabIndex = 4;
            this.label2.Text = "Автор";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(488, 57);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(30, 16);
            this.label3.TabIndex = 5;
            this.label3.Text = "Год";
            // 
            // add
            // 
            this.add.Location = new System.Drawing.Point(292, 152);
            this.add.Name = "add";
            this.add.Size = new System.Drawing.Size(123, 35);
            this.add.TabIndex = 6;
            this.add.Text = "Добавить";
            this.add.UseVisualStyleBackColor = true;
            this.add.Click += new System.EventHandler(this.add_Click);
            // 
            // year
            // 
            this.year.Location = new System.Drawing.Point(491, 77);
            this.year.Maximum = new decimal(new int[] {
            2025,
            0,
            0,
            0});
            this.year.Minimum = new decimal(new int[] {
            1970,
            0,
            0,
            0});
            this.year.Name = "year";
            this.year.Size = new System.Drawing.Size(120, 22);
            this.year.TabIndex = 7;
            this.year.Value = new decimal(new int[] {
            1970,
            0,
            0,
            0});
            // 
            // ListOfReferencesForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(706, 223);
            this.Controls.Add(this.year);
            this.Controls.Add(this.add);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.author);
            this.Controls.Add(this.book);
            this.Name = "ListOfReferencesForm";
            this.Text = "Список литературы";
            ((System.ComponentModel.ISupportInitialize)(this.year)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox book;
        private System.Windows.Forms.TextBox author;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button add;
        private System.Windows.Forms.NumericUpDown year;
    }
}