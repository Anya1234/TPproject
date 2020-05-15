//
// Created by annased on 01.05.2020.
//
#include "Gendalf.h"

Gendalf* Gendalf::p_instance = 0;

Gendalf* Gendalf::getInstance() {
    if(!p_instance)
        p_instance = new Gendalf();
    return p_instance;
}

void Gendalf::attack(Dragon* dragon) {
    while (dragon->get_HP() > 0) {
        dragon->reduce_HP();
    }
    std::cout << "Гендальф атаковал дракона" << std::endl;
}