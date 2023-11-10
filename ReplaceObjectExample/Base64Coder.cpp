#include "Base64Coder.h"
#include <QEventLoop>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QSslConfiguration>
#include <QEventLoop>
#include <QJsonDocument>
#include <QJsonObject>


QString Base64Coder::encode(const QString in)
{
    QString fixedIn = QString(in);
    fixedIn.replace(QString(" "), QString("%20"));
    /* < your code here to create the proper urlstring > */
    QNetworkAccessManager* networkManager = new QNetworkAccessManager;

    QNetworkRequest request(QUrl("https://networkcalc.com/api/encoder/"+fixedIn+"?encoding=base64"));

    QSslConfiguration sslConfig = request.sslConfiguration();
    sslConfig.setPeerVerifyMode(QSslSocket::VerifyNone);
    request.setSslConfiguration(sslConfig);

    QNetworkReply* reply = networkManager->get(request);

    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished,
                     &loop, &QEventLoop::quit);

    loop.exec(); //exec will delay execution until the signal has arrived
    QString result;

    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        result = QString(responseData);
    } else {
        result = "Error: " + reply->errorString();
    }

    // Clean up and delete the reply object
    reply->deleteLater();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(result.toUtf8());
    QJsonObject jsonObj = jsonDoc.object();

    QString encoded = jsonObj.value("encoded").toString();

    return encoded;
}

QString Base64Coder::decode(const QString in)
{
    QString fixedIn = QString(in);
    //fixedIn.replace(QString(" "), QString("%20"));
    /* < your code here to create the proper urlstring > */
    QNetworkAccessManager networkManager;


    QNetworkRequest request(QUrl("https://networkcalc.com/api/encoder/"+fixedIn+"?encoding=base64&decode=true"));

    QSslConfiguration sslConfig = request.sslConfiguration();
    sslConfig.setPeerVerifyMode(QSslSocket::VerifyNone);
    request.setSslConfiguration(sslConfig);

    QNetworkReply* reply = networkManager.get(request);

    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished,
                     &loop, &QEventLoop::quit);

    loop.exec(); //exec will delay execution until the signal has arrived
    QString result;

    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        result = QString(responseData);
    } else {
        result = "Error: " + reply->errorString();
    }

    // Clean up and delete the reply object
    reply->deleteLater();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(result.toUtf8());
    QJsonObject jsonObj = jsonDoc.object();

    QString decoded = jsonObj.value("decoded").toString();

    return decoded;
}

QString Base64Coder::getType(){
    return "Base64";
}

void Base64Coder::add(StringCoder* coder) {
}



