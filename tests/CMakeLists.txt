add_executable(read_version read_version.cpp)
target_link_libraries( read_version roboclaw)

add_executable(read_encoder read_encoder.cpp)
target_link_libraries( read_encoder roboclaw)

add_executable(read read.cpp)
target_link_libraries( read roboclaw)
