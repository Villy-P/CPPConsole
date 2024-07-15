#ifndef __CPP_CONSOLE_ERASE_HPP__
#define __CPP_CONSOLE_ERASE_HPP__

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
    /**
    * @brief Erases the screen from the cursor to the end of screen
    */
    void eraseFromCursorToEOS() {
        if (isANSIEnabled()) {
            std::cout << "\033[0J";
            return;
        }
        #ifdef __WIN32
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hConsole == INVALID_HANDLE_VALUE) {
            std::cerr << "Error: Unable to get console handle." << std::endl;
            return;
        }
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) {
            std::cerr << "Error: Unable to get console screen buffer info." << std::endl;
            return;
        }
        DWORD cellsToClear = csbi.dwSize.X * (csbi.dwSize.Y - csbi.dwCursorPosition.Y - 1) + (csbi.dwSize.X - csbi.dwCursorPosition.X);
        DWORD charsWritten;
        COORD startCoord = csbi.dwCursorPosition;
        FillConsoleOutputCharacter(hConsole, ' ', cellsToClear, startCoord, &charsWritten);
        FillConsoleOutputAttribute(hConsole, csbi.wAttributes, cellsToClear, startCoord, &charsWritten);
        SetConsoleCursorPosition(hConsole, csbi.dwCursorPosition);
        #endif
    }
}

#endif