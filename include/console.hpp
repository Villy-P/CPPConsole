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
}

#endif