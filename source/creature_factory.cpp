//
// Created by annased on 01.05.2020.
//
#include "creature_factory.h"

std::shared_ptr<Creature> Hobbit_Factory::Create_Creature() const {
    return std::make_shared<Hobbit>();
}

std::shared_ptr<Creature> Orcs_Factory::Create_Creature() const {
    return std::make_shared<Orc>();
}

std::shared_ptr<Creature> Human_Factory::Create_Creature() const {
    return std::make_shared<Human>();
}

