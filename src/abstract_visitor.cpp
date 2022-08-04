#include <abstract_visitor.hpp>
#include <eval.hpp>
#include <utils.hpp>

#include <iostream>
#include <memory>
#include <vector>

namespace abstract {

/* class add */

add::add(std::initializer_list<int> summands) noexcept
    : _summands(summands.begin(), summands.end())
{
}

int add::accept(visitor& visitor)
{
    return visitor(*this);
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

int sub::accept(visitor& visitor)
{
    return visitor(*this);
}

/* class mul */

mul::mul(std::initializer_list<int> factors) noexcept
    : _factors(factors.begin(), factors.end())
{
}

int mul::accept(visitor& visitor)
{
    return visitor(*this);
}

/* class div */

div::div(int operand1, int operand2) noexcept
    : _op1(operand1)
    , _op2(operand2)
{
}

int div::accept(visitor& visitor)
{
    return visitor(*this);
}

/* visitor implementation */

class abstract_visitor_impl : public abstract::visitor {
public:
    int operator()(abstract::add& expr) override
    {
        return evaluator::eval_add(expr);
    }

    int operator()(abstract::sub& expr) override
    {
        return evaluator::eval_sub(expr);
    }

    int operator()(abstract::mul& expr) override
    {
        return evaluator::eval_mul(expr);
    }

    int operator()(abstract::div& expr) override
    {
        return evaluator::eval_div(expr);
    }
};

void run_visitor()
{
    std::vector<std::unique_ptr<abstract::expression>> abstract_expressions {};
    utils::push_back_all(abstract_expressions,
        std::make_unique<abstract::add>(std::initializer_list<int> { 2, 5 }),
        std::make_unique<abstract::add>(std::initializer_list<int> { 1, 2, 3, 4, 5 }),
        std::make_unique<abstract::mul>(std::initializer_list<int> { 2, 2, 2, 2 }),
        std::make_unique<abstract::div>(1024, 128),
        std::make_unique<abstract::sub>(42),
        std::make_unique<abstract::sub>(43, 12));

    abstract_visitor_impl visitor;

    for (auto& expression : abstract_expressions) {
        int result = expression->accept(visitor);
        std::cout << "Got " << result << std::endl;
    }
}

};
