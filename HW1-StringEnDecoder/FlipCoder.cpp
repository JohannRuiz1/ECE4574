#include "FlipCoder.h"

FlipCoder::FlipCoder()
{

}

QString FlipCoder::encode(const QString input){
    std::string in = input.toStdString();
    std::string out = "";
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

QString FlipCoder::decode(const QString input){
    return encode(input);
}
