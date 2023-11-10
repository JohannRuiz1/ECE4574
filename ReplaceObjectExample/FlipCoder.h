#ifndef FLIPCODER_H
#define FLIPCODER_H

#include "StringCoder.h"
#include <QString>

class FlipCoder: public StringCoder
{
public:
    QString encode(const QString) override;
    QString decode(const QString) override;
    QString getType() override;
    void add(StringCoder* coder) override;
};

#endif // FLIPCODER_H
