#ifndef __CPP_CONSOLE_CURSOR_HPP__
#define __CPP_CONSOLE_CURSOR_HPP__

#ifdef __WIN32
#include <Windows.h>
#include <iostream>

/**
 * @brief Namespace Containing all console commands
 */
namespace console {
    HANDLE getHandle() {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hConsole == INVALID_HANDLE_VALUE) {
            std::cerr << "Error: Unable to get console handle." << std::endl;
            std::exit(1);
        }
        return hConsole;
    }
}

#endif
#endif