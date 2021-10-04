#include <iostream>

#include <vector>
#include <set>
#include <functional>
#include <algorithm>

#include "data.hpp"
#include "sort.hpp"

value::value(float data){
    this->data = data;
    this->grad = 0.0;
    std::function<void()> backward_ = []() mutable {}; // dummy backward function
    this -> backwardfunc = backward_;
}

value::value(const float data, const std::set<value> children){
    this->data = data;
    this->children = children;
    this->grad =  0;
    std::function<void()> backward_ = []() mutable {}; // dummy backward function
    this->backwardfunc = backward_;
}

//getters

float value::getdata(){
    return this->data;
}

float value::getgrad(){
    return this->grad;
}

//setters

void value::setbackward(std::function<void()> func){
    this->backwardfunc = func;
}

void value::setgrad(float newgrad){
    this->grad = newgrad;
}

bool operator< (const value &left, const value &right)
{
    return &(left) < &(right);
}


// overload plus operator
value value::operator+(float other){
    return (*this) + value(other);
}

value value::operator+(int other) {
   float other_float = static_cast <float>(other);
    return (*this) + value(other_float);
}

value value::operator+(value other){
    float new_data = this->data + other.data;
    std::set<value> newchildren;
    newchildren.insert(*this);
    newchildren.insert(other);
    value out(new_data, newchildren);

    std::function<void()> newbackward = [this, &out, other]() mutable {
        this->grad = this->grad + out.grad;
        std::cout << "setting grad " << other.grad + out.grad << std::endl;
        other.setgrad(other.grad+out.grad);
        std::cout << "grad set" << std::endl;
    };

    out.setbackward(newbackward);
    return out;
}

// overload plus operator
value value::operator*(float other){
    return (*this) * value(other);
}

value value::operator*(int other) {
   float other_float = static_cast <float>(other);
    return (*this) * value(other_float);
}

value value::operator*(value other){
    float new_data = this->data * other.data;
    std::set<value> newchildren;
    newchildren.insert(*this);
    newchildren.insert(other);
    value out(new_data, newchildren);

    std::function<void()> newbackward = [this, &out, other]() mutable {
        this->grad = this->grad + other.data*out.grad;
        other.setgrad(other.grad+ this->data*out.grad);
    };

    out.setbackward(newbackward);
    return out;

}

void value::backward(){
    std::cout << "goind back" << std::endl;
    std::set<value> visited;

    toposort<value>* topo = new toposort<value>();
    topo -> printrandomstuff(100);
    //do topo sort here
    std::vector<value> topo_result = topo->get_topological_sort(*this);
    
    std::cout << "topo sort result: " << std::endl;
    for (auto n:topo_result){
        std::cout << n.data << std::endl;
    }
    this->grad = 1;
    for (auto& node: topo_result){
        std::cout << "setting grad for " << node.data << std::endl;
        node.backwardfunc();
    }
}

void value::show(){
    std::cout << "Data : " << this->data << std::endl;
    std::cout << "Grad : " << this->grad << std::endl;
    std::cout << "Children : " << std::endl;
    for (auto n: this->children){
        std::cout << n.data << std::endl;
    }
    std::cout << "-----" << std::endl;
}