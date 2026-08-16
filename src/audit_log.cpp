#include"audit_log.h"
#include<iostream>

using namespace std;

void AuditLog::update(const string& event, const string& commandName){
    cout << "AuditLog: " << commandName << " " << event << "\n";
}