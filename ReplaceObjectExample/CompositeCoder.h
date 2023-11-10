#ifndef COMPOSITECODER_H
#define COMPOSITECODER_H

#include "StringCoder.h"
#include <QString>

class CompositeCoder: public StringCoder
{
public:
    QString encode(const QString) override;
    QString decode(const QString) override;
    QString getType() override;
    void add(StringCoder* coder) override;
private:
    std::vector<StringCoder*> childCoders;

};

#endif // COMPOSITECODER_H
