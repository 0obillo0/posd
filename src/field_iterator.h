#ifndef FIELD_ITERATOR_H
#define FIELD_ITERATOR_H

#include"crop_field.h"

class FieldIterator{
public:
    virtual ~FieldIterator() = default;
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool hasNext() = 0;
    virtual CropField* current() = 0;
};

#endif