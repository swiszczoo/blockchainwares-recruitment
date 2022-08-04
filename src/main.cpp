#include <abstract_visitor.hpp>
#include <eval.hpp>
#include <static_visitor.hpp>
#include <utils.hpp>

#include <fc/static_variant.hpp>

#include <algorithm>
#include <functional>
#include <iostream>
#include <memory>
#include <vector>

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

void run_static_visitor()
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

void run_abstract_visitor()
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

int main()
{
    std::cout << "Static visitor from fc library:" << std::endl;
    run_static_visitor();
    std::cout << std::endl;

    std::cout << "Abstract visitor:" << std::endl;
    run_abstract_visitor();
    std::cout << std::endl;

    return 0;
}
