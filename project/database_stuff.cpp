#include "database_stuff.h"
#include "account.h"
#include "tenant.h"
#include "landlord.h"
#include "serviceprovider.h"

bool DB_stuff::account_exists(const QString& username, const QString& password)
{
    // TODO
    (void)username;
    (void)password;
    return true;
}

std::unique_ptr<Accounts::Account> DB_stuff::get_account(const QString& username, const QString& password)
{
    // TODO
    // get account from database
    return std::unique_ptr<Accounts::Account>(
                new Accounts::Tenant("Franky", "Daniel", "fpdaniel2@csu.fullerton.edu",
                                     username, password, "1234 Fake Mailing Address",
                                     "1234 Fake Phys Address", "(909) 555-0121", 12345,
                                     Accounts::Acct_type::tenant, "My Prim. Location", "My LL Key"));
}
