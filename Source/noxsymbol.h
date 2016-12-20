#ifndef NOXSYMBOL_H
#define NOXSYMBOL_H
#include "qstring.h"

// Nox Symbols difinitions

class NoxSymbol
{
public:
    uchar ID; // The symbol ID, range between 0 and 255
    QByteArray Data; // Contained bytes of symbol
    int OffSet; // OffSet of symbol in the font file
    uchar State; // The State of symbol
    enum State_Enum{Normal = 1, Deleted = 2, ReallyDeleted = 3, Changed = 4}; //
    NoxSymbol();

//public:
//    NoxSymbol();

//signals:

//public slots:
};

#endif // NOXSYMBOL_H
