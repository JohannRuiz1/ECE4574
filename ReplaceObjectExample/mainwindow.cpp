#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "OneTimePad.h"
#include "coderfactory.h"

#include <random>
#include <ctime>
#include <vector>
#include <iostream>

// Method header for write string
QString writeString(QString value, QString title, QString end);

void widgetWriteHTMLString(QTextBrowser* textBrowser, const QString codedStr, const QString prefix, const QString suffix);

// Method header for solution
QString processHW1(QString input);



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    CoderFactory cFactory;
    this->coders.push_back(cFactory.create(CoderComponent::FLIP));
    this->coders.push_back(cFactory.create(CoderComponent::INVERTCASE));
    this->coders.push_back(cFactory.create(CoderComponent::OTP));
    this->coders.push_back(cFactory.create(CoderComponent::BASE64));
    this->coders.push_back((cFactory.create(CoderComponent::COMPOSITE)));
    this->coders.back()->add(cFactory.create(CoderComponent::INVERTCASE));
    this->coders.back()->add(cFactory.create(CoderComponent::FLIP));
    this->coders.push_back((cFactory.create(CoderComponent::COMPOSITE)));
    this->coders.back()->add(cFactory.create(CoderComponent::BASE64));
    this->coders.back()->add(cFactory.create(CoderComponent::OTP));
    this->coders.back()->add(cFactory.create(CoderComponent::INVERTCASE));

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_processButton_clicked()
{
    ui->textBrowser->clear();

    QString input = ui->inputWidget->text();

    QString codedstr, decodedstr;

    widgetWriteHTMLString(ui->textBrowser, input, "<b>Input:", "</b><br>");
    for (StringCoder* pCoder : this->coders)
    {
        codedstr = pCoder->encode(input);
        widgetWriteHTMLString(ui->textBrowser, codedstr, QString("<br>") + pCoder->getType() + ":", "<br>");
        decodedstr = pCoder->decode(codedstr);
        widgetWriteHTMLString(ui->textBrowser, decodedstr, "Decoded:", "<br>");
    }

}


void MainWindow::on_otpButton_clicked()
{
    ui->otpInput->clear();
    QString text = "";

    std::mt19937 rng(std::time(0)); // Mersenne Twister 19937 generator seeded with current time

    // Generate a random size between 16 and 32
    std::uniform_int_distribution<int> sizeDistribution(16, 32);
    int arraySize = sizeDistribution(rng);

    // Create a vector of the random size
    std::vector<int> randomArray(arraySize);

    // Fill the array with random values between 0 and 126
    std::uniform_int_distribution<int> valueDistribution(0, 95);
    for (int i = 0; i < arraySize; i++) {
        int randomNumber = valueDistribution(rng);
        randomArray[i] = randomNumber;
        text+=QString::number(randomNumber) + ",";
    }
    OneTimePad* pad = OneTimePad::getInstance();
    pad->regenerateOTP(randomArray);

    ui->otpInput->setText(text);
}


void widgetWriteHTMLString(QTextBrowser* textBrowser, const QString codedStr, const QString prefix, const QString suffix) {
    // Append HTML content to the QTextBrowser
    QString htmlContent = prefix + " &lt;" + QString::number(codedStr.length()) + "&gt;[ " + codedStr.toHtmlEscaped() + " ]" + suffix;
    textBrowser->insertHtml(htmlContent);
}
