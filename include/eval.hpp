#pragma once
#include <ostream>

struct evaluator {
    template <class add>
    static int eval_add(std::ostream& os, add& expr)
    {
        bool first = true;
        int sum = 0;

        for (int operand : expr) {
            if (!first) {
                os << " + ";
            }

            os << operand;

            first = false;
            sum += operand;
        }

        os << " = " << sum << std::endl;

        return sum;
    }

    template <class mul>
    static int eval_mul(std::ostream& os, mul& expr)
    {
        bool first = true;
        int result = 1;

        for (int operand : expr) {
            if (!first) {
                os << " * ";
            }

            os << operand;

            first = false;
            result *= operand;
        }

        os << " = " << result << std::endl;

        return result;
    }

    template <class sub>
    static int eval_sub(std::ostream& os, sub& expr)
    {
        int result = expr.first_operand() - expr.second_operand();
        os << expr.first_operand() << " - " << expr.second_operand()
                  << " = " << result << std::endl;

        return result;
    }

    template <class div>
    static int eval_div(std::ostream& os, div& expr)
    {
        int result = expr.first_operand() / expr.second_operand();
        os << expr.first_operand() << " / " << expr.second_operand()
           << " = " << result << std::endl;

        return result;
    }
};
