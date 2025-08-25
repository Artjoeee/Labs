namespace Lab_02
{
    partial class SortForm
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
            this.sortBox = new System.Windows.Forms.ListBox();
            this.sortButton = new System.Windows.Forms.Button();
            this.saveButton = new System.Windows.Forms.Button();
            this.sortPrice = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // sortBox
            // 
            this.sortBox.FormattingEnabled = true;
            this.sortBox.ItemHeight = 16;
            this.sortBox.Location = new System.Drawing.Point(100, 114);
            this.sortBox.Name = "sortBox";
            this.sortBox.Size = new System.Drawing.Size(463, 164);
            this.sortBox.TabIndex = 0;
            // 
            // sortButton
            // 
            this.sortButton.Location = new System.Drawing.Point(115, 34);
            this.sortButton.Name = "sortButton";
            this.sortButton.Size = new System.Drawing.Size(167, 44);
            this.sortButton.TabIndex = 3;
            this.sortButton.Text = "Сортировать по возрасту";
            this.sortButton.UseVisualStyleBackColor = true;
            this.sortButton.Click += new System.EventHandler(this.sortButton_Click);
            // 
            // saveButton
            // 
            this.saveButton.Location = new System.Drawing.Point(264, 298);
            this.saveButton.Name = "saveButton";
            this.saveButton.Size = new System.Drawing.Size(144, 33);
            this.saveButton.TabIndex = 5;
            this.saveButton.Text = "Сохранить";
            this.saveButton.UseVisualStyleBackColor = true;
            this.saveButton.Click += new System.EventHandler(this.saveButton_Click);
            // 
            // sortPrice
            // 
            this.sortPrice.Location = new System.Drawing.Point(322, 34);
            this.sortPrice.Name = "sortPrice";
            this.sortPrice.Size = new System.Drawing.Size(150, 44);
            this.sortPrice.TabIndex = 6;
            this.sortPrice.Text = "Сортировать по цене";
            this.sortPrice.UseVisualStyleBackColor = true;
            this.sortPrice.Click += new System.EventHandler(this.sortPrice_Click);
            // 
            // SortForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(677, 360);
            this.Controls.Add(this.sortPrice);
            this.Controls.Add(this.saveButton);
            this.Controls.Add(this.sortButton);
            this.Controls.Add(this.sortBox);
            this.Name = "SortForm";
            this.Text = "Сортировка";
            this.Load += new System.EventHandler(this.SortForm_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.ListBox sortBox;
        private System.Windows.Forms.Button sortButton;
        private System.Windows.Forms.Button saveButton;
        private System.Windows.Forms.Button sortPrice;
    }
}