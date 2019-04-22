#include "account.h"

namespace Accounts {

Account::Account()
{

}

QString Account::getFirstName() const
{
    return firstName;
}

void Account::setFirstName(const QString &value)
{
    firstName = value;
}

QString Account::getLastName() const
{
    return lastName;
}

void Account::setLastName(const QString &value)
{
    lastName = value;
}

QString Account::getEmail() const
{
    return email;
}

void Account::setEmail(const QString &value)
{
    email = value;
}

void Account::setPassword(const QString &value)
{
    password = value;
}

QString Account::getMailingAddress() const
{
    return mailingAddress;
}

void Account::setMailingAddress(const QString &value)
{
    mailingAddress = value;
}

QString Account::getPhysicalAddress() const
{
    return physicalAddress;
}

void Account::setPhysicalAddress(const QString &value)
{
    physicalAddress = value;
}

QString Account::getPhoneNumber() const
{
    return phoneNumber;
}

void Account::setPhoneNumber(const QString &value)
{
    phoneNumber = value;
}

qint64 Account::getAccountID() const
{
    return accountID;
}

void Account::setAccountID(const qint64 &value)
{
    accountID = value;
}

bool Account::matchPassword(const QString &value)
{
    return value == password;
}

} // namespace Accounts
