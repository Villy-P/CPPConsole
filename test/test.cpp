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
    int arr[] = {0, 1, 2, 3, 4};

    console::println("Wow!");
    console::println(vec);
    console::println(m);
    console::println(arr);
    return 0;
}