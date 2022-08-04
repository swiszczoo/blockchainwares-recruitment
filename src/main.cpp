#include <abstract_visitor.hpp>
#include <static_visitor.hpp>

#include <iostream>

int main()
{
    std::cout << "Static visitor and static_variant from fc library:" << std::endl;
    static_v::run_visitor_demo(std::cout);
    std::cout << std::endl;

    std::cout << "Abstract visitor:" << std::endl;
    abstract::run_visitor_demo(std::cout);
    std::cout << std::endl;

    return 0;
}
