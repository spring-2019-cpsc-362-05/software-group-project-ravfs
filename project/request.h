#ifndef REQUEST_H
#define REQUEST_H

#include <QtGlobal>
#include <QString>
#include <QDateTime>

namespace Requests {

class Request
{
public:
    Request();

    qint32 requestID() const;
    void setRequestID(const qint32 &requestID);

    qint32 tenantID() const;
    void setTenantID(const qint32 &tenantID);

    bool is_emergency() const;
    void setIs_emergency(bool is_emergency);

    QString kindOfService() const;
    void setKindOfService(const QString &kindOfService);

    QDateTime timeRequested() const;
    void setTimeRequested(const QDateTime &timeRequested);

    bool status() const;
    void setStatus(bool status);

    bool landlordStatus() const;
    void setLandlordStatus(bool landlordStatus);

    QDateTime timeCompleted() const;
    void setTimeCompleted(const QDateTime &timeCompleted);

    qint32 assignedProvider() const;
    void setAssignedProvider(const qint32 &assignedProvider);

    QString notes() const;
    void setNotes(const QString &notes);

private:
    qint32 m_requestID;
    qint32 m_tenantID;
    bool m_is_emergency;
    QString m_kindOfService;
    QDateTime m_timeRequested;
    bool m_status; // true if completed, false otherwise
    bool m_landlordStatus; // true if landlord will pay, false otherwise
    QDateTime m_timeCompleted;
    qint32 m_assignedProvider;
    QString m_notes;
};

} // namespace Requests

#endif // REQUEST_H
