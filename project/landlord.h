#ifndef LANDLORD_H
#define LANDLORD_H

#include "account.h"

#include <QString>

#include <vector>

namespace Accounts {

class Landlord : public Accounts::Account
{
public:
    Landlord();

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
    QString publicPhone;
    QString publicEmail;
    QString publicWebsite;
    std::vector<QString> locationsOwned;
};

} // namespace Accounts

#endif // LANDLORD_H
