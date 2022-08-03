#pragma once
#include <iostream>

struct evaluator {
    template <class add>
    static void eval_add(add& expr)
    {
        bool first = true;
        int sum = 0;

        for (int operand : expr)
        {
            if (!first)
                std::cout << " + ";
            std::cout << operand;

            first = false;
            sum += operand;
        }

        std::cout << " = " << sum << std::endl;
    }

    template <class mul>
    static void eval_mul(mul& expr)
    {
        bool first = true;
        int result = 1;

        for (int operand : expr)
        {
            if (!first)
                std::cout << " * ";
            std::cout << operand;

            first = false;
            result *= operand;
        }

        std::cout << " = " << result << std::endl;
    }

    template <class sub>
    static void eval_sub(sub& expr)
    {
        int result = expr.first_operand() - expr.second_operand();
        std::cout << expr.first_operand() << " - " << expr.second_operand() << " = " << result << std::endl;
    }

    template <class div>
    static void eval_div(div& expr)
    {
        int result = expr.first_operand() / expr.second_operand();
        std::cout << expr.first_operand() << " / " << expr.second_operand() << " = " << result << std::endl;
    }
};
