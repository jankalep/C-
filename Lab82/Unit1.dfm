object Form1: TForm1
  Left = 604
  Top = 107
  Width = 538
  Height = 361
  Caption = 'ln(x) - 5*sin^2(x)'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 32
    Top = 8
    Width = 154
    Height = 13
    Caption = #1055#1088#1077#1076#1077#1083#1099' '#1080#1085#1090#1077#1075#1088#1080#1088#1086#1074#1072#1085#1080#1103
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 8
    Top = 32
    Width = 23
    Height = 13
    Caption = #1072' = '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 104
    Top = 32
    Width = 23
    Height = 13
    Caption = 'b = '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 408
    Top = 16
    Width = 23
    Height = 13
    Caption = 'n = '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label5: TLabel
    Left = 408
    Top = 48
    Width = 36
    Height = 13
    Caption = 'eps = '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object RadioGroup1: TRadioGroup
    Left = 216
    Top = 8
    Width = 185
    Height = 65
    Caption = #1042#1099#1073#1086#1088' '#1084#1077#1090#1086#1076#1072
    ItemIndex = 0
    Items.Strings = (
      #1056#1072#1079#1073#1080#1077#1085#1080#1077' '#1085#1072' n'
      #1058#1086#1095#1085#1086#1089#1090#1100' eps')
    TabOrder = 0
  end
  object Memo1: TMemo
    Left = 16
    Top = 80
    Width = 193
    Height = 201
    Lines.Strings = (
      'Memo1')
    ScrollBars = ssVertical
    TabOrder = 1
  end
  object Edit1: TEdit
    Left = 35
    Top = 30
    Width = 49
    Height = 21
    TabOrder = 2
    Text = 'Edit1'
    OnKeyPress = Edit1KeyPress
  end
  object Edit2: TEdit
    Left = 131
    Top = 29
    Width = 49
    Height = 21
    TabOrder = 3
    Text = 'Edit2'
    OnKeyPress = Edit2KeyPress
  end
  object Edit3: TEdit
    Left = 448
    Top = 48
    Width = 41
    Height = 21
    TabOrder = 4
    Text = 'Edit3'
    OnKeyPress = Edit3KeyPress
  end
  object Edit4: TEdit
    Left = 440
    Top = 13
    Width = 41
    Height = 21
    TabOrder = 5
    Text = 'Edit4'
    OnKeyPress = Edit4KeyPress
  end
  object Chart1: TChart
    Left = 216
    Top = 80
    Width = 297
    Height = 201
    BackWall.Brush.Color = clWhite
    BackWall.Brush.Style = bsClear
    Title.Text.Strings = (
      #1043#1088#1072#1092#1080#1082' '#1092#1091#1085#1082#1094#1080#1080' f(x)')
    View3D = False
    TabOrder = 6
    object Series1: TLineSeries
      Marks.ArrowLength = 8
      Marks.Visible = False
      SeriesColor = clRed
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      Pointer.Visible = False
      XValues.DateTime = False
      XValues.Name = 'X'
      XValues.Multiplier = 1
      XValues.Order = loAscending
      YValues.DateTime = False
      YValues.Name = 'Y'
      YValues.Multiplier = 1
      YValues.Order = loNone
    end
  end
  object Button1: TButton
    Left = 248
    Top = 288
    Width = 225
    Height = 33
    Caption = #1056#1072#1089#1095#1077#1090
    TabOrder = 7
    OnClick = Button1Click
  end
end
