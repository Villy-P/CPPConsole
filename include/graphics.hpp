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

    /**
     * @brief Returns a strikethough string if ANSI is enabled
     */
    std::string strikethrough(const std::string& str) {
        if (isANSIEnabled())
            return "\033[9m" + str + "\033[29m";
        return str;
    }

    /**
     * @brief Sets the text to be bold or not
     * 
     * @param set Enable/Disable bold text
     */
    void setBold(bool set) {
        if (isANSIEnabled()) {
            std::cout << (set ? "\033[1m" : "\033[22m");
            return;
        }
    }

    /**
     * @brief Sets the text to be faint/dim or not
     * 
     * @param set Enable/Disable faint/dim text
     */
    void setFaint(bool set) {
        if (isANSIEnabled()) {
            std::cout << (set ? "\033[2m" : "\033[22m");
            return;
        }
        #ifdef __WIN32
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), set ? FOREGROUND_INTENSITY : (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE));
        #endif
    }

    /**
     * @brief Sets the text to be italicized or not
     * 
     * @param set Enable/Disable italicized text
     */
    void setItalic(bool set) {
        if (isANSIEnabled()) {
            std::cout << (set ? "\033[3m" : "\033[23m");
            return;
        }
    }

    /**
     * @brief Sets the text to be underlined or not
     * 
     * @param set Enable/Disable underlined text
     */
    void setUnderline(bool set) {
        if (isANSIEnabled()) {
            std::cout << (set ? "\033[4m" : "\033[24m");
            return;
        }
    }

    /**
     * @brief Sets the text to be blinking or not
     * 
     * @param set Enable/Disable blinking text
     */
    void setBlink(bool set) {
        if (isANSIEnabled()) {
            std::cout << (set ? "\033[5m" : "\033[25m");
            return;
        }
    }

    /**
     * @brief Sets the text to be inversed/reversed or not
     * 
     * @param set Enable/Disable inversed/reversed text
     */
    void setInverse(bool set) {
        if (isANSIEnabled()) {
            std::cout << (set ? "\033[7m" : "\033[27m");
            return;
        }
    }

    /**
     * @brief Sets the text to be hidden or not
     * 
     * @param set Enable/Disable hidden text
     */
    void setHidden(bool set) {
        if (isANSIEnabled()) {
            std::cout << (set ? "\033[8m" : "\033[28m");
            return;
        }
    }

    /**
     * @brief Sets the text to be strikethrough or not
     * 
     * @param set Enable/Disable strikethrough text
     */
    void setStrikethrough(bool set) {
        if (isANSIEnabled()) {
            std::cout << (set ? "\033[9m" : "\033[29m");
            return;
        }
    }
}

#endif