find_program(PRE_COMMIT_EXE NAMES pre-commit)
if(NOT PRE_COMMIT_EXE)
    message(WARNING "pre-commit not found — run: pip install pre-commit --break-system-packages")
endif()

find_program(CLANG_FORMAT_EXE NAMES clang-format clang-format-18 clang-format-17)

if(CLANG_FORMAT_EXE)
    file(GLOB_RECURSE FORMAT_SOURCES CONFIGURE_DEPENDS
        ${CMAKE_SOURCE_DIR}/test/*.c
        ${CMAKE_SOURCE_DIR}/test/*.cpp
        ${CMAKE_SOURCE_DIR}/include/*.h
        ${CMAKE_SOURCE_DIR}/include/*.hpp
    )

    message(STATUS "clang-format found: ${CLANG_FORMAT_EXE}")
    add_custom_target(clang-format
        COMMAND ${CLANG_FORMAT_EXE} -i -style=file ${FORMAT_SOURCES}
        COMMENT "Running clang-format..."
        USES_TERMINAL
        VERBATIM
    )

    add_custom_target(clang-format-check
        COMMAND ${CLANG_FORMAT_EXE} --dry-run --Werror -style=file ${FORMAT_SOURCES}
        COMMENT "Running clang-format check..."
        USES_TERMINAL
        VERBATIM
    )
else()
    message(STATUS "clang-format not found")
endif()