#include "data.hpp"

int main(){
    value v1(5.0);
    value v2(10.0);
    value v = v1 + v2;
    value v3(20.0);
    value v5 = v*v3;
    //std::cout << v->data << std::endl;
    //std::cout << v->grad << std::endl;


    v1.show();
    v2.show();
    v.show();
    v5.backward();
    v5.show();
    v.show();
    v1.show();
    v2.show();
    //std::cout << (v1+v2).grad;
}