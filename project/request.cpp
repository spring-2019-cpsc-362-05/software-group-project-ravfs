#include "request.h"

namespace Requests {

Request::Request()
{

}

qint32 Request::requestID() const
{
    return m_requestID;
}

void Request::setRequestID(const qint32 &requestID)
{
    m_requestID = requestID;
}

qint32 Request::tenantID() const
{
    return m_tenantID;
}

void Request::setTenantID(const qint32 &tenantID)
{
    m_tenantID = tenantID;
}

bool Request::is_emergency() const
{
    return m_is_emergency;
}

void Request::setIs_emergency(bool is_emergency)
{
    m_is_emergency = is_emergency;
}

QString Request::kindOfService() const
{
    return m_kindOfService;
}

void Request::setKindOfService(const QString &kindOfService)
{
    m_kindOfService = kindOfService;
}

QDateTime Request::timeRequested() const
{
    return m_timeRequested;
}

void Request::setTimeRequested(const QDateTime &timeRequested)
{
    m_timeRequested = timeRequested;
}

bool Request::status() const
{
    return m_status;
}

void Request::setStatus(bool status)
{
    m_status = status;
}

bool Request::landlordStatus() const
{
    return m_landlordStatus;
}

void Request::setLandlordStatus(bool landlordStatus)
{
    m_landlordStatus = landlordStatus;
}

QDateTime Request::timeCompleted() const
{
    return m_timeCompleted;
}

void Request::setTimeCompleted(const QDateTime &timeCompleted)
{
    m_timeCompleted = timeCompleted;
}

qint32 Request::assignedProvider() const
{
    return m_assignedProvider;
}

void Request::setAssignedProvider(const qint32 &assignedProvider)
{
    m_assignedProvider = assignedProvider;
}

QString Request::notes() const
{
    return m_notes;
}

void Request::setNotes(const QString &notes)
{
    m_notes = notes;
}

} // namespace Requests
