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

    /**
     * @brief Template for a map-like data type. Matches things like map and unordered_map
     * 
     * @tparam T Type of the data type
     */
    template <typename T>
    struct is_map {
        template <typename V>
        static auto check(int) -> decltype(
            std::declval<V&>()[std::declval<const typename V::key_type&>()],
            std::true_type{});

        template <typename V>
        static std::false_type check(...);

        enum { 
            is = decltype(check<T>(0))::value
        };
    };
}

#endif