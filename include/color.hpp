#ifndef __CPP_CONSOLE_COLOR_HPP__
#define __CPP_CONSOLE_COLOR_HPP__

#include "ansi.hpp"
#include "graphics.hpp"

#include <string>

/**
 * @brief Namespace Containing all console commands
 */
namespace console {
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

    /**
     * @brief Colors the text color to a custom color, between 0 to 255
     * 
     * From 0 to 15, the colors are the standard ANSI colors
     * From 16 to 231, the color uses the forumla `16 + (R × 36) + (G × 6) + B`
     * From 232 to 255, the colors are grayscale
     * 
     * @param color Color to set the text to
     * @param foreground Whether to set the foreground or background color (default is foreground)
     */
    std::string colorize(const std::string& str, unsigned char color, bool foreground = true) {
        if (isANSIEnabled())
            return "\033[" + std::to_string(foreground ? 38 : 48) + ";5;" + std::to_string(color) + "m" + str + "\033[0m";
        return str;
    }

    /**
     * @brief Colors the text color to a custom RGB color
     * 
     * @param color The color to set the text to
     * @param foreground Whether to set the foreground or background color (default is foreground)
     */
    std::string colorize(const std::string& str, unsigned char r, unsigned char g, unsigned char b, bool foreground = true) {
        if (isANSIEnabled())
            return "\033[" + std::to_string(foreground ? 38 : 48) + ";2;" + std::to_string(r) + ";" + std::to_string(g) + ";" + std::to_string(b) + "m" + str + "\033[0m";
        return str;
    }

    /**
     * @brief Sets the color of the text to a predefined color
     * 
     * @param color The color to set the text to
     */
    void setColor(Graphics color) {
        if (isANSIEnabled())
            std::cout << "\033[" << std::to_string(color) << "m";
    }

    /**
     * @brief Sets the color of the text to a custom color, between 0 to 255
     * 
     * From 0 to 15, the colors are the standard ANSI colors
     * From 16 to 231, the color uses the forumla `16 + (R × 36) + (G × 6) + B`
     * From 232 to 255, the colors are grayscale
     * 
     * @param color Color to set the text to
     * @param foreground Whether to set the foreground or background color (default is foreground)
     */
    void setColor(unsigned char color, bool foreground = true) {
        if (isANSIEnabled())
            std::cout << "\033[" << (foreground ? "38" : "48") << ";5;" << std::to_string(color) << "m";
    }

    /**
     * @brief Sets the color of the text to a custom RGB color
     * 
     * @param color The color to set the text to
     * @param foreground Whether to set the foreground or background color (default is foreground)
     */
    void setColor(unsigned char r, unsigned char g, unsigned char b, bool foreground = true) {
        if (isANSIEnabled())
            std::cout << "\033[" << (foreground ? "38" : "48") << ";2;" << std::to_string(r) << ";" << std::to_string(g) << ";" << std::to_string(b) << "m";
    }
}

#endif