#ifndef SERVICEPROVIDER_H
#define SERVICEPROVIDER_H

#include "account.h"

#include <QString>

#include <vector>

namespace Accounts {

class ServiceProvider : public Accounts::Account
{
public:
    ServiceProvider();

    QString getPublicPhone() const;
    void setPublicPhone(const QString &value);

    QString getPublicEmail() const;
    void setPublicEmail(const QString &value);

    QString getPublicWebsite() const;
    void setPublicWebsite(const QString &value);

    std::vector<QString> getNormalHours() const;
    void setNormalHours(const std::vector<QString> &value);

    std::vector<QString> getEmergencyHours() const;
    void setEmergencyHours(const std::vector<QString> &value);

    std::vector<QString> getServicesProvided() const;
    void setServicesProvided(const std::vector<QString> &value);

    qreal getHourRate() const;
    void setHourRate(const qreal &value);

    qreal getBaseRate() const;
    void setBaseRate(const qreal &value);

    QString getLandlordKey() const;
    void setLandlordKey(const QString &value);

private:
    QString publicPhone;
    QString publicEmail;
    QString publicWebsite;
    std::vector<QString> normalHours;
    std::vector<QString> emergencyHours;
    std::vector<QString> servicesProvided;
    qreal hourRate;
    qreal baseRate;
    QString landlordKey;
};

} // namespace Accounts

#endif // SERVICEPROVIDER_H
