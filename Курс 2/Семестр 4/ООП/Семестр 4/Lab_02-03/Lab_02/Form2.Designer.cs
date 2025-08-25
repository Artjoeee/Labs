namespace Lab_02
{
    partial class TeacherForm
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
            this.pi = new System.Windows.Forms.RadioButton();
            this.isit = new System.Windows.Forms.RadioButton();
            this.cd = new System.Windows.Forms.RadioButton();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.fullName = new System.Windows.Forms.TextBox();
            this.add = new System.Windows.Forms.Button();
            this.classroom = new System.Windows.Forms.ComboBox();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // pi
            // 
            this.pi.AutoSize = true;
            this.pi.Location = new System.Drawing.Point(32, 32);
            this.pi.Name = "pi";
            this.pi.Size = new System.Drawing.Size(48, 20);
            this.pi.TabIndex = 0;
            this.pi.Text = "ПИ";
            this.pi.UseVisualStyleBackColor = true;
            // 
            // isit
            // 
            this.isit.AutoSize = true;
            this.isit.Location = new System.Drawing.Point(32, 58);
            this.isit.Name = "isit";
            this.isit.Size = new System.Drawing.Size(66, 20);
            this.isit.TabIndex = 1;
            this.isit.Text = "ИСИТ";
            this.isit.UseVisualStyleBackColor = true;
            // 
            // cd
            // 
            this.cd.AutoSize = true;
            this.cd.Location = new System.Drawing.Point(32, 84);
            this.cd.Name = "cd";
            this.cd.Size = new System.Drawing.Size(46, 20);
            this.cd.TabIndex = 2;
            this.cd.Text = "ЦД";
            this.cd.UseVisualStyleBackColor = true;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.cd);
            this.groupBox1.Controls.Add(this.isit);
            this.groupBox1.Controls.Add(this.pi);
            this.groupBox1.Location = new System.Drawing.Point(225, 57);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(159, 127);
            this.groupBox1.TabIndex = 3;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Кафедра";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(36, 77);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(38, 16);
            this.label1.TabIndex = 5;
            this.label1.Text = "ФИО";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(423, 75);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(78, 16);
            this.label2.TabIndex = 7;
            this.label2.Text = "Аудитория";
            // 
            // fullName
            // 
            this.fullName.Location = new System.Drawing.Point(39, 96);
            this.fullName.Multiline = true;
            this.fullName.Name = "fullName";
            this.fullName.Size = new System.Drawing.Size(150, 29);
            this.fullName.TabIndex = 8;
            // 
            // add
            // 
            this.add.Location = new System.Drawing.Point(244, 217);
            this.add.Name = "add";
            this.add.Size = new System.Drawing.Size(127, 33);
            this.add.TabIndex = 9;
            this.add.Text = "Добавить";
            this.add.UseVisualStyleBackColor = true;
            this.add.Click += new System.EventHandler(this.add_Click);
            // 
            // classroom
            // 
            this.classroom.FormattingEnabled = true;
            this.classroom.Items.AddRange(new object[] {
            "100",
            "101",
            "102",
            "103"});
            this.classroom.Location = new System.Drawing.Point(426, 96);
            this.classroom.Name = "classroom";
            this.classroom.Size = new System.Drawing.Size(121, 24);
            this.classroom.TabIndex = 11;
            // 
            // TeacherForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(613, 280);
            this.Controls.Add(this.classroom);
            this.Controls.Add(this.add);
            this.Controls.Add(this.fullName);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.groupBox1);
            this.Name = "TeacherForm";
            this.Text = "Преподаватель";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.RadioButton pi;
        private System.Windows.Forms.RadioButton isit;
        private System.Windows.Forms.RadioButton cd;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox fullName;
        private System.Windows.Forms.Button add;
        private System.Windows.Forms.ComboBox classroom;
    }
}