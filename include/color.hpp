#ifndef __CPP_CONSOLE_COLOR_HPP__
#define __CPP_CONSOLE_COLOR_HPP__

#include "ansi.hpp"

#include <string>

/**
 * @brief Namespace Containing all console commands
 */
namespace console {
    /**
     * @brief Enumeration of builtin colors for ANSI escape codes, along with other graphics modes
     * 
     */
    enum Graphics {
        BLACK = 30,
        RED,
        GREEN,
        YELLOW,
        BLUE,
        MAGENTA,
        CYAN,
        WHITE,
        DEFAULT = 39,
        BG_BLACK = 40,
        BG_RED,
        BG_GREEN,
        BG_YELLOW,
        BG_BLUE,
        BG_MAGENTA,
        BG_CYAN,
        BG_WHITE,
        BG_DEFAULT = 49,
        BRIGHT_BLACK = 90,
        BRIGHT_RED,
        BRIGHT_GREEN,
        BRIGHT_YELLOW,
        BRIGHT_BLUE,
        BRIGHT_MAGENTA,
        BRIGHT_CYAN,
        BRIGHT_WHITE,
        BG_BRIGHT_BLACK = 100,
        BG_BRIGHT_RED,
        BG_BRIGHT_GREEN,
        BG_BRIGHT_YELLOW,
        BG_BRIGHT_BLUE,
        BG_BRIGHT_MAGENTA,
        BG_BRIGHT_CYAN,
        BG_BRIGHT_WHITE
    };

    /**
     * @brief Colors the text color to a predefined color
     * 
     * @param color The color to set the text to
     */
    std::string colorize(const std::string& str, Graphics color) {
        if (isANSIEnabled())
            return "\033[" + std::to_string(color) + "m" + str + "\033[0m";
        return str;
    }
}

#endif