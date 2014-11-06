#ifndef DEVICE_H
#define DEVICE_H

#include <QObject>
#include <QString>

#include "itransport.h"

    /**
     * @class Device
     * @brief Devices class base
     *
     *
     * @author tony
     * @date 3-11-2014
     */

class QString;

class Device
{
public:
    Device();
    virtual QString getName() const;
    virtual void setName(const QString &value);

    virtual ITransport *getTransport() const;
    virtual void setTransport(ITransport *value);

    void setIdProduct(unsigned short value);
    void setIdVendor(unsigned short value);

protected:
    ITransport * transport; /**< Pointer to generic transport */
    QString name; /**< Device name */
};

#endif // DEVICE_H
