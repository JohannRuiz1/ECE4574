#ifndef BASE64CODER_H
#define BASE64CODER_H

#include "StringCoder.h"
#include <QString>

class Base64Coder: public StringCoder
{
public:
    QString encode(const QString) override;
    QString decode(const QString) override;
    QString getType() override;
    void add(StringCoder* coder) override;
};

#endif // BASE64CODER_H
