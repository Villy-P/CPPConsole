#include <iostream>
#include <map>
#include <vector>

#include "console.hpp"
#include "printall.hpp"
#include "cursor.hpp"
#include "erase.hpp"
#include "graphics.hpp"

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

    console::println();
    console::printlnAll("Wow!", vec, m, arr);

    console::println(console::bold("Bold Text!"));
    console::println(console::faint("Faint Text!"));
    console::println(console::italic("Italic Text!"));
    console::println(console::bold(console::faint(console::italic("Bold, Faint, Italic Text!"))));
    console::println(console::underline("Underlined Text!"));
    console::println(console::blink("Blinking Text!"));
    console::println(console::reverse("Reversed Text!"));
    return 0;
}