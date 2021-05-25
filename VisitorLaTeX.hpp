#ifndef __VISITORLATEX_HPP__
#define __VISITORLATEX_HPP__

#include "visitor.hpp"
#include "base.hpp"
#include <string>

class VisitorLaTeX : public Visitor{


        public:

        std::string theString;

        std::string get_str(){
                theString = "$" + theString + "$";
                return theString;
        }

        void visit_op(Op* node){
                theString += "{" + node->stringify() + "}" ;
        }

        void visit_rand(Rand* node){
                theString += "{" + node->stringify() + "}";
        }

        void visit_add_begin(Add* node){
                theString += "{(";
        }
        void visit_add_middle(Add* node){
                theString += "+";
        }
        void visit_add_end(Add* node){
                theString += ")}";
        }
        void visit_sub_begin(Sub* node){
                theString += "{(";
        }
        void visit_sub_middle(Sub* node){
                theString += "-";
        }
        void visit_sub_end(Sub* node){
                theString += ")}";
        }
        void visit_mult_begin(Mult* node){
                theString += "{(";
        }
        void visit_mult_middle(Mult* node){
                theString += "\\cdot";
        }
        void visit_mult_end(Mult* node){
                theString += ")}";
        }
        void visit_div_begin(Div* node){
                theString += "{\\frac";
        }
	void visit_div_middle(Div* node) {
	}
        void visit_div_end(Div* node){
                theString += "}";
	}
         void visit_pow_begin(Pow* node){
                theString += "{(";
        }
        void visit_pow_middle(Pow* node){
                theString += "^";
        }
        void visit_pow_end(Pow* node){
                theString += ")}";
        }
};

#endif //__VISITORLATEX_HPP__
