#include"farm_iterator.h"

FarmIterator::FarmIterator(FarmComponent* root){
    if(root != nullptr){
        root->accept(_fields);
    }
}

void FarmIterator::first(){
    _index = 0;
}
void FarmIterator::next(){
    if(hasNext()){
        _index++;
    }
}
bool FarmIterator::hasNext(){
    return _index < static_cast<int>(_fields.size());
}
CropField* FarmIterator::current(){
    return _fields[_index];
}