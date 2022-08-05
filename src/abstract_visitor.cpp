#include <abstract_visitor.hpp>
#include <eval.hpp>
#include <utils.hpp>

#include <memory>

namespace abstract {

abstract_visitor_impl::abstract_visitor_impl(std::ostream& ostream) noexcept
    : _os(ostream)
{
}

int abstract_visitor_impl::operator()(const add& expr)
{
    return evaluator::eval_add(_os, expr);
}

int abstract_visitor_impl::operator()(const sub& expr)
{
    return evaluator::eval_sub(_os, expr);
}

int abstract_visitor_impl::operator()(const mul& expr)
{
    return evaluator::eval_mul(_os, expr);
}

int abstract_visitor_impl::operator()(const div& expr)
{
    return evaluator::eval_div(_os, expr);
}

void run_visitor_demo(std::ostream& ostream)
{
    std::vector<std::unique_ptr<abstract::expression>> abstract_expressions {};
    utils::push_back_all(abstract_expressions,
        std::make_unique<add>(std::initializer_list<int> { 2, 5 }),
        std::make_unique<add>(std::initializer_list<int> { 1, 2, 3, 4, 5 }),
        std::make_unique<mul>(std::initializer_list<int> { 2, 2, 2, 2 }),
        std::make_unique<div>(1024, 128),
        std::make_unique<sub>(42),
        std::make_unique<sub>(43, 12));

    abstract_visitor_impl visitor { ostream };

    for (auto& expression : abstract_expressions) {
        int result = expression->accept(visitor);
        ostream << "Got " << result << std::endl;
    }
}

};
