#include "gtest/gtest.h"
#include "interface_factory.h"
#include "creature_factory.h"
#include "Creatures.h"


TEST(HOBBIT_CREATING_TEST, T_1) {
    std::shared_ptr<Creatures_Factory> hobbits_factory = std::make_shared<Hobbit_Factory>();
    std::shared_ptr<Creature> hobbit = hobbits_factory->Create_Creature();
    EXPECT_EQ(hobbit->Get_ab_negotiate(), 0.8);
    EXPECT_EQ(hobbit->Get_ab_fight(), 0.2);
    EXPECT_EQ(hobbit->Get_HP(), 200);
    EXPECT_EQ(hobbit->Get_max_HP(), 200);
    EXPECT_EQ(hobbit->Get_power(), 0.5);
    EXPECT_EQ(hobbit->Get_damage(), 5);
    EXPECT_EQ(hobbit->Get_name(), "Bilbo");
    EXPECT_EQ(hobbit->Get_type(), HOBBIT);
}