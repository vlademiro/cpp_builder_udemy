object DM: TDM
  OldCreateOrder = False
  Height = 412
  Width = 468
  object ConexaoDB: TFDConnection
    Params.Strings = (
      'DriverID=FB'
      'CharacterSet=WIN1252'
      'Database=C:\Estudo\Curso_Udemy\BANCODADOS\PROJETOCURSO.FDB'
      'User_Name=SYSDBA'
      'Password=masterkey')
    Connected = True
    Left = 64
    Top = 64
  end
  object FDPhysFBDriverLink1: TFDPhysFBDriverLink
    VendorLib = 'C:\Program Files (x86)\Firebird\Firebird_2_5\bin\fbclient.dll'
    Left = 168
    Top = 64
  end
  object FDQueryIncluir: TFDQuery
    Connection = ConexaoDB
    SQL.Strings = (
      'insert into cliente (id, nome, endereco, cidade, estado )'
      'values (gen_id(id_cliente,1),:nome,:endereco,:cidade,:estado)')
    Left = 64
    Top = 128
    ParamData = <
      item
        Name = 'NOME'
        DataType = ftString
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'ENDERECO'
        DataType = ftString
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'CIDADE'
        DataType = ftString
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'ESTADO'
        DataType = ftString
        ParamType = ptInput
        Value = Null
      end>
  end
  object DSIncluir: TDataSource
    DataSet = FDQueryIncluir
    Left = 168
    Top = 128
  end
  object FDQueryAlterar: TFDQuery
    Connection = ConexaoDB
    SQL.Strings = (
      
        'update cliente set nome=:nome,endereco=:endereco,cidade=:cidade,' +
        'estado=:estado where id=:id')
    Left = 64
    Top = 184
    ParamData = <
      item
        Name = 'NOME'
        DataType = ftString
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'ENDERECO'
        DataType = ftString
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'CIDADE'
        DataType = ftString
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'ESTADO'
        DataType = ftString
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'ID'
        DataType = ftInteger
        ParamType = ptInput
        Value = Null
      end>
  end
  object FDQueryExcluir: TFDQuery
    Connection = ConexaoDB
    SQL.Strings = (
      'delete from cliente where id=:id')
    Left = 64
    Top = 248
    ParamData = <
      item
        Name = 'ID'
        DataType = ftInteger
        ParamType = ptInput
        Value = Null
      end>
  end
  object FDQueryExibir: TFDQuery
    Connection = ConexaoDB
    SQL.Strings = (
      'select * from cliente')
    Left = 64
    Top = 312
  end
  object DSAlterar: TDataSource
    DataSet = FDQueryAlterar
    Left = 160
    Top = 192
  end
  object DSExcluir: TDataSource
    DataSet = FDQueryExcluir
    Left = 168
    Top = 256
  end
  object DSExibir: TDataSource
    DataSet = FDQueryExibir
    Left = 160
    Top = 312
  end
end
