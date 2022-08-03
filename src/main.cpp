#include <abstract_visitor.hpp>
#include <eval.hpp>
#include <utils.hpp>

#include <iostream>
#include <memory>
#include <vector>

class abstract_visitor_impl : public abstract::visitor
{
public:
    void operator() (abstract::add& expr) override
    {
        evaluator::eval_add(expr);
    }

    void operator() (abstract::sub& expr) override
    {
        evaluator::eval_sub(expr);
    }

    void operator() (abstract::mul& expr) override
    {
        evaluator::eval_mul(expr);
    }

    void operator() (abstract::div& expr) override
    {
        evaluator::eval_div(expr);
    }
};

void run_abstract_visitor()
{
    std::vector<std::unique_ptr<abstract::expression>> abstract_expressions;
    utils::push_back_all(abstract_expressions,
                         std::make_unique<abstract::add>(std::initializer_list<int>{2, 5}),
                         std::make_unique<abstract::add>(std::initializer_list<int>{1, 2, 3, 4, 5}),
                         std::make_unique<abstract::mul>(std::initializer_list<int>{2, 2, 2, 2}),
                         std::make_unique<abstract::div>(1024, 128),
                         std::make_unique<abstract::sub>(42),
                         std::make_unique<abstract::sub>(43, 12));

    abstract_visitor_impl visitor;

    for (auto& expression : abstract_expressions) 
    {
        expression->accept(visitor);
    }
}

int main()
{
    run_abstract_visitor();

    return 0;
}
