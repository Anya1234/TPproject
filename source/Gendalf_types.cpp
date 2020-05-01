//
// Created by annased on 01.05.2020.
//
#include "Gendalf_types.h"


//_______________________Gendalf_Blue_DEFINITION_______________________
Make_Gendalf_Blue::Make_Gendalf_Blue() {
    gendalfptr = Gendalf::getInstance();
}

void Make_Gendalf_Blue::Say() {
    std::cout << "Many that live deserve death. "
                << "And some that die deserve life. "
                << "Can you give it to them? "
                << "Then do not be too eager to deal out death in judgement." << std::endl;
}

//_______________________Gendalf_Grey_DEFINITION_______________________
Make_Gendalf_Grey::Make_Gendalf_Grey() {
    gendalfptr = Gendalf::getInstance();
}

void Make_Gendalf_Grey::Say() {
    std::cout << "All we have to decide is what to do with the time that is given us. "<< std::endl;
}

//_______________________Gendalf_White_DEFINITION_______________________
Make_Gendalf_White::Make_Gendalf_White() {
    gendalfptr = Gendalf::getInstance();
}

void Make_Gendalf_White::Say() {
    std::cout << "I will not say: do not weep; for not all tears are an evil" << std::endl;
}