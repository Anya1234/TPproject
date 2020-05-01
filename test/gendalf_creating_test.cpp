#include "gtest/gtest.h"
#include "Gendalf.h"


TEST(GENDALF_CREATING_TEST, T_4) {
    Gendalf* gendalf = Gendalf::getInstance();
    Gendalf* tst_gendalf = Gendalf::getInstance();
    EXPECT_EQ(gendalf, tst_gendalf);
}