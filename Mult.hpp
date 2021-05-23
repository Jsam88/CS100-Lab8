#ifndef __MULT_HPP__
#define __MULT_HPP__

#include <iostream>
#include "base.hpp"
#include "op.hpp"
#include <string>

class Mult: public Base {
	 private:
                Base* Lnode = NULL;
                Base* Rnode = NULL;
                std::string str;
	 public:
                Mult(Base* leftPtr, Base* rightPtr) {
                        Lnode = leftPtr;
                        Rnode = rightPtr;
                }

                virtual double evaluate() { return Lnode->evaluate() * Rnode->evaluate(); }
                virtual std::string stringify() {
			 str += Lnode->stringify();
			 str += " * "; 
			 str += Rnode->stringify();
			 return str;
	}
};

#endif
