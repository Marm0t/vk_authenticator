#ifndef VKAUTHENTICATOR_H
#define VKAUTHENTICATOR_H

#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QRegExp>
#include <QUrlQuery>
#include <QMessageBox>
#include <QDialog>
#include <QPair>
#include <QLineEdit>

class UserPassDialog : public QDialog
{
    Q_OBJECT
public:
    UserPassDialog(QWidget *parent = 0);
    ~UserPassDialog();

    const QString& getUsername() ;
    const QString& getPassword() ;

private:
    QLineEdit *_usernameLineEdit;
    QLineEdit *_passLineEdit;
    QString _username;
    QString _password;
};



class VkAuthenticator : public QObject
{
Q_OBJECT

    public:
    enum VkAuthState_t
    {
        NotSet = 0,
        AuthorizeRerquestSent,
        CredentialsSent,
        GrantPermissionSent,
        TokenReceived,
        Error

    };

    VkAuthenticator(QString appId,
                    QString scope="notify,friends,photos,audio,video,docs,notes,pages,status,wall,groups,messages");

    private:
        QString _appId;
        QString _scope;
        QNetworkAccessManager _netMgr;
        VkAuthState_t _state;
        QString _errorMessage;
        QString _token;
        void emitError(QString message);
        void setState(VkAuthState_t newState){qDebug()<<"State changed from "<<_state<<" to "<<newState; _state = newState;}

    signals:
        void stateChanged(VkAuthState_t newState);
        void error(QString err);

    public slots:
        void redirectedSLot(QUrl url);
        void authenticate();

    private slots:
        void errorOccured(QNetworkReply::NetworkError err);
        void postCredentials(QByteArray &data);
        void messageReceived(QNetworkReply* reply);
};


#endif // VKAUTHENTICATOR_H

