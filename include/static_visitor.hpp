#pragma once
#include <initializer_list>
#include <vector>

namespace static_v {

class add {
public:
    add(std::initializer_list<int> summands) noexcept;

    inline std::vector<int>::const_iterator begin() const
    {
        return _summands.begin();
    }

    inline std::vector<int>::const_iterator end() const
    {
        return _summands.end();
    }

private:
    std::vector<int> _summands;
};

class sub {
public:
    explicit sub(int operand1) noexcept;
    explicit sub(int operand1, int operand2) noexcept;

    inline int first_operand() const
    {
        return _op1;
    }

    inline int second_operand() const
    {
        return _op2;
    }

private:
    int _op1, _op2;
};

class mul {
public:
    mul(std::initializer_list<int> factors) noexcept;

    inline std::vector<int>::const_iterator begin() const
    {
        return _factors.begin();
    }

    inline std::vector<int>::const_iterator end() const
    {
        return _factors.end();
    }

private:
    std::vector<int> _factors;
};

class div {
public:
    explicit div(int operand1, int operand2) noexcept;

    inline int first_operand() const
    {
        return _op1;
    }

    inline int second_operand() const
    {
        return _op2;
    }

private:
    int _op1, _op2;
};

};
