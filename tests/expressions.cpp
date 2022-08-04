#include <gtest/gtest.h>

#include <abstract_visitor.hpp>
#include <eval.hpp>
#include <static_visitor.hpp>

#include <sstream>

using namespace testing;

class expressions : public Test {
protected:
    void SetUp() override
    {
        oss = std::ostringstream {};
    }

    std::ostringstream oss;
};

TEST_F(expressions, abstract_addition)
{
    EXPECT_THROW(abstract::add {}, std::invalid_argument);

    abstract::add test1 { 1, 2, 3, 4 };
    EXPECT_EQ(evaluator::eval_add(oss, test1), 10);
    EXPECT_EQ(oss.str(), "1 + 2 + 3 + 4 = 10\n");

    oss.str("");

    abstract::add test2 { 8, -12 };
    EXPECT_EQ(evaluator::eval_add(oss, test2), -4);
    EXPECT_EQ(oss.str(), "8 + -12 = -4\n");
}

TEST_F(expressions, static_addition)
{
    EXPECT_THROW(static_v::add {}, std::invalid_argument);

    static_v::add test1 { 1, 2, 3, 4 };
    EXPECT_EQ(evaluator::eval_add(oss, test1), 10);
    EXPECT_EQ(oss.str(), "1 + 2 + 3 + 4 = 10\n");

    oss.str("");

    static_v::add test2 { 8, -12 };
    EXPECT_EQ(evaluator::eval_add(oss, test2), -4);
    EXPECT_EQ(oss.str(), "8 + -12 = -4\n");
}

TEST_F(expressions, abstract_subtraction)
{
    abstract::sub test1 { 10, 5 };
    EXPECT_EQ(evaluator::eval_sub(oss, test1), 5);
    EXPECT_EQ(oss.str(), "10 - 5 = 5\n");

    oss.str("");

    abstract::sub test2 { 42 };
    EXPECT_EQ(evaluator::eval_sub(oss, test2), -42);
    EXPECT_EQ(oss.str(), "0 - 42 = -42\n");
}

TEST_F(expressions, static_subtraction)
{
    static_v::sub test1 { 10, 5 };
    EXPECT_EQ(evaluator::eval_sub(oss, test1), 5);
    EXPECT_EQ(oss.str(), "10 - 5 = 5\n");

    oss.str("");

    static_v::sub test2 { 42 };
    EXPECT_EQ(evaluator::eval_sub(oss, test2), -42);
    EXPECT_EQ(oss.str(), "0 - 42 = -42\n");
}

TEST_F(expressions, abstract_multiplication)
{
    EXPECT_THROW(abstract::mul {}, std::invalid_argument);

    abstract::mul test1 { 3, 3, 3, 3 };
    EXPECT_EQ(evaluator::eval_mul(oss, test1), 81);
    EXPECT_EQ(oss.str(), "3 * 3 * 3 * 3 = 81\n");

    oss.str("");

    abstract::mul test2 { 4, -3 };
    EXPECT_EQ(evaluator::eval_mul(oss, test2), -12);
    EXPECT_EQ(oss.str(), "4 * -3 = -12\n");
}

TEST_F(expressions, static_multiplication)
{
    EXPECT_THROW(static_v::mul {}, std::invalid_argument);

    static_v::mul test1 { 3, 3, 3, 3 };
    EXPECT_EQ(evaluator::eval_mul(oss, test1), 81);
    EXPECT_EQ(oss.str(), "3 * 3 * 3 * 3 = 81\n");

    oss.str("");

    static_v::mul test2 { 4, -3 };
    EXPECT_EQ(evaluator::eval_mul(oss, test2), -12);
    EXPECT_EQ(oss.str(), "4 * -3 = -12\n");
}

TEST_F(expressions, abstract_division)
{
    abstract::div test1 { 48, 6 };
    EXPECT_EQ(evaluator::eval_div(oss, test1), 8);
    EXPECT_EQ(oss.str(), "48 / 6 = 8\n");

    oss.str("");

    abstract::div test2 { 1, 2 };
    EXPECT_EQ(evaluator::eval_div(oss, test2), 0);
    EXPECT_EQ(oss.str(), "1 / 2 = 0\n");
}

TEST_F(expressions, static_division)
{
    static_v::div test1 { 48, 6 };
    EXPECT_EQ(evaluator::eval_div(oss, test1), 8);
    EXPECT_EQ(oss.str(), "48 / 6 = 8\n");

    oss.str("");

    static_v::div test2 { 1, 2 };
    EXPECT_EQ(evaluator::eval_div(oss, test2), 0);
    EXPECT_EQ(oss.str(), "1 / 2 = 0\n");
}
