//
// Created by annased on 01.05.2020.
//
#pragma once
#include <iostream>
#include <string>

enum CREATURE_TYPE {
    HOBBIT,
    ORC,
    HUMAN
};

//_______________________CREATURE_DECLARATION_______________________
class Creature {
protected:
    double ab_negotiate;
    double ab_fight;
    double HP;
    double max_HP;
    double power;
    std::string name;
    CREATURE_TYPE type;
    double damage;
    bool ifalive = true;
public:
    Creature (double ab_negotiate, double ab_fight,
              double HP, double max_HP,
              double power, double damage, std::string name, CREATURE_TYPE type);

    double Get_ab_negotiate() const;
    double Get_ab_fight() const;
    double Get_HP() const;
    double Get_max_HP()const;
    double Get_power() const;
    std::string Get_name() const;
    CREATURE_TYPE Get_type() const;
    double Get_damage() const;

    void check_is_alive();
    virtual void reduce_hp() {}
    virtual void change_power(bool is_improves) {}
    void attack(Creature& other);
    bool negotiate(Creature& other);
    virtual ~Creature() {}
};

//_______________________HOBBIT_DECLARATION_______________________
class Hobbit: public Creature {
public:
    Hobbit(std::string name = "Bilbo");
private:
    void reduce_hp() override;
};

//_______________________ORC_DECLARATION_______________________
class Orc: public Creature {
public:
    Orc(std::string name = "Azog");
private:
    void reduce_hp() override;
};

//_______________________HUMAN_DECLARATION_______________________
class Human: public Creature {
public:
    Human(std::string name = "Beor");
    void reduce_hp() override;
};

