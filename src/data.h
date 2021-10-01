#include <vector>
#include <set>
#include <functional>

class value{
    public:
        float data;
        float grad;
        std::function<void()> backward;
        std::set<value> children;

        value(float data){
            this->data = data;
        }

        value(float data, std::set<value> children){
            this->data = data;
            this->children = children;
        }

        //getters

        float getdata(){
            return this->data;
        }

        float getgrad(){
            return this->grad;
        }

        //setters

        void setbackward(std::function<void()> func){
            this->backward = func;
        }

        void setgrad(float newgrad){
            this->grad = newgrad;
        }

        // overload plus operator
        //value operator + (float other){
        //    return (*this) + value(other);
        //}

        //value operator + (int other) {
        //   float other_float = static_cast <float>(other);
        //    return (*this) + value(other_float);
        //}
        value* operator+(value* other){
            float new_data = this->data + other->data;
            std::set<value> newchildren;
            //newchildren.insert(*this);
            //newchildren.insert(*other);
            value* out = new value(new_data, newchildren);

            //std::function<void()> newbackward = [this, out, other](){
            //    this->grad = this->grad + out->grad;
            //    other->setgrad(other->grad+out->grad);
            //};

            //out->setbackward(newbackward);
            return out;
        }
};