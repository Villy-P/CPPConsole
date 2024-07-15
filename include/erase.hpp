#ifndef __CPP_CONSOLE_ERASE_HPP__
#define __CPP_CONSOLE_ERASE_HPP__

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

/**
 * @brief Namespace Containing all console commands
 */
namespace console {

}

#endif