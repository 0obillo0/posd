#ifndef SPRAY_STRATEGY_H
#define SPRAY_STRATEGY_H

#include<string>
using namespace std; 

class SprayStrategy{
public:
    virtual ~SprayStrategy() = default;
    virtual void spray(const string& cropName,double area) const = 0;
    virtual string getStrategyName() const = 0;
};

class WideAreaSpray : public SprayStrategy{
public:
    void spray(const string& cropName,double area) const override;
    string getStrategyName() const override;
};

class PrecisionSpray : public SprayStrategy{
public:
    void spray(const string& cropName,double area) const override;
    string getStrategyName() const override;
};

class CrownSpray : public SprayStrategy{
public:
    void spray(const string& cropName,double area) const override;
    string getStrategyName() const override;
};

class MistSpray : public SprayStrategy{
public:
    void spray(const string& cropName,double area) const override;
    string getStrategyName() const override;
};

#endif