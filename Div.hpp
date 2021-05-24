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
                                visitor->visit_div_begin(this);
                        }

                        if(i == 1){
                                visitor->visit_div_middle(this);
                        }

                        if(i == 2){
                                visitor->visit_div_end(this);
                        }
                }
};
#endif
