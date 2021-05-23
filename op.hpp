#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include <string>
#include <iostream>
#include <sstream>

class Op : public Base {
    private:
        double num;
	std::string str;

    public:
	Op(double value) : Base() { num = value; }

	virtual double evaluate() { return num; }
        virtual std::string stringify() {
			std::stringstream out;
            out << num;
            return out.str();
		}

    virtual int number_of_children(){
        return num;
    }

    virtual Base* get_child(int i){
        return NULL;
    }

    virtual void num_of_visits(Visitor* visitor, int i){
        visitor->visit_op();
    }		
};
#endif //__OP_HPP__
