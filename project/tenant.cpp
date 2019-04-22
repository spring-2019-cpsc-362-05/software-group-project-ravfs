#include "tenant.h"

namespace Accounts {

Tenant::Tenant()
{

}

void Tenant::setLocation(const QString &address)
{
    primaryLocation = address;
}

QString Tenant::getLocation() const
{
    return primaryLocation;
}

} // namespace Accounts
