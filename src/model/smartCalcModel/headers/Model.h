
#ifndef CPP3_SMARTCALC_V2_0_1_MODEL_HEADERS_MODEL_H_
#define CPP3_SMARTCALC_V2_0_1_MODEL_HEADERS_MODEL_H_

#include <stack>
#include <cmath>
#include <algorithm>
#include "Tokenizer.h"
#include "Error.h"

namespace s21
{

/**
 * @brief The Model class provides functionality for processing mathematical expressions in SmartCalc.
 *
 * This class includes methods for converting infix expressions to postfix notation, calculating expressions
 * in postfix notation, checking the correctness of bracket sequences, formatting expressions for tokenization,
 * handling operators, handling functions, checking the correctness of operator sequences, replacing 'x' in expressions,
 * and handling functions specifically designed for graph plotting.
 */
class Model
{
public:
    /**
     * @brief Converts an infix expression to postfix notation.
     *
     * @param tokens The vector of tokens representing the infix expression.
     * @return The vector of tokens in postfix notation.
     */
    std::vector<Token> fromInfixToPostfix(const std::vector<Token> &tokens);

    /**
     * @brief Calculates the result of an expression in postfix notation.
     *
     * @param tokens The vector of tokens representing the expression in postfix notation.
     * @param isGraph Flag indicating if the expression is for graph plotting.
     * @return The result of the expression calculation.
     */
    double calculatePolishNotation(const std::vector<Token> &tokens, bool isGraph = false);

    /**
     * @brief Checks the correctness of the bracket sequence in an expression.
     *
     * @param expr The expression to be checked.
     */
    void checkCorrectBracketSequence(const std::string &expr);

    /**
     * @brief Formats the expression for tokenization.
     *
     * @param expr The expression to be formatted.
     * @return The formatted expression as a string.
     */
    std::string formatStrForTokenize(const std::string &expr);

    /**
     * @brief Handles binary operators during expression evaluation.
     *
     * @param num1 The first operand.
     * @param num2 The second operand.
     * @param oper The binary operator.
     * @return The result of the operation.
     */
    double operatorsHandler(double num1, double num2, const std::string& oper);

    /**
     * @brief Handles unary functions during expression evaluation.
     *
     * @param num The operand.
     * @param oper The unary function.
     * @return The result of the function.
     */
    double functionHandler(double num, const std::string& oper);

    /**
     * @brief Checks the correctness of the operator sequence in an expression.
     *
     * @param expr The expression to be checked.
     */
    void checkCorrectOperatorSequence(const std::string &expr);

    /**
     * @brief Replaces 'x' in an expression with the specified value.
     *
     * @param expr The expression containing 'x'.
     * @param x The value to replace 'x' with.
     * @return The modified expression as a string.
     */
    std::string replaceX(const std::string &expr, double x);

    /**
     * @brief Handles unary functions during graph plotting.
     *
     * @param num The operand.
     * @param oper The unary function.
     * @return The result of the function.
     */
    double functionHandlerForGraph(double num, const std::string& oper);
};

} // namespace s21

#endif // CPP3_SMARTCALC_V2_0_1_MODEL_HEADERS_MODEL_H_
