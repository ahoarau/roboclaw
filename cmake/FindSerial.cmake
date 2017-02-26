#  SERIAL_FOUND - system has serial
#  SERIAL_INCLUDE_DIRS - the serial include directory
#  SERIAL_LIBRARIES - The libraries needed to use serial

find_path(serial_INCLUDE_DIR serial/serial.h
   HINTS
   /usr/include
   /usr/local/include
)

find_library(serial_LIBRARY NAMES serial
   HINTS
   /usr/lib
   /usr/local/lib
)

if(serial_INCLUDE_DIR AND serial_LIBRARY)
   set(serial_LIBRARIES ${serial_LIBRARY})
   set(serial_INCLUDE_DIRS ${serial_INCLUDE_DIR})

   if (${CMAKE_SYSTEM} MATCHES "Linux")
       list(APPEND ${serial_LIBRARIES} rt)
   endif()

endif()

include(FindPackageHandleStandardArgs)
# handle the QUIETLY and REQUIRED arguments and set serial_FOUND to TRUE
# if all listed variables are TRUE
find_package_handle_standard_args(serial  DEFAULT_MSG
                        serial_LIBRARY serial_INCLUDE_DIR)

mark_as_advanced(serial_INCLUDE_DIR serial_INCLUDE_DIRS serial_LIBRARIES serial_LIBRARY)
