#ifndef ALERTSERVICE_H
#define ALERTSERVICE_H

#include <string>

class AlertService
{
public:
    virtual void sendAlert(
        std::string message,
        std::string priority
    ) = 0;

    virtual void retractAlert(
        std::string message
    ) = 0;

    virtual ~AlertService();
};

#endif