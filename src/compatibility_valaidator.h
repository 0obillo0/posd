#ifndef COMPATIBILITY_VALAIDATOR_H
#define COMPATIBILITY_VALAIDATOR_H

#include<string>
#include<memory>
#include"fertilizer.h"
#include"pesticide.h"
#include"spray_configuration.h"
using namespace std;

class CompatibilityValaidator{
public:
    static bool validateCompatibility(const Fertilizer& fertilizer, const Pesticide& pesticide, const SprayConfiguration& configuration);
};

#endif