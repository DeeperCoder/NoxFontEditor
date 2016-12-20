#include "noxfontfile.h"
#include <QFile>

//This is class for work with Nox Font Files.
//It provides open, read, and modify font files

NoxFontFile::NoxFontFile(QString FileName)
{
    FirstSymbolASCII = -1;
    LastSymbolASCII = -1;
    SymbolNumberOfBytes = -1;
    SymbolSizeType = -1;
    NumberOfLists = -1;

    FontFile.setFileName(FileName);
    if (!FontFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug("Cannot open the nox file!");
        return;
    }

    this->FileName = FileName;
    QByteArray NoxFontFileSign("1234", 4);
    FontFile.seek(0);
    NoxFontFileSign = FontFile.read(4);
    if (NoxFontFileSign == NoxFontFileSign_C){
        qDebug("Font File is Correct");
    } else {qDebug("Font file is incorrect!");}

    SymbolHeight = GetSymbolHeight();
    SymbolNumberOfBytes = GetSymbolNumberOfBytes();
    SymbolSizeType = GetSymbolSizeType();
    SymbolSizeTypeName = GetSymbolSizeTypeName(SymbolSizeType);
    NumberOfLists = GetNumberOfLists();
    Lists = GetLists(NumberOfLists);
    FirstSymbolASCII = Lists.front().FirstSymbol;
    LastSymbolASCII = Lists.back().LastSymbol;
    Symbols = GetSymbols();

    FontFile.close();
    qDebug("End");
}

int NoxFontFile::GetSymbolHeight()
{
    FontFile.seek(0x10);
    return *FontFile.read(1);
}

int NoxFontFile::GetNumberOfLists()
{
    FontFile.seek(0x14);
    return *FontFile.read(1);
}

int NoxFontFile::GetSymbolNumberOfBytes()
{
    FontFile.seek(0x18);
    return *FontFile.read(1);
}

int NoxFontFile::GetSymbolSizeType()
{
    FontFile.seek(0xC);
    return *FontFile.read(1);
}

QString NoxFontFile::GetSymbolSizeTypeName(int SymbolSizeType)
{
    QString TypeName;
    switch (SymbolSizeType) {
    case 1:
        TypeName = "Маленькие";
        break;
    case 2:
        TypeName = "Средние";
        break;
    case 3:
        TypeName = "Большие";
        break;
    default:
        TypeName = "---";
        break;
    }
    return TypeName;
}

std::vector<ListOfSymbols> NoxFontFile::GetLists(int N)
{
    std::vector<ListOfSymbols> Lists;
    ListOfSymbols List;
    Lists.resize(N - 1);
    FontFile.seek(0x1C);
    for (int i = 0; i <= N - 1; ++i) {
        List.Indent = *FontFile.read(1);
        FontFile.seek(FontFile.pos() + 3);
        List.FirstSymbol = *FontFile.read(1);
        FontFile.seek(FontFile.pos() + 1);
        List.LastSymbol = *FontFile.read(1);
        FontFile.seek(FontFile.pos() + 1);
        Lists.push_back(List);
    }
    this->DataStartPosition = FontFile.pos();
    return Lists;
}

std::vector<NoxSymbol> NoxFontFile::GetSymbols()
{
    std::vector<NoxSymbol> Symbols;
    NoxSymbol Symbol;
    FontFile.seek(this->DataStartPosition);
    for (int List_Index = 0; List_Index <= NumberOfLists - 1; ++List_Index) {
        uint Symbol_Index = Lists.at(List_Index).FirstSymbol;
        uint Symbol_Index_End = Lists.at(List_Index).LastSymbol;
        for (; Symbol_Index <= Symbol_Index_End; ++Symbol_Index) {
            Symbol.ID = Symbol_Index;
            Symbol.OffSet = FontFile.pos();
            Symbol.Data = FontFile.read(this->SymbolNumberOfBytes);
            Symbol.State = NoxSymbol::Normal;
            Symbols.push_back(Symbol);
        }
    }
    return Symbols;
}


