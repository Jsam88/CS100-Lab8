#ifndef __SUB_HPP__
#define __SUB_HPP__

#include <iostream>
#include "base.hpp"
#include <string>
#include "op.hpp"


class Sub: public Base {

	private:
                Base* Lnode = NULL;
                Base* Rnode = NULL;
                std::string str;

        public:
                Sub(Base* LEFT, Base* RIGHT) {
                        Lnode = LEFT;
                        Rnode = RIGHT;
                }

               
		virtual double evaluate() { return Lnode->evaluate() - Rnode->evaluate() ; }
                virtual std::string stringify(){
                str += Lnode->stringify();
                str +=  " - ";
                str += Rnode->stringify();
                return str;
}
              
};

#endif
