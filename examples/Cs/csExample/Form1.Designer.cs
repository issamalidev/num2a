namespace csExample
{
	partial class Form1
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
			this.btnGetnum2aW = new System.Windows.Forms.Button();
			this.btnNum2aW = new System.Windows.Forms.Button();
			this.label6 = new System.Windows.Forms.Label();
			this.cbItemNameGender = new System.Windows.Forms.ComboBox();
			this.txtPluralItemName = new System.Windows.Forms.TextBox();
			this.label5 = new System.Windows.Forms.Label();
			this.txtDualItemName = new System.Windows.Forms.TextBox();
			this.label4 = new System.Windows.Forms.Label();
			this.txtItemNameWithTanween = new System.Windows.Forms.TextBox();
			this.label3 = new System.Windows.Forms.Label();
			this.txtItemName = new System.Windows.Forms.TextBox();
			this.label2 = new System.Windows.Forms.Label();
			this.panel2 = new System.Windows.Forms.Panel();
			this.txtResult = new System.Windows.Forms.TextBox();
			this.label7 = new System.Windows.Forms.Label();
			this.panel3 = new System.Windows.Forms.Panel();
			this.txtNum = new System.Windows.Forms.TextBox();
			this.label1 = new System.Windows.Forms.Label();
			this.panel4 = new System.Windows.Forms.Panel();
			this.btnGetfnum2aW = new System.Windows.Forms.Button();
			this.udDecimalPlace = new System.Windows.Forms.NumericUpDown();
			this.label13 = new System.Windows.Forms.Label();
			this.btnFnum2aW = new System.Windows.Forms.Button();
			this.label8 = new System.Windows.Forms.Label();
			this.cbFractionalItemNameGender = new System.Windows.Forms.ComboBox();
			this.txtFractionalPluralItemName = new System.Windows.Forms.TextBox();
			this.label9 = new System.Windows.Forms.Label();
			this.txtFractionalDualItemName = new System.Windows.Forms.TextBox();
			this.label10 = new System.Windows.Forms.Label();
			this.txtFractionalItemNameWithTanween = new System.Windows.Forms.TextBox();
			this.label11 = new System.Windows.Forms.Label();
			this.txtFractionalItemName = new System.Windows.Forms.TextBox();
			this.label12 = new System.Windows.Forms.Label();
			this.panel1.SuspendLayout();
			this.panel2.SuspendLayout();
			this.panel3.SuspendLayout();
			this.panel4.SuspendLayout();
			((System.ComponentModel.ISupportInitialize)(this.udDecimalPlace)).BeginInit();
			this.SuspendLayout();
			// 
			// panel1
			// 
			this.panel1.Controls.Add(this.btnGetnum2aW);
			this.panel1.Controls.Add(this.btnNum2aW);
			this.panel1.Controls.Add(this.label6);
			this.panel1.Controls.Add(this.cbItemNameGender);
			this.panel1.Controls.Add(this.txtPluralItemName);
			this.panel1.Controls.Add(this.label5);
			this.panel1.Controls.Add(this.txtDualItemName);
			this.panel1.Controls.Add(this.label4);
			this.panel1.Controls.Add(this.txtItemNameWithTanween);
			this.panel1.Controls.Add(this.label3);
			this.panel1.Controls.Add(this.txtItemName);
			this.panel1.Controls.Add(this.label2);
			this.panel1.Location = new System.Drawing.Point(12, 71);
			this.panel1.Name = "panel1";
			this.panel1.Size = new System.Drawing.Size(323, 186);
			this.panel1.TabIndex = 4;
			// 
			// btnGetnum2aW
			// 
			this.btnGetnum2aW.Location = new System.Drawing.Point(117, 142);
			this.btnGetnum2aW.Name = "btnGetnum2aW";
			this.btnGetnum2aW.Size = new System.Drawing.Size(88, 23);
			this.btnGetnum2aW.TabIndex = 15;
			this.btnGetnum2aW.Text = "get_num2aW";
			this.btnGetnum2aW.UseVisualStyleBackColor = true;
			this.btnGetnum2aW.Click += new System.EventHandler(this.btnGetnum2aW_Click);
			// 
			// btnNum2aW
			// 
			this.btnNum2aW.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
						| System.Windows.Forms.AnchorStyles.Right)));
			this.btnNum2aW.Location = new System.Drawing.Point(19, 142);
			this.btnNum2aW.Name = "btnNum2aW";
			this.btnNum2aW.Size = new System.Drawing.Size(92, 23);
			this.btnNum2aW.TabIndex = 14;
			this.btnNum2aW.Text = "num2aW";
			this.btnNum2aW.UseVisualStyleBackColor = true;
			this.btnNum2aW.Click += new System.EventHandler(this.btnNum2aW_Click);
			// 
			// label6
			// 
			this.label6.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
			this.label6.AutoSize = true;
			this.label6.Location = new System.Drawing.Point(240, 118);
			this.label6.Name = "label6";
			this.label6.Size = new System.Drawing.Size(70, 13);
			this.label6.TabIndex = 13;
			this.label6.Text = "جنس المعدود";
			// 
			// cbItemNameGender
			// 
			this.cbItemNameGender.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
						| System.Windows.Forms.AnchorStyles.Right)));
			this.cbItemNameGender.FormattingEnabled = true;
			this.cbItemNameGender.Items.AddRange(new object[] {
            "مذكر",
            "مؤنث"});
			this.cbItemNameGender.Location = new System.Drawing.Point(18, 115);
			this.cbItemNameGender.Name = "cbItemNameGender";
			this.cbItemNameGender.Size = new System.Drawing.Size(187, 21);
			this.cbItemNameGender.TabIndex = 12;
			// 
			// txtPluralItemName
			// 
			this.txtPluralItemName.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
						| System.Windows.Forms.AnchorStyles.Right)));
			this.txtPluralItemName.Location = new System.Drawing.Point(19, 89);
			this.txtPluralItemName.Name = "txtPluralItemName";
			this.txtPluralItemName.Size = new System.Drawing.Size(186, 20);
			this.txtPluralItemName.TabIndex = 11;
			this.txtPluralItemName.Text = "ليرات";
			// 
			// label5
			// 
			this.label5.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
			this.label5.AutoSize = true;
			this.label5.Location = new System.Drawing.Point(245, 92);
			this.label5.Name = "label5";
			this.label5.Size = new System.Drawing.Size(65, 13);
			this.label5.TabIndex = 10;
			this.label5.Text = "جمع المعدود";
			// 
			// txtDualItemName
			// 
			this.txtDualItemName.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
						| System.Windows.Forms.AnchorStyles.Right)));
			this.txtDualItemName.Location = new System.Drawing.Point(19, 63);
			this.txtDualItemName.Name = "txtDualItemName";
			this.txtDualItemName.Size = new System.Drawing.Size(186, 20);
			this.txtDualItemName.TabIndex = 9;
			this.txtDualItemName.Text = "ليرتان";
			// 
			// label4
			// 
			this.label4.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
			this.label4.AutoSize = true;
			this.label4.Location = new System.Drawing.Point(240, 66);
			this.label4.Name = "label4";
			this.label4.Size = new System.Drawing.Size(70, 13);
			this.label4.TabIndex = 8;
			this.label4.Text = "مثنى المعدود";
			// 
			// txtItemNameWithTanween
			// 
			this.txtItemNameWithTanween.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
						| System.Windows.Forms.AnchorStyles.Right)));
			this.txtItemNameWithTanween.Location = new System.Drawing.Point(19, 37);
			this.txtItemNameWithTanween.Name = "txtItemNameWithTanween";
			this.txtItemNameWithTanween.Size = new System.Drawing.Size(186, 20);
			this.txtItemNameWithTanween.TabIndex = 7;
			this.txtItemNameWithTanween.Text = "ليرةً";
			// 
			// label3
			// 
			this.label3.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
			this.label3.AutoSize = true;
			this.label3.Location = new System.Drawing.Point(219, 40);
			this.label3.Name = "label3";
			this.label3.Size = new System.Drawing.Size(91, 13);
			this.label3.TabIndex = 6;
			this.label3.Text = "اسم المعدود منوناً";
			// 
			// txtItemName
			// 
			this.txtItemName.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
						| System.Windows.Forms.AnchorStyles.Right)));
			this.txtItemName.Location = new System.Drawing.Point(19, 11);
			this.txtItemName.Name = "txtItemName";
			this.txtItemName.Size = new System.Drawing.Size(186, 20);
			this.txtItemName.TabIndex = 5;
			this.txtItemName.Text = "ليرة";
			// 
			// label2
			// 
			this.label2.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
			this.label2.AutoSize = true;
			this.label2.Location = new System.Drawing.Point(243, 14);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(67, 13);
			this.label2.TabIndex = 4;
			this.label2.Text = "اسم المعدود";
			// 
			// panel2
			// 
			this.panel2.Controls.Add(this.txtResult);
			this.panel2.Controls.Add(this.label7);
			this.panel2.Location = new System.Drawing.Point(12, 309);
			this.panel2.Name = "panel2";
			this.panel2.Size = new System.Drawing.Size(699, 83);
			this.panel2.TabIndex = 5;
			// 
			// txtResult
			// 
			this.txtResult.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)
						| System.Windows.Forms.AnchorStyles.Right)));
			this.txtResult.Location = new System.Drawing.Point(18, 28);
			this.txtResult.Multiline = true;
			this.txtResult.Name = "txtResult";
			this.txtResult.Size = new System.Drawing.Size(665, 41);
			this.txtResult.TabIndex = 3;
			// 
			// label7
			// 
			this.label7.AutoSize = true;
			this.label7.Location = new System.Drawing.Point(647, 12);
			this.label7.Name = "label7";
			this.label7.Size = new System.Drawing.Size(38, 13);
			this.label7.TabIndex = 2;
			this.label7.Text = "النتيجة";
			// 
			// panel3
			// 
			this.panel3.Controls.Add(this.txtNum);
			this.panel3.Controls.Add(this.label1);
			this.panel3.Location = new System.Drawing.Point(12, 12);
			this.panel3.Name = "panel3";
			this.panel3.Size = new System.Drawing.Size(699, 40);
			this.panel3.TabIndex = 6;
			// 
			// txtNum
			// 
			this.txtNum.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
						| System.Windows.Forms.AnchorStyles.Right)));
			this.txtNum.Location = new System.Drawing.Point(23, 12);
			this.txtNum.Name = "txtNum";
			this.txtNum.Size = new System.Drawing.Size(610, 20);
			this.txtNum.TabIndex = 3;
			// 
			// label1
			// 
			this.label1.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
			this.label1.AutoSize = true;
			this.label1.Location = new System.Drawing.Point(647, 12);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(31, 13);
			this.label1.TabIndex = 2;
			this.label1.Text = "الرقم";
			// 
			// panel4
			// 
			this.panel4.Controls.Add(this.btnGetfnum2aW);
			this.panel4.Controls.Add(this.udDecimalPlace);
			this.panel4.Controls.Add(this.label13);
			this.panel4.Controls.Add(this.btnFnum2aW);
			this.panel4.Controls.Add(this.label8);
			this.panel4.Controls.Add(this.cbFractionalItemNameGender);
			this.panel4.Controls.Add(this.txtFractionalPluralItemName);
			this.panel4.Controls.Add(this.label9);
			this.panel4.Controls.Add(this.txtFractionalDualItemName);
			this.panel4.Controls.Add(this.label10);
			this.panel4.Controls.Add(this.txtFractionalItemNameWithTanween);
			this.panel4.Controls.Add(this.label11);
			this.panel4.Controls.Add(this.txtFractionalItemName);
			this.panel4.Controls.Add(this.label12);
			this.panel4.Location = new System.Drawing.Point(341, 71);
			this.panel4.Name = "panel4";
			this.panel4.Size = new System.Drawing.Size(370, 207);
			this.panel4.TabIndex = 7;
			// 
			// btnGetfnum2aW
			// 
			this.btnGetfnum2aW.Location = new System.Drawing.Point(132, 176);
			this.btnGetfnum2aW.Name = "btnGetfnum2aW";
			this.btnGetfnum2aW.Size = new System.Drawing.Size(90, 23);
			this.btnGetfnum2aW.TabIndex = 17;
			this.btnGetfnum2aW.Text = "get_fnum2aW";
			this.btnGetfnum2aW.UseVisualStyleBackColor = true;
			this.btnGetfnum2aW.Click += new System.EventHandler(this.btnGetfnum2aW_Click);
			// 
			// udDecimalPlace
			// 
			this.udDecimalPlace.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
						| System.Windows.Forms.AnchorStyles.Right)));
			this.udDecimalPlace.Location = new System.Drawing.Point(19, 145);
			this.udDecimalPlace.Name = "udDecimalPlace";
			this.udDecimalPlace.Size = new System.Drawing.Size(203, 20);
			this.udDecimalPlace.TabIndex = 16;
			this.udDecimalPlace.Value = new decimal(new int[] {
            2,
            0,
            0,
            0});
			// 
			// label13
			// 
			this.label13.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
			this.label13.AutoSize = true;
			this.label13.Location = new System.Drawing.Point(267, 147);
			this.label13.Name = "label13";
			this.label13.Size = new System.Drawing.Size(89, 13);
			this.label13.TabIndex = 15;
			this.label13.Text = "خانة كسر المعدود";
			// 
			// btnFnum2aW
			// 
			this.btnFnum2aW.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
						| System.Windows.Forms.AnchorStyles.Right)));
			this.btnFnum2aW.Location = new System.Drawing.Point(18, 176);
			this.btnFnum2aW.Name = "btnFnum2aW";
			this.btnFnum2aW.Size = new System.Drawing.Size(92, 23);
			this.btnFnum2aW.TabIndex = 14;
			this.btnFnum2aW.Text = "fnum2aW";
			this.btnFnum2aW.UseVisualStyleBackColor = true;
			this.btnFnum2aW.Click += new System.EventHandler(this.btnFnum2aW_Click);
			// 
			// label8
			// 
			this.label8.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
			this.label8.AutoSize = true;
			this.label8.Location = new System.Drawing.Point(267, 118);
			this.label8.Name = "label8";
			this.label8.Size = new System.Drawing.Size(95, 13);
			this.label8.TabIndex = 13;
			this.label8.Text = "جنس كسر المعدود";
			// 
			// cbFractionalItemNameGender
			// 
			this.cbFractionalItemNameGender.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
						| System.Windows.Forms.AnchorStyles.Right)));
			this.cbFractionalItemNameGender.FormattingEnabled = true;
			this.cbFractionalItemNameGender.Items.AddRange(new object[] {
            "مذكر",
            "مؤنث"});
			this.cbFractionalItemNameGender.Location = new System.Drawing.Point(18, 115);
			this.cbFractionalItemNameGender.Name = "cbFractionalItemNameGender";
			this.cbFractionalItemNameGender.Size = new System.Drawing.Size(205, 21);
			this.cbFractionalItemNameGender.TabIndex = 12;
			// 
			// txtFractionalPluralItemName
			// 
			this.txtFractionalPluralItemName.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
						| System.Windows.Forms.AnchorStyles.Right)));
			this.txtFractionalPluralItemName.Location = new System.Drawing.Point(19, 89);
			this.txtFractionalPluralItemName.Name = "txtFractionalPluralItemName";
			this.txtFractionalPluralItemName.Size = new System.Drawing.Size(204, 20);
			this.txtFractionalPluralItemName.TabIndex = 11;
			this.txtFractionalPluralItemName.Text = "قروش";
			// 
			// label9
			// 
			this.label9.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
			this.label9.AutoSize = true;
			this.label9.Location = new System.Drawing.Point(272, 92);
			this.label9.Name = "label9";
			this.label9.Size = new System.Drawing.Size(90, 13);
			this.label9.TabIndex = 10;
			this.label9.Text = "جمع كسر المعدود";
			// 
			// txtFractionalDualItemName
			// 
			this.txtFractionalDualItemName.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
						| System.Windows.Forms.AnchorStyles.Right)));
			this.txtFractionalDualItemName.Location = new System.Drawing.Point(19, 63);
			this.txtFractionalDualItemName.Name = "txtFractionalDualItemName";
			this.txtFractionalDualItemName.Size = new System.Drawing.Size(204, 20);
			this.txtFractionalDualItemName.TabIndex = 9;
			this.txtFractionalDualItemName.Text = "قرشان";
			// 
			// label10
			// 
			this.label10.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
			this.label10.AutoSize = true;
			this.label10.Location = new System.Drawing.Point(267, 66);
			this.label10.Name = "label10";
			this.label10.Size = new System.Drawing.Size(95, 13);
			this.label10.TabIndex = 8;
			this.label10.Text = "مثنى كسر المعدود";
			// 
			// txtFractionalItemNameWithTanween
			// 
			this.txtFractionalItemNameWithTanween.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
						| System.Windows.Forms.AnchorStyles.Right)));
			this.txtFractionalItemNameWithTanween.Location = new System.Drawing.Point(19, 37);
			this.txtFractionalItemNameWithTanween.Name = "txtFractionalItemNameWithTanween";
			this.txtFractionalItemNameWithTanween.Size = new System.Drawing.Size(204, 20);
			this.txtFractionalItemNameWithTanween.TabIndex = 7;
			this.txtFractionalItemNameWithTanween.Text = "قرشاً";
			// 
			// label11
			// 
			this.label11.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
			this.label11.AutoSize = true;
			this.label11.Location = new System.Drawing.Point(246, 40);
			this.label11.Name = "label11";
			this.label11.Size = new System.Drawing.Size(116, 13);
			this.label11.TabIndex = 6;
			this.label11.Text = "اسم كسر المعدود منوناً";
			// 
			// txtFractionalItemName
			// 
			this.txtFractionalItemName.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
						| System.Windows.Forms.AnchorStyles.Right)));
			this.txtFractionalItemName.Location = new System.Drawing.Point(19, 11);
			this.txtFractionalItemName.Name = "txtFractionalItemName";
			this.txtFractionalItemName.Size = new System.Drawing.Size(204, 20);
			this.txtFractionalItemName.TabIndex = 5;
			this.txtFractionalItemName.Text = "قرش";
			// 
			// label12
			// 
			this.label12.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
			this.label12.AutoSize = true;
			this.label12.Location = new System.Drawing.Point(270, 14);
			this.label12.Name = "label12";
			this.label12.Size = new System.Drawing.Size(92, 13);
			this.label12.TabIndex = 4;
			this.label12.Text = "اسم كسر المعدود";
			// 
			// Form1
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(723, 404);
			this.Controls.Add(this.panel4);
			this.Controls.Add(this.panel3);
			this.Controls.Add(this.panel2);
			this.Controls.Add(this.panel1);
			this.Name = "Form1";
			this.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
			this.RightToLeftLayout = true;
			this.Text = "num2a- CSExample";
			this.panel1.ResumeLayout(false);
			this.panel1.PerformLayout();
			this.panel2.ResumeLayout(false);
			this.panel2.PerformLayout();
			this.panel3.ResumeLayout(false);
			this.panel3.PerformLayout();
			this.panel4.ResumeLayout(false);
			this.panel4.PerformLayout();
			((System.ComponentModel.ISupportInitialize)(this.udDecimalPlace)).EndInit();
			this.ResumeLayout(false);

		}

		#endregion

		private System.Windows.Forms.Panel panel1;
		private System.Windows.Forms.ComboBox cbItemNameGender;
		private System.Windows.Forms.TextBox txtPluralItemName;
		private System.Windows.Forms.Label label5;
		private System.Windows.Forms.TextBox txtDualItemName;
		private System.Windows.Forms.Label label4;
		private System.Windows.Forms.TextBox txtItemNameWithTanween;
		private System.Windows.Forms.Label label3;
		private System.Windows.Forms.TextBox txtItemName;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.Button btnNum2aW;
		private System.Windows.Forms.Label label6;
		private System.Windows.Forms.Panel panel2;
		private System.Windows.Forms.TextBox txtResult;
		private System.Windows.Forms.Label label7;
		private System.Windows.Forms.Panel panel3;
		private System.Windows.Forms.TextBox txtNum;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.Panel panel4;
		private System.Windows.Forms.Button btnFnum2aW;
		private System.Windows.Forms.Label label8;
		private System.Windows.Forms.ComboBox cbFractionalItemNameGender;
		private System.Windows.Forms.TextBox txtFractionalPluralItemName;
		private System.Windows.Forms.Label label9;
		private System.Windows.Forms.TextBox txtFractionalDualItemName;
		private System.Windows.Forms.Label label10;
		private System.Windows.Forms.TextBox txtFractionalItemNameWithTanween;
		private System.Windows.Forms.Label label11;
		private System.Windows.Forms.TextBox txtFractionalItemName;
		private System.Windows.Forms.Label label12;
		private System.Windows.Forms.Label label13;
		private System.Windows.Forms.NumericUpDown udDecimalPlace;
		private System.Windows.Forms.Button btnGetnum2aW;
		private System.Windows.Forms.Button btnGetfnum2aW;
	}
}

