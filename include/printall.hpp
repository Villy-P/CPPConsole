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

    template <typename T>
    void printlnAll(T t) {
        println(t);
    }

    /**
     * @brief Prints all items
     * 
     * @param args Items to print 
     */
    template<typename T, typename... Args>
    void printlnAll(T t, Args... args) {
        println(t);
        printlnAll(args...);
    }
}

#endif