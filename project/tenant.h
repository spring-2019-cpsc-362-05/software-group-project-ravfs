#ifndef TENANT_H
#define TENANT_H

#include "account.h"

namespace Accounts {

class Tenant : public Accounts::Account
{
public:
    Tenant();

    void setLocation(const QString &address);
    QString getLocation() const;

    // makeRequest()
    // cancelRequest()
    // viewRequest()

    bool setLandlordLink(const QString &link);

private:
    QString primaryLocation;
    QString landlordKey;
};

} // namespace Accounts

#endif // TENANT_H
