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
    std::vector< std::shared_ptr<Creature> > creatures;
public:
    Team() = default;
    void AddPerson(std::shared_ptr<Creature> person);
    std::shared_ptr<Creature> GetPerson(int number);
    void RemovePerson(int number);
    size_t Get_quantity();
    void PrintTeam();
    int Get_HP();
    void Print();
};