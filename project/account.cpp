#include "account.h"

namespace Accounts {

Account::Account()
{

}

QString Account::getFirstName() const
{
    return m_firstName;
}

void Account::setFirstName(const QString &value)
{
    m_firstName = value;
}

QString Account::getLastName() const
{
    return m_lastName;
}

void Account::setLastName(const QString &value)
{
    m_lastName = value;
}

QString Account::getEmail() const
{
    return m_email;
}

void Account::setEmail(const QString &value)
{
    m_email = value;
}

void Account::setPassword(const QString &value)
{
    m_password = value;
}

QString Account::getMailingAddress() const
{
    return m_mailingAddress;
}

void Account::setMailingAddress(const QString &value)
{
    m_mailingAddress = value;
}

QString Account::getPhysicalAddress() const
{
    return m_physicalAddress;
}

void Account::setPhysicalAddress(const QString &value)
{
    m_physicalAddress = value;
}

QString Account::getPhoneNumber() const
{
    return m_phoneNumber;
}

void Account::setPhoneNumber(const QString &value)
{
    m_phoneNumber = value;
}

qint64 Account::getAccountID() const
{
    return m_accountID;
}

void Account::setAccountID(const qint64 &value)
{
    m_accountID = value;
}

bool Account::matchPassword(const QString &value)
{
    return value == m_password;
}

Acct_type Account::getAcct_type() const
{
    return m_acct_type;
}

QString Account::getUsername() const
{
    return m_username;
}

void Account::setUsername(const QString &username)
{
    m_username = username;
}

} // namespace Accounts
