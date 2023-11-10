#ifndef CODER_FACTORY_H
#define CODER_FACTORY_H

#include "StringCoder.h"
#include <list>  // Include the necessary header for std::list

enum class CoderComponent {
    FLIP,
    INVERTCASE,
    OTP,
    BASE64,
    COMPOSITE
};

class CoderFactory {
public:
    StringCoder* create(CoderComponent type);

private:

};

#endif // CODER_FACTORY_H
