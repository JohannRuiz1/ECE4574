#ifndef OTPCODER_H
#define OTPCODER_H

#include "StringCoder.h"
#include <QString>

class OTPCoder: public StringCoder
{
public:
    QString encode(const QString) override;
    QString decode(const QString) override;
    QString getType() override;
    void add(StringCoder* coder) override;

};

#endif // OTPCODER_H
