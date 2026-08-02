#include<string>
#include<memory>
#include<iostream>
#include<algorithm>
#include"spray_plan.h"

using namespace std;

SprayPlan::SprayPlan(string planName, string cropName, Season season, unique_ptr<Fertilizer> fertilizer, unique_ptr<Pesticide> pesticide,unique_ptr<SprayConfiguration> configuration)
    :_planName(planName), 
    _cropName(cropName), 
    _season(season), 
    _fertilizer(move(fertilizer)),
    _pesticide(move(pesticide)), 
    _configuration(move(configuration)){}
SprayPlan::SprayPlan(const SprayPlan& other)
    :_planName(other._planName), 
    _cropName(other._cropName), 
    _season(other._season),
    _droneRout(other._droneRout), 
    _safetyWarnings(other._safetyWarnings), 
    _executionHours(other._executionHours), 
    _requiresWeatherCheck(other._requiresWeatherCheck),
    _requiresManagerApproval(other._requiresManagerApproval)
    {
        if(other._fertilizer){
            _fertilizer = other._fertilizer->clone();
        }
        if(other._pesticide){
            _pesticide = other._pesticide->clone();
        }
        if(other._configuration){
            _configuration = other._configuration->clone();
        }

    }
SprayPlan& SprayPlan::operator=(const SprayPlan& other){
    if(this != &other){
        _planName = other._planName;
        _cropName = other._cropName;
        _season = other._season;
        _droneRout = other._droneRout;
        _safetyWarnings = other._safetyWarnings;
        _executionHours = other._executionHours;
        _requiresWeatherCheck = other._requiresWeatherCheck;
        _requiresManagerApproval = other._requiresManagerApproval;

        _fertilizer = other._fertilizer ? other._fertilizer->clone() : nullptr;
        _pesticide = other._pesticide ? other._pesticide->clone() : nullptr;
        _configuration = other._configuration ? other._configuration->clone() : nullptr;
    }
    return *this;
}

unique_ptr<SprayPlanPrototype> SprayPlan::clone() const{
    return make_unique<SprayPlan>(*this);
}
void SprayPlan::addRoute(const string& route){
    _droneRout.push_back(route);
}
void SprayPlan::removeRoute(const string& route){
    auto it = find(_droneRout.begin(), _droneRout.end(),route);
    if(it != _droneRout.end()){
        _droneRout.erase(it);
    }
}
void SprayPlan::addWarning(const string& warning){
    _safetyWarnings.push_back(warning);
}
void SprayPlan::removeWarning(const string& warning){
    auto it = find(_safetyWarnings.begin(), _safetyWarnings.end(),warning);
    if(it != _safetyWarnings.end()){
        _safetyWarnings.erase(it);
    }
}
void SprayPlan::addExecutionHour(int hour){
    _executionHours.push_back(hour);
}
void SprayPlan::removeExecutionHour(int hour){
    auto it = find(_executionHours.begin(), _executionHours.end(),hour);
    if(it != _executionHours.end()){
        _executionHours.erase(it);
    }
}

void SprayPlan::setPlanName(const string name){
    _planName = name;
}

void SprayPlan::setRequiresManagerApproval(const bool managerApproval){
    _requiresManagerApproval = managerApproval;
}

void SprayPlan::printPlan() const{
    cout << "planName: " << _planName << "\n";
    cout << "cropName: " << _cropName << "\n";
    cout << "object adress: " << static_cast<const void*>(this) << "\n";
    cout << "fertilizer: " << (_fertilizer ? _fertilizer->getName() : "None") <<"(" << static_cast<const void*>(_fertilizer.get())<<")"<<"\n";
    cout << "pesticide: " << (_pesticide ? _pesticide->getName() : "None") << "(" << static_cast<const void*>(_pesticide.get())<<")"<<"\n";
    cout << "configuration: " << (_configuration ? _configuration->getConfiguration() : "None") << "(" << static_cast<const void*>(_configuration.get())<<")"<<"\n";
    
    for (const auto& r : _droneRout){
        cout << " " << r << "\n";
    }

    for (const auto& w : _safetyWarnings){
        cout << " " << w << "\n";
    }

    for (const auto& h : _executionHours){
        cout << " " << h << "\n";
    }
    
    cout << "Requires Weather Check: " << (_requiresWeatherCheck ? "yes" :"no") << "\n";
    cout << "Requires Manager Approval: " << (_requiresManagerApproval ? "yes" :"no") << "\n";


}