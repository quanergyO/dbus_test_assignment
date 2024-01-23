
#ifndef CPP3_SMARTCALC_V2_0_1_MODEL_HEADERS_TOKEN_H_
#define CPP3_SMARTCALC_V2_0_1_MODEL_HEADERS_TOKEN_H_

#include <string>

namespace s21
{

/**
 * @brief The Token class represents a token in a mathematical expression for SmartCalc.
 *
 * This class includes an enumeration Type to categorize the type of the token, an enumeration
 * OperatorAssociativity to indicate the associativity of an operator, and methods to access
 * information about the token, such as its type, associativity, and string representation.
 */
class Token
{
public:
    /**
     * @brief Enumeration defining the types of tokens.
     */
    enum Type
    {
        OPERATOR,        /**< Operator token type. */
        OPEN_BRACKET,    /**< Open bracket token type. */
        CLOSE_BRACKET,   /**< Close bracket token type. */
        INT_NUMBER,      /**< Integer number token type. */
        FLOAT_NUMBER,    /**< Floating-point number token type. */
        FUNCTION,        /**< Function token type. */
        SEPARATOR        /**< Separator token type. */
    };

    /**
     * @brief Enumeration defining the associativity of operators.
     */
    enum OperatorAssociativity
    {
        NONE,   /**< No associativity. */
        RIGHT,  /**< Right associativity. */
        LEFT    /**< Left associativity. */
    };

    /**
     * @brief Constructor for the Token class.
     *
     * Initializes the token with the provided string representation, type, and operator associativity.
     *
     * @param token The string representation of the token.
     * @param type The type of the token (e.g., OPERATOR, OPEN_BRACKET, etc.).
     * @param asc The operator associativity (e.g., NONE, RIGHT, LEFT).
     */
    Token(const std::string &token, Type type, OperatorAssociativity asc = NONE);

    /**
     * @brief Returns the precedence of the operator token.
     *
     * @return The precedence of the operator token.
     */
    int getPrecendance() const noexcept;

    /**
     * @brief Gets the type of the token.
     *
     * @return The type of the token (e.g., OPERATOR, OPEN_BRACKET, etc.).
     */
    const Type& getType() const { return type_; }

    /**
     * @brief Gets the operator associativity.
     *
     * @return The operator associativity (e.g., NONE, RIGHT, LEFT).
     */
    const OperatorAssociativity& getAsc() const { return operatorAsc_; }

    /**
     * @brief Gets the string representation of the token.
     *
     * @return The string representation of the token.
     */
    const std::string& getStr() const { return str_; }

private:
    /**
     * @brief The type of the token (e.g., OPERATOR, OPEN_BRACKET, etc.).
     */
    Type type_;

    /**
     * @brief The operator associativity (e.g., NONE, RIGHT, LEFT).
     */
    OperatorAssociativity operatorAsc_;

    /**
     * @brief The string representation of the token.
     */
    std::string str_;
};

} // namespace s21

#endif // CPP3_SMARTCALC_V2_0_1_MODEL_HEADERS_TOKEN_HPP_
