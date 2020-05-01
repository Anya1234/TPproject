//
// Created by annased on 01.05.2020.
//
#include "Gendalf.h"

Gendalf * Gendalf::p_instance = 0;

Gendalf* Gendalf::getInstance() {
    if(!p_instance)
        p_instance = new Gendalf();
    return p_instance;
}