add_executable(roboclaw_read_version read_version.cpp)
target_link_libraries( roboclaw_read_version roboclaw)

add_executable(roboclaw_read_encoder read_encoder.cpp)
target_link_libraries( roboclaw_read_encoder roboclaw)

add_executable(roboclaw_read read.cpp)
target_link_libraries( roboclaw_read roboclaw)

add_executable(roboclaw_set_m1_vel set_m1_vel.cpp)
target_link_libraries( roboclaw_set_m1_vel roboclaw)


install(TARGETS roboclaw_read_version roboclaw_read_encoder roboclaw_read roboclaw_set_m1_vel
        ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
        LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
        RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION})
