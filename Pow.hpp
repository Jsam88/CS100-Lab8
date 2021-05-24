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

		virtual int number_of_children() {
                        int counter = 0;
                        if(Lnode != NULL){
                                ++counter;
                        }
                        if(Rnode != NULL) {
                                ++counter;
                        }
                        return counter;
                }

                virtual Base* get_child(int i){
                        if(i < number_of_children()){
                                if(i == 0){
                                        return Lnode;
                                }
                                else if(i == 1){
                                        return Rnode;
                                }
                        }
                }

                virtual void accept(Visitor* visitor, int i){
                        if(i == 0){
                                visitor->visit_pow_begin();
                        }

                        if(i == 1){
                                visitor->visit_pow_middle();
                        }

                        if(i == 2){
                                visitor->visit_pow_end();
                        }
                }






};

#endif
