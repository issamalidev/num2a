/*
 * @file JavaNum2aExample.java
 * num2a example in Java using Java Native Interface (JNI) 
 * By Issam Ali  issamsoft.com
 */
 
import javax.swing.*;
import java.awt.event.*;
import java.awt.*;
import javax.swing.UIManager;
import java.awt.ComponentOrientation;
import java.io.*;

class JavaNum2aExample extends JFrame{
		private static JavaNum2aExample mainForm;
		private static JTextField txtNum, txtItemName, txtItemNameWithTanween, txtDualItemName, txtPluralItemName,
		txtFractionalItemName, txtFractionalItemNameWithTanween, txtFractionalDualItemName,
		txtFractionalPluralItemName, txtResult;
		
		
		private static JComboBox<String> cbItemNameGender, cbFractionalItemNameGenders;
		private static JSpinner spDecimalPlace;
		private JButton btnNum2aW, btnFnum2aW, btnGetNum2aW, btnGetFnum2aW;
		private static String[] genders = { "مذكر", "مؤنث"};
		private static String encoding;
		
		private static final String MSG_ENCODING_EXCEPTION = "missing required encoding: ";
		
		static 
		{
			System.loadLibrary("jnum2a"); // Load the native num2a wrapper
		}
		

		
		static private native byte[] num2aW(
						double num, 
						byte[] itemName, 
						byte[] itemNameWithTanween,
						byte[] dualItemName,
						byte[] pluralItemName,
						int ig
						);
		
		static private native byte[] get_num2aW(
						double num, 
						byte[] itemName, 
						byte[] itemNameWithTanween,
						byte[] dualItemName,
						byte[] pluralItemName,
						int ig
						);
					
		
		static private native byte[] fnum2aW(
						double num, 		
						byte[] itemName, 	
						byte[] itemNameWithTanween,	
						byte[] dualItemName,
						byte[] pluralItemName,		
						int ig,	
						byte[] fractionalItemName,	
						byte[] fractionalItemNameWithTanween,
						byte[] fractionalDualItemName,
						byte[] fractionalPluralItemName,	
						int fig,
						int decimalPlace			
						);	
						
