#include "revgrad/data.hpp"

int main(){
    float lr = 0.005;

    value input1(1);
    value input2(4);
    value input3(10);

    value input4 = input1 + input2;
    value input5 = input4*input3;

    value input6(8);
    value input7 = (input5 - input6)*(input5 - input6); // loss

    std::vector<value*> ls = {&input1, &input2, &input3, &input4, &input5, &input6};

    for (int i=0; i<100; i++){
        input7.backward();

        /**
        for (auto &l: ls){
            l->update(lr);
        }*/

        // todo : make this better
        input1.update(lr);
        input2.update(lr);
        input3.update(lr);
        input4.update(lr);
        input5.update(lr);
        input6.update(lr);

        input7 = (input5 - input6)*(input5 - input6);

        if (i%8 == 0){
            std::cout << "current loss " << input7.data << std::endl;
        }
    }


}