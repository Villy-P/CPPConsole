#include <iostream>
#include <map>
#include <vector>

#include "console.hpp"
#include "printall.hpp"
#include "cursor.hpp"
#include "erase.hpp"
#include "graphics.hpp"
#include "color.hpp"

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

    console::println("Press ENTER to continue.");
    std::cin.get();
    console::eraseEntireScreen();
    console::moveCursorHome();
    console::print("Testing Cursor Movement");
    console::moveCursorDown(5);
    console::print("Moved Down 5 Lines");
    console::moveCursorUp(5);
    console::print("Moved Up 5 Lines");
    console::moveCursorRight(50);
    console::print("Moved Right 50 Characters");
    console::moveCursorDown(5);
    console::moveCursorLeft(50);
    console::print("Moved Left 50 Characters");
    console::moveCursorHome();
    console::moveCursorDown(6);


    console::print("Press ENTER to continue");
    std::cin.get();
    console::eraseEntireScreen();
    console::moveCursorHome();
    console::println("Testing Text Effects");
    console::print(console::bold("Bold "));
    console::print(console::faint("Faint "));
    console::print(console::italic("Italic "));
    console::print(console::underline("Underline "));
    console::print(console::blink("Blink "));
    console::print(console::inverse("Inverse "));
    console::print(console::hidden("Hidden "));
    console::print(console::strikethrough("Strikethrough "));
    console::println();


    console::print("Press ENTER to continue");
    std::cin.get();
    console::eraseEntireScreen();
    console::moveCursorHome();
    console::println("Testing Colors");
    console::print("Basic Colors: ");
    for (int i = 30; i < 38; ++i)
        console::print(console::colorize(std::to_string(i), static_cast<console::Graphics>(i)) + " ");
    for (int i = 40; i < 48; ++i)
        console::print(console::colorize(std::to_string(i), static_cast<console::Graphics>(i)) + " ");
    for (int i = 90; i < 98; ++i)
        console::print(console::colorize(std::to_string(i), static_cast<console::Graphics>(i)) + " ");
    for (int i = 100; i < 108; ++i)
        console::print(console::colorize(std::to_string(i), static_cast<console::Graphics>(i)) + " ");
    console::println();

    console::print("Testing Finished");
    return 0;
}