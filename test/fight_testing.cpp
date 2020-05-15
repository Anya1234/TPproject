#include "gtest/gtest.h"
#include "interface_factory.h"
#include "creature_factory.h"
#include "Creatures.h"
#include "Team.h"


TEST(FIGHT_TEST, T_7) {
    std::shared_ptr<Creatures_Factory> humans_factory = std::make_shared<Human_Factory>();
    std::shared_ptr<Creature> human = humans_factory->Create_Creature();
    std::shared_ptr<Creatures_Factory> hobbits_factory = std::make_shared<Hobbit_Factory>();
    std::shared_ptr<Creature> hobbit = hobbits_factory->Create_Creature();

    int cur_hobbit_HP = hobbit->Get_HP();
    int cur_human_HP = human->Get_HP();

    if (hobbit->attack(human)) {
        cur_human_HP -= 20;
    }
    else {
        cur_hobbit_HP -= 10;
    }

    EXPECT_EQ(hobbit->Get_HP(), cur_hobbit_HP);
    EXPECT_EQ(human->Get_HP(), cur_human_HP);

}