#include "visitor.hpp"
#include "Add.hpp"
#include "base.hpp"
#include "Div.hpp"
#include "Mult.hpp"
#include "op.hpp"
#include "Pow.hpp"
#include "Sub.hpp"
#include "Random.hpp"

VisitorLaTeX::VisitorLaTeX() {
    str = "$";
}

std::string VisitorLaTeX::getString(){
    return str + "$";
}

void VisitorLaTeX::visit_op(Op* node){
    str += "{" + node->stringify() + "}";
}

void VisitorLaTeX::visit_rand(Rand* node){
    str += "{" + node->stringify() + "}";
}


void VisitorLaTeX::visit_add_begin(Add* node){
    str += "{(";
}
void VisitorLaTeX::visit_add_middle(Add* node){
    str += "+";
}
void VisitorLaTeX::visit_add_end(Add* node){
    str += ")}";
}


void VisitorLaTeX::visit_div_begin(Div* node){
    str += "{\\frac";
}
void VisitorLaTeX::visit_div_middle(Div* node){
    str += "";
}
void VisitorLaTeX::visit_div_end(Div* node){
    str += "}";
}


void VisitorLaTeX::visit_mult_begin(Mult* node){
    str += "{(";
}
void VisitorLaTeX::visit_mult_middle(Mult* node){
    str += "\\cdot";
}
void VisitorLaTeX::visit_mult_end(Mult* node){
    str += ")}";
}


void VisitorLaTeX::visit_pow_begin(Pow* node){
    str += "{(";
}
void VisitorLaTeX::visit_pow_middle(Pow* node){
    str += "^";
}
void VisitorLaTeX::visit_pow_end(Pow* node){
    str += ")}";
}


void VisitorLaTeX::visit_sub_begin(Sub* node){
    str += "{(";
}
void VisitorLaTeX::visit_sub_middle(Sub* node){
    str += "-";
}
void VisitorLaTeX::visit_sub_end(Sub* node){
    str += ")}";
}
