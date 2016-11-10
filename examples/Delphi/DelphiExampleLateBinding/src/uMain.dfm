object Form3: TForm3
  Left = 0
  Top = 0
  BiDiMode = bdRightToLeft
  BorderStyle = bsDialog
  Caption = 'num2a -Delphi Example / Late Binding'
  ClientHeight = 372
  ClientWidth = 679
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  ParentBiDiMode = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 636
    Top = 35
    Width = 23
    Height = 13
    Caption = #1575#1604#1593#1583#1583
  end
  object Label2: TLabel
    Left = 599
    Top = 62
    Width = 60
    Height = 13
    Caption = #1575#1587#1605' '#1575#1604#1605#1593#1583#1608#1583
  end
  object Label3: TLabel
    Left = 596
    Top = 121
    Width = 63
    Height = 13
    Caption = #1605#1579#1606#1609' '#1575#1604#1605#1593#1583#1608#1583
  end
  object Label4: TLabel
    Left = 601
    Top = 148
    Width = 58
    Height = 13
    Caption = #1580#1605#1593' '#1575#1604#1605#1593#1583#1608#1583
  end
  object Label6: TLabel
    Left = 246
    Top = 62
    Width = 85
    Height = 13
    Caption = #1575#1587#1605' '#1603#1587#1585' '#1575#1604#1605#1593#1583#1608#1583
  end
  object Label7: TLabel
    Left = 243
    Top = 121
    Width = 88
    Height = 13
    Caption = #1605#1579#1606#1609' '#1603#1587#1585' '#1575#1604#1605#1593#1583#1608#1583
  end
  object Label8: TLabel
    Left = 248
    Top = 148
    Width = 83
    Height = 13
    Caption = #1580#1605#1593' '#1603#1587#1585' '#1575#1604#1605#1593#1583#1608#1583
  end
  object Label5: TLabel
    Left = 244
    Top = 215
    Width = 82
    Height = 13
    Caption = #1582#1575#1606#1577' '#1603#1587#1585' '#1575#1604#1605#1593#1583#1608#1583
  end
  object Label9: TLabel
    Left = 575
    Top = 89
    Width = 84
    Height = 13
    Caption = #1575#1587#1605' '#1575#1604#1605#1593#1583#1608#1583' '#1605#1606#1608#1606#1575#1611
  end
  object Label10: TLabel
    Left = 222
    Top = 89
    Width = 109
    Height = 13
    Caption = #1575#1587#1605' '#1603#1587#1585' '#1575#1604#1605#1593#1583#1608#1583' '#1605#1606#1608#1606#1575#1611
  end
  object Label11: TLabel
    Left = 596
    Top = 183
    Width = 63
    Height = 13
    Caption = #1580#1606#1587' '#1575#1604#1605#1593#1583#1608#1583
  end
  object Label12: TLabel
    Left = 243
    Top = 183
    Width = 88
    Height = 13
    Caption = #1580#1606#1587' '#1603#1587#1585' '#1575#1604#1605#1593#1583#1608#1583
  end
  object Label13: TLabel
    Left = 628
    Top = 303
    Width = 31
    Height = 13
    Caption = #1575#1604#1606#1578#1610#1580#1577
  end
  object btnNum2a: TButton
    Left = 465
    Top = 256
    Width = 97
    Height = 25
    Caption = 'num2aW'
    TabOrder = 0
    OnClick = btnNum2aClick
  end
  object edNumber: TEdit
    Left = 362
    Top = 32
    Width = 200
    Height = 21
    TabOrder = 1
  end
  object edItemName: TEdit
    Left = 362
    Top = 59
    Width = 200
    Height = 21
    TabOrder = 2
    Text = #1604#1610#1585#1577
  end
  object edDualItemName: TEdit
    Left = 362
    Top = 118
    Width = 200
    Height = 21
    TabOrder = 3
    Text = #1604#1610#1585#1578#1575#1606
  end
  object edPluralItemName: TEdit
    Left = 362
    Top = 145
    Width = 200
    Height = 21
    TabOrder = 4
    Text = #1604#1610#1585#1575#1578
  end
  object edFractionalItemName: TEdit
    Left = 10
    Top = 59
    Width = 200
    Height = 21
    TabOrder = 5
    Text = #1602#1585#1588
  end
  object edFractionalDualItemName: TEdit
    Left = 10
    Top = 118
    Width = 200
    Height = 21
    TabOrder = 6
    Text = #1602#1585#1588#1575#1606
  end
  object edFractionalPluralItemName: TEdit
    Left = 10
    Top = 145
    Width = 200
    Height = 21
    TabOrder = 7
    Text = #1602#1585#1608#1588
  end
  object btnfnum2aW: TButton
    Left = 113
    Top = 256
    Width = 97
    Height = 25
    Caption = 'fnum2aW'
    TabOrder = 8
    OnClick = btnfnum2aWClick
  end
  object edDecimalPlace: TSpinEdit
    Left = 10
    Top = 212
    Width = 200
    Height = 22
    MaxValue = 0
    MinValue = 0
    TabOrder = 9
    Value = 2
  end
  object edItemNameTanween: TEdit
    Left = 362
    Top = 86
    Width = 200
    Height = 21
    TabOrder = 10
    Text = #1604#1610#1585#1577#1611
  end
  object edFractionalItemNameWithTanween: TEdit
    Left = 10
    Top = 86
    Width = 200
    Height = 21
    TabOrder = 11
    Text = #1602#1585#1588#1575#1611
  end
  object edResult: TEdit
    Left = 10
    Top = 300
    Width = 552
    Height = 21
    TabOrder = 12
  end
  object cbItemGender: TComboBox
    Left = 362
    Top = 183
    Width = 200
    Height = 21
    Style = csDropDownList
    ItemIndex = 1
    TabOrder = 13
    Text = #1605#1572#1606#1617#1579
    Items.Strings = (
      #1605#1584#1603#1617#1585
      #1605#1572#1606#1617#1579)
  end
  object cbFractionalItemNameGender: TComboBox
    Left = 8
    Top = 180
    Width = 200
    Height = 21
    Style = csDropDownList
    ItemIndex = 0
    TabOrder = 14
    Text = #1605#1584#1603#1617#1585
    Items.Strings = (
      #1605#1584#1603#1617#1585
      #1605#1572#1606#1617#1579)
  end
  object btnGetnum2aW: TButton
    Left = 362
    Top = 256
    Width = 97
    Height = 25
    Caption = 'get_num2aW'
    TabOrder = 15
    OnClick = btnGetnum2aWClick
  end
  object btnGetfnum2aW: TButton
    Left = 8
    Top = 256
    Width = 99
    Height = 25
    Caption = 'get_fnum2aW'
    TabOrder = 16
    OnClick = btnGetfnum2aWClick
  end
end
