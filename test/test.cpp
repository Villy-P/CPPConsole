#include <iostream>
#include <map>
#include <vector>

#include "console.hpp"

int main() {
    std::vector<int> vec = {0, 1, 2, 4, 8, 16};
    std::map<int, int> m = {
        {0, 0},
        {1, 1},
        {2, 4},
        {3, 9},
        {4, 16}
    };

    console::print("Wow!");
    console::print(vec);
    console::print(m);
    return 0;
}