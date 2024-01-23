#include <gtest/gtest.h>
#include <cmath>
#include "../headers/Model.h"
#include "../headers/Token.h"
#include "../headers/Tokenizer.h"



double calcExpression(const std::string& expr)
{
  s21::Model model;
  std::vector<s21::Token> tokensInfix;
  std::string str = model.formatStrForTokenize(expr);
  model.checkCorrectBracketSequence(str);
  tokenize(str, tokensInfix);
  std::vector<s21::Token> tokensPostfix = model.fromInfixToPostfix(tokensInfix);
  double result = model.calculatePolishNotation(tokensPostfix);
  return result;
}

TEST(Plus, True)
{
    std::string expr = "2+2";
    ASSERT_DOUBLE_EQ(calcExpression(expr), 4.0);
}

TEST(Minus, True)
{
    std::string expr = "2-2";
    ASSERT_DOUBLE_EQ(calcExpression(expr), 0.0);
}

TEST(Mul, True)
{
    std::string expr = "3*2";
    ASSERT_DOUBLE_EQ(calcExpression(expr), 6.0);
}

TEST(Div, True)
{
    std::string expr = "10/5";
    ASSERT_DOUBLE_EQ(calcExpression(expr), 2.0);
}

TEST(Sin, True)
{
    std::string expr = "sin(90)";
    ASSERT_DOUBLE_EQ(calcExpression(expr), 1.0);
}

TEST(Asin, True)
{
    std::string expr = "asin(1)";
    ASSERT_DOUBLE_EQ(calcExpression(expr), 90.0);
}

TEST(Acos, True)
{
    std::string expr = "acos(0.5)";
    ASSERT_DOUBLE_EQ(calcExpression(expr), 60.0);
}

TEST(Pow, True)
{
    std::string expr = "2^3";
    ASSERT_DOUBLE_EQ(calcExpression(expr), 8.0);
}

TEST(Cos, True)
{
    std::string expr = "cos(60)";
    ASSERT_DOUBLE_EQ(calcExpression(expr), 0.5);
}

TEST(Unary1, True)
{
    std::string expr = "-(-2)";
    ASSERT_DOUBLE_EQ(calcExpression(expr), 2.0);
}

TEST(Unary2, True)
{
    std::string expr = "-2";
    ASSERT_DOUBLE_EQ(calcExpression(expr), -2.0);
}

TEST(Ln, True)
{
    std::string expr = "ln(1)";
    ASSERT_DOUBLE_EQ(calcExpression(expr), 0.0);
}

TEST(Log, True)
{
    std::string expr = "log(100)";
    ASSERT_DOUBLE_EQ(calcExpression(expr), 2.0);
}

TEST(Sqrt, True)
{
    std::string expr = "sqrt(144)";
    ASSERT_DOUBLE_EQ(calcExpression(expr), 12.0);
}

TEST(Atan, True)
{
    std::string expr = "atan(1)";
    ASSERT_DOUBLE_EQ(calcExpression(expr), 45.0);
}

TEST(UnaryPlus, True)
{
    std::string expr = "-2+3";
    ASSERT_DOUBLE_EQ(calcExpression(expr), 1.0);
}

TEST(Mod, True)
{
    std::string expr = "5mod2";
    ASSERT_DOUBLE_EQ(calcExpression(expr), 1.0);
}

TEST(Brackets, True)
{
    std::string expr = "(2+2)*2";
    ASSERT_DOUBLE_EQ(calcExpression(expr), 8.0);
}

TEST(Test1, True)
{
    std::string expr = "2+2*2";
    ASSERT_DOUBLE_EQ(calcExpression(expr), 6.0);
}

TEST(Tan, True)
{
    std::string expr = "tan(45)";
    ASSERT_DOUBLE_EQ(calcExpression(expr), 1.0);
}

TEST(Test, False)
{
    std::string expr = "()sin";
    ASSERT_ANY_THROW(calcExpression(expr));
}

TEST(Test2, False)
{
    std::string expr = "(.)/(.)";
    ASSERT_ANY_THROW(calcExpression(expr));
}

TEST(Test3, False)
{
    std::string expr = "2)+(2";
    ASSERT_ANY_THROW(calcExpression(expr));
}

TEST(UnaryMinus, True)
{
    std::string expr = "-2-2";
    ASSERT_DOUBLE_EQ(calcExpression(expr), -4.0);
}

TEST(UnaryMinus1, True)
{
    std::string expr = "-2+3";
    ASSERT_DOUBLE_EQ(calcExpression(expr), 1.0);
}

TEST(UnaryMinus2, True)
{
    std::string expr = "-2-(-3)";
    ASSERT_DOUBLE_EQ(calcExpression(expr), 1.0);
}

TEST(UnaryMinus3, True)
{
    std::string expr = "-2-3";
    ASSERT_DOUBLE_EQ(calcExpression(expr), -5.0);
}

TEST(Y01k4, True)
{
    std::string expr = "(acos(0.6877) + atan(0.666778) ) ^3 + ( ( ln(66) + lg(88) * (78 + (-8) * 7) ) / (tan(88))^4";
    ASSERT_DOUBLE_EQ(calcExpression(expr), 516740.92455125228);
}

TEST(Test4, False)
{
    std::string expr = "*5";
    ASSERT_ANY_THROW(calcExpression(expr));
}

TEST(Test5, False)
{
    std::string expr = "5**5";
    ASSERT_ANY_THROW(calcExpression(expr));
}

TEST(Test6, False)
{
    std::string expr = "-.5";
    ASSERT_ANY_THROW(calcExpression(expr));
}

TEST(Test7, False)
{
    std::string expr = "5sin(90)";
    ASSERT_ANY_THROW(calcExpression(expr));
}

TEST(Test8, False)
{
    std::string expr = "5.5.5";
    ASSERT_ANY_THROW(calcExpression(expr));
}

TEST(Test9, False)
{
    std::string expr = "2+.2";
    ASSERT_ANY_THROW(calcExpression(expr));
}

TEST(Test10, False)
{
    std::string expr = "sin+cos";
    ASSERT_ANY_THROW(calcExpression(expr));
}

TEST(Test11, False)
{
    std::string expr = "~5";
    ASSERT_ANY_THROW(calcExpression(expr));
}

TEST(Test12, False)
{
    std::string expr = "tan1";
    ASSERT_ANY_THROW(calcExpression(expr));
}

TEST(Test13, False)
{
    std::string expr = "x+2";
    ASSERT_ANY_THROW(calcExpression(expr));
}

TEST(UnaryMinusFunction, True)
{
    std::string expr = "-sin(90)";
    ASSERT_DOUBLE_EQ(calcExpression(expr), -1.0);
}

TEST(UnaryMinys, True)
{
    std::string expr = "2*-10";
    ASSERT_DOUBLE_EQ(calcExpression(expr), -20.0);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
