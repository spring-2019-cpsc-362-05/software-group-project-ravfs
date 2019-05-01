#include "tenant.h"

namespace Accounts {

Tenant::Tenant(const QString& firstName, const QString& lastName,
               const QString& email, const QString& username, const QString& password,
               const QString& mailingAddress, const QString& physicalAddress,
               const QString& phoneNumber, qint64 accountID, Acct_type acct_type,
               const QString& primaryLocation, const QString& landlordKey)
{
    m_firstName = firstName;
    m_lastName = lastName;
    m_email = email;
    m_username = username;
    m_password = password;
    m_mailingAddress = mailingAddress;
    m_physicalAddress = physicalAddress;
    m_phoneNumber = phoneNumber;
    m_accountID = accountID;
    m_acct_type = acct_type;
    m_primaryLocation = primaryLocation;
    m_landlordKey = landlordKey;
}

void Tenant::setLocation(const QString &address)
{
    m_primaryLocation = address;
}

QString Tenant::getLocation() const
{
    return m_primaryLocation;
}

} // namespace Accounts
