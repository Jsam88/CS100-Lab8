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
#include "VisitorLaTeX.hpp"
#include <iostream>
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

int main(int argc, char** argv) {
    Base* two = new Op(2);
    Base* eight = new Op(8);
    Base* add = new Add(two,eight);

    std::cout << PrintLaTeX(add) << std::endl; 
    
    return 0;
}
