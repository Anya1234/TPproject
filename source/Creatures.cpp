//
// Created by annased on 01.05.2020.
//
#include "Creatures.h"


//_______________________CREATURE_DEFINITION_______________________
Creature::Creature(double ab_negotiate, double ab_fight,
                   double HP, double max_HP,
                   double power, double damage, std::string name, CREATURE_TYPE type): ab_negotiate(ab_negotiate),
                                                                    ab_fight(ab_fight),
                                                                    HP(HP),
                                                                    max_HP(max_HP),
                                                                    power(power),
                                                                    damage(damage),
                                                                    name(name),
                                                                    type(type) {}

void Creature::check_is_alive() {
    if (HP < 0) {
        std::cout << name << " is dead " << std::endl;
        ifalive = false;
    }
}

void Creature::attack(Creature& other) {
    int using_rand = rand()%100;
    double chance = static_cast<double>(using_rand)/100;
    int probability = power*ab_fight;
    if (probability >= chance) {
        std::cout << "Attack by " << name << " succeed" << std::endl;
        other.reduce_hp();
        power +=1;
    }
    else {
        std::cout << "Attack by " << name << " failed" << std::endl;
        reduce_hp();
    }
}

bool Creature::negotiate(Creature &other) {
    int using_rand = rand()%100;
    double chance = static_cast<double>(using_rand)/100;
    int probability = ab_negotiate * HP/max_HP;
    if (probability >= chance) {
       std::cout << name << " reached agreement with " << other.name << std::endl;
       std::cout << other.name << "will be glad to join you" << std::endl;
       return true;
    }
    else {
        std::cout << name << " only made " << other.name <<  " mad" << std::endl;
        std::cout << "He is going to kill " << name <<  std::endl;
        other.attack(*this);
        return false;
    }
}

double Creature::Get_ab_negotiate() const {
    return ab_negotiate;
}

double Creature::Get_ab_fight() const {
    return ab_fight;
}

double Creature::Get_HP() const {
    return HP;
}

double Creature::Get_max_HP() const {
    return max_HP;
}

double Creature::Get_power() const {
    return power;
}

std::string Creature::Get_name() const {
    return name;
}

CREATURE_TYPE Creature::Get_type() const {
    return type;
}

double Creature::Get_damage() const {
    return damage;
}

//_______________________HOBBIT_DEFINITION_______________________
Hobbit::Hobbit(std::string name):
    Creature(0.8, 0.2, 200, 200, 0.5, 5, name, HOBBIT) {}

void Hobbit::reduce_hp() {
    HP -= 10;
    check_is_alive();
}

//_______________________ORC_DEFINITION_______________________
Orc::Orc(std::string name):
    Creature (0.2, 0.8, 100, 100, 1, 10, name, ORC) {}

void Orc::reduce_hp() {
    HP -= 15;
    check_is_alive();
}

//_______________________HUMAN_DEFINITION_______________________
Human::Human(std::string name):
    Creature (0.5, 0.5, 150, 150, 0.5, 10, name, HUMAN) {}

void Human::reduce_hp() {
    HP -=20;
    check_is_alive();
}
