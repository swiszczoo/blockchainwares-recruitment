#pragma once
#include <initializer_list>
#include <vector>

namespace abstract {

/* Forward declarations */
class visitor;

class expression {
public:
    virtual ~expression() = default;

    expression() = default;
    expression(const expression& other) = default;
    expression(expression&& other) = default;
    expression& operator=(const expression& other) = default;
    expression& operator=(expression&& other) = default;

    virtual int accept(visitor& visitor) = 0;
};

class add : public expression {
public:
    add(std::initializer_list<int> summands) noexcept;

    int accept(visitor& visitor) override;

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

class sub : public expression {
public:
    explicit sub(int operand1) noexcept;
    explicit sub(int operand1, int operand2) noexcept;

    int accept(visitor& visitor) override;

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

class mul : public expression {
public:
    mul(std::initializer_list<int> factors) noexcept;

    int accept(visitor& visitor) override;

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

class div : public expression {
public:
    explicit div(int operand1, int operand2) noexcept;

    int accept(visitor& visitor) override;

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

class visitor {
public:
    virtual ~visitor() = default;

    visitor() = default;
    visitor(const visitor& other) = default;
    visitor(visitor&& other) = default;
    visitor& operator=(const visitor& other) = default;
    visitor& operator=(visitor&& other) = default;

    virtual int operator()(add& expr) = 0;
    virtual int operator()(sub& expr) = 0;
    virtual int operator()(mul& expr) = 0;
    virtual int operator()(div& expr) = 0;
};

void run_visitor();

};
