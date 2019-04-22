#include "landlord.h"

namespace Accounts {

Landlord::Landlord()
{

}

QString Landlord::getPublicPhone() const
{
    return publicPhone;
}

void Landlord::setPublicPhone(const QString &value)
{
    publicPhone = value;
}

QString Landlord::getPublicEmail() const
{
    return publicEmail;
}

void Landlord::setPublicEmail(const QString &value)
{
    publicEmail = value;
}

QString Landlord::getPublicWebsite() const
{
    return publicWebsite;
}

void Landlord::setPublicWebsite(const QString &value)
{
    publicWebsite = value;
}

std::vector<QString> Landlord::getLocationsOwned() const
{
    return locationsOwned;
}

//void Landlord::setLocationsOwned(const std::vector<QString> &value)
//{
//    locationsOwned = value;
//}

} // namespace Accounts
