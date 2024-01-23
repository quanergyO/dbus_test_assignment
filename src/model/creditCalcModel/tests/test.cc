
#include <gtest/gtest.h>
#include <cmath>
#include "../modelcreditcalc.h"

TEST(CreditrCalc1, True)
{
    s21::ModelCreditCalc creditCalc;
    creditCalc.setData("1000", "1", "5", true);
    auto answer = creditCalc.calculate();
    double first = std::stod(answer[0]);
    double second = std::stod(answer[1]);
    double third = std::stod(answer[2]);
    ASSERT_DOUBLE_EQ(first, 85.607482);
    ASSERT_DOUBLE_EQ(second, 1027.289781);
    ASSERT_DOUBLE_EQ(third, 27.289781);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
