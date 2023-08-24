#ifndef INVERTCASECODER_H
#define INVERTCASECODER_H

#include <QString>

class InvertCaseCoder
{
public:
    InvertCaseCoder();

    QString encode(const QString);
    // accepts a QString and returns result in a QString
    QString decode(const QString);
    // accepts a QString and returns result in a QString
};

#endif // INVERTCASECODER_H
