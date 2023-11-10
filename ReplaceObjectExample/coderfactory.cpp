#include "coderfactory.h"
#include "Base64Coder.h"
#include "FlipCoder.h"
#include "InvertCaseCoder.h"
#include "OTPCoder.h"
#include "CompositeCoder.h"

StringCoder* CoderFactory::create(CoderComponent type){
    StringCoder* coder = nullptr;
    switch (type) {
    case CoderComponent::BASE64:
        coder = new Base64Coder();
        break;
    case CoderComponent::FLIP:
        coder = new FlipCoder();
        break;
    case CoderComponent::INVERTCASE:
        coder = new InvertCaseCoder();
        break;
    case CoderComponent::OTP:
        coder = new OTPCoder();
        break;
    case CoderComponent::COMPOSITE:
        coder = new CompositeCoder();
        break;
    default:
        // Handle the default case, if needed
        break;
    }
    return coder;
}
