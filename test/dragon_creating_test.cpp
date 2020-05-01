#include "gtest/gtest.h"
#include "Dragon.h"


TEST(DRAGON_CREATING_TEST, T_5) {
    Dragon* dragon = Dragon::getInstance();
    Dragon* tst_dragon = Dragon::getInstance();
    EXPECT_EQ(dragon, tst_dragon);
}