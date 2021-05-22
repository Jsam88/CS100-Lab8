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
};

#endif //__OP_HPP__