		static private native byte[] get_fnum2aW(
						double num, 		
						byte[] itemName, 	
						byte[] itemNameWithTanween,	
						byte[] dualItemName,
						byte[] pluralItemName,		
						int ig,	
						byte[] fractionalItemName,	
						byte[] fractionalItemNameWithTanween,
						byte[] fractionalDualItemName,
						byte[] fractionalPluralItemName,	
						int fig,
						int decimalPlace			
						);		
		
		
		JavaNum2aExample(String s)
		{
			super(s);
			setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
			
			JPanel pnlMain = new JPanel();
			pnlMain.setLayout(new GridBagLayout());
			
			GridBagConstraints gbc = new GridBagConstraints();
			gbc.fill = GridBagConstraints.HORIZONTAL;
			gbc.gridwidth = 1;
			gbc.gridx = 0;
			gbc.gridy = 0;
			gbc.insets = new Insets(0, 10, 0, 0);
			gbc.weightx = 1;
			pnlMain.add(new JLabel("الرقم"), gbc);
			
			txtNum = new JTextField();
			gbc = new GridBagConstraints();
			gbc.fill = GridBagConstraints.HORIZONTAL;
			gbc.gridwidth = 1;
			gbc.gridx = 1;
			gbc.gridy = 0;
			gbc.insets = new Insets(5, 0, 0, 10);
			gbc.weightx = 1;
			pnlMain.add(txtNum, gbc);
			
			gbc = new GridBagConstraints();
			gbc.fill = GridBagConstraints.HORIZONTAL;
			gbc.gridwidth = 1;
			gbc.gridx = 0;
			gbc.gridy = 1;
			gbc.insets = new Insets(0, 10, 0, 0);
			gbc.weightx = 1;
			pnlMain.add(new JLabel("اسم المعدود"), gbc);			
			
			txtItemName = new JTextField();
			txtItemName.setText("ليرة");
			gbc = new GridBagConstraints();
			gbc.fill = GridBagConstraints.HORIZONTAL;
			gbc.gridwidth = 1;
			gbc.gridx = 1;
			gbc.gridy = 1;
			gbc.insets = new Insets(5, 0, 0, 10);
			gbc.weightx = 1;
			pnlMain.add(txtItemName, gbc);
			
			gbc = new GridBagConstraints();
			gbc.fill = GridBagConstraints.HORIZONTAL;
			gbc.gridwidth = 1;
			gbc.gridx = 0;
			gbc.gridy = 2;
			gbc.insets = new Insets(0, 10, 0, 0);
			gbc.weightx = 1;
			pnlMain.add(new JLabel("اسم المعدود منوناً"), gbc);				
			
			txtItemNameWithTanween = new JTextField();
			txtItemNameWithTanween.setText("ليرةً");
			gbc = new GridBagConstraints();
			gbc.fill = GridBagConstraints.HORIZONTAL;
			gbc.gridwidth = 1;
			gbc.gridx = 1;
			gbc.gridy = 2;
			gbc.insets = new Insets(5, 0, 0, 10);
			gbc.weightx = 1;
			pnlMain.add(txtItemNameWithTanween, gbc);

			gbc = new GridBagConstraints();
			gbc.fill = GridBagConstraints.HORIZONTAL;
			gbc.gridwidth = 1;
			gbc.gridx = 0;
			gbc.gridy = 3;
			gbc.insets = new Insets(0, 10, 0, 0);
			gbc.weightx = 1;
			pnlMain.add(new JLabel("مثنى المعدود"), gbc);	

			txtDualItemName = new JTextField();
			txtDualItemName.setText("ليرتان");
			gbc = new GridBagConstraints();
			gbc.fill = GridBagConstraints.HORIZONTAL;
			gbc.gridwidth =1;
			gbc.gridx = 1;
			gbc.gridy = 3;
			gbc.insets = new Insets(5, 0, 0, 10);
			gbc.weightx = 1;
			pnlMain.add(txtDualItemName, gbc);			
			
			gbc = new GridBagConstraints();
			gbc.fill = GridBagConstraints.HORIZONTAL;
			gbc.gridwidth = 1;
			gbc.gridx = 0;
			gbc.gridy = 4;
			gbc.insets = new Insets(0, 10, 0, 0);
			gbc.weightx = 1;
			pnlMain.add(new JLabel("جمع المعدود"), gbc);	
			
			txtPluralItemName = new JTextField();
			txtPluralItemName.setText("ليرات");
			gbc = new GridBagConstraints();
			gbc.fill = GridBagConstraints.HORIZONTAL;
			gbc.gridwidth = 1;
			gbc.gridx = 1;
			gbc.gridy = 4;
			gbc.insets = new Insets(5, 0, 0, 10);
			gbc.weightx = 1;
			pnlMain.add(txtPluralItemName, gbc);

			gbc = new GridBagConstraints();
			gbc.fill = GridBagConstraints.HORIZONTAL;
			gbc.gridwidth = 1;
			gbc.gridx = 0;
			gbc.gridy = 5;
			gbc.insets = new Insets(0, 10, 0, 0);
			gbc.weightx = 1;
			pnlMain.add(new JLabel("جنس المعدود"), gbc);	
			
			cbItemNameGender = new JComboBox<>(genders);
			cbItemNameGender.setSelectedIndex(1);
			gbc = new GridBagConstraints();
			gbc.fill = GridBagConstraints.HORIZONTAL;
			gbc.gridwidth = 1;
			gbc.gridx = 1;
			gbc.gridy = 5;
			gbc.insets = new Insets(5, 0, 0, 10);
			gbc.weightx = 1;
			pnlMain.add(cbItemNameGender, gbc);
			
			btnNum2aW = new JButton("num2aW");
			btnNum2aW.addActionListener(new ActionListener(){
				public void actionPerformed(ActionEvent e){
					btnNum2aClicked();
				}
			});	
			btnGetNum2aW = new JButton("get_num2aW");
			btnGetNum2aW.addActionListener(new ActionListener(){
				public void actionPerformed(ActionEvent e){
					btnGetNum2aWClicked();
				}
			});	
			JPanel pnl1 = new JPanel();
			pnl1.add(btnNum2aW);
			pnl1.add(btnGetNum2aW);
			gbc = new GridBagConstraints();
			gbc.fill = GridBagConstraints.HORIZONTAL;
			gbc.gridwidth = 1;
			gbc.gridx = 1;
			gbc.gridy = 7;
			gbc.insets = new Insets(0, 10, 0, 0);
			gbc.weightx = 1;
			pnlMain.add(pnl1, gbc);

			
			
			gbc = new GridBagConstraints();
			gbc.fill = GridBagConstraints.HORIZONTAL;
			gbc.gridwidth = 1;
			gbc.gridx = 2;
			gbc.gridy = 1;
			gbc.insets = new Insets(0, 10, 0, 0);
			gbc.weightx = 1;
			pnlMain.add(new JLabel("اسم كسر المعدود"), gbc);				
			
			txtFractionalItemName = new JTextField();
			txtFractionalItemName.setText("قرش");
			gbc = new GridBagConstraints();
			gbc.fill = GridBagConstraints.HORIZONTAL;
			gbc.gridwidth = 1;
			gbc.gridx = 3;
			gbc.gridy = 1;
			gbc.insets = new Insets(5, 0, 0, 10);
			gbc.weightx = 1;
			pnlMain.add(txtFractionalItemName, gbc);
			

			gbc = new GridBagConstraints();
			gbc.fill = GridBagConstraints.HORIZONTAL;
			gbc.gridwidth = 1;
			gbc.gridx = 2;
			gbc.gridy = 2;
			gbc.insets = new Insets(0, 10, 0, 0);
			gbc.weightx = 1;
			pnlMain.add(new JLabel("اسم كسر المعدود منوناً"), gbc);				
			
			txtFractionalItemNameWithTanween = new JTextField();
			txtFractionalItemNameWithTanween.setText("قرشاً");
			gbc = new GridBagConstraints();
			gbc.fill = GridBagConstraints.HORIZONTAL;
			gbc.gridwidth = 1;
			gbc.gridx = 3;
			gbc.gridy = 2;
			gbc.insets = new Insets(5, 0, 0, 10);
			gbc.weightx = 1;
			pnlMain.add(txtFractionalItemNameWithTanween, gbc);
			
			gbc = new GridBagConstraints();
			gbc.fill = GridBagConstraints.HORIZONTAL;
			gbc.gridwidth = 1;
			gbc.gridx = 2;
			gbc.gridy = 3;
			gbc.insets = new Insets(0, 10, 0, 0);
			gbc.weightx = 1;
			pnlMain.add(new JLabel("مثنى كسر المعدود"), gbc);				
			
			txtFractionalDualItemName = new JTextField();
			txtFractionalDualItemName.setText("قرشان");
			gbc = new GridBagConstraints();
			gbc.fill = GridBagConstraints.HORIZONTAL;
			gbc.gridwidth = 1;
			gbc.gridx = 3;
			gbc.gridy = 3;
			gbc.insets = new Insets(5, 0, 0, 10);
			gbc.weightx = 1;
			pnlMain.add(txtFractionalDualItemName, gbc);

			gbc = new GridBagConstraints();
			gbc.fill = GridBagConstraints.HORIZONTAL;
			gbc.gridwidth = 1;
			gbc.gridx = 2;
			gbc.gridy = 4;
			gbc.insets = new Insets(0, 10, 0, 0);
			gbc.weightx = 1;
			pnlMain.add(new JLabel("جمع كسر المعدود"), gbc);				
			
			txtFractionalPluralItemName = new JTextField();
			txtFractionalPluralItemName.setText("قروش");
			gbc = new GridBagConstraints();
			gbc.fill = GridBagConstraints.HORIZONTAL;
			gbc.gridwidth = 1;
			gbc.gridx = 3;
			gbc.gridy = 4;
			gbc.insets = new Insets(5, 0, 0, 10);
			gbc.weightx = 1;
			pnlMain.add(txtFractionalPluralItemName, gbc);			
			
			gbc = new GridBagConstraints();
			gbc.fill = GridBagConstraints.HORIZONTAL;
			gbc.gridwidth = 1;
			gbc.gridx = 2;
			gbc.gridy = 5;
			gbc.insets = new Insets(0, 10, 0, 0);
			gbc.weightx = 1;
			pnlMain.add(new JLabel("جنس كسر المعدود"), gbc);	
			
			cbFractionalItemNameGenders = new JComboBox<>(genders);
			cbFractionalItemNameGenders.setSelectedIndex(0);
			gbc = new GridBagConstraints();
			gbc.fill = GridBagConstraints.HORIZONTAL;
			gbc.gridwidth = 1;
			gbc.gridx = 3;
			gbc.gridy = 5;
			gbc.insets = new Insets(5, 0, 0, 10);
			gbc.weightx = 1;
			pnlMain.add(cbFractionalItemNameGenders, gbc);

			gbc = new GridBagConstraints();
			gbc.fill = GridBagConstraints.HORIZONTAL;
			gbc.gridwidth = 1;
			gbc.gridx = 2;
			gbc.gridy = 6;
			gbc.insets = new Insets(0, 10, 0, 0);
			gbc.weightx = 1;
			pnlMain.add(new JLabel("خانة كسر المعدود"), gbc);	

			SpinnerModel model = new SpinnerNumberModel(2, 0, 6,1);			
			spDecimalPlace = new JSpinner( model);
			gbc = new GridBagConstraints();
			gbc.fill = GridBagConstraints.HORIZONTAL;
			gbc.gridwidth = 1;
			gbc.gridx = 3;
			gbc.gridy = 6;
			gbc.insets = new Insets(5, 0, 0, 10);
			gbc.weightx = 1;
			pnlMain.add(spDecimalPlace, gbc);			
			
			JPanel pnl2 = new JPanel();
			btnFnum2aW = new JButton("fnum2aW");
			btnFnum2aW.addActionListener(new ActionListener(){
				public void actionPerformed(ActionEvent e){
					btnFnum2aWClicked();
				}
			});	
			btnGetFnum2aW = new JButton("get_fnum2aW");
			btnGetFnum2aW.addActionListener(new ActionListener(){
				public void actionPerformed(ActionEvent e){
					btnGetFnum2aWClicked();
				}
			});	
			
			pnl2.add(btnFnum2aW);
			pnl2.add(btnGetFnum2aW);
			gbc = new GridBagConstraints();
			gbc.fill = GridBagConstraints.HORIZONTAL;
			gbc.gridwidth = 1;
			gbc.gridx = 3;
			gbc.gridy = 7;
			gbc.insets = new Insets(0, 10, 0, 0);
			gbc.weightx = 1;
			pnlMain.add(pnl2, gbc);			
			
			gbc = new GridBagConstraints();
			gbc.fill = GridBagConstraints.HORIZONTAL;
			gbc.gridwidth = 1;
			gbc.gridx = 0;
			gbc.gridy = 8;
			gbc.insets = new Insets(0, 10, 0, 0);
			gbc.weightx = 1;
			pnlMain.add(new JLabel("النتيجة"), gbc);	

			txtResult = new JTextField();
			gbc = new GridBagConstraints();
			gbc.fill = GridBagConstraints.HORIZONTAL;
			gbc.gridwidth = 3;
			gbc.gridx = 1;
			gbc.gridy = 8;
			gbc.insets = new Insets(5, 0, 0, 10);
			gbc.weightx = 1;
			pnlMain.add(txtResult, gbc);
			
			add(pnlMain);
			pack();
			setVisible(true);
		}
		
		
		public static void main(String[] argv)
		{
			//todo: I assume that most non-windows systems are using UTF-32 little endian, 
			//change this if your target system does not use this encoding  
			if (System.getProperty("os.name").toLowerCase().indexOf("win") >= 0)
				encoding = "UTF-16LE";
			else
				encoding = "UTF-32LE";

				
			mainForm = new JavaNum2aExample("num2a- JavaExample");
		}
		
		
		
