
#ifndef CPP3_SMARTCALC_V2_0_1_MODEL_HEADERS_CREDITCALC_H_
#define CPP3_SMARTCALC_V2_0_1_MODEL_HEADERS_CREDITCALC_H_

#include <string>
#include <vector>

namespace s21
{
    /**
     * @brief The ModelCreditCalc class provides functionality for credit calculation in SmartCalc.
     *
     * This class includes methods to set credit-related data such as total loan amount, term, and interest rate,
     * as well as methods to calculate either annuity or differentiated credit payments.
     */
    class ModelCreditCalc
    {
    public:
        /**
         * @brief Default constructor for the ModelCreditCalc class.
         */
        ModelCreditCalc() = default;

        /**
         * @brief Sets credit-related data for calculation.
         *
         * @param totalLoanAmount The total loan amount as a string.
         * @param term The loan term as a string.
         * @param interestRate The interest rate as a string.
         * @param isAnnuity Flag indicating whether to calculate annuity or differentiated credit.
         */
        void setData(const std::string &totalLoanAmount, const std::string &term, const std::string &interestRate, bool isAnnuity);

        /**
         * @brief Calculates credit payments based on the provided data.
         *
         * @return A vector of strings representing the calculated credit payments.
         */
        std::vector<std::string> calculate() const noexcept;

    private:
        /**
         * @brief Calculates annuity credit payments.
         *
         * @return A vector of strings representing the calculated annuity credit payments.
         */
        std::vector<std::string> annuityCredit() const noexcept;

        /**
         * @brief Calculates differentiated credit payments.
         *
         * @return A vector of strings representing the calculated differentiated credit payments.
         */
        std::vector<std::string> differentiatedCredit() const noexcept;

    private:
        /**
         * @brief Flag indicating whether to calculate annuity or differentiated credit.
         */
        bool isAnnuity_;

        /**
         * @brief The total loan amount as a string.
         */
        std::string totalLoanAmount_;

        /**
         * @brief The loan term as a string.
         */
        std::string term_;

        /**
         * @brief The interest rate as a string.
         */
        std::string interestRate_;
    };
} // namespace s21

#endif // CPP3_SMARTCALC_V2_0_1_MODEL_HEADERS_CREDITCALC_H_
