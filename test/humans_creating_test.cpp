#include "gtest/gtest.h"
#include "interface_factory.h"
#include "creature_factory.h"
#include "Creatures.h"


TEST(HUMAN_CREATING_TEST, T_2) {
    std::shared_ptr<Creatures_Factory> humans_factory = std::make_shared<Human_Factory>();
    std::shared_ptr<Creature> human = humans_factory->Create_Creature();
    EXPECT_EQ(human->Get_ab_negotiate(), 0.5);
    EXPECT_EQ(human->Get_ab_fight(), 0.5);
    EXPECT_EQ(human->Get_HP(), 150);
    EXPECT_EQ(human->Get_max_HP(), 150);
    EXPECT_EQ(human->Get_power(), 0.5);
    EXPECT_EQ(human->Get_damage(), 10);
    EXPECT_EQ(human->Get_name(), "Beor");
    EXPECT_EQ(human->Get_type(), HUMAN);
}