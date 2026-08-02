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
    string _planName;
    string _cropName;
    Season _season;
    unique_ptr<Fertilizer> _fertilizer;
    unique_ptr<Pesticide> _pesticide;
    unique_ptr<SprayConfiguration> _configuration;
    vector<string> _droneRout = {};
    vector<string> _safetyWarnings = {};
    vector<int> _executionHours = {};
    bool _requiresWeatherCheck = false;
    bool _requiresManagerApproval = false;
public:
    SprayPlan(string planName, string cropName, Season season, unique_ptr<Fertilizer> fertilizer, unique_ptr<Pesticide> pesticide,unique_ptr<SprayConfiguration> configuration);
    SprayPlan(const SprayPlan& other);
    SprayPlan& operator=(const SprayPlan& other);
    unique_ptr<SprayPlanPrototype> clone() const override;
    void addRoute(const string& route);
    void removeRoute(const string& route);
    void addWarning(const string& warning);
    void removeWarning(const string& warning);
    void addExecutionHour(int hour);
    void removeExecutionHour(int hour);
    void printPlan() const;

    void setPlanName(const string name);
    void setRequiresManagerApproval(const bool managerApproval);
};
#endif