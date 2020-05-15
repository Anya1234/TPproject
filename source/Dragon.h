//
// Created by annased on 01.05.2020.
//
#pragma once


class Dragon {
public:
    static Dragon* getInstance();
    static double get_HP();
    static double get_power();
    static void reduce_HP();
private:
    static int HP;
    static double power;
    static Dragon * p_instance;
    Dragon() = default;
};

