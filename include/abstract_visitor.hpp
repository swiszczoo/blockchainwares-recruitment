#pragma once
#include <initializer_list>
#include <vector>

namespace abstract
{

/* Forward declarations */
class visitor;

class expression
{
public:
    virtual void accept(visitor& visitor) = 0;
};

class add : public expression
{
public:
    add(std::initializer_list<int> summands) noexcept;

    void accept(visitor& visitor) override;

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

class sub : public expression
{
public:
    explicit sub(int operand1) noexcept;
    explicit sub(int operand1, int operand2) noexcept;

    void accept(visitor& visitor) override;

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

class mul : public expression
{
public:
    mul(std::initializer_list<int> factors) noexcept;

    void accept(visitor& visitor) override;

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

class div : public expression
{
public:
    explicit div(int operand1, int operand2) noexcept;

    void accept(visitor& visitor) override;

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

class visitor
{
public:
    virtual void operator() (add& expr) = 0;
    virtual void operator() (sub& expr) = 0;
    virtual void operator() (mul& expr) = 0;
    virtual void operator() (div& expr) = 0;
};

};
