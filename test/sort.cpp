#include "gtest/gtest.h"
#include "revgrad/sort.hpp"
#include "revgrad/data.hpp"

#include <vector>

TEST(TOPOSORT, SORT) {
	value v(0);
	std::vector<int> children;
	for (int i = 1; i <= 10; i++){
		v = v + i;
	}
	for (auto c: v.children){
		std::cout << c.data << std::endl;
		children.push_back(c.data);
	}

	//ASSERT_EQ(children[0], 10);
	//ASSERT_EQ(children[1], 45);
}
