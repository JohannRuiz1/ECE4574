#include "FlipCoder.h"

/**
 * @brief FlipCoder::encode
 * Flip encoding takes a printable character and find the character at
 * the opposite of printable character
 * @param input -  Plaintext string to be encoded
 * @return
 *      Encoded text
 */
QString FlipCoder::encode(const QString input){
    std::string in = input.toStdString();
    std::string out = "";
    // Loop through every character in the string
    for(size_t i = 0; i < in.length(); i++){
        char c = in.at(i);
        // Nonprintable characters
        if(c < 32 || c > 126){
            out += c;
        }
        // Printable characters (flipped)
        else{
            out += 126 - (c - 32);
        }
    }
    return QString::fromStdString(out);
}


/**
 * @brief FlipCoder::encode
 * Flip encoding takes a printable character and find the character at
 * the opposite of printable character
 * @param input -  Plaintext string to be encoded
 * @return
 *      Encoded text
 */
QString FlipCoder::decode(const QString input){
    // Encoding and decoding work the same way
    return encode(input);
}

QString FlipCoder::getType(){
    return "Flip";
}

void FlipCoder::add(StringCoder* coder) {
}
