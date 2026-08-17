#include"drink_preparation.h"
#include<iostream>

void DrinKPreparation::prepare(){
    prepareCup();
    prepareBase();
    addMainIngredient();
    specialProcessing();
    adjustSugarAndIce();
    finish();
}
void DrinKPreparation::prepareCup(){
    cout << "Prepare Cup" << "\n";
}

void DrinKPreparation::specialProcessing(){

}

void DrinKPreparation::adjustSugarAndIce(){
    cout << "Adjust Sugar And Ice" << "\n";
}

void DrinKPreparation::finish(){
    cout << "Finish" << "\n";
}