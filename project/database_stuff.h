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
/*Account database functions*/
bool createAccount(const QString& firstName,const QString& lastName,
                   const QString& email,const QString& username,const QString& password,
                   const QString& mailingAddress,const QString& physicalAddress,const QString& phoneNumber);

QString aGetFName(const QString& accountID);
QString aGetLName(const QString& accountID);
QString aGetEMail (const QString& accountID);
QString aGetMAddress(const QString& accountID);
QString aGetPAddress(const QString& accountID);
QString aGetPNumber(const QString& accountID);


QString aSetFName(const QString& accountID,const QString& valueToSet);
QString aSetLName(const QString& accountID,const QString& valueToSet);
QString aSetEMail (const QString& accountID,const QString& valueToSet);
QString aSetMAddress(const QString& accountID,const QString& valueToSet);
QString aSetPAddress(const QString& accountID,const QString& valueToSet);
QString aSetPNumber(const QString& accountID,const QString& valueToSet);
QString aSetPassword(const QString& accountID,const QString& valueToSet);


/*Request database functions.*/
QString rGetEFLag(const QString& requestID);
QString rGetServiceType(const QString& requestID);
QString rGetDateRequested(const QString& requestID);
QString rGetDateCompleted(const QString& requestID);
QString rGetStatus(const QString& requestID);
QString rGetNotes(const QString& requestID);
QString rGetProvider(const QString& requestID);
QString rGetProviderContact(const QString& requestID);

/*Service Provider database functions*/
bool createServiceProvider(const QString& accountID,const QString& SPPhone,
                           const QString& SPEmail,const QString& SPWebsite,
                           const QString& SPNormalHours,const QString& SPEHours,
                           const QString& SPServicesProvided,const QString& SPHourlyRate,
                           const QString& SPBaseRate,const QString& SPLocationKey);
//These getter functions can possibly be used from other account types
//ProviderID is just the accountID of the provider in question
QString spGetPhone(const QString& ProviderID);
QString spGetEmail(const QString& ProviderID);
QString spGetWebsite(const QString& ProviderID);
QString spGetHours(const QString& ProviderID);
QString spGetEHours(const QString& ProviderID);
QString spGetServicesProvided(const QString& ProviderID);
QString spGetHourlyRate(const QString& ProviderID);
QString spGetBaseRate(const QString& ProviderID);
QString spGetLocationKeys(const QString& ProviderID);

//These can only be used by the provider themselves!
//So we can use their accountID
bool spSetPhone(const QString& accountID, const QString& valueToSet);
bool spSetEmail(const QString& accountID, const QString& valueToSet);
bool spSetWebsite(const QString& accountID, const QString& valueToSet);
bool spSetHours(const QString& accountID, const QString& valueToSet);
bool spSetEHours(const QString& accountID, const QString& valueToSet);
bool spSetServices(const QString& accountID, const QString& valueToSet);
bool spAddServices(const QString& accountID, const QString& valueToSet);
bool spSetHourlyRate(const QString& accountID, const QString& valueToSet);
bool spSetBaseRate(const QString& accountID, const QString& valueToSet);
bool spSetLocationKey(const QString& accountID, const QString& valueToSet);
bool spAddLocationKey(const QString& accountID, const QString& valueToSet);
//viewRequests
bool spProcessRequest(const QString& accountID, const QString& requestID);
bool spCreateAClaim(const QString& accountID, const QString& requestID, const QString& invoice);
/*Tenant database functions*/
bool createTenant(const QString& accountID,const QString& primaryLocation,const QString& locationKey);
bool tSetLocationKey(const QString& accountID,const QString& locationKey);
QString tGetLocation(const QString& accountID);//returns the location based on the location key!
bool tMakeRequest(const QString& accountID, const QString& eFlag, const QString& serviceType, const QString& notes);
bool tCancelRequest(const QString& accountID, const QString& requestID);
//view requests



/*Landlord database functions*/
bool createLandlord(const QString& accountID, const QString& LLPhone,
                    const QString& LLEmail, const QString& LLWebsite);
bool llAddLocation(const QString& accountID, const QString& locHours,
                   const QString& locAddress, const QString& locDays,
                   const QString& locPhone, const QString& locEmail,
                   const QString& locWebsite);

//view request
bool llAcceptRequest(const QString& accountID, const QString& requestID);
bool llDenyRequest(const QString& accountID, const QString& requestID);
bool llSetPhone(const QString& accountID, const QString& valueToSet);
QString llGetPhone(const QString& accountID);
QString llGetLocationInfo(const QString& accountID, const QString& locationID);
QString llGetLocationLink(const QString& accountID, const QString& locationID);
QString llGetAllLocations(const QString& accountID);
QString llPayClaim(const QString& claimID);

//Service Provider, Tenant, and Landlord want to view all their requests!

QString spGetAllRequests(const QString& providerAccountID);
QString llGetAllRequests(const QString& landlordAccountID);
QString tGetAllRequests(const QString& tenantAccountID);

/*Claim database functions*/
QString getClaimID(const QString& requestID);
QString getClaimInvoice(const QString& claimID);
QString getClaimProvider(const QString& claimID);
QString getClaimFilledTime(const QString& claimID);
QString getClaimPaidTime(const QString& claimID);
QString getClaimStatus(const QString& claimID);
QString setModifyClaimInvoice(const QString& claimID, const QString& valueToSet);



#endif // DATABASE_STUFF_H
