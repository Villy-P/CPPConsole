#ifndef __CPP_CONSOLE_TEMPLATE_HPP__
#define __CPP_CONSOLE_TEMPLATE_HPP__

/**
 * @brief Namespace Containing all console commands
 */
namespace console {
    /**
     * @brief Template for a iterable data type. Matches things like vector, deque, map, etc. 
     * 
     * @tparam T Type of the data type
     */
    template<typename T>
    struct iterable {
        template<class V> static long check(...); 
        template<class V> static char  check(
            int, typename V::const_iterator = T().end()); 
            
        enum { 
            is = sizeof(check<T>(0)) == sizeof(char) 
        }; 
    };
}

#endif