#ifndef SORT_HPP
#define SORT_HPP

#include <iostream>
#include <set>
#include <vector>

#include "data.hpp"

template <typename T>
class toposort{
    public:
        std::set<T> visited;
        std::vector<T> sorted_result;

        toposort<T>();

        void topological_sort(T);

        std::vector<T> get_topological_sort(T);

        void printrandomstuff(int);
};

#endif