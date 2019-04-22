#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QString>

namespace Accounts {

class Account
{
public:
    Account();

    QString getFirstName() const;
    void setFirstName(const QString &value);

    QString getLastName() const;
    void setLastName(const QString &value);

    QString getEmail() const;
    void setEmail(const QString &value);

    void setPassword(const QString &value);

    QString getMailingAddress() const;
    void setMailingAddress(const QString &value);

    QString getPhysicalAddress() const;
    void setPhysicalAddress(const QString &value);

    QString getPhoneNumber() const;
    void setPhoneNumber(const QString &value);

    qint64 getAccountID() const;
    void setAccountID(const qint64 &value);

    bool matchPassword(const QString &value);

private:
    QString firstName;
    QString lastName;
    QString email;
    QString password;
    QString mailingAddress;
    QString physicalAddress;
    QString phoneNumber;
    qint64 accountID;
};

} // namespace Accounts

#endif // ACCOUNT_H
