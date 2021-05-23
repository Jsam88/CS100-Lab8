#ifndef __DIV_HPP__
#define __DIV_HPP__

#include <iostream>
#include "base.hpp"
#include "op.hpp"
#include <string>

class Div: public Base {
	private:
                Base* Lnode = NULL;
                Base* Rnode = NULL;
                std::string str;

        public:
                Div(Base* LEFT, Base* RIGHT) {
                        Lnode = LEFT;
                        Rnode = RIGHT;
                }
                virtual double evaluate() { return Lnode->evaluate() / Rnode->evaluate(); }
                virtual std::string stringify() {
			 str += Lnode->stringify(); 
                         str += " / "; 
                         str += Rnode->stringify();
                         return str;
	}
};

#endif
