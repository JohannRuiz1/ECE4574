#include "CompositeCoder.h"

void CompositeCoder::add(StringCoder* coder) {
    childCoders.push_back(coder);
}

QString CompositeCoder::encode(const QString input) {
    QString output = input;
    for (StringCoder* coder : childCoders) {
        output = coder->encode(output);
    }
    return output;
}

QString CompositeCoder::decode(const QString input) {
    QString output = input;
    // Decode in reverse order
    for (auto it = childCoders.rbegin(); it != childCoders.rend(); ++it) {
        output = (*it)->decode(output);
    }
    return output;
}

QString CompositeCoder::getType() {
    QString output = "";
    for (int i = 0; i < childCoders.size(); i++){
        output += childCoders[i]->getType();
        if(i != childCoders.size() - 1){
            output += ", ";
        }
    }
    return output;
}
