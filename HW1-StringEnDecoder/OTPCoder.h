#ifndef OTPCODER_H
#define OTPCODER_H

#include <QString>

class OTPCoder
{
public:    
    OTPCoder(); // a constructor
    QString encode(const QString);
    // accepts a QString and returns result in a QString
    QString decode(const QString);
    // accepts a QString and returns result in a QString
};

#endif // OTPCODER_H
