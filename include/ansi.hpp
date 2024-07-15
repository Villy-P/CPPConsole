#ifndef __CPP_CONSOLE_ANSI_HPP__
#define __CPP_CONSOLE_ANSI_HPP__

#include "console.hpp"

#ifdef __WIN32
#include <Windows.h>
#else
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#endif

/**
 * @brief Namespace Containing all console commands
 */
namespace console {
    /**
     * @brief Checks if ANSI Codes are enable in windows.
     * 
     * @return True, if enabled, false if not. Always returns true on Linux systems
    */
    bool isANSIEnabled() {
        #ifdef __WIN32
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        DWORD consoleMode;
        GetConsoleMode(hConsole, &consoleMode);
        return consoleMode & ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        #else
        return true;
        #endif
    }

    /**
     * @brief Enables ANSI for Windows environments
    */
    void enableANSI() {
        #ifdef __WIN32
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        DWORD consoleMode;
        GetConsoleMode(hConsole, &consoleMode);
        consoleMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        SetConsoleMode(hConsole, consoleMode);
        #endif
    }
}

#endif