#ifndef TENANT_H
#define TENANT_H

#include "account.h"

namespace Accounts {

class Tenant : public Accounts::Account
{
public:
    Tenant(const QString& firstName, const QString& lastName,
           const QString& email, const QString& username, const QString& password,
           const QString& mailingAddress, const QString& physicalAddress,
           const QString& phoneNumber, qint64 accountID, Acct_type acct_type,
           const QString& primaryLocation, const QString& landlordKey);

    void setLocation(const QString &address);
    QString getLocation() const;

    // makeRequest()
    // cancelRequest()
    // viewRequest()

    // TODO
    // why is this bool?
    bool setLandlordLink(const QString& link);

private:
    QString m_primaryLocation;
    QString m_landlordKey;
};

} // namespace Accounts

#endif // TENANT_H
