object MainForm: TMainForm
  Left = 0
  Top = 0
  Caption = 'Sudoku'
  ClientHeight = 540
  ClientWidth = 917
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnCreate = FormCreate
  DesignSize = (
    917
    540)
  PixelsPerInch = 96
  TextHeight = 13
  object Shape1: TShape
    Left = 422
    Top = 30
    Width = 488
    Height = 100
    Anchors = [akLeft, akTop, akRight]
    Pen.Color = clGray
  end
  object Label1: TLabel
    Left = 440
    Top = 39
    Width = 131
    Height = 14
    Caption = 'Propriedades da solu'#231#227'o'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 692
    Top = 98
    Width = 119
    Height = 13
    Caption = 'C'#233'lulas vazias na cria'#231#227'o'
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 917
    Height = 24
    ButtonWidth = 109
    Caption = 'm_Tools'
    DrawingStyle = dsGradient
    Images = ImageList1
    List = True
    AllowTextButtons = True
    TabOrder = 0
    ExplicitWidth = 796
    object m_create: TToolButton
      Left = 0
      Top = 0
      Caption = ' Criar sudoku'
      ImageIndex = 0
      Style = tbsTextButton
      OnClick = m_createClick
    end
    object m_solve: TToolButton
      Left = 94
      Top = 0
      Caption = ' Resolver sudoku'
      ImageIndex = 1
      Style = tbsTextButton
      OnClick = m_solveClick
    end
    object m_ToolCancel: TToolButton
      Left = 207
      Top = 0
      Caption = 'Cancelar solu'#231#227'o'
      Enabled = False
      ImageIndex = 6
      Style = tbsTextButton
      OnClick = m_ToolCancelClick
    end
    object ToolButton2: TToolButton
      Left = 319
      Top = 0
      Width = 8
      Caption = 'ToolButton2'
      ImageIndex = 3
      Style = tbsSeparator
    end
    object m_clean: TToolButton
      Left = 327
      Top = 0
      Caption = ' Limpar  tabuleiro'
      ImageIndex = 2
      Style = tbsTextButton
      OnClick = m_cleanClick
    end
  end
  object m_sudoku: TStringGrid
    Left = 8
    Top = 30
    Width = 408
    Height = 228
    ColCount = 9
    DefaultColWidth = 44
    DrawingStyle = gdsClassic
    FixedCols = 0
    RowCount = 9
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    PopupMenu = PopupMenu1
    TabOrder = 1
    OnDrawCell = m_sudokuDrawCell
  end
  object m_TreeSolve: TTreeView
    Left = 422
    Top = 136
    Width = 488
    Height = 396
    Anchors = [akLeft, akTop, akRight, akBottom]
    Images = ImageList1
    Indent = 19
    TabOrder = 2
    OnClick = m_TreeSolveClick
    ExplicitWidth = 491
  end
  object m_status: TRichEdit
    Left = 8
    Top = 264
    Width = 408
    Height = 268
    Anchors = [akLeft, akTop, akBottom]
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    ScrollBars = ssBoth
    TabOrder = 3
  end
  object m_TimeReal: TRadioButton
    Left = 440
    Top = 68
    Width = 129
    Height = 17
    Caption = 'Tempo de solu'#231#227'o real'
    TabOrder = 4
    OnClick = m_TimeRealClick
  end
  object m_Simulation: TRadioButton
    Left = 440
    Top = 97
    Width = 129
    Height = 17
    Caption = 'Simula'#231#227'o de solu'#231#227'o'
    TabOrder = 5
    OnClick = m_SimulationClick
  end
  object m_time: TEdit
    Left = 575
    Top = 95
    Width = 58
    Height = 21
    Hint = 'Informe o tempo de simula'#231#227'o em (ms)'
    Enabled = False
    NumbersOnly = True
    TabOrder = 6
    Text = '0'
  end
  object m_UpDown: TUpDown
    Left = 633
    Top = 95
    Width = 16
    Height = 21
    Associate = m_time
    Enabled = False
    Max = 10000
    TabOrder = 7
  end
  object m_CreateTreeSolve: TCheckBox
    Left = 692
    Top = 68
    Width = 141
    Height = 17
    Caption = 'Criar '#225'rvore de solu'#231#227'o'
    TabOrder = 8
  end
  object m_numbers: TEdit
    Left = 826
    Top = 95
    Width = 58
    Height = 21
    NumbersOnly = True
    TabOrder = 9
    Text = '1'
  end
  object m_UpDownNumbers: TUpDown
    Left = 884
    Top = 95
    Width = 16
    Height = 21
    Associate = m_numbers
    Min = 1
    Max = 8
    Position = 1
    TabOrder = 10
  end
  object ImageList1: TImageList
    Left = 752
    Top = 384
    Bitmap = {
      494C010107000800180110001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000002000000001002000000000000020
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000BE91649ECCB2996800000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000A3A399698E8E7D878E8E7D878E8E
      7D878E8E7D878E8E7D878E8E7D878E8E7D878E8E7D878E8E7D878E8E7D878E8E
      7D87A16523E7A16523E7927A54B3A3A399690000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000009B9B8A81F9F9E9FFF3F3E2FFF3F3
      E2FFF3F3E2FFF3F3E2FFF3F3E2FFF3F3E2FFD1A46CFFC18540FFC18540FFC185
      40FFC18540FFFFC538FFC38742FF9E8760AF0000000000000000000000009B9B
      AF6433337FCC9E9EB261000000000000000000000000000000009F9FB3603333
      7FCC9B9BAF640000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000A9A9987AF4F4E4FFFFCC44FFFECB
      43FFECD286FFDADAC9FFD8D8C7FFD6D6C5FFC78B43FFFFE392FFFFD56AFFFFD1
      5DFFFFD15DFFFFD15DFFFFD873FFBE823AE50000000000000000B7B7CF483333
      8ECC1111D8FF33338ECCB7B7CF480000000000000000B7B7CF4833338ECC1111
      D8FF33338ECCB7B7CF4800000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000083A5827D50914EB13B8538C750914EB183A5827D000000000000
      000000000000000000000000000000000000AFAF9E77F5F5E6FFFFCC44FFFFEE
      88FFECD286FFF5F5EEFFF5F5EEFFD6D6C5FFDFB27BFFD99D55FFD2964CFFD99D
      55FFD99D55FFFFE597FFD99D53FFB59E75A8000000000000000033339BCC1111
      D0FF1111D0FF1111D0FF33339BCCB7B7DB48B7B7DB4833339BCC1111D0FF1111
      D0FF1111D0FF33339BCC00000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00006BAF659A31A927DF26C817F623D212FD25C716F630A926DF6BAF659A0000
      000000000000000000000000000000000000B3B3A175F6F6E9FFFFCC44FFFECB
      43FFECD286FFDADAC9FFD8D8C7FFDCDCCCFFD4D4C3FFD3D3C2FFD8D8C8FFCFCF
      BEFFDCA052FFDCA052FFEFD4ABFFB3B3A1750000000000000000B7B7DD483333
      9FCC1111C4FF1111C4FF1111C4FF33339FCC33339FCC1111C4FF1111C4FF1111
      C4FF33339FCCB7B7DD4800000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009BCD
      966939AD2CDF27C616FF22C511FF22C511FF22C511FF22C411FF32AA26DF9BCD
      966900000000000000000000000000000000B6B6A573F7F7EBFFFFCC44FFFFEE
      88FFECD286FFF7F7F1FFF7F7F1FFD6D6C5FFF7F7F1FFF7F7F1FFD1D1C0FFF7F7
      F1FFEEC186FFD6BB8EFFF7F7EBFFB6B6A573000000000000000000000000B7B7
      DE483333A3CC1111B8FF1111B8FF1111B8FF1111B8FF1111B8FF1111B8FF3333
      A3CCB7B7DE480000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000005AB1
      51AE41BF31F622B211FF22B211FF22B211FF22B211FF22B211FF29B019F65AB1
      51AE00000000000000000000000000000000B9B9A772F8F8EEFFFFCC44FFFECB
      43FFECD286FFDADAC9FFD8D8C7FFDDDDCEFFD4D4C3FFD3D3C2FFD9D9CAFFCFCF
      BEFFCECEBDFFCDCDBCFFF8F8EEFFB9B9A7720000000000000000000000000000
      0000B7B7DF483333A7CC1515AFFF1111ACFF1111ACFF1111ACFF3333A7CCB7B7
      DF48000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000000000000044AC
      38C754CB43FD38B327FF27A616FF22A211FF22A211FF22A211FF2BA91AFD44AC
      38C700000000000000000000000000000000BCBCAB70F9F9F1FFFFCC44FFFFEE
      88FFECD286FFF9F9F5FFF9F9F5FFD6D6C5FFF9F9F5FFF9F9F5FFD1D1C0FFF9F9
      F5FFF9F9F5FFCDCDBCFFF9F9F1FFBCBCAB700000000000000000000000000000
      0000B7B7E1483333ABCC2525B4FF1111A2FF1111A2FF1414A5FF3333ABCCB7B7
      E148000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000005DBA
      51AE5ACF49F649C038FF47BE36FF40B72FFF39B028FF38AF27FF46BC36F65DBA
      51AE00000000000000000000000000000000BFBFAE6EFBFBF4FFFFCC44FFFECB
      43FFECD286FFDADAC9FFD8D8C7FFDEDED0FFD4D4C3FFD3D3C2FFDADACCFFCFCF
      BEFFCECEBDFFCDCDBCFFFBFBF4FFBFBFAE6E000000000000000000000000B7B7
      E3483333AFCC5353DBFF2E2EB7FF3D3DC6FF3131BAFF15159FFF1E1EA8FF3333
      AFCCB7B7E3480000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009DD8
      966950C541DF60D74FFF57CE46FF57CE46FF57CE46FF5ED54DFF4DC13DDF9DD8
      966900000000000000000000000000000000C1C1B06DFCFCF7FFFFCC44FFFFEE
      88FFECD286FFFCFCFAFFFCFCFAFFD6D6C5FFFCFCFAFFFCFCFAFFD1D1C0FFFCFC
      FAFFFCFCFAFFCDCDBCFFFCFCF7FFC1C1B06D0000000000000000B7B7E4483333
      B3CC6767EFFF3636BEFF5E5EE6FF3333B3CC3333B3CC4F4FD7FF3636BEFF4545
      CDFF3333B3CCB7B7E44800000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000071C8659A52C942DF66DD55F66BE25AFD65DC54F651C841DF71C8659A0000
      000000000000000000000000000000000000C4C4B36BFDFDF9FFFFCC44FFFECB
      43FFF5CE64FFEBD285FFE9D083FFE7CE81FFE5CC80FFE4CB7EFFE2C97CFFE0C7
      7AFFDFC679FFDEC578FFFDFDF9FFC4C4B36B00000000000000003333B5CC7676
      FEFF4C4CD4FF7272FAFF3333B5CCB7B7E548B7B7E5483333B5CC6262EAFF4C4C
      D4FF5C5CE4FF3333B5CC00000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009EDB96695FC451AE48BB38C75FC451AE9EDB9669000000000000
      000000000000000000000000000000000000C6C6B56AFEFEFCFFFFCC44FFFFEE
      88FFFDCA42FFFCEB85FFFBEA84FFF8C53DFFF6E57FFFF4E37DFFF3C038FFF1E0
      7AFFEFDE78FFEFBC34FFFEFEFCFFC6C6B56A0000000000000000B7B7E6483333
      B8CC7777FFFF3333B8CCB7B7E6480000000000000000B7B7E6483333B8CC7070
      F8FF3333B8CCB7B7E64800000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000C8C8B868FFFFFEFFFFCC44FFFECB
      43FFFDCA42FFFCC941FFFAC73FFFF8C53DFFF6C33CFFF5C23AFFF3C038FFF1BE
      36FFF0BD35FFEFBC34FFFFFFFEFFC8C8B868000000000000000000000000B7B7
      E7483333BBCCB7B7E74800000000000000000000000000000000B7B7E7483333
      BBCCB7B7E7480000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000CACAB967FFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFCACAB9670000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000D8D8CB4DCBCBBB66CBCBBB66CBCB
      BB66CBCBBB66CBCBBB66CBCBBB66CBCBBB66CBCBBB66CBCBBB66CBCBBB66CBCB
      BB66CBCBBB66CBCBBB66CBCBBB66D8D8CB4D0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000001B318FF01B318FF01B318FF01B318FF01B318FF01B318FF0000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FFFFFF95FFFFFFFFFFFF
      FFFFFFFFFF950000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000001B318FF00D012FF01BF1EFF01BF1EFF00D012FF01B318FF0000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000CECECE5F7E7E7EFF7E7E7EFF7E7E
      7EFF7E7E7EFF7E7E7EFF7E7E7EFF7E7E7EFF7E7E7EFFFFFFFFFF4DCA5DFF01B3
      18FFFFFFFFFFC9C9C9FF7E7E7EFFAEAEAE9F0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000001B318FF00D322FF01C62AFF01C62AFF00D322FF01B318FF0000
      0000000000000000000000000000000000000000000099999966CCCCCCFFD1D1
      D1FFD6D6D6FFDBDBDBFFE0E0E0FFE5E5E5FFEAEAEAFFEBEBEBFFE4E4E4FFDEDE
      DEFFD8D8D8FFD1D1D1FF99999966000000007E7E7EFFE5E5E5FFE5E5E5FFE5E5
      E5FFE5E5E5FFE5E5E5FFE5E5E5FFF4F4F4FFFFFFFFFFFFFFFFFF01B318FF00D4
      23FF01B318FFFFFFFFFFF5F5F5FF808080FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000001B318FF00D733FF01CC37FF01CC37FF00D733FF01B318FF0000
      00000000000000000000000000000000000000000000B2B2B24DB2B2B24DB2B2
      B24DB2B2B24DB2B2B24DB2B2B24DB2B2B24DB2B2B24DB2B2B24DB2B2B24DB2B2
      B24DB2B2B24DB2B2B24DB2B2B24D000000007E7E7EFFE5E5E5FFE5E5E5FFE5E5
      E5FFE5E5E5FFE5E5E5FFE5E5E5FFFFFFFFFF01B318FF01B318FF01B318FF00DA
      42FF00DA42FF01B318FFFFFFFFFFCBCBCBFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000001B318FF00DB44FF00D245FF00D245FF00DB44FF01B318FF0000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000001B318FF01B318FF01B318FF01B318FF01B318FF01B318FF0000
      0000000000000000000000000000000000007E7E7EFFE5E5E5FFE5E5E5FFE5E5
      E5FFE5E5E5FFE5E5E5FFE5E5E5FFFFFFFFFF01B318FF00DF61FF00DD5EFF00D9
      59FF00D653FF01D04AFF01B318FFFFFFFFFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000001B318FF01B318FF01B318FF01B3
      18FF01B318FF01B318FF00DE55FF00D853FF00D853FF00DE55FF01B318FF01B3
      18FF01B318FF01B318FF01B318FF01B318FF0000000000000000000000000000
      00000000000001B318FF00D21BFF01BF21FF01BF21FF00D21BFF01B318FF0000
      0000000000000000000000000000000000007E7E7EFFE5E5E5FFE5E5E5FFE5E5
      E5FFE5E5E5FFE5E5E5FFE5E5E5FFFFFFFFFF01B318FF00E479FF00E173FF00DD
      6CFF00D963FF01D358FF01B318FFFFFFFFFF0000000000000000000000000000
      000000000000000000000000000000000000A5805BA6BAA38D73000000000000
      00000000000000000000000000000000000001B318FF00E266FF00E266FF00E2
      66FF00E266FF00E266FF00E266FF00DD63FF00DD63FF00E266FF00E266FF00E2
      66FF00E266FF00E266FF00E266FF01B318FF0000000000000000000000000000
      00000000000001B318FF00D732FF01C730FF01C730FF00D732FF01B318FF0000
      0000000000000000000000000000000000007E7E7EFFE5E5E5FFE5E5E5FFE5E5
      E5FFE5E5E5FFE5E5E5FFE5E5E5FFFFFFFFFF01B318FF01B318FF01B318FF00EE
      9CFF00EE9CFF01B318FFFFFFFFFFCECECEFF0000000000000000000000000000
      000000000000000000000000000000000000B87C3DCCB87C3DCCD0BCA65C0000
      00000000000000000000000000000000000001B318FF00E676FF00E676FF00E6
      76FF00E676FF00E676FF00E676FF00E373FF00E373FF00E676FF00E676FF00E6
      76FF00E676FF00E676FF00E676FF01B318FF00000000000000004CC95CB301B3
      18FF01B318FF01B318FF00DC48FF01CE40FF01CE40FF00DC48FF01B318FF01B3
      18FF01B318FF4CC95CB300000000000000008B8B8BFFF2F2F2FFF2F2F2FFF2F2
      F2FFF2F2F2FFF2F2F2FFF2F2F2FFFAFAFAFFFFFFFFFFFFFFFFFF01B318FF00F4
      BAFF01B318FFFFFFFFFFFBFBFBFF919191FF0000000000000000000000000000
      0000D3A67599C38746CCC38746CCC38746CCC38746CCFFC538FFC38746CCE5C9
      AC5C0000000000000000000000000000000001B318FF00E987FF00E987FF00E9
      87FF00E987FF00E987FF00E987FF00E784FF00E784FF00E987FF00E987FF00E9
      87FF00E987FF00E987FF00E987FF01B318FF000000000000000001B318FF00E1
      5FFF00E15FFF00E15FFF00E15FFF00D653FF00D653FF00E15FFF00E15FFF00E1
      5FFF00E15FFF01B318FF00000000000000008B8B8BFFF2F2F2FFF2F2F2FFF2F2
      F2FFF2F2F2FFF2F2F2FFF2F2F2FFF2F2F2FFF2F2F2FFFFFFFFFF4DCA5DFF01B3
      18FFFFFFFFFFFBFBFBFFF3F3F3FF8D8D8DFF0000000000000000000000000000
      0000CF934FCCFFE392FFFFD56AFFFFD15DFFFFD15DFFFFD15DFFFFD873FFCF93
      4FCC0000000000000000000000000000000001B318FF00ED98FF00ED98FF00ED
      98FF00ED98FF00ED98FF00ED98FF00EC96FF00EC96FF00ED98FF00ED98FF00ED
      98FF00ED98FF00ED98FF00ED98FF01B318FF00000000000000000000000001B3
      18FF00E676FF00E676FF00E676FF00DC67FF00DC67FF00E676FF00E676FF00E6
      76FF01B318FF0000000000000000000000008B8B8BFFF2F2F2FFF2F2F2FFF2F2
      F2FFF2F2F2FFF2F2F2FFF2F2F2FFF2F2F2FFF3F3F3FFFAFAFAFFFFFFFFFFFFFF
      FFFFFBFBFBFFF3F3F3FFF2F2F2FF8B8B8BFF0000000000000000000000000000
      0000E2B58199DB9F57CCDB9F57CCDB9F57CCDB9F57CCFFE597FFDB9F57CCEED2
      B35C0000000000000000000000000000000001B318FF01B318FF01B318FF01B3
      18FF01B318FF01B318FF00F1A9FF00F1A9FF00F1A9FF00F1A9FF01B318FF01B3
      18FF01B318FF01B318FF01B318FF01B318FF0000000000000000000000000000
      000001B318FF00EB8EFF00EB8EFF00E47EFF00E47EFF00EB8EFF00EB8EFF01B3
      18FF000000000000000000000000000000008B8B8BFFF2F2F2FFF2F2F2FFF2F2
      F2FFF2F2F2FFF2F2F2FFF2F2F2FFF2F2F2FFF4F4F4FFF6F6F6FFF7F7F7FFF6F6
      F6FFF4F4F4FFF2F2F2FFF2F2F2FF8B8B8BFF0000000000000000000000000000
      000000000000000000000000000000000000E5A95FCCE5A95FCCF3D8B65C0000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000001B318FF00F4BAFF00F4BAFF00F4BAFF00F4BAFF01B318FF0000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000001B318FF00F0A5FF00EA96FF00EA96FF00F0A5FF01B318FF0000
      000000000000000000000000000000000000838383FFF2F2F2FFF2F2F2FFF2F2
      F2FFF2F2F2FFF2F2F2FFF2F2F2FFF4F4F4FFF5F5F5FFF7F7F7FFF6F6F6FFF4F4
      F4FFF2F2F2FFF2F2F2FFF2F2F2FF838383FF0000000000000000000000000000
      000000000000000000000000000000000000F0C38B99F6DBB95C000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000001B318FF00F8CBFF00F8CBFF00F8CBFF00F8CBFF01B318FF0000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000001B318FF00F1AFFF00F1AFFF01B318FF000000000000
      000000000000000000000000000000000000838283FF8A888AFF8A888AFFA0A0
      A0FF8A888AFF8C8A8CFF959495FFA7A5A7FFB2B1B2FFAEACAEFF9D9C9DFF908E
      90FF8A888AFF8A888AFF8A888AFF838283FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000001B318FF00FBDBFF00FBDBFF00FBDBFF00FBDBFF01B318FF0000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000001B318FF01B318FF00000000000000000000
      000000000000000000000000000000000000ADA9ADFF2322EFFFA7A7A7FF23EE
      EFFFA7A7A7FF24CF66FFB8B4B8FFC1BEC1FFC3C0C3FFBBB8BBFFB2AEB2FFAEAA
      AEFFADA9ADFFEFEEEFFFEFEEEFFFADA9ADFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000001B318FF00FFECFF00FFECFF00FFECFF00FFECFF01B318FF0000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000BABABA7E666666FF666666FF9999
      99FF666666FF686868FF6C6C6CFF6F6F6FFF6E6E6EFF6A6A6AFF676767FF6666
      66FF666666FF666666FF666666FFA0A0A0B10000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000001B318FF01B318FF01B318FF01B318FF01B318FF01B318FF0000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000424D3E000000000000003E000000
      2800000040000000200000000100010000000000000100000000000000000000
      000000000000000000000000FFFFFF00FFFFFFF3FFFF0000FFFF0000FFFF0000
      FFFF0000E3C70000FFFF0000C1830000F83F0000C0030000F01F0000C0030000
      E00F0000E0070000E00F0000F00F0000E00F0000F00F0000E00F0000E0070000
      E00F0000C0030000F01F0000C0030000F83F0000C1830000FFFF0000E3C70000
      FFFF0000FFFF0000FFFF0000FFFF0000F81FFFFFFF87FFFFF81FFFFF0000FFFF
      F81F80010000FFFFF81F80010000FFFFF81FF81F0000FFFF0000F81F0000FF3F
      0000F81F0000FF1F0000C0030000F00F0000C0030000F00F0000E0070000F00F
      0000F00F0000FF1FF81FF81F0000FF3FF81FFC3F0000FFFFF81FFE7F0000FFFF
      F81FFFFF0000FFFFF81FFFFFFFFFFFFF00000000000000000000000000000000
      000000000000}
  end
  object PopupMenu1: TPopupMenu
    Left = 664
    Top = 384
    object Copiar1: TMenuItem
      Caption = 'Copiar'
      ShortCut = 16451
      OnClick = Copiar1Click
    end
    object Colar1: TMenuItem
      Caption = 'Colar'
      ShortCut = 16470
      OnClick = Colar1Click
    end
  end
end