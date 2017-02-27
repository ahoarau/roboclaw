cmake_minimum_required(VERSION 2.8.3)
project(roboclaw)


set(VARS_PREFIX "Roboclaw")

set(${VARS_PREFIX}_MAJOR_VERSION 0)
set(${VARS_PREFIX}_MINOR_VERSION 0)
set(${VARS_PREFIX}_PATCH_VERSION 0)
set(${VARS_PREFIX}_VERSION ${${VARS_PREFIX}_MAJOR_VERSION}.${${VARS_PREFIX}_MINOR_VERSION}.${${VARS_PREFIX}_PATCH_VERSION})

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules)

#
# set(CMAKE_MODULE_PATH
#     ${CMAKE_CURRENT_SOURCE_DIR}/cmake
#     ${CMAKE_MODULE_PATH}
# )

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

find_package(Serial REQUIRED)

include_directories(
    ${Serial_INCLUDE_DIRS}
    include
)

add_library(${PROJECT_NAME}
    src/${PROJECT_NAME}/roboclaw.cpp
)

target_link_libraries(${PROJECT_NAME} ${Serial_LIBRARIES})



# install(TARGETS ${PROJECT_NAME}
#     ARCHIVE DESTINATION lib
#     LIBRARY DESTINATION lib
#     RUNTIME DESTINATION bin
# )
#
# install(DIRECTORY include/${PROJECT_NAME}/
#     DESTINATION include/${PROJECT_NAME}/
#     FILES_MATCHING PATTERN "*.h"
#     PATTERN ".svn" EXCLUDE
# )

# Install the header files to the include/ dir.
install(DIRECTORY include/${PROJECT_NAME}/
        DESTINATION ${CMAKE_INSTALL_PREFIX}/include/${PROJECT_NAME}
        FILES_MATCHING PATTERN "*.h")

# Install the library to the lib/ dir.
install(TARGETS ${PROJECT_NAME}
        EXPORT Roboclaw
        DESTINATION lib)

# Add to the Roboclaw targets so that the .cmake points to them.
set_property(GLOBAL APPEND PROPERTY ${VARS_PREFIX}_TARGETS ${PROJECT_NAME})

# add_subdirectory(tests)
find_package(Serial REQUIRED)


set_property(GLOBAL APPEND PROPERTY PACKAGE_${VARS_PREFIX}_INCLUDEDIR ${CMAKE_INSTALL_PREFIX}/include)

include(InstallBasicPackageFiles)
get_property(PACKAGE_${VARS_PREFIX}_INCLUDEDIR GLOBAL PROPERTY PACKAGE_${VARS_PREFIX}_INCLUDEDIR)
install_basic_package_files(Roboclaw VARS_PREFIX ${VARS_PREFIX}
                                        VERSION ${${VARS_PREFIX}_VERSION}
                                        COMPATIBILITY SameMajorVersion
                                        TARGETS_PROPERTY ${VARS_PREFIX}_TARGETS
                                    )
include(AddUninstallTarget)
