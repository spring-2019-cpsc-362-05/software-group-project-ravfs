#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QString>

namespace Accounts {

enum class Acct_type : int {tenant = 1, landlord, serv_prov};

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

    Acct_type getAcct_type() const;

    QString getUsername() const;
    void setUsername(const QString &value);

protected:
    QString m_firstName;
    QString m_lastName;
    QString m_email;
    QString m_username;
    QString m_password;
    QString m_mailingAddress;
    QString m_physicalAddress;
    QString m_phoneNumber;
    qint64 m_accountID;
    Acct_type m_acct_type;
};

} // namespace Accounts

#endif // ACCOUNT_H
