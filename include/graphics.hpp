#ifndef __CPP_CONSOLE_GRAPHICS_HPP__
#define __CPP_CONSOLE_GRAPHICS_HPP__

#include "ansi.hpp"

#include <string>

/**
 * @brief Namespace Containing all console commands
 */
namespace console {
    /**
     * @brief Returns a bolded string if ANSI is enabled
     */
    std::string bold(const std::string& str) {
        if (isANSIEnabled())
            return "\033[1m" + str + "\033[22m";
        return str;
    }

    /**
     * @brief Returns a faint/dim string if ANSI is enabled
     */
    std::string faint(const std::string& str) {
        if (isANSIEnabled())
            return "\033[2m" + str + "\033[22m";
        return str;
    }

    /**
     * @brief Returns an italicized string if ANSI is enabled
     */
    std::string italic(const std::string& str) {
        if (isANSIEnabled())
            return "\033[3m" + str + "\033[23m";
        return str;
    }

    /**
     * @brief Returns an underlined string if ANSI is enabled
     */
    std::string underline(const std::string& str) {
        if (isANSIEnabled())
            return "\033[4m" + str + "\033[24m";
        return str;
    }

    /**
     * @brief Returns a blinking string if ANSI is enabled
     */
    std::string blink(const std::string& str) {
        if (isANSIEnabled())
            return "\033[5m" + str + "\033[25m";
        return str;
    }

    /**
     * @brief Returns a inversed/reversed string if ANSI is enabled
     */
    std::string inverse(const std::string& str) {
        if (isANSIEnabled())
            return "\033[7m" + str + "\033[27m";
        return str;
    }

    /**
     * @brief Returns a hidden string if ANSI is enabled
     */
    std::string hidden(const std::string& str) {
        if (isANSIEnabled())
            return "\033[8m" + str + "\033[28m";
        return str;
    }
}

#endif