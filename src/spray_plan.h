#ifndef SPRAY_PLAN
#define SPRAY_PLAN

#include<string>
#include<memory>
#include<vector>
#include"spray_plan_prototype.h"
#include"fertilizer.h"
#include"pesticide.h"
#include"spray_configuration.h"
using namespace std;

enum class Season{
    Spring,
    Summer,
    Winter
};

class SprayPlan : public SprayPlanPrototype{
private: 
    string planName;
    string cropName;
    Season season;
    unique_ptr<Fertilizer> fertilizer;
    unique_ptr<Pesticide> pesticide;
    unique_ptr<SprayConfiguration> configuration;
    vector<string> droneRoute;
    vector<string> safetyWarnings;
    vector<int> executionHours;
    bool requiresWeatherCheck;
    bool requiresManagerApproval;
public:
    SprayPlan(string planName, string cropName, Season season, unique_ptr<Fertilizer> fertilizer, unique_ptr<Pesticide> pesticide,unique_ptr<SprayConfiguration> configuration);
    unique_ptr<SprayPlanPrototype> clone() const override;
    void addRoute(const string& route);
    void removeRoute(const string& route);
    void addWarning(const string& warning);
    void removeWarning(const string& warning);
    void addExecutionHour(int hour);
    void removeExecutionHour(int hour);
    void printPlan() const;

};
#endif