object Form1: TForm1
  Left = 192
  Top = 125
  Width = 505
  Height = 497
  Caption = #1047#1086#1083#1086#1090#1086#1081' 760801 '#1042#1072#1088#1080#1072#1085#1090' 5 '#1059#1088#1086#1074#1077#1085#1100' 3'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  DesignSize = (
    489
    458)
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 96
    Top = 8
    Width = 268
    Height = 16
    Anchors = [akTop]
    Caption = #1042#1074#1077#1076#1080#1090#1077' '#1074#1072#1096' '#1090#1077#1082#1089#1090' '#1076#1083#1103' '#1079#1072#1096#1080#1092#1088#1086#1074#1082#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    OnClick = Label1Click
  end
  object Label2: TLabel
    Left = 8
    Top = 56
    Width = 3
    Height = 13
  end
  object Label3: TLabel
    Left = 8
    Top = 96
    Width = 29
    Height = 13
    Caption = #1060#1072#1081#1083
  end
  object Edit1: TEdit
    Left = 8
    Top = 32
    Width = 369
    Height = 21
    Anchors = [akLeft, akTop, akRight]
    TabOrder = 0
    OnKeyPress = Edit1KeyPress
  end
  object Button1: TButton
    Left = 384
    Top = 32
    Width = 33
    Height = 25
    Anchors = [akTop, akRight]
    Caption = '<'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 424
    Top = 32
    Width = 57
    Height = 25
    Anchors = [akTop, akRight]
    Caption = #1079#1072#1087#1080#1089#1072#1090#1100
    TabOrder = 2
    OnClick = Button2Click
  end
  object Memo1: TMemo
    Left = 8
    Top = 136
    Width = 473
    Height = 281
    Anchors = [akLeft, akTop, akRight]
    Lines.Strings = (
      '')
    TabOrder = 3
  end
  object Button3: TButton
    Left = 8
    Top = 120
    Width = 97
    Height = 17
    Caption = #1086#1090#1082#1088#1099#1090#1100' '#1092#1072#1081#1083
    TabOrder = 4
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 376
    Top = 120
    Width = 105
    Height = 17
    Anchors = [akTop, akRight]
    Caption = #1076#1077#1096#1080#1092#1088#1086#1074#1072#1090#1100' '#1092#1072#1081#1083
    TabOrder = 5
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 192
    Top = 424
    Width = 121
    Height = 25
    Anchors = [akBottom]
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1074#1089#1105
    TabOrder = 6
    OnClick = Button5Click
  end
  object OpenDialog1: TOpenDialog
    Filter = #1058#1077#1082#1089#1090#1086#1074#1099#1081' '#1092#1072#1081#1083'|*.txt|'#1042#1089#1077' '#1092#1072#1081#1083#1099'|*.*'
    Left = 8
    Top = 8
  end
  object SaveDialog1: TSaveDialog
    DefaultExt = '.txt'
    Filter = #1058#1077#1082#1089#1090#1086#1074#1099#1081' '#1092#1072#1081#1083'|*.txt'
    Left = 40
    Top = 8
  end
end
