#include "gtest/gtest.h"
#include <string>
#include "base.hpp"
#include "op.hpp"
#include "Add.hpp"
#include "Div.hpp"
#include "Mult.hpp"
#include "Pow.hpp"
#include "Sub.hpp"
#include "Random.hpp"
#include "iterator.hpp"
#include "visitor.hpp"
#include "VisitorLaTeX.hpp"
using namespace std;

string PrintLaTeX(Base* ptr){
        VisitorLaTeX v;
        string out;
        Iterator it(ptr);

        while(!it.is_done()){
            it.current_node()->accept(&v, it.current_index());
            it.next();
        }
        out = v.get_str();
        return out;
}


TEST(numberOfChildren_test, add_numberOfChildren){
        Op* eight = new Op(8);
        Op* seven = new Op(7);
        Add* test = new Add(eight, seven);
        EXPECT_EQ(test->number_of_children(), 2);
}

TEST(getChild_test, add_getChildLeft){
        Op* eight = new Op(8);
        Op* seven = new Op(7);
        Add* test = new Add(eight, seven);
        EXPECT_EQ(test->get_child(0), eight);
}

TEST(getChild_test, add_getChildRight){
        Op* eight = new Op(8);
        Op* seven = new Op(7);
        Add* test = new Add(eight, seven);
        EXPECT_EQ(test->get_child(1), seven);
}

TEST(getChild_test, add_getChildNull){
        Op* five = new Op(5);
        Op* one = new Op(1);
        Add* test = new Add(five, one);
        EXPECT_EQ(test->get_child(2), nullptr);
}

TEST(PrintLaTeX_test, sub_test){
        Base* op1 = new Op(8);
        Base* op2 = new Op(2);
        Base* test = new Sub(op1,op2);
        EXPECT_EQ(PrintLaTeX(test), "${({8}-{2})}$");
}

TEST(PrintLaTeX_test, add_test){
        Base* op1 = new Op(8);
        Base* op2 = new Op(10);
        Base* test = new Add(op1,op2);
        EXPECT_EQ(PrintLaTeX(test), "${({8}+{10})}$");
}

TEST(PrintLaTeX_test, pow_test){
        Base* op1 = new Op(3);
        Base* op2 = new Op(3);
        Base* test = new Pow(op1,op2);
        EXPECT_EQ(PrintLaTeX(test), "${({3}^{3})}$");
}

TEST(PrintLaTeX_test, mult_test){
        Base* op1 = new Op(8);
        Base* op2 = new Op(1);
        Base* test = new Mult(op1,op2);
        EXPECT_EQ(PrintLaTeX(test), "${({8}\\cdot{1})}$");
}

TEST(PrintLaTeX_test, div_test){
        Base* op1 = new Op(8);
        Base* op2 = new Op(10);
        Base* test = new Div(op1,op2);
        EXPECT_EQ(PrintLaTeX(test), "${\\frac{8}{10}}$");
}

TEST(PrintLaTeX_test, add_sub_test){
        Base* op1 = new Op(1);
        Base* op2 = new Op(5);
        Base* op3 = new Op(0);
        Base* test = new Sub(op2,op3);
        Base *test2 = new Add(op1, test);
        EXPECT_EQ(PrintLaTeX(test2), "${({1}+{({5}-{0})})}$");
}

TEST(PrintLaTeX_test, mult_div_pow_test){
        Base* op1 = new Op(2);
        Base* op2 = new Op(5);
        Base* test = new Mult(op1,op2);
        Base* test2 = new Pow(op2, op1);
        Base* test3 = new Div(test, test2);
        EXPECT_EQ(PrintLaTeX(test3), "${\\frac{({2}\\cdot{5})}{({5}^{2})}}$");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
