#include "gtest/gtest.h"
#include "interface_factory.h"
#include "creature_factory.h"
#include "Creatures.h"


TEST(ORC_CREATING_TEST, T_3) {
    std::shared_ptr<Creatures_Factory> orcs_factory = std::make_shared<Orcs_Factory>();
    std::shared_ptr<Creature> orc = orcs_factory->Create_Creature();
    EXPECT_EQ(orc->Get_ab_negotiate(), 0.2);
    EXPECT_EQ(orc->Get_ab_fight(), 0.8);
    EXPECT_EQ(orc->Get_HP(), 100);
    EXPECT_EQ(orc->Get_max_HP(), 100);
    EXPECT_EQ(orc->Get_power(), 1);
    EXPECT_EQ(orc->Get_damage(), 10);
    EXPECT_EQ(orc->Get_name(), "Azog");
    EXPECT_EQ(orc->Get_type(), ORC);
}