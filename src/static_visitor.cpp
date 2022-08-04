#include <eval.hpp>
#include <static_visitor.hpp>
#include <utils.hpp>

#include <fc/static_variant.hpp>

#include <iostream>
#include <vector>

namespace static_v {

/* class add */

add::add(std::initializer_list<int> summands) noexcept
    : _summands(summands.begin(), summands.end())
{
}

/* class sub */

sub::sub(int operand1) noexcept
    : sub(0, operand1)
{
}

sub::sub(int operand1, int operand2) noexcept
    : _op1(operand1)
    , _op2(operand2)
{
}

/* class mul */

mul::mul(std::initializer_list<int> factors) noexcept
    : _factors(factors.begin(), factors.end())
{
}

/* class div */

div::div(int operand1, int operand2) noexcept
    : _op1(operand1)
    , _op2(operand2)
{
}

/* visitor implementation */

using variant_expr_t = fc::static_variant<
    static_v::add,
    static_v::sub,
    static_v::mul,
    static_v::div>;

class static_visitor_impl {
public:
    using result_type = int;

    int operator()(static_v::add& expr)
    {
        return evaluator::eval_add(expr);
    }

    int operator()(static_v::sub& expr)
    {
        return evaluator::eval_sub(expr);
    }

    int operator()(static_v::mul& expr)
    {
        return evaluator::eval_mul(expr);
    }

    int operator()(static_v::div& expr)
    {
        return evaluator::eval_div(expr);
    }
};

void run_visitor()
{
    std::vector<variant_expr_t> variant_expressions {};
    utils::push_back_all(variant_expressions,
        static_v::add { 2, 5 },
        static_v::add { 1, 2, 3, 4, 5 },
        static_v::mul { 2, 2, 2, 2 },
        static_v::div { 1024, 128 },
        static_v::sub { 42 },
        static_v::sub { 43, 12 });

    static_visitor_impl visitor;

    for (auto& expression : variant_expressions) {
        int result = expression.visit(visitor);
        std::cout << "Got " << result << std::endl;
    }
}

};
