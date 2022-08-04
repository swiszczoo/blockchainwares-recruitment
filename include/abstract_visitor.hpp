#pragma once
#include <abstract_expressions.hpp>

#include <ostream>

namespace abstract {

class abstract_visitor_impl : public visitor {
public:
    abstract_visitor_impl(std::ostream& ostream) noexcept;

    int operator()(const add& expr) override;
    int operator()(const sub& expr) override;
    int operator()(const mul& expr) override;
    int operator()(const div& expr) override;

private:
    std::ostream& _os;
};

void run_visitor_demo(std::ostream& ostream);

};
