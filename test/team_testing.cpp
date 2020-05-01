#include "gtest/gtest.h"
#include "interface_factory.h"
#include "creature_factory.h"
#include "Creatures.h"
#include "Team.h"


TEST(TEAM_TEST, T_6) {
    Team orcs_team = Team(ORC, 10);
    Team hobbits_team = Team(HOBBIT, 15);
    Team humans_team = Team(HUMAN, 20);
    EXPECT_EQ(orcs_team.Get_type(), ORC);
    EXPECT_EQ(orcs_team.Get_quantity(), 10);
    EXPECT_EQ(hobbits_team.Get_type(), HOBBIT);
    EXPECT_EQ(hobbits_team.Get_quantity(), 15);
    EXPECT_EQ(humans_team.Get_type(), HUMAN);
    EXPECT_EQ(humans_team.Get_quantity(), 20);
}