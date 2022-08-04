#pragma once
#include <iostream>

struct evaluator {
    template <class add>
    static int eval_add(add& expr)
    {
        bool first = true;
        int sum = 0;

        for (int operand : expr) {
            if (!first) {
                std::cout << " + ";
            }
            
            std::cout << operand;

            first = false;
            sum += operand;
        }

        std::cout << " = " << sum << std::endl;
        
        return sum;
    }

    template <class mul>
    static int eval_mul(mul& expr)
    {
        bool first = true;
        int result = 1;

        for (int operand : expr) {
            if (!first) {
                std::cout << " * ";
            }

            std::cout << operand;

            first = false;
            result *= operand;
        }

        std::cout << " = " << result << std::endl;
        
        return result;
    }

    template <class sub>
    static int eval_sub(sub& expr)
    {
        int result = expr.first_operand() - expr.second_operand();
        std::cout << expr.first_operand() << " - " << expr.second_operand()
                  << " = " << result << std::endl;
        
        return result;
    }

    template <class div>
    static int eval_div(div& expr)
    {
        int result = expr.first_operand() / expr.second_operand();
        std::cout << expr.first_operand() << " / " << expr.second_operand()
                  << " = " << result << std::endl;
        
        return result;
    }
};
