#include<string>
#include<memory>
#include"compatibility_valaidator.h"

using namespace std;

bool CompatibilityValaidator::validateCompatibility(const Fertilizer& fertilizer, const Pesticide& pesticide, const SprayConfiguration& configuration){
    string fName = fertilizer.getName();
    string pName = pesticide.getName();
    string cName = configuration.getConfiguration();

    bool isSpring = (fName.find("Spring") != string::npos) && (pName.find("Spring") != string::npos) && (cName.find("Spring") != string::npos);
    bool isSummer = (fName.find("Summer") != string::npos) && (pName.find("Summer") != string::npos) && (cName.find("Summer") != string::npos);
    bool isWinter = (fName.find("Winter") != string::npos) && (pName.find("Winter") != string::npos) && (cName.find("Winter") != string::npos);
    return isSpring || isSummer || isWinter;
}