#ifndef SORT_HPP
#define SORT_HPP

#include <iostream>
#include <set>
#include <vector>

template <typename T>
class toposort{
    public:
        T* startnode;
        std::set<T*> visited;
        std::vector<T*> sorted_result;


    toposort<T>(T* startnode){
        std::cout << "instantiating toposort" << std::endl;
        this -> startnode = startnode;
    }

    void topological_sort(T* curnode){
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

    std::vector<T*> get_topological_sort(T* startnode){
        this->topological_sort(startnode);
        std::reverse(this->sorted_result.begin(), this->sorted_result.end());
        return this->sorted_result;
    }

    void printrandomstuff(int val){
        std::cout << val << std::endl;
    }
};

#endif