cmake_minimum_required(VERSION 2.8.3)
project(roboclaw)

find_package(catkin REQUIRED COMPONENTS serial)

catkin_package(
        INCLUDE_DIRS include
        LIBRARIES ${PROJECT_NAME}
        CATKIN_DEPENDS serial
)

include_directories(
        ${catkin_INCLUDE_DIRS}
        include
)

add_subdirectory(tests)

add_library(${PROJECT_NAME}
        src/${PROJECT_NAME}/roboclaw.cpp
)

target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES})

install(DIRECTORY include/${PROJECT_NAME}/
        DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
        FILES_MATCHING PATTERN "*.h")

install(TARGETS ${PROJECT_NAME}
        ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
        LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
        RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION})
