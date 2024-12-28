#ifndef __CPP_CONSOLE_DIMENSIONS_HPP__
#define __CPP_CONSOLE_DIMENSIONS_HPP__

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
     * @brief A structure representing the dimensions of the console
     */
    typedef struct {
        int width;
        int height;
    } Dimensions;

    /**
     * @brief Gets the width and height of the console
     * 
     * @return A struct containing the width and height of the console
     */
    Dimensions getDimensions() {
        #ifdef __WIN32
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        return {
            csbi.srWindow.Right - csbi.srWindow.Left + 1,
            csbi.srWindow.Bottom - csbi.srWindow.Top + 1
        };
        #else
        struct winsize w;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        return {
            w.ws_row, w.ws_col
        };
        #endif
    }
}

#endif