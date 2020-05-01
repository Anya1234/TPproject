#include "Team.h"

Team::Team(CREATURE_TYPE type, size_t quantity):
                            type(type), 
                            quantity(quantity),
                            hobbit_factory(std::make_shared<Hobbit_Factory>()),
                            orc_factory(std::make_shared<Orcs_Factory>()),
                            human_factory(std::make_shared<Human_Factory>()) {

    if (type == HOBBIT) {
        for (size_t i = 0; i <= quantity; ++i) {
            std::shared_ptr<Creature> hobbitptr = hobbit_factory->Create_Creature();
            creatures.push_back(hobbitptr);
        }
    }
    else if (type == ORC) {
        for (size_t i = 0; i <= quantity; ++i) {
            std::shared_ptr<Creature> orcptr = orc_factory->Create_Creature();
            creatures.push_back(orcptr);
        }
    }
    else if (type == HUMAN) {
        for (size_t i = 0; i <= quantity; ++i) {
            std::shared_ptr<Creature> humanptr = human_factory->Create_Creature();
            creatures.push_back(humanptr);
        }
    }
}

size_t Team::Get_quantity() {
    return quantity;
}

CREATURE_TYPE Team::Get_type() {
    return type;
}

void Team::Print() {
        std::cout << "Quantity: " << Get_quantity() << 
                     " Type: " << Get_type() << "\n";
}