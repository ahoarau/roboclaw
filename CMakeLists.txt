cmake_minimum_required(VERSION 2.8.3)
project(roboclaw)

set(CMAKE_MODULE_PATH
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake
    ${CMAKE_MODULE_PATH}
)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

find_package(serial REQUIRED)

include_directories(
    ${serial_INCLUDE_DIRS}
    include
)

add_library(${PROJECT_NAME}
    src/${PROJECT_NAME}/roboclaw.cpp
)

target_link_libraries(${PROJECT_NAME} ${serial_LIBRARIES})

add_subdirectory(tests)


install(TARGETS ${PROJECT_NAME}
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

install(DIRECTORY include/${PROJECT_NAME}/
    DESTINATION include/${PROJECT_NAME}/
    FILES_MATCHING PATTERN "*.h"
    PATTERN ".svn" EXCLUDE
)
