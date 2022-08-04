#include <abstract_expressions.hpp>

#include <stdexcept>

namespace abstract {

/* class add */

add::add(std::initializer_list<int> summands) noexcept(false)
    : _summands(summands.begin(), summands.end())
{
    if (summands.size() == 0) {
        throw std::invalid_argument("summand list cannot be empty");
    }
}

int add::accept(visitor& visitor) const
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

int sub::accept(visitor& visitor) const
{
    return visitor(*this);
}

/* class mul */

mul::mul(std::initializer_list<int> factors) noexcept(false)
    : _factors(factors.begin(), factors.end())
{
    if (factors.size() == 0) {
        throw std::invalid_argument("factor list cannot be empty");
    }
}

int mul::accept(visitor& visitor) const
{
    return visitor(*this);
}

/* class div */

div::div(int operand1, int operand2) noexcept
    : _op1(operand1)
    , _op2(operand2)
{
}

int div::accept(visitor& visitor) const
{
    return visitor(*this);
}

};
