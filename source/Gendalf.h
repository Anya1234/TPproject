//
// Created by annased on 01.05.2020.
//
#pragma once

class Gendalf {
public:
    static Gendalf* getInstance();
private:
    static Gendalf * p_instance;
    Gendalf() = default;
};
