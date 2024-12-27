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
    #ifdef __WIN32
    typedef struct ConsoleInfo {
        HANDLE hConsole;
        CONSOLE_SCREEN_BUFFER_INFO csbi;
    };

    ConsoleInfo getConsoleInfo() {
        ConsoleInfo info;
        info.hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        if (info.hConsole == INVALID_HANDLE_VALUE) {
            std::cerr << "Error: Unable to get console handle." << std::endl;
            return info;
        }
        if (!GetConsoleScreenBufferInfo(info.hConsole, &info.csbi)) {
            std::cerr << "Error: Unable to get console screen buffer info." << std::endl;
            return info;
        }
        return info;
    }
    #endif

    /**
    * @brief Erases the screen from the cursor to the end of screen
    */
    void eraseFromCursorToEOS() {
        if (isANSIEnabled()) {
            std::cout << "\033[0J";
            return;
        }
        #ifdef __WIN32
        ConsoleInfo info = getConsoleInfo();
        DWORD cellsToClear = info.csbi.dwSize.X * (info.csbi.dwSize.Y - info.csbi.dwCursorPosition.Y - 1) + (info.csbi.dwSize.X - info.csbi.dwCursorPosition.X);
        DWORD charsWritten;
        COORD startCoord = info.csbi.dwCursorPosition;
        FillConsoleOutputCharacter(info.hConsole, ' ', cellsToClear, startCoord, &charsWritten);
        FillConsoleOutputAttribute(info.hConsole, info.csbi.wAttributes, cellsToClear, startCoord, &charsWritten);
        SetConsoleCursorPosition(info.hConsole, info.csbi.dwCursorPosition);
        #endif
    }

    /**
     * @brief Erases the screen from the cursor to the beginning of screen
     */
    void eraseFromCursorToBOS() {
        if (isANSIEnabled()) {
            std::cout << "\033[1J";
            return;
        }
        #ifdef __WIN32
        ConsoleInfo info = getConsoleInfo();
        DWORD cellsToClear = info.csbi.dwCursorPosition.Y * info.csbi.dwSize.X + info.csbi.dwCursorPosition.X + 1;
        DWORD charsWritten;
        COORD startCoord = {0, 0};
        FillConsoleOutputCharacter(info.hConsole, ' ', cellsToClear, startCoord, &charsWritten);
        FillConsoleOutputAttribute(info.hConsole, info.csbi.wAttributes, cellsToClear, startCoord, &charsWritten);
        SetConsoleCursorPosition(info.hConsole, info.csbi.dwCursorPosition);
        #endif
    }

    /**
     * @brief Erases the entire screen
     */
    void eraseEntireScreen() {
        if (isANSIEnabled()) {
            std::cout << "\033[2J";
            return;
        }
        #ifdef __WIN32
        ConsoleInfo info = getConsoleInfo();
        DWORD cellsToClear = info.csbi.dwSize.X * info.csbi.dwSize.Y;
        DWORD charsWritten;
        COORD startCoord = {0, 0};
        FillConsoleOutputCharacter(info.hConsole, ' ', cellsToClear, startCoord, &charsWritten);
        FillConsoleOutputAttribute(info.hConsole, info.csbi.wAttributes, cellsToClear, startCoord, &charsWritten);
        #endif
    }

    /**
     * @brief Erases from the cursor position to the end of the line
     */
    void eraseFromCursorToEOL() {
        if (isANSIEnabled()) {
            std::cout << "\033[0K";
            return;
        }
        #ifdef __WIN32
        ConsoleInfo info = getConsoleInfo();
        DWORD cellsToClear = info.csbi.dwSize.X - info.csbi.dwCursorPosition.X;
        DWORD charsWritten;
        COORD startCoord = info.csbi.dwCursorPosition;
        FillConsoleOutputCharacter(info.hConsole, ' ', cellsToClear, startCoord, &charsWritten);
        FillConsoleOutputAttribute(info.hConsole, info.csbi.wAttributes, cellsToClear, startCoord, &charsWritten);
        SetConsoleCursorPosition(info.hConsole, info.csbi.dwCursorPosition);
        #endif
    }

    /**
     * @brief Erases from the cursor position to the beginning of the line
     */
    void eraseFromCursorToBOL() {
        if (isANSIEnabled()) {
            std::cout << "\033[1K";
            return;
        }
        ConsoleInfo info = getConsoleInfo();
        DWORD cellsToClear = info.csbi.dwCursorPosition.X + 1;
        DWORD charsWritten;
        COORD startCoord = {0, info.csbi.dwCursorPosition.Y};
        FillConsoleOutputCharacter(info.hConsole, ' ', cellsToClear, startCoord, &charsWritten);
        FillConsoleOutputAttribute(info.hConsole, info.csbi.wAttributes, cellsToClear, startCoord, &charsWritten);
        SetConsoleCursorPosition(info.hConsole, info.csbi.dwCursorPosition);
    }

    /**
     * @brief Erases the line the cursor is currently on
     */
    void eraseCurrentLine() {
        if (isANSIEnabled()) {
            std::cout << "\033[2K";
            return;
        }
        ConsoleInfo info = getConsoleInfo();
        DWORD cellsToClear = info.csbi.dwSize.X;
        DWORD charsWritten;
        COORD startCoord = {0, info.csbi.dwCursorPosition.Y};
        FillConsoleOutputCharacter(info.hConsole, ' ', cellsToClear, startCoord, &charsWritten);
        FillConsoleOutputAttribute(info.hConsole, info.csbi.wAttributes, cellsToClear, startCoord, &charsWritten);
        SetConsoleCursorPosition(info.hConsole, info.csbi.dwCursorPosition);
    }
}

#endif