		static void btnNum2aClicked()
		{
			txtResult.setText("");
			if(txtNum.getText().equals(""))
				return;
			String result; 
			byte itemName[], itemNameWithTanween[], dualItemName[], pluralItemName[],
				bResult[];
			double num = Double.parseDouble(txtNum.getText());

			try
			{
				itemName = txtItemName.getText().getBytes(encoding);
				itemNameWithTanween =  txtItemNameWithTanween.getText().getBytes(encoding);
				dualItemName = txtDualItemName.getText().getBytes(encoding);
				pluralItemName = txtPluralItemName.getText().getBytes(encoding);
			}
			catch(UnsupportedEncodingException e)
			{
				throw new InternalError(MSG_ENCODING_EXCEPTION + encoding);
			}
			bResult = num2aW(
				num,
				itemName,
				itemNameWithTanween,
				dualItemName,
				pluralItemName,
				cbItemNameGender.getSelectedIndex()
				);
			try
			{
				result = new String(bResult, encoding);
			}
			catch(UnsupportedEncodingException e)
			{
				throw new InternalError(MSG_ENCODING_EXCEPTION + encoding);
			}
			
			txtResult.setText(result);
		}
		
		
		static void btnFnum2aWClicked()
		{
			txtResult.setText("");
			if(txtNum.getText().equals(""))
				return;
			String result; 
			byte itemName[], itemNameWithTanween[], dualItemName[], pluralItemName[],
				fractionalItemName[], fractionalItemNameWithTanween[], fractionalDualItemName[],
				fractionalPluralItemName[], bResult[];
			Integer decimalPlace = (Integer)spDecimalPlace.getValue();
			double num = Double.parseDouble(txtNum.getText());
			try
			{
				itemName = txtItemName.getText().getBytes(encoding);
				itemNameWithTanween =  txtItemNameWithTanween.getText().getBytes(encoding);
				dualItemName = txtDualItemName.getText().getBytes(encoding);
				pluralItemName = txtPluralItemName.getText().getBytes(encoding);
				fractionalItemName = txtFractionalItemName.getText().getBytes(encoding);
				fractionalItemNameWithTanween = txtFractionalItemNameWithTanween.getText().getBytes(encoding);
				fractionalDualItemName = txtDualItemName.getText().getBytes(encoding);
				fractionalPluralItemName = txtFractionalPluralItemName.getText().getBytes(encoding);
			}
			catch(UnsupportedEncodingException e)
			{
				throw new InternalError(MSG_ENCODING_EXCEPTION + encoding);
			}
			bResult = fnum2aW(
				num,
				itemName,
				itemNameWithTanween,
				dualItemName,
				pluralItemName,
				cbItemNameGender.getSelectedIndex(),
				fractionalItemName,
				fractionalItemNameWithTanween,
				fractionalDualItemName,
				fractionalPluralItemName,
				cbFractionalItemNameGenders.getSelectedIndex(),
				decimalPlace
				);
			try
			{
				result = new String(bResult, encoding);
			}
			catch(UnsupportedEncodingException e)
			{
				throw new InternalError(MSG_ENCODING_EXCEPTION + encoding);
			}
			
			txtResult.setText(result);
		}

