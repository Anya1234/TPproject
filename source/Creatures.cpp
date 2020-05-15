//
// Created by annased on 01.05.2020.
//
#include "Creatures.h"


//_______________________CREATURE_DEFINITION_______________________
Creature::Creature(double ab_negotiate, double ab_fight,
                   int HP, int max_HP, double power, double damage, 
                   std::string name, CREATURE_TYPE type) : ab_negotiate(ab_negotiate),
                                                           ab_fight(ab_fight),
                                                           HP(HP),
                                                           max_HP(max_HP),
                                                           power(power),
                                                           damage(damage),
                                                           name(name),
                                                           type(type) {}

bool Creature::check_is_alive() {
    if (HP <= 0) {
        ifalive = false;
        return false;
    }
    return true;
}

bool Creature::attack(std::shared_ptr<Creature> other) {
    srand(time(NULL));
    int using_rand = rand() % 100;
    double chance = static_cast<double>(using_rand) / 100;
    double probability = power * ab_fight;
    if (probability >= chance) {
        other->reduce_hp();
        power += 0.01;
        return true;
    }
    else {
        reduce_hp();
        return false;
    }
    return false;
}

bool Creature::negotiate(std::shared_ptr<Creature> other) {
    int using_rand = rand() % 100;
    double chance = static_cast<double>(using_rand)/100;
    double probability = ab_negotiate * static_cast<double>(HP) / static_cast<double>(max_HP);
    
    if (probability >= chance) {
       std::cout << name << " договорился с " << other->name << std::endl;
       std::cout << other->name << " будет рад сражаться за вас!" << std::endl;
       return true;
    }
    else {
        std::cout << name << " только вывел из себя  " << other->name << std::endl;
        std::cout << "Теперь он собирается убить " << name <<  std::endl;
        attack(other);
        return false;
    }
}


double Creature::Get_ab_negotiate() const {
    return ab_negotiate;
}

double Creature::Get_ab_fight() const {
    return ab_fight;
}

int Creature::Get_HP() const {
    return HP;
}

int Creature::Get_max_HP() const {
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

std::string Hobbit::Print_type() const {
    return "Hobbit";
}

//_______________________ORC_DEFINITION_______________________
Orc::Orc(std::string name):
    Creature (0.2, 0.8, 100, 100, 1, 10, name, ORC) {}

void Orc::reduce_hp() {
    HP -= 15;
    check_is_alive();
}

std::string Orc::Print_type() const {
    return "Orc";
}

//_______________________HUMAN_DEFINITION_______________________
Human::Human(std::string name):
    Creature (0.5, 0.5, 150, 150, 0.5, 10, name, HUMAN) {}

void Human::reduce_hp() {
    HP -=20;
    check_is_alive();
}

std::string Human::Print_type() const {
    return "Human";
}
