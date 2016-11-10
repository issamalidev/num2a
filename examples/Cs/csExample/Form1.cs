using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace csExample
{
	public partial class Form1 : Form
	{
		[DllImport("num2a.dll", EntryPoint = "num2aW", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl)]
		public static extern IntPtr num2aW(
				double num,
				[MarshalAsAttribute(UnmanagedType.LPWStr)]  string itemName,
				[MarshalAsAttribute(UnmanagedType.LPWStr)]  string itemNameWithTanween,
				[MarshalAsAttribute(UnmanagedType.LPWStr)]  string dualItemName,
				[MarshalAsAttribute(UnmanagedType.LPWStr)]  string pluralItemName,
				int ig);

		[DllImport("num2a.dll", EntryPoint = "get_num2aW", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl)]
		public static extern int get_num2aW(
				StringBuilder dest,
				uint dest_len,
				double num,
				[MarshalAsAttribute(UnmanagedType.LPWStr)]  string itemName,
				[MarshalAsAttribute(UnmanagedType.LPWStr)]  string itemNameWithTanween,
				[MarshalAsAttribute(UnmanagedType.LPWStr)]  string dualItemName,
				[MarshalAsAttribute(UnmanagedType.LPWStr)]  string pluralItemName,
				int ig);

		[DllImport("num2a.dll", EntryPoint = "fnum2aW", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl)]
		public static extern IntPtr fnum2aW(
				double num,
				[MarshalAsAttribute(UnmanagedType.LPWStr)]  string itemName,
				[MarshalAsAttribute(UnmanagedType.LPWStr)]  string itemNameWithTanween,
				[MarshalAsAttribute(UnmanagedType.LPWStr)]  string dualItemName,
				[MarshalAsAttribute(UnmanagedType.LPWStr)]  string pluralItemName,
				int ig,
				[MarshalAsAttribute(UnmanagedType.LPWStr)]  string fractionalItemName,
				[MarshalAsAttribute(UnmanagedType.LPWStr)]  string fractionalItemNameWithTanween,
				[MarshalAsAttribute(UnmanagedType.LPWStr)]  string fractionalDualItemName,
				[MarshalAsAttribute(UnmanagedType.LPWStr)]  string fractionalPluralItemName,
				int fig,
				int decimalPlace
				);

		[DllImport("num2a.dll", EntryPoint = "get_fnum2aW", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl)]
		public static extern int get_fnum2aW(
				StringBuilder dest,
				uint dest_len,
				double num,
				[MarshalAsAttribute(UnmanagedType.LPWStr)]  string itemName,
				[MarshalAsAttribute(UnmanagedType.LPWStr)]  string itemNameWithTanween,
				[MarshalAsAttribute(UnmanagedType.LPWStr)]  string dualItemName,
				[MarshalAsAttribute(UnmanagedType.LPWStr)]  string pluralItemName,
				int ig,
				[MarshalAsAttribute(UnmanagedType.LPWStr)]  string fractionalItemName,
				[MarshalAsAttribute(UnmanagedType.LPWStr)]  string fractionalItemNameWithTanween,
				[MarshalAsAttribute(UnmanagedType.LPWStr)]  string fractionalDualItemName,
				[MarshalAsAttribute(UnmanagedType.LPWStr)]  string fractionalPluralItemName,
				int fig,
				int decimalPlace
				);

		[DllImport("num2a.dll", EntryPoint = "n2a_clean", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl)]
		public static extern void clean(IntPtr ptr);

		const int MAX_NUMBER_NAME_LENGTH = 1024;

		public Form1()
		{
			InitializeComponent();
			cbItemNameGender.SelectedIndex = 1;
			cbFractionalItemNameGender.SelectedIndex = 0;
		}

		private void btnNum2aW_Click(object sender, EventArgs e)
		{
			txtResult.Clear();
			if (String.IsNullOrEmpty(txtNum.Text))
				return;
			IntPtr res = num2aW(
						Convert.ToDouble(txtNum.Text),
						txtItemName.Text,
						txtItemNameWithTanween.Text,
						txtDualItemName.Text,
						txtPluralItemName.Text,
						cbItemNameGender.SelectedIndex
						);


			txtResult.Text = Marshal.PtrToStringUni(res);
			clean(res);
		}

		private void btnFnum2aW_Click(object sender, EventArgs e)
		{
			txtResult.Clear();
			if (String.IsNullOrEmpty(txtNum.Text))
				return;
			IntPtr res = fnum2aW(
						Convert.ToDouble(txtNum.Text),
						txtItemName.Text,
						txtItemNameWithTanween.Text,
						txtDualItemName.Text,
						txtPluralItemName.Text,
						cbItemNameGender.SelectedIndex,
						txtFractionalItemName.Text,
						txtFractionalItemNameWithTanween.Text,
						txtFractionalDualItemName.Text,
						txtFractionalPluralItemName.Text,
						cbFractionalItemNameGender.SelectedIndex,
						(int)udDecimalPlace.Value
						);


			txtResult.Text = Marshal.PtrToStringUni(res);
			clean(res);
		}

		private void btnGetnum2aW_Click(object sender, EventArgs e)
		{
			txtResult.Clear();
			if (String.IsNullOrEmpty(txtNum.Text))
				return;
			StringBuilder dest = new StringBuilder(MAX_NUMBER_NAME_LENGTH);
			if (get_num2aW(
						dest,
						MAX_NUMBER_NAME_LENGTH,
						Convert.ToDouble(txtNum.Text),
						txtItemName.Text,
						txtItemNameWithTanween.Text,
						txtDualItemName.Text,
						txtPluralItemName.Text,
						cbItemNameGender.SelectedIndex
						) == 1)
			{
				txtResult.Text = dest.ToString();
			}
		}

		private void btnGetfnum2aW_Click(object sender, EventArgs e)
		{
			txtResult.Clear();
			if (String.IsNullOrEmpty(txtNum.Text))
				return;
			StringBuilder dest = new StringBuilder(MAX_NUMBER_NAME_LENGTH);
			if (get_fnum2aW(
						dest,
						MAX_NUMBER_NAME_LENGTH,
						Convert.ToDouble(txtNum.Text),
						txtItemName.Text,
						txtItemNameWithTanween.Text,
						txtDualItemName.Text,
						txtPluralItemName.Text,
						cbItemNameGender.SelectedIndex,
						txtFractionalItemName.Text,
						txtFractionalItemNameWithTanween.Text,
						txtFractionalDualItemName.Text,
						txtFractionalPluralItemName.Text,
						cbFractionalItemNameGender.SelectedIndex,
						(int)udDecimalPlace.Value
						) == 1)
			{
				txtResult.Text = dest.ToString();
			}
		}
	}
}
