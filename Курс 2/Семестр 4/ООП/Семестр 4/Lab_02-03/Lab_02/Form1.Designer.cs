using System.Runtime.CompilerServices;
using System.ComponentModel.DataAnnotations;

namespace Lab_02
{
    partial class EducationDepartmentForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(EducationDepartmentForm));
            this.course = new System.Windows.Forms.ListBox();
            this.label1 = new System.Windows.Forms.Label();
            this.age = new System.Windows.Forms.ComboBox();
            this.label2 = new System.Windows.Forms.Label();
            this.beginner = new System.Windows.Forms.RadioButton();
            this.advanced = new System.Windows.Forms.RadioButton();
            this.professional = new System.Windows.Forms.RadioButton();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.lectures = new System.Windows.Forms.NumericUpDown();
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.labs = new System.Windows.Forms.NumericUpDown();
            this.exam = new System.Windows.Forms.RadioButton();
            this.test = new System.Windows.Forms.RadioButton();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.listOfReferences = new System.Windows.Forms.CheckedListBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.save = new System.Windows.Forms.Button();
            this.teacher = new System.Windows.Forms.ListBox();
            this.read = new System.Windows.Forms.Button();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.teacherButton = new System.Windows.Forms.ToolStripMenuItem();
            this.listOfReferencesButton = new System.Windows.Forms.ToolStripMenuItem();
            this.searchButton = new System.Windows.Forms.ToolStripMenuItem();
            this.sortButton = new System.Windows.Forms.ToolStripMenuItem();
            this.saveButton = new System.Windows.Forms.ToolStripMenuItem();
            this.infoButton = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStrip1 = new System.Windows.Forms.ToolStrip();
            this.toolStripDropDownButton1 = new System.Windows.Forms.ToolStripDropDownButton();
            this.searh = new System.Windows.Forms.ToolStripMenuItem();
            this.sort = new System.Windows.Forms.ToolStripMenuItem();
            this.statusStrip1 = new System.Windows.Forms.StatusStrip();
            this.objectCount = new System.Windows.Forms.ToolStripStatusLabel();
            this.last = new System.Windows.Forms.ToolStripStatusLabel();
            this.date = new System.Windows.Forms.ToolStripStatusLabel();
            this.clear = new System.Windows.Forms.ToolStripMenuItem();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.lectures)).BeginInit();
            this.tabControl1.SuspendLayout();
            this.tabPage1.SuspendLayout();
            this.tabPage2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.labs)).BeginInit();
            this.groupBox2.SuspendLayout();
            this.menuStrip1.SuspendLayout();
            this.toolStrip1.SuspendLayout();
            this.statusStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // course
            // 
            this.course.FormattingEnabled = true;
            this.course.ItemHeight = 16;
            this.course.Items.AddRange(new object[] {
            "C++",
            "C#",
            "JavaScript",
            "Python"});
            this.course.Location = new System.Drawing.Point(70, 94);
            this.course.Name = "course";
            this.course.Size = new System.Drawing.Size(117, 36);
            this.course.TabIndex = 0;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(67, 73);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(114, 16);
            this.label1.TabIndex = 1;
            this.label1.Text = "Название курса";
            // 
            // age
            // 
            this.age.FormattingEnabled = true;
            this.age.Items.AddRange(new object[] {
            "18 - 25",
            "26 - 35",
            "36 - 50",
            "51 и более"});
            this.age.Location = new System.Drawing.Point(70, 170);
            this.age.Name = "age";
            this.age.Size = new System.Drawing.Size(121, 24);
            this.age.TabIndex = 2;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(67, 149);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(62, 16);
            this.label2.TabIndex = 3;
            this.label2.Text = "Возраст";
            // 
            // beginner
            // 
            this.beginner.AutoSize = true;
            this.beginner.Location = new System.Drawing.Point(26, 30);
            this.beginner.Name = "beginner";
            this.beginner.Size = new System.Drawing.Size(85, 20);
            this.beginner.TabIndex = 4;
            this.beginner.TabStop = true;
            this.beginner.Text = "Новичок";
            this.beginner.UseVisualStyleBackColor = true;
            // 
            // advanced
            // 
            this.advanced.AutoSize = true;
            this.advanced.Location = new System.Drawing.Point(26, 57);
            this.advanced.Name = "advanced";
            this.advanced.Size = new System.Drawing.Size(118, 20);
            this.advanced.TabIndex = 5;
            this.advanced.TabStop = true;
            this.advanced.Text = "Продвинутый";
            this.advanced.UseVisualStyleBackColor = true;
            // 
            // professional
            // 
            this.professional.AutoSize = true;
            this.professional.Location = new System.Drawing.Point(26, 83);
            this.professional.Name = "professional";
            this.professional.Size = new System.Drawing.Size(127, 20);
            this.professional.TabIndex = 6;
            this.professional.TabStop = true;
            this.professional.Text = "Профессионал";
            this.professional.UseVisualStyleBackColor = true;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.professional);
            this.groupBox1.Controls.Add(this.advanced);
            this.groupBox1.Controls.Add(this.beginner);
            this.groupBox1.Location = new System.Drawing.Point(240, 73);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(179, 121);
            this.groupBox1.TabIndex = 7;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Сложность курса";
            // 
            // lectures
            // 
            this.lectures.Location = new System.Drawing.Point(19, 17);
            this.lectures.Maximum = new decimal(new int[] {
            20,
            0,
            0,
            0});
            this.lectures.Name = "lectures";
            this.lectures.Size = new System.Drawing.Size(120, 22);
            this.lectures.TabIndex = 9;
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.tabPage1);
            this.tabControl1.Controls.Add(this.tabPage2);
            this.tabControl1.Location = new System.Drawing.Point(70, 274);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(349, 86);
            this.tabControl1.TabIndex = 13;
            // 
            // tabPage1
            // 
            this.tabPage1.Controls.Add(this.lectures);
            this.tabPage1.Location = new System.Drawing.Point(4, 25);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(341, 57);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "Количество лекций";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // tabPage2
            // 
            this.tabPage2.Controls.Add(this.labs);
            this.tabPage2.Location = new System.Drawing.Point(4, 25);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(341, 57);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "Количество лабораторных";
            this.tabPage2.UseVisualStyleBackColor = true;
            // 
            // labs
            // 
            this.labs.Location = new System.Drawing.Point(19, 17);
            this.labs.Maximum = new decimal(new int[] {
            20,
            0,
            0,
            0});
            this.labs.Name = "labs";
            this.labs.Size = new System.Drawing.Size(120, 22);
            this.labs.TabIndex = 0;
            // 
            // exam
            // 
            this.exam.AutoSize = true;
            this.exam.Location = new System.Drawing.Point(24, 30);
            this.exam.Name = "exam";
            this.exam.Size = new System.Drawing.Size(86, 20);
            this.exam.TabIndex = 14;
            this.exam.Text = "Экзамен";
            this.exam.UseVisualStyleBackColor = true;
            // 
            // test
            // 
            this.test.AutoSize = true;
            this.test.Location = new System.Drawing.Point(24, 56);
            this.test.Name = "test";
            this.test.Size = new System.Drawing.Size(68, 20);
            this.test.TabIndex = 15;
            this.test.Text = "Зачет";
            this.test.UseVisualStyleBackColor = true;
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.test);
            this.groupBox2.Controls.Add(this.exam);
            this.groupBox2.Location = new System.Drawing.Point(454, 73);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(143, 93);
            this.groupBox2.TabIndex = 16;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Вид контроля";
            // 
            // listOfReferences
            // 
            this.listOfReferences.CheckOnClick = true;
            this.listOfReferences.FormattingEnabled = true;
            this.listOfReferences.Location = new System.Drawing.Point(454, 220);
            this.listOfReferences.Name = "listOfReferences";
            this.listOfReferences.Size = new System.Drawing.Size(369, 89);
            this.listOfReferences.TabIndex = 19;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(451, 201);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(136, 16);
            this.label3.TabIndex = 20;
            this.label3.Text = "Список литературы";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(630, 73);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(111, 16);
            this.label4.TabIndex = 22;
            this.label4.Text = "Преподаватель";
            // 
            // save
            // 
            this.save.Location = new System.Drawing.Point(266, 385);
            this.save.Name = "save";
            this.save.Size = new System.Drawing.Size(153, 41);
            this.save.TabIndex = 23;
            this.save.Text = "Сохранить данные";
            this.save.UseVisualStyleBackColor = true;
            this.save.Click += new System.EventHandler(this.save_Click);
            // 
            // teacher
            // 
            this.teacher.FormattingEnabled = true;
            this.teacher.ItemHeight = 16;
            this.teacher.Location = new System.Drawing.Point(633, 94);
            this.teacher.Name = "teacher";
            this.teacher.Size = new System.Drawing.Size(212, 52);
            this.teacher.TabIndex = 24;
            // 
            // read
            // 
            this.read.Location = new System.Drawing.Point(451, 385);
            this.read.Name = "read";
            this.read.Size = new System.Drawing.Size(146, 41);
            this.read.TabIndex = 25;
            this.read.Text = "Вывод данных";
            this.read.UseVisualStyleBackColor = true;
            this.read.Click += new System.EventHandler(this.read_Click);
            // 
            // menuStrip1
            // 
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.teacherButton,
            this.listOfReferencesButton,
            this.searchButton,
            this.sortButton,
            this.saveButton,
            this.infoButton});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(897, 28);
            this.menuStrip1.TabIndex = 30;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // teacherButton
            // 
            this.teacherButton.Name = "teacherButton";
            this.teacherButton.Size = new System.Drawing.Size(131, 24);
            this.teacherButton.Text = "Преподаватель";
            this.teacherButton.Click += new System.EventHandler(this.teacherButton_Click);
            // 
            // listOfReferencesButton
            // 
            this.listOfReferencesButton.Name = "listOfReferencesButton";
            this.listOfReferencesButton.Size = new System.Drawing.Size(158, 24);
            this.listOfReferencesButton.Text = "Список литературы";
            this.listOfReferencesButton.Click += new System.EventHandler(this.listOfReferencesButton_Click);
            // 
            // searchButton
            // 
            this.searchButton.Name = "searchButton";
            this.searchButton.Size = new System.Drawing.Size(66, 24);
            this.searchButton.Text = "Поиск";
            this.searchButton.Click += new System.EventHandler(this.searchButton_Click);
            // 
            // sortButton
            // 
            this.sortButton.Name = "sortButton";
            this.sortButton.Size = new System.Drawing.Size(106, 24);
            this.sortButton.Text = "Сортировка";
            this.sortButton.Click += new System.EventHandler(this.sortButton_Click);
            // 
            // saveButton
            // 
            this.saveButton.Name = "saveButton";
            this.saveButton.Size = new System.Drawing.Size(97, 24);
            this.saveButton.Text = "Сохранить";
            this.saveButton.Click += new System.EventHandler(this.saveButton_Click);
            // 
            // infoButton
            // 
            this.infoButton.Name = "infoButton";
            this.infoButton.Size = new System.Drawing.Size(118, 24);
            this.infoButton.Text = "О программе";
            this.infoButton.Click += new System.EventHandler(this.infoButton_Click);
            // 
            // toolStrip1
            // 
            this.toolStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.toolStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripDropDownButton1});
            this.toolStrip1.Location = new System.Drawing.Point(0, 28);
            this.toolStrip1.Name = "toolStrip1";
            this.toolStrip1.Size = new System.Drawing.Size(897, 25);
            this.toolStrip1.TabIndex = 31;
            this.toolStrip1.Text = "toolStrip1";
            // 
            // toolStripDropDownButton1
            // 
            this.toolStripDropDownButton1.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.None;
            this.toolStripDropDownButton1.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.searh,
            this.sort,
            this.clear});
            this.toolStripDropDownButton1.Image = ((System.Drawing.Image)(resources.GetObject("toolStripDropDownButton1.Image")));
            this.toolStripDropDownButton1.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripDropDownButton1.Name = "toolStripDropDownButton1";
            this.toolStripDropDownButton1.Size = new System.Drawing.Size(14, 22);
            this.toolStripDropDownButton1.Text = "toolStripDropDownButton1";
            // 
            // searh
            // 
            this.searh.Name = "searh";
            this.searh.Size = new System.Drawing.Size(224, 26);
            this.searh.Text = "Поиск";
            this.searh.Click += new System.EventHandler(this.searh_Click);
            // 
            // sort
            // 
            this.sort.Name = "sort";
            this.sort.Size = new System.Drawing.Size(224, 26);
            this.sort.Text = "Сортировка";
            this.sort.Click += new System.EventHandler(this.sort_Click);
            // 
            // statusStrip1
            // 
            this.statusStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.statusStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.objectCount,
            this.last,
            this.date});
            this.statusStrip1.Location = new System.Drawing.Point(0, 461);
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.Size = new System.Drawing.Size(897, 26);
            this.statusStrip1.TabIndex = 32;
            this.statusStrip1.Text = "statusStrip1";
            // 
            // objectCount
            // 
            this.objectCount.Name = "objectCount";
            this.objectCount.Size = new System.Drawing.Size(151, 20);
            this.objectCount.Text = "toolStripStatusLabel1";
            // 
            // last
            // 
            this.last.Name = "last";
            this.last.Size = new System.Drawing.Size(151, 20);
            this.last.Text = "toolStripStatusLabel2";
            // 
            // date
            // 
            this.date.Name = "date";
            this.date.Size = new System.Drawing.Size(151, 20);
            this.date.Text = "toolStripStatusLabel3";
            // 
            // clear
            // 
            this.clear.Name = "clear";
            this.clear.Size = new System.Drawing.Size(224, 26);
            this.clear.Text = "Очистка";
            this.clear.Click += new System.EventHandler(this.clear_Click);
            // 
            // EducationDepartmentForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(897, 487);
            this.Controls.Add(this.statusStrip1);
            this.Controls.Add(this.toolStrip1);
            this.Controls.Add(this.read);
            this.Controls.Add(this.teacher);
            this.Controls.Add(this.save);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.listOfReferences);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.tabControl1);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.age);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.course);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "EducationDepartmentForm";
            this.Text = "Учебный отдел";
            this.Load += new System.EventHandler(this.EducationDepartmentForm_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.lectures)).EndInit();
            this.tabControl1.ResumeLayout(false);
            this.tabPage1.ResumeLayout(false);
            this.tabPage2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.labs)).EndInit();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.toolStrip1.ResumeLayout(false);
            this.toolStrip1.PerformLayout();
            this.statusStrip1.ResumeLayout(false);
            this.statusStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListBox course;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ComboBox age;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.RadioButton beginner;
        private System.Windows.Forms.RadioButton advanced;
        private System.Windows.Forms.RadioButton professional;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.NumericUpDown lectures;
        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.RadioButton exam;
        private System.Windows.Forms.RadioButton test;
        private System.Windows.Forms.GroupBox groupBox2;
        public System.Windows.Forms.CheckedListBox listOfReferences;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Button save;
        public System.Windows.Forms.ListBox teacher;
        private System.Windows.Forms.NumericUpDown labs;
        private System.Windows.Forms.Button read;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem teacherButton;
        private System.Windows.Forms.ToolStripMenuItem listOfReferencesButton;
        private System.Windows.Forms.ToolStripMenuItem searchButton;
        private System.Windows.Forms.ToolStripMenuItem sortButton;
        private System.Windows.Forms.ToolStripMenuItem saveButton;
        private System.Windows.Forms.ToolStripMenuItem infoButton;
        private System.Windows.Forms.ToolStrip toolStrip1;
        private System.Windows.Forms.ToolStripDropDownButton toolStripDropDownButton1;
        private System.Windows.Forms.ToolStripMenuItem searh;
        private System.Windows.Forms.ToolStripMenuItem sort;
        private System.Windows.Forms.StatusStrip statusStrip1;
        private System.Windows.Forms.ToolStripStatusLabel objectCount;
        public System.Windows.Forms.ToolStripStatusLabel last;
        private System.Windows.Forms.ToolStripStatusLabel date;
        private System.Windows.Forms.ToolStripMenuItem clear;
    }
}

