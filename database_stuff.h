#ifndef DATABASE_STUFF_H
#define DATABASE_STUFF_H

#include "account.h"
//#include "tenant.h"
//#include "landlord.h"
//#include "serviceprovider.h"

#include <memory>

#include <QString>

namespace DB_stuff {

bool account_exists(const QString& username, const QString& password);

std::unique_ptr<Accounts::Account> get_account(const QString& username, const QString& password);

}

#endif // DATABASE_STUFF_H
