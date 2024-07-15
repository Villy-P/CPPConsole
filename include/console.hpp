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
}

#endif