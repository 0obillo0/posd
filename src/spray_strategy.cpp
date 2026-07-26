#include "spray_strategy.h"

void WideAreaSpray::spray(const string& cropName,double area) const{
    printf("WideAreaSpray\n");
}
string WideAreaSpray::getStrategyName() const{
    return "WideAreaSpray";
}

void PrecisionSpray::spray(const string& cropName,double area) const{
    printf("PrecisionSpray\n");
}
string PrecisionSpray::getStrategyName() const{
    return "PrecisionSpray";
}

void CrownSpray::spray(const string& cropName,double area) const{
    printf("CrownSpray\n");
}
string CrownSpray::getStrategyName() const{
    return "CrownSpray";
}

void MistSpray::spray(const string& cropName,double area) const{
    printf("MistSpray\n");
}
string MistSpray::getStrategyName() const{
    return "MistSpray";
}