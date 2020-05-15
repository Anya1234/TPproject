#include "gtest/gtest.h"
#include "interface_factory.h"
#include "creature_factory.h"
#include "Creatures.h"
#include "Team.h"


TEST(TEAM_TEST, T_6) {
    std::shared_ptr<Creatures_Factory> orcs_factory = std::make_shared<Orcs_Factory>();
    std::shared_ptr<Creature> orc = orcs_factory->Create_Creature();
    std::shared_ptr<Creatures_Factory> humans_factory = std::make_shared<Human_Factory>();
    std::shared_ptr<Creature> human = humans_factory->Create_Creature();
    std::shared_ptr<Creatures_Factory> hobbits_factory = std::make_shared<Hobbit_Factory>();
    std::shared_ptr<Creature> hobbit = hobbits_factory->Create_Creature();
    Team test_team;

    test_team.AddPerson(hobbit);
    test_team.AddPerson(human);
    test_team.AddPerson(orc);

    EXPECT_EQ(test_team.Get_quantity(), 3);
    EXPECT_EQ(test_team.Get_HP(), hobbit->Get_HP() + human->Get_HP() + orc->Get_HP());
    EXPECT_EQ(test_team.GetPerson(1), human);
    test_team.RemovePerson(0);
    EXPECT_EQ(test_team.Get_quantity(), 2);
    EXPECT_EQ(test_team.Get_HP(), human->Get_HP() + orc->Get_HP());
    EXPECT_EQ(test_team.GetPerson(1), orc);
    EXPECT_EQ(test_team.GetPerson(0), human);
}