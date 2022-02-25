namespace Gomoku
{
    partial class Gform
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
            this.panel1 = new System.Windows.Forms.Panel();
            this.Start = new System.Windows.Forms.Button();
            this.Fifteen = new System.Windows.Forms.RadioButton();
            this.Ten = new System.Windows.Forms.RadioButton();
            this.Five = new System.Windows.Forms.RadioButton();
            this.GRID = new System.Windows.Forms.FlowLayoutPanel();
            this.panel2 = new System.Windows.Forms.Panel();
            this.CMP = new System.Windows.Forms.RadioButton();
            this.Human = new System.Windows.Forms.RadioButton();
            this.panel1.SuspendLayout();
            this.panel2.SuspendLayout();
            this.SuspendLayout();
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.panel2);
            this.panel1.Controls.Add(this.Start);
            this.panel1.Controls.Add(this.Fifteen);
            this.panel1.Controls.Add(this.Ten);
            this.panel1.Controls.Add(this.Five);
            this.panel1.Location = new System.Drawing.Point(0, 0);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(924, 194);
            this.panel1.TabIndex = 0;
            // 
            // Start
            // 
            this.Start.Location = new System.Drawing.Point(166, 118);
            this.Start.Name = "Start";
            this.Start.Size = new System.Drawing.Size(198, 61);
            this.Start.TabIndex = 3;
            this.Start.Text = "Start";
            this.Start.UseVisualStyleBackColor = true;
            this.Start.Click += new System.EventHandler(this.Start_Click);
            // 
            // Fifteen
            // 
            this.Fifteen.AutoSize = true;
            this.Fifteen.Location = new System.Drawing.Point(690, 49);
            this.Fifteen.Name = "Fifteen";
            this.Fifteen.Size = new System.Drawing.Size(71, 21);
            this.Fifteen.TabIndex = 2;
            this.Fifteen.TabStop = true;
            this.Fifteen.Text = "15 x15";
            this.Fifteen.UseVisualStyleBackColor = true;
            // 
            // Ten
            // 
            this.Ten.AutoSize = true;
            this.Ten.Location = new System.Drawing.Point(387, 48);
            this.Ten.Name = "Ten";
            this.Ten.Size = new System.Drawing.Size(67, 21);
            this.Ten.TabIndex = 1;
            this.Ten.TabStop = true;
            this.Ten.Text = "10x10";
            this.Ten.UseVisualStyleBackColor = true;
            // 
            // Five
            // 
            this.Five.AutoSize = true;
            this.Five.Location = new System.Drawing.Point(68, 48);
            this.Five.Name = "Five";
            this.Five.Size = new System.Drawing.Size(51, 21);
            this.Five.TabIndex = 0;
            this.Five.TabStop = true;
            this.Five.Text = "5x5";
            this.Five.UseVisualStyleBackColor = true;
            // 
            // GRID
            // 
            this.GRID.Location = new System.Drawing.Point(26, 200);
            this.GRID.Name = "GRID";
            this.GRID.Size = new System.Drawing.Size(936, 461);
            this.GRID.TabIndex = 1;
            // 
            // panel2
            // 
            this.panel2.Controls.Add(this.Human);
            this.panel2.Controls.Add(this.CMP);
            this.panel2.Location = new System.Drawing.Point(629, 88);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(238, 103);
            this.panel2.TabIndex = 4;
            // 
            // CMP
            // 
            this.CMP.AutoSize = true;
            this.CMP.Location = new System.Drawing.Point(45, 61);
            this.CMP.Name = "CMP";
            this.CMP.Size = new System.Drawing.Size(125, 21);
            this.CMP.TabIndex = 1;
            this.CMP.TabStop = true;
            this.CMP.Text = "CMP vs Human";
            this.CMP.UseVisualStyleBackColor = true;
            // 
            // Human
            // 
            this.Human.AutoSize = true;
            this.Human.Location = new System.Drawing.Point(76, 26);
            this.Human.Name = "Human";
            this.Human.Size = new System.Drawing.Size(74, 21);
            this.Human.TabIndex = 2;
            this.Human.TabStop = true;
            this.Human.Text = "Human";
            this.Human.UseVisualStyleBackColor = true;
            // 
            // Gform
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(984, 688);
            this.Controls.Add(this.GRID);
            this.Controls.Add(this.panel1);
            this.Name = "Gform";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Gform_Load);
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Button Start;
        private System.Windows.Forms.RadioButton Fifteen;
        private System.Windows.Forms.RadioButton Ten;
        private System.Windows.Forms.RadioButton Five;
        private System.Windows.Forms.FlowLayoutPanel GRID;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.RadioButton CMP;
        private System.Windows.Forms.RadioButton Human;
    }
}

