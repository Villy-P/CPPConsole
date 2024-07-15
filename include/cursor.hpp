#ifndef __CPP_CONSOLE_CURSOR_HPP__
#define __CPP_CONSOLE_CURSOR_HPP__

#include <iostream>

#ifdef __WIN32
#include <Windows.h>
#else
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#endif

#include "console.hpp"
#include "ansi.hpp"

/**
 * @brief Namespace Containing all console commands
 */
namespace console {
    void moveCursorHome() {
        if (isANSIEnabled()) {
            std::cout << "\033[H";
            return;
        }
        #ifdef __WIN32
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hConsole == INVALID_HANDLE_VALUE) {
            std::cerr << "Error: Unable to get console handle." << std::endl;
            return;
        }
        COORD homeCoords = {0, 0};
        SetConsoleCursorPosition(hConsole, homeCoords);
        #endif
    }
}

#endif