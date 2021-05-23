#ifndef __RANDOM_HPP__
#define __RANDOM_HPP__

#include <iostream>
#include "base.hpp"
#include "op.hpp"
#include <string>

class Random: public Base {
        public:
                Random() { num = rand() % 100; }
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

    virtual void num_of_visits(Visitor* visitor, int i){
        visitor->visit_random();
    } 




};


#endif
