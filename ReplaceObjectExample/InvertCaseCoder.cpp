#include "InvertCaseCoder.h"


/**
 * @brief InvertCaseCoder::encode
 * Inverter encoding converts lowercase letters to uppercase and
 * uppercase to lowercase
 * @param input -  Plaintext string to be encoded
 * @return
 *      Encoded text
 */
QString InvertCaseCoder::encode(const QString input){
    std::string in = input.toStdString();
    std::string out = "";
    // Loop through every character in the string
    for(size_t i = 0; i < in.length(); i++){
        char currentCharacter = in.at(i);
        // Uppercase letters
        if(currentCharacter >= 65 && currentCharacter <= 90){
            out += (currentCharacter + 32);
        }
        // Lower characters
        else if (currentCharacter >= 97 && currentCharacter <= 122){
            out += (currentCharacter - 32);
        }
        // Non-alphabetical characters
        else{
            out += currentCharacter;
        }
    }
    return QString::fromStdString(out);
}

/**
 * @brief InvertCaseCoder::decode
 * Inverter decoding converts lowercase letters to uppercase and
 * uppercase to lowercase
 * @param input
 * @return
 *      Decoded text
 */
QString InvertCaseCoder::decode(const QString input){
    // Encoding and decoding work the same way
    return encode(input);
}

QString InvertCaseCoder::getType(){
    return "Invert";
}

void InvertCaseCoder::add(StringCoder* coder) {
}
