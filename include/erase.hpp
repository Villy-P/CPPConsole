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

    /**
     * @brief Erases the screen from the cursor to the beginning of screen
     */
    void eraseFromCursorToBOS() {
        if (isANSIEnabled()) {
            std::cout << "\033[1J";
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
        DWORD cellsToClear = csbi.dwCursorPosition.Y * csbi.dwSize.X + csbi.dwCursorPosition.X + 1;
        DWORD charsWritten;
        COORD startCoord = {0, 0};
        FillConsoleOutputCharacter(hConsole, ' ', cellsToClear, startCoord, &charsWritten);
        FillConsoleOutputAttribute(hConsole, csbi.wAttributes, cellsToClear, startCoord, &charsWritten);
        SetConsoleCursorPosition(hConsole, csbi.dwCursorPosition);
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
        DWORD cellsToClear = csbi.dwSize.X * csbi.dwSize.Y;
        DWORD charsWritten;
        COORD startCoord = {0, 0};
        FillConsoleOutputCharacter(hConsole, ' ', cellsToClear, startCoord, &charsWritten);
        FillConsoleOutputAttribute(hConsole, csbi.wAttributes, cellsToClear, startCoord, &charsWritten);
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
        DWORD cellsToClear = csbi.dwSize.X - csbi.dwCursorPosition.X;
        DWORD charsWritten;
        COORD startCoord = csbi.dwCursorPosition;
        FillConsoleOutputCharacter(hConsole, ' ', cellsToClear, startCoord, &charsWritten);
        FillConsoleOutputAttribute(hConsole, csbi.wAttributes, cellsToClear, startCoord, &charsWritten);
        SetConsoleCursorPosition(hConsole, csbi.dwCursorPosition);
        #endif
    }
}

#endif