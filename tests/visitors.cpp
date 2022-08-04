#include <gtest/gtest.h>

#include <abstract_visitor.hpp>
#include <static_visitor.hpp>

#include <fc/static_variant.hpp>

#include <sstream>

using namespace testing;

TEST(visitors, abstract_visitor)
{
    std::ostringstream oss;
    abstract::abstract_visitor_impl instance { oss };

    abstract::add expr1 { 1, 2 };
    abstract::mul expr2 { 1, 2 };
    abstract::div expr3 { 1, 2 };
    abstract::sub expr4 { 1, 2 };
    EXPECT_EQ(expr1.accept(instance), 3);
    EXPECT_EQ(expr2.accept(instance), 2);
    EXPECT_EQ(expr3.accept(instance), 0);
    EXPECT_EQ(expr4.accept(instance), -1);

    const std::string expected = "1 + 2 = 3\n"
                                 "1 * 2 = 2\n"
                                 "1 / 2 = 0\n"
                                 "1 - 2 = -1\n";

    EXPECT_EQ(oss.str(), expected);
}

TEST(visitors, static_visitor)
{
    std::ostringstream oss;
    static_v::static_visitor_impl instance { oss };

    using expr_t = fc::static_variant<
        static_v::add, 
        static_v::sub, 
        static_v::mul, 
        static_v::div>;

    expr_t expr1 = static_v::add { 1, 2 };
    expr_t expr2 = static_v::mul { 1, 2 };
    expr_t expr3 = static_v::div { 1, 2 };
    expr_t expr4 = static_v::sub { 1, 2 };
    EXPECT_EQ(expr1.visit(instance), 3);
    EXPECT_EQ(expr2.visit(instance), 2);
    EXPECT_EQ(expr3.visit(instance), 0);
    EXPECT_EQ(expr4.visit(instance), -1);

    const std::string expected = "1 + 2 = 3\n"
                                 "1 * 2 = 2\n"
                                 "1 / 2 = 0\n"
                                 "1 - 2 = -1\n";

    EXPECT_EQ(oss.str(), expected);
}
