#ifndef FARM_ITERATOR_H
#define FARM_ITERATOR_H


#include<vector>
#include"field_iterator.h"
#include"farm_component.h"

class FarmIterator : public FieldIterator{
private:
    vector<CropField*> _fields;
    int _index;
public:
    explicit FarmIterator(FarmComponent* root);

    void first() override;
    void next() override;
    bool hasNext() override;
    CropField* current() override;
}; 

#endif