#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

#include <vector>
#include <set>
#include <functional>
#include <algorithm>

#include "sort.hpp"

class value{
    public:
        float data;
        float grad;
        std::function<void()> backwardfunc;
        std::set<value*> children;

        value(float);

        value(float, std::set<value*>);

        //getters

        float getdata();

        float getgrad();

        //setters

        void setbackward(std::function<void()>);

        void setgrad(float);

        // overload plus operator
        //value operator + (float other){
        //    return (*this) + value(other);
        //}

        //value operator + (int other) {
        //   float other_float = static_cast <float>(other);
        //    return (*this) + value(other_float);
        //}
        value* operator+(value*);

        value* operator*(value*);

        void backward();

        void show();
};

#endif