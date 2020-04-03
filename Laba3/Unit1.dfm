object Form1: TForm1
  Left = 192
  Top = 125
  Width = 524
  Height = 485
  Caption = #1050#1088#1077#1081#1079#1086' 760801 '#1042#1072#1088#1110#1072#1085#1090' 6 '#1059#1088#1086#1074#1077#1085#1100' 3'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  DesignSize = (
    508
    446)
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 16
    Width = 262
    Height = 16
    Align = alCustom
    Caption = #1042#1074#1077#1076#1080#1090#1077' '#1088#1072#1079#1084#1077#1088' '#1082#1074#1072#1076#1088#1072#1090#1085#1086#1081' '#1084#1072#1090#1088#1080#1094#1099' N'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 8
    Top = 366
    Width = 508
    Height = 16
    Align = alCustom
    Anchors = [akLeft, akBottom]
    Caption = #1057#1082#1072#1083#1103#1088#1085#1086#1077' '#1087#1088#1086#1080#1079#1074#1077#1076#1077#1085#1080#1077' '#1076#1074#1091#1093' '#1089#1090#1088#1086#1082
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 8
    Top = 392
    Width = 480
    Height = 13
    Align = alCustom
    Anchors = [akLeft, akBottom]
  end
  object Edit1: TEdit
    Left = 288
    Top = 16
    Width = 73
    Height = 21
    Anchors = [akLeft, akTop, akRight]
    TabOrder = 0
  end
  object StringGrid1: TStringGrid
    Left = 16
    Top = 48
    Width = 477
    Height = 212
    Anchors = [akLeft, akTop, akRight, akBottom]
    ColCount = 1
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 1
  end
  object StringGrid2: TStringGrid
    Left = 16
    Top = 283
    Width = 477
    Height = 73
    Anchors = [akLeft, akRight, akBottom]
    ColCount = 1
    FixedCols = 0
    RowCount = 2
    FixedRows = 0
    TabOrder = 2
  end
  object Button1: TButton
    Left = 368
    Top = 16
    Width = 70
    Height = 25
    Anchors = [akTop, akRight]
    Caption = #1054#1087#1088#1077#1076#1077#1083#1080#1090#1100
    TabOrder = 3
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 189
    Top = 416
    Width = 113
    Height = 25
    Anchors = [akBottom]
    Caption = #1055#1086#1089#1095#1080#1090#1072#1090#1100
    TabOrder = 4
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 444
    Top = 16
    Width = 49
    Height = 25
    Anchors = [akTop, akRight]
    Caption = #1057#1073#1088#1086#1089
    TabOrder = 5
    OnClick = Button3Click
  end
end
