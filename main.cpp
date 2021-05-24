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
#include <iostream>

inline std::string PrintLaTeX(Base* ptr){
    Iterator* test = new Iterator(ptr);

    VisitorLaTeX* v = new VisitorLaTeX();
	while(!test->is_done()){
		test->current_node()->accept(v,test->current_index());
		test->next();
	}
    return  v->getString();
}

int main() {
	Base* val1 = new Op(2);
	Base* val2 = new Op(5);
	Base* add = new Add(val1, val2);
	std::cout << PrintLaTeX(add) <<std::endl;
	return 0;
}
