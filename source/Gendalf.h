//
// Created by annased on 01.05.2020.
//
#pragma once
#include "Dragon.h"
#include <memory>
#include <iostream>

class Gendalf {
public:
    static Gendalf* getInstance();
    void attack(Dragon* dragon);
private:
    static Gendalf * p_instance;
    Gendalf() = default;
};
