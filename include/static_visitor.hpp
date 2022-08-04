#pragma once
#include <static_expressions.hpp>

#include <ostream>

namespace static_v {

class static_visitor_impl {
public:
    using result_type = int;

    static_visitor_impl(std::ostream& ostream) noexcept;

    int operator()(add& expr) const;
    int operator()(sub& expr) const;
    int operator()(mul& expr) const;
    int operator()(div& expr) const;
    
private:
    std::ostream& _os;
};

void run_visitor_demo(std::ostream& ostream);

};
