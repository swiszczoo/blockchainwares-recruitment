#include <eval.hpp>
#include <static_visitor.hpp>
#include <utils.hpp>

#include <fc/static_variant.hpp>

namespace static_v {

using variant_expr_t = fc::static_variant<
    add,
    sub,
    mul,
    div>;

static_visitor_impl::static_visitor_impl(std::ostream& ostream) noexcept
    : _os(ostream)
{
}

int static_visitor_impl::operator()(add& expr) const
{
    return evaluator::eval_add(_os, expr);
}

int static_visitor_impl::operator()(sub& expr) const
{
    return evaluator::eval_sub(_os, expr);
}

int static_visitor_impl::operator()(mul& expr) const
{
    return evaluator::eval_mul(_os, expr);
}

int static_visitor_impl::operator()(div& expr) const
{
    return evaluator::eval_div(_os, expr);
}

void run_visitor_demo(std::ostream& ostream)
{
    std::vector<variant_expr_t> variant_expressions {};
    utils::push_back_all(variant_expressions,
        add { 2, 5 },
        add { 1, 2, 3, 4, 5 },
        mul { 2, 2, 2, 2 },
        div { 1024, 128 },
        sub { 42 },
        sub { 43, 12 });

    static_visitor_impl visitor { ostream };

    for (auto& expression : variant_expressions) {
        int result = expression.visit(visitor);
        ostream << "Got " << result << std::endl;
    }
}

};
