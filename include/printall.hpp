#ifndef __CPP_CONSOLE_PRINTALL_HPP__
#define __CPP_CONSOLE_PRINTALL_HPP__

#include "console.hpp"

/**
 * @brief Namespace Containing all console commands
 */
namespace console {
    template <typename T>
    void printAll(T t) {
        print(t);
    }

    /**
     * @brief Prints all items, with a space inbetween
     * 
     * @param args Items to print 
     */
    template<typename T, typename... Args>
    void printAll(T t, Args... args) {
        print(t);
        print(" ");
        printAll(args...);
    }
}

#endif