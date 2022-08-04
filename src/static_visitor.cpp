#include <static_visitor.hpp>

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

};
