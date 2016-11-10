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

pnum2aW = function(
              v: double;
              itemName,
              itemNameWithTanween,
              dualItemName,
              pluralItemName:PWideChar;
              itemGender: integer
              ):PWideChar ;cdecl;

pget_num2aW = function(
              dest: PWideChar;
              dest_len: Integer;
              v: double;
              itemName,
              itemNameWithTanween,
              dualItemName,
              pluralItemName:PWideChar;
              itemGender: integer
              ):integer ;cdecl;

pfnum2aW = function(
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
              ):PWideChar ;cdecl;

pget_fnum2aW = function(
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
              ):Integer ;cdecl;

pclean = procedure(ptr: Pointer); cdecl;

const
  MAX_NUMBER_NAME_LENGTH = 2048;

var
  Form3: TForm3;

implementation

{$R *.dfm}

procedure TForm3.btnfnum2aWClick(Sender: TObject);
var
  h: cardinal;
  p: pfnum2aW;
  clean: pclean;
  s: PWideChar;
  num: double;
begin
  edResult.Clear;
  if edNumber.Text = '' then
    Exit;
  h := LoadLibrary(PChar('num2a.dll'));
  if (h <> 0) then
  begin
    try
      p := getprocaddress(h, PChar('fnum2aW'));
      clean := GetProcAddress(h, PChar('n2a_clean'));
      if (assigned(p)) and (Assigned(clean)) then
      begin
        num := StrToFloat(edNumber.Text);
        s := p(
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
        clean(s);
      end;
    finally
      FreeLibrary(h);
    end;
  end;
end;

procedure TForm3.btnGetfnum2aWClick(Sender: TObject);
var
  dest: array [0 .. MAX_NUMBER_NAME_LENGTH] of char;
  h: cardinal;
  p: pget_fnum2aW;
  clean: pclean;
  num: double;
begin
  edResult.Clear;
  if edNumber.Text = '' then
    Exit;
  h := LoadLibrary(PChar('num2a.dll'));
  if (h <> 0) then
  begin
    try
      p := getprocaddress(h, PChar('get_fnum2aW'));
      clean := GetProcAddress(h, PChar('n2a_clean'));
      if (assigned(p)) and (Assigned(clean)) then
      begin
        num := StrToFloat(edNumber.Text);
        if(p(
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
    finally
      FreeLibrary(h);
    end;
  end;
end;

procedure TForm3.btnGetnum2aWClick(Sender: TObject);
var
  dest: array [0 .. MAX_NUMBER_NAME_LENGTH] of char;
  h: cardinal;
  p: pget_num2aW;
  clean: pclean;
  num: double;
begin
  edResult.Clear;
  if edNumber.Text = '' then
    Exit;
  h := LoadLibrary(PChar('num2a.dll'));
  if (h <> 0) then
  begin
    try
      p := getprocaddress(h, PChar('get_num2aW'));
      clean := GetProcAddress(h, PChar('n2a_clean'));
      if (assigned(p)) and (Assigned(clean)) then
      begin
        num := StrToFloat(edNumber.Text);
        if (p(
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
    finally
      FreeLibrary(h);
    end;
  end;

end;

procedure TForm3.btnNum2aClick(Sender: TObject);
var
  h: cardinal;
  p: pnum2aW;
  clean: pclean;
  s: PWideChar;
  num: double;
begin
  edResult.Clear;
  if edNumber.Text = '' then
    Exit;
  h := LoadLibrary(PChar('num2a.dll'));
  if (h <> 0) then
  begin
    try
      p := getprocaddress(h, PChar('num2aW'));
      clean := GetProcAddress(h, PChar('n2a_clean'));
      if (assigned(p)) and (Assigned(clean)) then
      begin
        num := StrToFloat(edNumber.Text);
        s := p(
              num,
              PWideChar(edItemName.Text),
              PWideChar(edItemNameTanween.Text),
              PWideChar(edDualItemName.Text),
              PWideChar(edPluralItemName.Text),
              cbItemGender.ItemIndex
              );
        edResult.Text := s;
        clean(s);
      end;
    finally
      FreeLibrary(h);
    end;
  end;

end;

end.
