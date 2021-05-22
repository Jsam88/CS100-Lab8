#ifndef __ADD_HPP__
#define __ADD_HPP__

#include <iostream>
#include "base.hpp"
#include <string>
#include "op.hpp"


class Add: public Base {
	private:
                Base* Lnode = NULL;
                Base* Rnode = NULL;
                std::string str;
        public:
                Add(Base* LEFT, Base* RIGHT) {
                        Lnode = LEFT;
                        Rnode = RIGHT;
                }

		virtual double evaluate() { return Lnode->evaluate() + Rnode->evaluate() ; }
                virtual std::string stringify(){
		str += Lnode->stringify();
		str += " + ";
		str += Rnode->stringify();
		return str;
}      
              
};

#endif
