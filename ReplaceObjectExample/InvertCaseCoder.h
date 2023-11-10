#ifndef INVERTCASECODER_H
#define INVERTCASECODER_H

#include "StringCoder.h"
#include <QString>

class InvertCaseCoder: public StringCoder
{
public:
    QString encode(const QString) override;
    QString decode(const QString) override;
    QString getType() override;
    void add(StringCoder* coder) override;
};

#endif // INVERTCASECODER_H
