
#ifndef CPP3_SMARTCALC_V2_0_1_MODEL_HEADERS_ERROR_H_
#define CPP3_SMARTCALC_V2_0_1_MODEL_HEADERS_ERROR_H_

#include <string>

namespace s21
{

/**
 * @brief The Error class represents an error in the SmartCalc application.
 *
 * This class includes an enumeration Type to categorize the type of error and a message providing details
 * about the error. It is designed to be thrown when an error occurs during the application's execution.
 */
class Error
{
public:
    /**
     * @brief Enumeration defining the types of errors.
     */
    enum Type
    {
        Syntax, /**< Syntax error type. Indicates a syntax error in the application. */
    } type_;

    /**
     * @brief Constructor for the Error class.
     *
     * Initializes the error type and constructs an appropriate error message based on the type.
     *
     * @param message The message providing details about the error.
     * @param errorType The type of the error (e.g., Syntax).
     */
    Error(const std::string &message, Type errorType) : type_(errorType)
    {
        switch (errorType)
        {
            case Syntax:
                msg_ = "Syntax Error: " + message;
                break;
        }
    }

    /**
     * @brief Returns the error message.
     *
     * @return The error message as a string.
     */
    std::string what() { return msg_; }

private:
    /**
     * @brief The error message providing details about the error.
     */
    std::string msg_;
};

} // namespace s21

#endif // CPP3_SMARTCALC_V2_0_1_MODEL_HEADERS_ERROR_H_
