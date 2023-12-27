namespace LR4_1
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.numeric1 = new System.Windows.Forms.NumericUpDown();
            this.numeric2 = new System.Windows.Forms.NumericUpDown();
            this.numeric4 = new System.Windows.Forms.NumericUpDown();
            this.numeric3 = new System.Windows.Forms.NumericUpDown();
            this.numeric8 = new System.Windows.Forms.NumericUpDown();
            this.numeric7 = new System.Windows.Forms.NumericUpDown();
            this.numeric6 = new System.Windows.Forms.NumericUpDown();
            this.numeric5 = new System.Windows.Forms.NumericUpDown();
            this.button1 = new System.Windows.Forms.Button();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.button2 = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.numeric1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numeric2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numeric4)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numeric3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numeric8)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numeric7)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numeric6)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numeric5)).BeginInit();
            this.SuspendLayout();
            // 
            // numeric1
            // 
            this.numeric1.Location = new System.Drawing.Point(26, 25);
            this.numeric1.Maximum = new decimal(new int[] {
            1000,
            0,
            0,
            0});
            this.numeric1.Name = "numeric1";
            this.numeric1.Size = new System.Drawing.Size(95, 39);
            this.numeric1.TabIndex = 0;
            // 
            // numeric2
            // 
            this.numeric2.Location = new System.Drawing.Point(155, 25);
            this.numeric2.Maximum = new decimal(new int[] {
            1000,
            0,
            0,
            0});
            this.numeric2.Name = "numeric2";
            this.numeric2.Size = new System.Drawing.Size(95, 39);
            this.numeric2.TabIndex = 1;
            // 
            // numeric4
            // 
            this.numeric4.Location = new System.Drawing.Point(412, 25);
            this.numeric4.Maximum = new decimal(new int[] {
            1000,
            0,
            0,
            0});
            this.numeric4.Name = "numeric4";
            this.numeric4.Size = new System.Drawing.Size(95, 39);
            this.numeric4.TabIndex = 3;
            this.numeric4.ValueChanged += new System.EventHandler(this.numericUpDown3_ValueChanged);
            // 
            // numeric3
            // 
            this.numeric3.Location = new System.Drawing.Point(283, 25);
            this.numeric3.Maximum = new decimal(new int[] {
            1000,
            0,
            0,
            0});
            this.numeric3.Name = "numeric3";
            this.numeric3.Size = new System.Drawing.Size(95, 39);
            this.numeric3.TabIndex = 2;
            // 
            // numeric8
            // 
            this.numeric8.Location = new System.Drawing.Point(929, 25);
            this.numeric8.Maximum = new decimal(new int[] {
            1000,
            0,
            0,
            0});
            this.numeric8.Name = "numeric8";
            this.numeric8.Size = new System.Drawing.Size(95, 39);
            this.numeric8.TabIndex = 7;
            // 
            // numeric7
            // 
            this.numeric7.Location = new System.Drawing.Point(800, 25);
            this.numeric7.Maximum = new decimal(new int[] {
            1000,
            0,
            0,
            0});
            this.numeric7.Name = "numeric7";
            this.numeric7.Size = new System.Drawing.Size(95, 39);
            this.numeric7.TabIndex = 6;
            this.numeric7.ValueChanged += new System.EventHandler(this.numericUpDown6_ValueChanged);
            // 
            // numeric6
            // 
            this.numeric6.Location = new System.Drawing.Point(672, 25);
            this.numeric6.Maximum = new decimal(new int[] {
            1000,
            0,
            0,
            0});
            this.numeric6.Name = "numeric6";
            this.numeric6.Size = new System.Drawing.Size(95, 39);
            this.numeric6.TabIndex = 5;
            // 
            // numeric5
            // 
            this.numeric5.Location = new System.Drawing.Point(543, 25);
            this.numeric5.Maximum = new decimal(new int[] {
            1000,
            0,
            0,
            0});
            this.numeric5.Name = "numeric5";
            this.numeric5.Size = new System.Drawing.Size(95, 39);
            this.numeric5.TabIndex = 4;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(26, 84);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(150, 38);
            this.button1.TabIndex = 8;
            this.button1.Text = "Process1";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(23, 184);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(1001, 39);
            this.textBox1.TabIndex = 9;
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(27, 244);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(150, 38);
            this.button2.TabIndex = 10;
            this.button2.Text = "Process2";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(13F, 32F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1061, 316);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.numeric8);
            this.Controls.Add(this.numeric7);
            this.Controls.Add(this.numeric6);
            this.Controls.Add(this.numeric5);
            this.Controls.Add(this.numeric4);
            this.Controls.Add(this.numeric3);
            this.Controls.Add(this.numeric2);
            this.Controls.Add(this.numeric1);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.numeric1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numeric2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numeric4)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numeric3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numeric8)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numeric7)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numeric6)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numeric5)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private NumericUpDown numeric1;
        private NumericUpDown numeric2;
        private NumericUpDown numeric4;
        private NumericUpDown numeric3;
        private NumericUpDown numeric8;
        private NumericUpDown numeric7;
        private NumericUpDown numeric6;
        private NumericUpDown numeric5;
        private Button button1;
        private TextBox textBox1;
        private Button button2;
    }
}