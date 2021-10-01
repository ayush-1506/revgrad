#include <iostream>

#include <vector>
#include <set>
#include <functional>
#include <algorithm>

class value{
    public:
        float data;
        float grad;
        std::function<void()> backwardfunc;
        std::set<value*> children;

        class toposort{
            public:
                value* startnode;
                std::set<value*> visited;
                std::vector<value*> sorted_result;

                toposort(value* startnode){
                    this -> startnode = startnode;
                }

                void topological_sort(value* curnode){
                    for (auto n: this->sorted_result){
                        std::cout << n->data << std::endl;
                    }
                    for (auto& child: curnode->children){
                        bool ispresent = this->visited.find(child) != this->visited.end();
                        if (!ispresent){
                            this->visited.insert(child);
                            this->topological_sort(child);
                        }
                    }
                    this->sorted_result.push_back(curnode);
                }

                //getters
                std::vector<value*> get_topoligical_sort(value* startnode){
                    this->topological_sort(startnode);
                    std::reverse(this->sorted_result.begin(), this->sorted_result.end());
                    return this->sorted_result;
                }
        };

        value(float data){
            this->data = data;
            this->grad = 0.0;
        }

        value(float data, std::set<value*> children){
            this->data = data;
            this->children = children;
            this ->grad =  0;
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
            this->backwardfunc = func;
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
            std::set<value*> newchildren;
            newchildren.insert(this);
            newchildren.insert(other);
            value* out = new value(new_data, newchildren);

            std::function<void()> newbackward = [this, out, other]() mutable {
                this->grad = this->grad + out->grad;
                std::cout << "setting grad " << other->grad + out->grad << std::endl;
                other->setgrad(other->grad+out->grad);
                std::cout << "grad set" << std::endl;
            };

            out->setbackward(newbackward);
            return out;
        }

        void backward(){
            std::set<value*> visited;
            toposort* topo = new toposort(this);
            //do topo sort here
            std::vector<value*> topo_result = topo->get_topoligical_sort(this);
            std::cout << "topo sort result: " << std::endl;
            for (auto n:topo_result){
                std::cout << n->data << std::endl;
            }
            this->grad = 1;
            for (auto& node: topo_result){
                std::cout << "setting grad for " << node->data << std::endl;
                node->backwardfunc();
            }
        }

        void show(){
            std::cout << "Data : " << this->data << std::endl;
            std::cout << "Grad : " << this->grad << std::endl;
            std::cout << "Children : " << std::endl;
            for (auto n: this->children){
                std::cout << n->data << std::endl;
            }
            std::cout << "-----" << std::endl;
        }
};



int main(){
    value v1(5.0);
    value* v2 = new value(10.0);
    value* v = v1 + v2;
    //std::cout << v->data << std::endl;
    //std::cout << v->grad << std::endl;
    v1.show();
    v2->show();
    v->show();
    v->backward();
    
    v->show();
    v1.show();
    v2->show();
    //std::cout << (v1+v2).grad;
}