#pragma once
#include "interface_factory.h"
#include "creature_factory.h"
#include "Creatures.h"
#include "Location.h"
#include <memory>

class Shire : Location {
public:
    Shire();
    std::shared_ptr<Creature> Get_Creature(innt ) override;
};

class Gondor : Location {
public:
    Gondor();
    std::shared_ptr<Creature> Get_Creature() override;
};

class Prancing_Pony : Location {
public:
    Prancing_Pony();
    std::shared_ptr<Creature> Get_Creature() override;
};

class Mordor : Location {
public:
    Mordor();
    std::shared_ptr<Creature> Get_Creature() override;
};