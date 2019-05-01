#include "landlord.h"

namespace Accounts {

Landlord::Landlord(const QString& firstName, const QString& lastName,
                   const QString& email, const QString& username, const QString& password,
                   const QString& mailingAddress, const QString& physicalAddress,
                   const QString& phoneNumber, qint64 accountID, Acct_type acct_type,
                   const QString& publicPhone, const QString& publicEmail,
                   const QString& publicWebsite, const std::vector<QString>& locationsOwned)
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
    m_publicPhone = publicPhone;
    m_publicEmail = publicEmail;
    m_publicWebsite = publicWebsite;
    m_locationsOwned = locationsOwned;

}

QString Landlord::getPublicPhone() const
{
    return m_publicPhone;
}

void Landlord::setPublicPhone(const QString &value)
{
    m_publicPhone = value;
}

QString Landlord::getPublicEmail() const
{
    return m_publicEmail;
}

void Landlord::setPublicEmail(const QString &value)
{
    m_publicEmail = value;
}

QString Landlord::getPublicWebsite() const
{
    return m_publicWebsite;
}

void Landlord::setPublicWebsite(const QString &value)
{
    m_publicWebsite = value;
}

std::vector<QString> Landlord::getLocationsOwned() const
{
    return m_locationsOwned;
}

//void Landlord::setLocationsOwned(const std::vector<QString> &value)
//{
//    locationsOwned = value;
//}

} // namespace Accounts
