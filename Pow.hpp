#ifndef __POW_HPP__
#define __POW_HPP__

#include <iostream>
#include "base.hpp"
#include <string>
#include <cmath>
#include "op.hpp"

class Pow: public Base {

	private:
                Base* Lnode = NULL;
                Base* Rnode = NULL;
                std::string str;
        public:
                Pow(Base * LEFT, Base* RIGHT) {
                        Lnode = LEFT;
                        Rnode = RIGHT;
                }

                virtual double evaluate() { return pow(Lnode->evaluate(), Rnode->evaluate()) ; }
                virtual std::string stringify(){
                str += Lnode->stringify();
                str +=  " ^ ";
                str += Rnode->stringify();
                return str;
}

};

#endif
