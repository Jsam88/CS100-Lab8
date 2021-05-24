#ifndef __RANDOM_HPP__
#define __RANDOM_HPP__

#include <iostream>
#include "base.hpp"
#include "op.hpp"
#include <string>
#include "visitor.hpp"

class Rand: public Base {
        public:
                Rand() { num = rand() % 100; }
                virtual double evaluate() { return num; }
                virtual std::string stringify() { return std::to_string(num);}
        private:
                double num;

	virtual int number_of_children(){
        return num;
    }

    virtual Base* get_child(int i){
        return NULL;
    }

    virtual void accept(Visitor* visitor, int i){
        visitor->visit_rand(this);
    } 




};


#endif
