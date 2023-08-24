#ifndef FLIPCODER_H
#define FLIPCODER_H

#include <QString>

class FlipCoder
{
public:
    FlipCoder();

    QString encode(const QString);
    // accepts a QString and returns result in a QString
    QString decode(const QString);
    // accepts a QString and returns result in a QString
};

#endif // FLIPCODER_H
