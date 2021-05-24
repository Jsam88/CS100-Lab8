#include "gtest/gtest.h"
#include <string>

#include "iterator.hpp"
#include "visitor.hpp"
#include "Add.hpp"
#include "base.hpp"
#include "Div.hpp"
#include "Mult.hpp"
#include "op.hpp"
#include "Pow.hpp"
#include "Sub.hpp"
#include "Random.hpp"


TEST(LatexTest, testADD){
	Base* val1 = new Op(5);
	Base* val2 = new Op(4);
	Add* add = new Add(val1, val2);
	Iterator* num = new Iterator(add);
    	VisitorLaTeX* form = new VisitorLaTeX();
//	for(num; !num->is_done(); num->next()){
//		num->current_node()->accept(form,num->current_index());
//	}
	EXPECT_EQ(form->getString(), "${({5} + {4})}$");
}

TEST(LatexTest, testSub){
        Base* val1 = new Op(5);
        Base* val2 = new Op(4);
        Sub* sub = new Sub(val1, val2);
        Iterator* num = new Iterator(sub);
        VisitorLaTeX* form = new VisitorLaTeX();
        for(num; !num->is_done(); num->next()){
                num->current_node()->accept(form,num->current_index());
        }
        EXPECT_EQ(form->getString(), "${({5} - {4})}$");
}

TEST(LatexTest, testDiv){
        Base* val1 = new Op(8);
        Base* val2 = new Op(4);
        Div* div = new Div(val1, val2);
        Iterator* num = new Iterator(div);
        VisitorLaTeX* form = new VisitorLaTeX();
        for(num; !num->is_done(); num->next()){
                num->current_node()->accept(form,num->current_index());
        }
        EXPECT_EQ(form->getString(), "${\\frac{8}{4}}$");
}

TEST(LatexTest, testMult){
        Base* val1 = new Op(4);
        Base* val2 = new Op(2);
        Mult* mult = new Mult(val1, val2);
        Iterator* num = new Iterator(mult);
        VisitorLaTeX* form = new VisitorLaTeX();
        for(num; !num->is_done(); num->next()){
                num->current_node()->accept(form,num->current_index());
        }
        EXPECT_EQ(form->getString(), "${({4}\\cdot{2})}$");
}


TEST(LatexTest, testPow){
        Base* val1 = new Op(6);
        Base* val2 = new Op(2);
        Pow* pow = new Pow(val1, val2);
        Iterator* num = new Iterator(pow);
        VisitorLaTeX* form = new VisitorLaTeX();
        for(num; !num->is_done(); num->next()){
                num->current_node()->accept(form,num->current_index());
        }
        EXPECT_EQ(form->getString(), "${({6}^{2})}$");
}

TEST(LatexTest, testALL){
        Base* val1 = new Op(4);
    	Base* val2 = new Op(2);
    	Base* val3 = new Op(3);

        Add* addition = new Add(val3, val2);
    	Sub* subtract = new Sub(val2, val1);
    	Mult* multiply = new Mult(val3, val2);
    	Div* divide = new Div(val3, val2);
    	Pow* power = new Pow(val2, val3);
    	      
        Iterator* num = new Iterator(addition);

        VisitorLaTeX* form = new VisitorLaTeX();
        for(num; !num->is_done(); num->next()){
                num->current_node()->accept(form, num->current_index());
        }

        EXPECT_EQ(form->getString(), "${({\\frac{({3}\\cdot{2})}{({2}-{4})}}+{({2}^{3})})}$");
}

TEST(MethodAddTest, checkAdd){
	Base* val1 = new Op(2);
	Base* val2 = new Op(4);
	Base* add = new Add(val1, val2);

	EXPECT_EQ(add->number_of_children(), 2);
	EXPECT_EQ(add->get_child(0), val1);
	EXPECT_EQ(add->get_child(1), val2);
	EXPECT_EQ(add->stringify(), "(2 + 4)");
	EXPECT_EQ(add->evaluate(), 6);
}

TEST(MethodSubTest, checkSub){
        Base* val1 = new Op(5);
        Base* val2 = new Op(1);
        Base* sub = new Sub(val1, val2);

        EXPECT_EQ(sub->number_of_children(), 2);
        EXPECT_EQ(sub->get_child(0), val1);
        EXPECT_EQ(sub->get_child(1), val2);
        EXPECT_EQ(sub->stringify(), "(5 - 1)");
        EXPECT_EQ(sub->evaluate(), 4);
}
TEST(MethodDivTest, checkDiv){
        Base* val1 = new Op(10);
        Base* val2 = new Op(5);
        Base* div = new Div(val1, val2);

        EXPECT_EQ(div->number_of_children(), 2);
        EXPECT_EQ(div->get_child(0), val1);
        EXPECT_EQ(div->get_child(1), val2);
        EXPECT_EQ(div->stringify(), "(10 / 5)");
        EXPECT_EQ(div->evaluate(), 2);

}

