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
#include "data.hpp"

/**
 * @brief Namespace Containing all console commands
 */
namespace console {
    /**
     * @brief Gets the position of the cursor within the console
     * 
     * @return The row, col position within the console
     */
    ConsoleCoord getCursorPosition() {
        #ifdef __WIN32
        CONSOLE_SCREEN_BUFFER_INFO cbsi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cbsi);
        return { cbsi.dwCursorPosition.X, cbsi.dwCursorPosition.Y };
        #else
        ConsoleCoord coord;
        struct termios term, term_orig;
        tcgetattr(STDIN_FILENO, &term);
        term_orig = term;

        term.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &term);
        std::cout << "\033[6n";
        std::cin.ignore();

        char ignore;
        std::cin >> ignore >> coord.X;
        std::cin.ignore();
        std::cin >> coord.Y;

        tcsetattr(STDIN_FILENO, TCSANOW, &term_orig);
        return coord;
        #endif
    }

    /**
     * @brief Moves cursor to home position (0, 0)
     */
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

    /**
     * @brief Move the cursor to the specified position in the console
     * 
     * @param row Row to move to
     * @param col Column to move to
     */
    void moveCursorToPosition(int row, int col) {
        if (isANSIEnabled()) {
            std::cout << "\033[" << std::to_string(row) << ";" << std::to_string(col) << "H";
            return;
        }
        #ifdef __WIN32
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hConsole == INVALID_HANDLE_VALUE) {
            std::cerr << "Error: Unable to get console handle." << std::endl;
            return;
        }
        COORD coord;
        coord.X = row;
        coord.Y = col;
        SetConsoleCursorPosition(hConsole, coord);
        #endif
    }

    /**
    * @brief Move the cursor up by n lines
    * 
    * @param n Number of lines to move by.
    */
    void moveCursorUp(int n) {
        if (isANSIEnabled()) {
            std::cout << "\033[" << std::to_string(n) << "A";
            return;
        }
        #ifdef __WIN32
        ConsoleCoord coord = getCursorPosition();
        moveCursorToPosition(coord.X, coord.Y - n);
        #endif
    }

    /**
    * @brief Move the cursor down by n lines
    * 
    * @param n Number of lines to move by.
    */
    void moveCursorDown(int n) {
        if (isANSIEnabled()) {
            std::cout << "\033[" << std::to_string(n) << "B";
            return;
        }
        #ifdef __WIN32
        ConsoleCoord coord = getCursorPosition();
        moveCursorToPosition(coord.X, coord.Y + n);
        #endif
    }

    /**
    * @brief Move the cursor right by n lines
    * 
    * @param n Number of lines to move by.
    */
    void moveCursorRight(int n) {
        if (isANSIEnabled()) {
            std::cout << "\033[" << std::to_string(n) << "C";
            return;
        }
        #ifdef __WIN32
        ConsoleCoord coord = getCursorPosition();
        moveCursorToPosition(coord.X + n, coord.Y);
        #endif
    }

    /**
    * @brief Move the cursor left by n lines
    * 
    * @param n Number of lines to move by.
    */
    void moveCursorLeft(int n) {
        if (isANSIEnabled()) {
            std::cout << "\033[" << std::to_string(n) << "C";
            return;
        }
        #ifdef __WIN32
        ConsoleCoord coord = getCursorPosition();
        moveCursorToPosition(coord.X - n, coord.Y);
        #endif
    }
}

#endif