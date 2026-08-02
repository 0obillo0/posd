#include<string>
#include<memory>
#include"compatibility_valaidator.h"

using namespace std;

bool CompatibilityValaidator::validateCompatibility(const Fertilizer& fertilizer, const Pesticide& pesticide, const SprayConfiguration& configuration){
    string fName = fertilizer.getName();
    string pName = pesticide.getName();
    string cName = configuration.getConfiguration();

    bool isSpring = (fName.find("spring") != string::npos) && (pName.find("spring") != string::npos) && (cName.find("spring") != string::npos);
    bool isSummer = (fName.find("summer") != string::npos) && (pName.find("summer") != string::npos) && (cName.find("summer") != string::npos);
    bool isWinter = (fName.find("winter") != string::npos) && (pName.find("winter") != string::npos) && (cName.find("winter") != string::npos);
    return isSpring || isSummer || isWinter;
}