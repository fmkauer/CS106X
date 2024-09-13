#ifndef SPL_BUILD_H
#define SPL_BUILD_H

#ifndef SPL_CMAKE_BUILD
    // Building from pro file
    #define SPL_VERSION \"$$SPL_VERSION\"
    #define SPL_BUILD_DATE \"$$_DATE_\"
    #define SPL_BUILD_USER \"$$(USER)\"
#else
    // Building from CMake
    #define SPL_VERSION "2023.1"
    #define SPL_BUILD_DATE "13/09/2024"
    #define SPL_BUILD_USER "Villela"
#endif

#endif
