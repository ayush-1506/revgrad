#include "sort.hpp"

template <typename T>
toposort<T>::toposort(){
    //std::cout << "instantiating toposort" << std::endl;
};

template <typename T>
void toposort<T>::topological_sort(T curnode){
    //for (auto n: this->sorted_result){
    //    std::cout << n.data << std::endl;
    //}
    for (auto& child: curnode.children){
        bool ispresent = this->visited.find(child) != this->visited.end();
        if (!ispresent){
            this->visited.insert(child);
            this->topological_sort(child);
        }
    }
    this->sorted_result.push_back(curnode);
};

template <typename T>
std::vector<T> toposort<T>::get_topological_sort(T startnode){
    this->topological_sort(startnode);
    std::reverse(this->sorted_result.begin(), this->sorted_result.end());
    return this->sorted_result;
};

template <typename T>
void toposort<T>::printrandomstuff(int val){
    std::cout << val << std::endl;
};


// https://stackoverflow.com/questions/115703/storing-c-template-function-definitions-in-a-cpp-file
template class toposort<value>;