#include "serviceprovider.h"

namespace Accounts {

ServiceProvider::ServiceProvider()
{

}

QString ServiceProvider::getPublicPhone() const
{
    return publicPhone;
}

void ServiceProvider::setPublicPhone(const QString &value)
{
    publicPhone = value;
}

QString ServiceProvider::getPublicEmail() const
{
    return publicEmail;
}

void ServiceProvider::setPublicEmail(const QString &value)
{
    publicEmail = value;
}

QString ServiceProvider::getPublicWebsite() const
{
    return publicWebsite;
}

void ServiceProvider::setPublicWebsite(const QString &value)
{
    publicWebsite = value;
}

std::vector<QString> ServiceProvider::getNormalHours() const
{
    return normalHours;
}

void ServiceProvider::setNormalHours(const std::vector<QString> &value)
{
    normalHours = value;
}

std::vector<QString> ServiceProvider::getEmergencyHours() const
{
    return emergencyHours;
}

void ServiceProvider::setEmergencyHours(const std::vector<QString> &value)
{
    emergencyHours = value;
}

std::vector<QString> ServiceProvider::getServicesProvided() const
{
    return servicesProvided;
}

void ServiceProvider::setServicesProvided(const std::vector<QString> &value)
{
    servicesProvided = value;
}

qreal ServiceProvider::getHourRate() const
{
    return hourRate;
}

void ServiceProvider::setHourRate(const qreal &value)
{
    hourRate = value;
}

qreal ServiceProvider::getBaseRate() const
{
    return baseRate;
}

void ServiceProvider::setBaseRate(const qreal &value)
{
    baseRate = value;
}

QString ServiceProvider::getLandlordKey() const
{
    return landlordKey;
}

void ServiceProvider::setLandlordKey(const QString &value)
{
    landlordKey = value;
}

} // namespace Accounts
