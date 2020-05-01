//
// Created by annased on 01.05.2020.
//
#pragma once
#include "interface_factory.h"
#include <memory>

class Hobbit_Factory : public Creatures_Factory {
public:
    std::shared_ptr<Creature> Create_Creature() const override;
};

class Orcs_Factory : public Creatures_Factory {
public:
    std::shared_ptr<Creature> Create_Creature() const override;
};

class Human_Factory : public Creatures_Factory {
public:
    std::shared_ptr<Creature> Create_Creature() const override;
};