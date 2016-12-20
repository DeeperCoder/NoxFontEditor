#ifndef NOXFONTFILE_H
#define NOXFONTFILE_H
#include "noxsymbol.h"
#include "qstring.h"
#include "QFile"

// First 4 bytes of the correct nox font file
const QByteArray NoxFontFileSign_C = "tNoF";

//This is class for work with Nox Font Files.
//It provides open, read, and modify font files

struct ListOfSymbols{int Indent; uchar FirstSymbol; uchar LastSymbol;}; //

class NoxFontFile
{
private:
    QFile FontFile; //
    QString FileName; // File Name of the Nox Font File
    int FirstSymbolASCII; // First symbol in the font file (ASCII)
    int LastSymbolASCII; // Last symbol in the font file (ASCII)
    int SymbolHeight; //
    int SymbolNumberOfBytes; // Bytes contained in one symbol (with relative length)
    int SymbolSizeType;
    QString SymbolSizeTypeName;
    // 8 - for small fonts, 16 - for middle, 24 - large
    // Based on the Symbol Width
    int NumberOfLists; // The number of lists
    int DataStartPosition; // The start position of symbols data

    std::vector<ListOfSymbols> Lists;
    std::vector<NoxSymbol> Symbols;

    int GetSymbolHeight();
    int GetNumberOfLists();
    int GetSymbolNumberOfBytes();
    int GetSymbolSizeType();
    QString GetSymbolSizeTypeName(int SymbolSizeType);
    std::vector<ListOfSymbols> GetLists(int N);
    std::vector<NoxSymbol> GetSymbols();
public:
    NoxFontFile(QString FileName);

//signals:

//public slots:
};

#endif // NOXFONTFILE_H
