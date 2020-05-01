//
// Created by annased on 01.05.2020.
//
#include "Dragon.h"

Dragon * Dragon::p_instance = 0;

Dragon* Dragon::getInstance() {
    if(!p_instance)
        p_instance = new Dragon();
    return p_instance;
}

double Dragon::HP = 100000;

double Dragon::power = 1000;

double Dragon::get_HP() {
    return HP;
}

double Dragon::get_power() {
    return power;
}