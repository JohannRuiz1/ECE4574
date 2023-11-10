#ifndef STRINGCODER_H
#define STRINGCODER_H
#include <QString>


class StringCoder {
public:
    virtual QString encode(const QString input) = 0;
    virtual QString decode(const QString input) = 0;
    virtual QString getType() = 0;
    virtual void add(StringCoder* coder) = 0;


};

#endif // STRINGCODER_H
