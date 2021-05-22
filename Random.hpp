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
};


#endif
