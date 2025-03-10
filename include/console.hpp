#ifndef __CPP_CONSOLE_HPP__
#define __CPP_CONSOLE_HPP__

#include "template.hpp"

/**
 * @brief Namespace Containing all console commands
 */
namespace console {
    /**
     * @brief Prints out a value
     * 
     * @tparam T Type of the value
     * @param value The item to print
     */
    template<typename T>
    void print(const T& value) { 
        if constexpr (console::is_map<T>::is) {
            print("{ ");
            for (auto it = value.begin(); it != value.end(); ++it) {
                print("{");
                print(it->first);
                print(", ");
                print(it->second);
                print("}");
                if (it != std::prev(value.end()))
                    print(", ");
            }
            print(" }");
        } else if constexpr (console::iterable<T>::is) {
            print("{ ");
            std::size_t count = 0;
            for (const auto& element : value) {
                print(element);
                if (count != value.size() - 1)
                    print(", ");
                count++;
            }
            print(" }");
        } else {
            std::cout << value; 
        }
    }

    /**
     * @brief Prints out the values of an array
     * 
     * @tparam T Type of the array
     * @tparam N Length of the array
     * @param arr The array
     */
    template<typename T, size_t N, typename std::enable_if_t<is_not_string<T>::value, int> = 0>
    void print(const T (&arr)[N]) {
        std::cout << "{ ";
        std::size_t count = 0;
        for (const auto& element : arr) {
            print(element);
            if (count != N - 1)
                std::cout << ", ";
            count++;
        }
        std::cout << " }";
    }

    /**
     * @brief Prints out a char array
     * 
     * @tparam N Size of array
     * @param arr The array
     */
    template<size_t N>
    void print(const char (&arr)[N]) {
        std::cout << arr;
    }

    /**
     * @brief Prints out a string
     * 
     * @param str The string to print
     */
    void print(const std::string& str) {
        std::cout << str;
    }
    void print() { }

    /**
     * @brief Prints out an object, then a newline
     * 
     * @tparam T Type of the item passed in
     * @param value Value to print
     */
    template<typename T>
    void println(const T& value) { 
        print(value);
        std::cout << std::endl;
    }

    /**
     * @brief Prints out a newline
     */
    void println() { std::cout << std::endl; }
}

#endif