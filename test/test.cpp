#include <iostream>
#include <map>
#include <vector>

#include "console.hpp"
#include "printall.hpp"
#include "cursor.hpp"
#include "erase.hpp"
#include "graphics.hpp"

int main() {
    console::println("Testing C++ Console. Press ENTER to begin.");
    std::cin.get();

    console::eraseEntireScreen();
    console::moveCursorHome();
    console::println("Console Has Been Cleared");
    console::println("Testing Printing Data Structures");

    std::vector<int> vec = {0, 1, 2, 4, 8, 16};
    std::map<int, int> m = {
        {0, 0},
        {1, 1},
        {2, 4},
        {3, 9},
        {4, 16}
    };
    int arr[] = {0, 1, 2, 3, 4};

    console::print("Vector: ");
    console::println(vec);
    console::print("Map: ");
    console::println(m);
    console::print("Array: ");
    console::println(arr);

    console::println();
    console::println("Testing PrintAll");
    console::printAll("Hello", "World", "From", "C++", "Console!\n");
    console::printAll("Wow!", vec, m, arr, "\n");
    console::printlnAll("Wow!", vec, m, arr);

    // console::println(console::bold("Bold Text!"));
    // console::println(console::faint("Faint Text!"));
    // console::println(console::italic("Italic Text!"));
    // console::println(console::bold(console::faint(console::italic("Bold, Faint, Italic Text!"))));
    // console::println(console::underline("Underlined Text!"));
    // console::println(console::blink("Blinking Text!"));
    // console::println(console::inverse("Reversed Text!"));
    // console::println(console::hidden("Hidden Text!"));
    // console::println(console::strikethrough("Strikethrough Text!"));
    // console::println(console::bold(console::faint(console::italic(console::underline(console::blink(console::inverse(console::strikethrough("All Text Effects!"))))))));

    // console::setBold(true);
    // console::println("Bold Text!");
    // console::setBold(false);
    // console::println("Normal Text!");
    return 0;
}