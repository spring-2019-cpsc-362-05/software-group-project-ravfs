#ifndef LANDLORD_H
#define LANDLORD_H

#include "account.h"

#include <QString>

#include <vector>

namespace Accounts {

class Landlord : public Accounts::Account
{
public:
    Landlord(const QString& firstName, const QString& lastName,
             const QString& email, const QString& username, const QString& password,
             const QString& mailingAddress, const QString& physicalAddress,
             const QString& phoneNumber, qint64 accountID, Acct_type acct_type,
             const QString& publicPhone, const QString& publicEmail,
             const QString& publicWebsite, const std::vector<QString>& locationsOwned);

    QString getPublicPhone() const;
    void setPublicPhone(const QString &value);

    QString getPublicEmail() const;
    void setPublicEmail(const QString &value);

    QString getPublicWebsite() const;
    void setPublicWebsite(const QString &value);

    std::vector<QString> getLocationsOwned() const;
    //void setLocationsOwned(const std::vector<QString> &value);

    // setLocation()
    // getLocation()
    // getLocationLink()

    // viewRequest()
    // acceptRequest()
    // denyRequest()

private:
    QString m_publicPhone;
    QString m_publicEmail;
    QString m_publicWebsite;
    std::vector<QString> m_locationsOwned;
};

} // namespace Accounts

#endif // LANDLORD_H