TEST(MethodMultTest, checkMult){
        Base* val1 = new Op(5);
        Base* val2 = new Op(3);
        Base* mult = new Mult(val1, val2);

        EXPECT_EQ(mult->number_of_children(), 2);
        EXPECT_EQ(mult->get_child(0), val1);
        EXPECT_EQ(mult->get_child(1), val2);
        EXPECT_EQ(mult->stringify(), "(5 * 3)");
        EXPECT_EQ(mult->evaluate(), 15);

}


TEST(MethodPowTest, checkPow){
        Base* val1 = new Op(4);
        Base* val2 = new Op(2);
        Base* pow = new Pow(val1, val2);

        EXPECT_EQ(pow->number_of_children(), 2);
        EXPECT_EQ(pow->get_child(0), val1);
        EXPECT_EQ(pow->get_child(1), val2);
        EXPECT_EQ(pow->stringify(), "(4 ** 2)");
        EXPECT_EQ(pow->evaluate(), 16);

}

TEST(IteratorTest, iteratorCheck){
        Base* num1 = new Op(6);
        Base* num2 = new Op(4);
        Base* add = new Add(num1, num2);

	Iterator* val = new Iterator(add);
	EXPECT_EQ(val->current_node(), add);
	EXPECT_EQ(val->current_index(), 0);
	EXPECT_EQ(val->is_done(), false);

	val->next();
        EXPECT_EQ(val->current_node(), num1);
        EXPECT_EQ(val->current_index(), 0);
        EXPECT_EQ(val->is_done(), false);

        val->next();
        EXPECT_EQ(val->current_node(), add);
        EXPECT_EQ(val->current_index(), 6);
        EXPECT_EQ(val->is_done(), false);

	val->next();
        EXPECT_EQ(val->current_node(), num2);
        EXPECT_EQ(val->current_index(), 0);
        EXPECT_EQ(val->is_done(), false);

	val->next();
	EXPECT_EQ(val->is_done(), false);
        EXPECT_EQ(val->current_node(), add);
        EXPECT_EQ(val->current_index(), 4);

	val->next();
	EXPECT_EQ(val->is_done(), true);
}

TEST(IteratorTest, stringTest){
        Base* num5 = new Op(5);
        Base* num1 = new Op(1);
        Base* num2 = new Op(2);
        Base* add = new Add(num5,num1);
        Base* sub = new Sub(num2,num1);
        Base* pow = new Pow(num1,num2);
        Base* mult = new Mult(sub, pow);
        Base* div = new Div(add, mult);

	std::string string = "";
	Iterator* val = new Iterator(div);

	for(val; !val->is_done(); val->next()){
		string = val->current_node()->stringify();
	}
        EXPECT_EQ(string, "((5 + 1) / ((2 - 1) * (1 ** 2)))");

}
TEST(IteratorTest, calcTest){
        Base* num5 = new Op(5);
        Base* num1 = new Op(1);
        Base* num2 = new Op(2);     
        Base* add = new Add(num5,num1);
        Base* sub = new Sub(num2,num1);
        Base* pow = new Pow(num1,num2);
        Base* mult = new Mult(sub, pow);
        Base* div = new Div(add, mult);

        double calc = 0;
        Iterator* val = new Iterator(div);

        for(val; !val->is_done(); val->next()){
                calc = val->current_node()->evaluate();
        }
        EXPECT_EQ(calc, 6);
}

TEST(ExpressionTree, fullTest){
        Base* num5 = new Op(5);
        Base* num1 = new Op(1);
        Base* num2 = new Op(2);
        Base* add = new Add(num5,num1);
        Base* sub = new Sub(num2,num1);
        Base* pow = new Pow(num1,num2);
        Base* mult = new Mult(sub, pow);
        Base* div = new Div(add, mult);

        EXPECT_EQ(div->number_of_children(), 2);
        EXPECT_EQ(div->get_child(0), add);
        EXPECT_EQ(div->get_child(1), mult);
        EXPECT_EQ(div->stringify(), "((5 + 1) / ((2 - 1) * (1 ** 2)))");
        EXPECT_EQ(div->evaluate(), 6);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
