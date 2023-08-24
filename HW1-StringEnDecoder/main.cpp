#include <QCoreApplication>
#include <QDebug>
#include <QTextStream>
#include <iostream>

#include "FlipCoder.h"
#include "OTPCoder.h"
#include "InvertCaseCoder.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextStream stream(stdin);
    QString input;

    std::cout << "Enter the string to be encoded: ";
    stream.readLineInto(&input);

    std::cout << "Input: <" << input.length() << ">" << "[" << input.toStdString() << "]" << std::endl << std::endl;


    FlipCoder flipCoder;
    OTPCoder otpCoder;
    InvertCaseCoder inverterCoder;


    std::cout << "Flipped: <" << input.length() << ">" << "[" << flipCoder.encode(input).toStdString() << "]" << std::endl;
    std::cout << "Unflipped: <" << input.length() << ">" << "[" << flipCoder.decode(flipCoder.encode(input)).toStdString() << "]" << std::endl << std::endl;

    std::cout << "OTPed: <" << input.length() << ">" << "[" << otpCoder.encode(input).toStdString() << "]" << std::endl;
    std::cout << "unOPTed: <" << input.length() << ">" << "[" << otpCoder.decode(flipCoder.encode(input)).toStdString() << "]" << std::endl << std::endl;

    std::cout << "inverted: <" << input.length() << ">" << "[" << inverterCoder.encode(input).toStdString() << "]" << std::endl;
    std::cout << "reverted: <" << input.length() << ">" << "[" << inverterCoder.decode(flipCoder.encode(input)).toStdString() << "]" << std::endl << std::endl;

    return a.exec();
}
