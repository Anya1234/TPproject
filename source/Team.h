//
// Created by annased on 01.05.2020.
//
#pragma once
#include <vector>
#include "creature_factory.h"
#include "Creatures.h"

class Team {
private:
    size_t quantity;
    CREATURE_TYPE type;
    std::vector<std::shared_ptr<Creature>> creatures;
    std::shared_ptr<Creatures_Factory> hobbit_factory;
    std::shared_ptr<Creatures_Factory> orc_factory;
    std::shared_ptr<Creatures_Factory> human_factory;
public:
    Team(CREATURE_TYPE type, size_t quantity = 1);
    size_t Get_quantity();
    CREATURE_TYPE Get_type();
    void Print();
};