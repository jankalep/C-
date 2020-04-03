object Form1: TForm1
  Left = 192
  Top = 125
  Width = 374
  Height = 438
  Caption = #1050#1088#1077#1081#1079#1086' 760801 '#1059#1088#1086#1074#1077#1085#1100' 3 '#1042#1072#1088#1110#1072#1085#1090' 6'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  DesignSize = (
    358
    399)
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 0
    Width = 141
    Height = 20
    Align = alCustom
    Anchors = [akLeft, akTop, akRight]
    Caption = #1042#1074#1077#1076#1080#1090#1077' '#1089#1090#1088#1086#1082#1091' '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 8
    Top = 72
    Width = 176
    Height = 20
    Align = alCustom
    Anchors = [akLeft, akTop, akRight]
    Caption = #1048#1090#1086#1075#1086#1074#1072#1103' '#1087#1086#1076#1089#1090#1088#1086#1082#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Edit1: TEdit
    Left = 16
    Top = 32
    Width = 282
    Height = 21
    Anchors = [akLeft, akTop, akRight]
    TabOrder = 0
    OnKeyPress = Edit1KeyPress
  end
  object Button1: TButton
    Left = 305
    Top = 32
    Width = 41
    Height = 25
    Anchors = [akTop, akRight]
    Caption = #1057#1073#1088#1086#1089
    TabOrder = 1
    OnClick = Button1Click
  end
  object Memo1: TMemo
    Left = 16
    Top = 104
    Width = 332
    Height = 287
    Anchors = [akLeft, akTop, akRight, akBottom]
    Lines.Strings = (
      'Memo1')
    TabOrder = 2
  end
end
