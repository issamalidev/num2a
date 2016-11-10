unit uMain;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, Spin;

type
  TForm3 = class(TForm)
    btnNum2a: TButton;
    edNumber: TEdit;
    Label1: TLabel;
    edItemName: TEdit;
    Label2: TLabel;
    edDualItemName: TEdit;
    Label3: TLabel;
    edPluralItemName: TEdit;
    Label4: TLabel;
    Label6: TLabel;
    Label7: TLabel;
    Label8: TLabel;
    edFractionalItemName: TEdit;
    edFractionalDualItemName: TEdit;
    edFractionalPluralItemName: TEdit;
    btnfnum2aW: TButton;
    edDecimalPlace: TSpinEdit;
    Label5: TLabel;
    edItemNameTanween: TEdit;
    Label9: TLabel;
    edFractionalItemNameWithTanween: TEdit;
    Label10: TLabel;
    Label11: TLabel;
    Label12: TLabel;
    Label13: TLabel;
    edResult: TEdit;
    cbItemGender: TComboBox;
    cbFractionalItemNameGender: TComboBox;
    btnGetnum2aW: TButton;
    btnGetfnum2aW: TButton;
    procedure btnNum2aClick(Sender: TObject);
    procedure btnfnum2aWClick(Sender: TObject);
    procedure btnGetnum2aWClick(Sender: TObject);
    procedure btnGetfnum2aWClick(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

  function num2aW(
              v: double;
              itemName,
              itemNameWithTanween,
              dualItemName,
              pluralItemName:PWideChar;
              itemGender: integer
              ):PWideChar ; cdecl; external 'num2a.dll';

  function get_num2aW(
              dest: PWideChar;
              dest_len: Integer;
              v: double;
              itemName,
              itemNameWithTanween,
              dualItemName,
              pluralItemName:PWideChar;
              itemGender: integer
              ):integer ;cdecl;external 'num2a.dll';

   function fnum2aW(
              v: double;
              itemName,
              itemNameWithTanween,
              dualItemName,
              pluralItemName:PWideChar;
              itemGender: integer;
              fractionalItemName,
              fractionalItemNameWithTanween,
              fractionalDualItemName,
              fractionalPluralItemName: PWideChar;
              fig,
              decimalPlace: Integer
              ):PWideChar ;cdecl; external 'num2a.dll';

   function get_fnum2aW(
              dest:PWideChar;
              dest_len: Integer;
              v: double;
              itemName,
              itemNameWithTanween,
              dualItemName,
              pluralItemName:PWideChar;
              itemGender: integer;
              fractionalItemName,
              fractionalItemNameWithTanween,
              fractionalDualItemName,
              fractionalPluralItemName: PWideChar;
              fig,
              decimalPlace: Integer
              ):Integer ;cdecl; external 'num2a.dll';

   procedure n2a_clean(ptr: Pointer); cdecl; external 'num2a.dll';

const
  MAX_NUMBER_NAME_LENGTH = 2048;

var
  Form3: TForm3;

implementation

{$R *.dfm}

procedure TForm3.btnfnum2aWClick(Sender: TObject);
var
  s: PWideChar;
  num: double;
begin
  edResult.Clear;
  if edNumber.Text = '' then
    Exit;
    num := StrToFloat(edNumber.Text);
    s := fnum2aW(
          num,
          PWideChar(edItemName.Text),
          PWideChar(edItemNameTanween.Text),
          PWideChar(edDualItemName.Text),
          PWideChar(edPluralItemName.Text),
          cbItemGender.ItemIndex,
          PWideChar(edFractionalItemName.Text),
          PWideChar(edFractionalItemNameWithTanween.Text),
          PWideChar(edFractionalDualItemName.Text),
          PWideChar(edFractionalPluralItemName.Text),
          cbFractionalItemNameGender.ItemIndex,
          edDecimalPlace.Value
          );
    edResult.Text := s;
    n2a_clean(s);
end;

procedure TForm3.btnGetfnum2aWClick(Sender: TObject);
var
  dest: array [0 .. MAX_NUMBER_NAME_LENGTH] of char;
  h: cardinal;
  num: double;
begin
  edResult.Clear;
  if edNumber.Text = '' then
    Exit;
    num := StrToFloat(edNumber.Text);
    if(get_fnum2aW(
        dest,
        MAX_NUMBER_NAME_LENGTH,
        num,
        PWideChar(edItemName.Text),
        PWideChar(edItemNameTanween.Text),
        PWideChar(edDualItemName.Text),
        PWideChar(edPluralItemName.Text),
        cbItemGender.ItemIndex,
        PWideChar(edFractionalItemName.Text),
        PWideChar(edFractionalItemNameWithTanween.Text),
        PWideChar(edFractionalDualItemName.Text),
        PWideChar(edFractionalPluralItemName.Text),
        cbFractionalItemNameGender.ItemIndex,
        edDecimalPlace.Value
        ) = 1) then
    begin
      edResult.Text := dest;
    end;
end;

procedure TForm3.btnGetnum2aWClick(Sender: TObject);
var
  dest: array [0 .. MAX_NUMBER_NAME_LENGTH] of char;
  num: double;
begin
  edResult.Clear;
  if edNumber.Text = '' then
    Exit;
  num := StrToFloat(edNumber.Text);
  if (get_num2aW(
      dest,
      MAX_NUMBER_NAME_LENGTH,
      num,
      PWideChar(edItemName.Text),
      PWideChar(edItemNameTanween.Text),
      PWideChar(edDualItemName.Text),
      PWideChar(edPluralItemName.Text),
      cbItemGender.ItemIndex
      )= 1) then
  Begin
      edResult.Text := dest;
  End;
end;

procedure TForm3.btnNum2aClick(Sender: TObject);
var
  s: PWideChar;
  num: double;
begin
  edResult.Clear;
  if edNumber.Text = '' then
    Exit;
  num := StrToFloat(edNumber.Text);
  s := num2aW(
        num,
        PWideChar(edItemName.Text),
        PWideChar(edItemNameTanween.Text),
        PWideChar(edDualItemName.Text),
        PWideChar(edPluralItemName.Text),
        cbItemGender.ItemIndex
        );
  edResult.Text := s;
  n2a_clean(s);


end;

end.
