#include "OTPCoder.h"
#include "OneTimePad.h"


/**
 * @brief OTPCoder::encode
 * OTP encoding adds an offset value to every character, looping
 * to the beginning of printable characters if there's an overflow
 * @param input -  Plaintext string to be encoded
 * @return
 *      Encoded text
 */
QString OTPCoder::encode(const QString input){
    std::string in = input.toStdString();
    std::string out = "";
    size_t otpIndex = 0;
    OneTimePad* pad = OneTimePad::getInstance();
    std::vector<int> otp = pad->getOTP();

    // Loop through every character in the string
    for(size_t i = 0; i < in.length(); i++){
        char currentCharacter  = in.at(i);
        // Nonprintable characters
        if(currentCharacter < 32 || currentCharacter > 126){
            out += currentCharacter;
        }
        // Printable characters (flipped)
        else{
            // Convert into number to check for overflow
            int asciiNum = currentCharacter + otp[otpIndex];
            if(asciiNum > 126){
                currentCharacter = (asciiNum % 126) + 31;
            }
            else{
                currentCharacter = asciiNum;
            }
            out += currentCharacter;
        }
        // Go to next padding index in a circular manner
        otpIndex = (otpIndex + 1) % otp.size();
    }
    return QString::fromStdString(out);
}

/**
 * @brief OTPCoder::decode
 * OTP decoding removes the offset value to every character, looping
 * to the end of printable characters if there's an underflo
 * @param input - Encoded string to be decoded
 * @return
 *      Decoded text
 */
QString OTPCoder::decode(const QString input){
    std::string in = input.toStdString();
    std::string out = "";
    size_t otpIndex = 0;
    OneTimePad* pad = OneTimePad::getInstance();
     std::vector<int> otp = pad->getOTP();

    for(size_t i = 0; i < in.length(); i++){
        char currentCharacter  = in.at(i);
        // Nonprintable characters
        if(currentCharacter < 32 || currentCharacter > 126){
            out += currentCharacter;
        }
        // Printable characters
        else{
            // Convert into number to check for underflow
            int asciiNum = currentCharacter - otp[otpIndex];
            if(asciiNum < 32){
                currentCharacter = 127 - (32 - asciiNum);
            }
            else{
                currentCharacter = asciiNum;
            }
            out += currentCharacter;
        }
        // Go to next padding index in a circular manner
        otpIndex = (otpIndex + 1) % otp.size();
    }
    return QString::fromStdString(out);
}

QString OTPCoder::getType(){
    return "OTP";
}

void OTPCoder::add(StringCoder* coder) {
}