		void btnGetNum2aWClicked()
		{
			txtResult.setText("");
			if(txtNum.getText().equals(""))
				return;
			String result; 
			byte itemName[], itemNameWithTanween[], dualItemName[], pluralItemName[],
				bResult[];
			double num = Double.parseDouble(txtNum.getText());

			try
			{
				itemName = txtItemName.getText().getBytes(encoding);
				itemNameWithTanween =  txtItemNameWithTanween.getText().getBytes(encoding);
				dualItemName = txtDualItemName.getText().getBytes(encoding);
				pluralItemName = txtPluralItemName.getText().getBytes(encoding);
			}
			catch(UnsupportedEncodingException e)
			{
				throw new InternalError(MSG_ENCODING_EXCEPTION + encoding);
			}
			bResult = get_num2aW(
				num,
				itemName,
				itemNameWithTanween,
				dualItemName,
				pluralItemName,
				cbItemNameGender.getSelectedIndex()
				);
			try
			{
				result = new String(bResult, encoding);
			}
			catch(UnsupportedEncodingException e)
			{
				throw new InternalError(MSG_ENCODING_EXCEPTION + encoding);
			}
			
			txtResult.setText(result);
		}
		
		static void btnGetFnum2aWClicked()
		{
			txtResult.setText("");
			if(txtNum.getText().equals(""))
				return;
			String result; 
			byte itemName[], itemNameWithTanween[], dualItemName[], pluralItemName[],
				fractionalItemName[], fractionalItemNameWithTanween[], fractionalDualItemName[],
				fractionalPluralItemName[], bResult[];
			Integer decimalPlace = (Integer)spDecimalPlace.getValue();
			double num = Double.parseDouble(txtNum.getText());
			try
			{
				itemName = txtItemName.getText().getBytes(encoding);
				itemNameWithTanween =  txtItemNameWithTanween.getText().getBytes(encoding);
				dualItemName = txtDualItemName.getText().getBytes(encoding);
				pluralItemName = txtPluralItemName.getText().getBytes(encoding);
				fractionalItemName = txtFractionalItemName.getText().getBytes(encoding);
				fractionalItemNameWithTanween = txtFractionalItemNameWithTanween.getText().getBytes(encoding);
				fractionalDualItemName = txtDualItemName.getText().getBytes(encoding);
				fractionalPluralItemName = txtFractionalPluralItemName.getText().getBytes(encoding);
			}
			catch(UnsupportedEncodingException e)
			{
				throw new InternalError(MSG_ENCODING_EXCEPTION + encoding);
			}
			bResult = get_fnum2aW(
				num,
				itemName,
				itemNameWithTanween,
				dualItemName,
				pluralItemName,
				cbItemNameGender.getSelectedIndex(),
				fractionalItemName,
				fractionalItemNameWithTanween,
				fractionalDualItemName,
				fractionalPluralItemName,
				cbFractionalItemNameGenders.getSelectedIndex(),
				decimalPlace
				);
			try
			{
				result = new String(bResult, encoding);
			}
			catch(UnsupportedEncodingException e)
			{
				throw new InternalError(MSG_ENCODING_EXCEPTION + encoding);
			}
			
			txtResult.setText(result);
			
		}
		
}
