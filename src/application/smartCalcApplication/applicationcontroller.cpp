#include "applicationcontroller.h"
#include "headers/Model.h"
#include "headers/Token.h"
#include "headers/Tokenizer.h"


double ApplicationController::calculateExpression(const QString &expression) const {
    try {
        s21::Model model_;
        std::vector<s21::Token> tokensInfix;
        std::string str = model_.formatStrForTokenize(expression.toStdString());
        model_.checkCorrectBracketSequence(str);
        tokenize(str, tokensInfix);
        std::vector<s21::Token> tokensPostfix = model_.fromInfixToPostfix(tokensInfix);
        return model_.calculatePolishNotation(tokensPostfix, false);
    } catch (...) {
        return NAN;
    }
}


