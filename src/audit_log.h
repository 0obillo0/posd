
#ifndef AUDIT_LOG_H
#define AUDIT_LOG_H

#include<string>
#include"observer.h"
using namespace std;

class AuditLog : public Observer{
public:
    void update(const string& event, const string& commandName) override; 
};

#endif