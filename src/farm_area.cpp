#include"farm_area.h"

#include<iostream>
#include"farm_iterator.h"

FarmArea::FarmArea(const string& name):_name(name){
}

void FarmArea::add(unique_ptr<FarmComponent> compoent){
    _children.push_back(move(compoent));
}
void FarmArea::remove(const string& name){
    for(auto it = _children.begin(); it != _children.end(); it ++){
        if((*it)->getName() == name){
            _children.erase(it);
            return;
        }
        
    }
}

FarmComponent* FarmArea::getChild(int index){
    return _children[index].get();
}

string FarmArea::getName() const{
    return _name;
}

double FarmArea::getArea() const{
    double total = 0.0;
    for(const auto& child:_children){
        total += child->getArea();
    }
    return total;
}

void FarmArea::display() const{
    cout << "name:" << _name << "\n";
    for(const auto& child : _children){
        child->display();
    }
}

void FarmArea::accept(vector<CropField*>& fields){
    for(auto& child: _children){
        child->accept(fields);
    }
}

unique_ptr<FieldIterator> FarmArea::createIterator(){
    return make_unique<FarmIterator>(this);
}