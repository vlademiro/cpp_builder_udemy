object DM: TDM
  OldCreateOrder = False
  Height = 363
  Width = 438
  object ConexaoDB: TFDConnection
    Params.Strings = (
      'User_Name=sysdba'
      'Database=C:\Estudo\Curso_Udemy\BANCODADOS\PROJETOCURSO.FDB'
      'Password=masterkey'
      'Server=localhost'
      'CharacterSet=WIN1252'
      'DriverID=FB')
    Connected = True
    Left = 40
    Top = 40
  end
  object FDQueryExibir: TFDQuery
    Connection = ConexaoDB
    SQL.Strings = (
      'select * from cliente')
    Left = 40
    Top = 104
  end
  object DSExibir: TDataSource
    DataSet = FDQueryExibir
    Left = 112
    Top = 104
  end
  object FDQueryIncluir: TFDQuery
    Connection = ConexaoDB
    SQL.Strings = (
      'insert into cliente (id, nome, endereco, cidade, estado )'
      'values (gen_id(id_cliente,1),:nome,:endereco,:cidade,:estado)')
    Left = 40
    Top = 160
    ParamData = <
      item
        Name = 'NOME'
        DataType = ftString
        ParamType = ptInput
        Size = 50
        Value = Null
      end
      item
        Name = 'ENDERECO'
        DataType = ftString
        ParamType = ptInput
        Size = 50
      end
      item
        Name = 'CIDADE'
        DataType = ftString
        ParamType = ptInput
        Size = 50
      end
      item
        Name = 'ESTADO'
        DataType = ftString
        ParamType = ptInput
        Size = 2
      end>
  end
  object FDPhysFBDriverLink1: TFDPhysFBDriverLink
    VendorLib = 'C:\Program Files (x86)\Firebird\Firebird_2_5\bin\fbclient.dll'
    Left = 136
    Top = 40
  end
  object DSIncluir: TDataSource
    DataSet = FDQueryIncluir
    Left = 112
    Top = 160
  end
  object FDQueryAlterar: TFDQuery
    Connection = ConexaoDB
    SQL.Strings = (
      
        'update cliente set nome=:nome,endereco=:endereco,cidade=:cidade,' +
        'estado=:estado where id=:id')
    Left = 40
    Top = 224
    ParamData = <
      item
        Name = 'NOME'
        DataType = ftString
        ParamType = ptInput
        Size = 50
        Value = Null
      end
      item
        Name = 'ENDERECO'
        DataType = ftString
        ParamType = ptInput
        Size = 50
      end
      item
        Name = 'CIDADE'
        DataType = ftString
        ParamType = ptInput
        Size = 50
      end
      item
        Name = 'ESTADO'
        DataType = ftString
        ParamType = ptInput
        Size = 2
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
    Left = 40
    Top = 280
    ParamData = <
      item
        Name = 'ID'
        DataType = ftInteger
        ParamType = ptInput
        Value = Null
      end>
  end
  object DSAlterar: TDataSource
    DataSet = FDQueryAlterar
    Left = 112
    Top = 224
  end
  object DSExcluir: TDataSource
    DataSet = FDQueryExcluir
    Left = 112
    Top = 280
  end
end
