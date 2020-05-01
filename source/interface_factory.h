//
// Created by annased on 01.05.2020.
//
#pragma once
#include <set>
#include <memory>
#include "Creatures.h"

class Creatures_Factory {
public:
    virtual std::shared_ptr<Creature> Create_Creature() const = 0;
    virtual ~Creatures_Factory() {};
};