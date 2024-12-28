#ifndef __CPP_CONSOLE_GRAPHICS_HPP__
#define __CPP_CONSOLE_GRAPHICS_HPP__

#include "ansi.hpp"

#include <string>
#include <initializer_list>

/**
 * @brief Namespace Containing all console commands
 */
namespace console {
    /**
     * @brief Enumeration of builtin colors for ANSI escape codes, along with other graphics modes
     * 
     */
    enum Graphics {
        BOLD = 1,
        DIM,
        ITALIC,
        UNDERLINE,
        BLINK,
        INVERT,
        HIDDEN,
        STRIKETHROUGH,
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

    void set(std::initializer_list<Graphics> list) {
        std::string itemStr = "";
        for (const auto& item : list) {
            itemStr += std::to_string(item);
            if (item != *(list.end() - 1))
                itemStr += ";";
        }
        if (isANSIEnabled()) {
            std::cout << "\033[" << itemStr << "m";
            return;
        }
    }

    std::string set(const std::string& str, std::initializer_list<Graphics> list) {
        std::string itemStr = "";
        for (const auto& item : list) {
            itemStr += std::to_string(item);
            if (item != *(list.end() - 1))
                itemStr += ";";
        }
        if (isANSIEnabled())
            return "\033[" + itemStr + "m" + str + "\033[0m";
        return str;
    }

    void clearGraphics() {
        if (isANSIEnabled()) {
            std::cout << "\033[0m";
            return;
        }
    }
}

#endif