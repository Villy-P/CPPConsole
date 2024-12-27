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
            return "\033[1m" + str + "\033[0m";
        return str;
    }

    /**
     * @brief Returns a faint/dim string if ANSI is enabled
     */
    std::string faint(const std::string& str) {
        if (isANSIEnabled())
            return "\033[2m" + str + "\033[0m";
        return str;
    }

    /**
     * @brief Returns an italicized string if ANSI is enabled
     */
    std::string italic(const std::string& str) {
        if (isANSIEnabled())
            return "\033[3m" + str + "\033[0m";
        return str;
    }
}

#endif