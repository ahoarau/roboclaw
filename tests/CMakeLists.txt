add_executable(read_version read_version.cpp)
target_link_libraries( read_version roboclaw)
install(TARGETS read_version
        EXPORT Roboclaw
        DESTINATION bin)

add_executable(read_encoder read_encoder.cpp)
target_link_libraries( read_encoder roboclaw)
install(TARGETS read_encoder
        EXPORT Roboclaw
        DESTINATION bin)

add_executable(read read.cpp)
target_link_libraries( read roboclaw)
install(TARGETS read
        EXPORT Roboclaw
        DESTINATION bin)

add_executable(set_m1_vel set_m1_vel.cpp)
target_link_libraries( set_m1_vel roboclaw)
install(TARGETS set_m1_vel
        EXPORT Roboclaw
        DESTINATION bin)
