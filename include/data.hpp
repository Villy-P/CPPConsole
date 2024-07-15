#ifndef __CPP_CONSOLE_DATA_HPP__
#define __CPP_CONSOLE_DATA_HPP__

#include "console.hpp"

/**
 * @brief Namespace Containing all console commands
 */
namespace console {
     /**
     * @brief A position on the console (row and column)
     */
    typedef struct {
        int X;
        int Y;
    } ConsoleCoord;
}

#endif