
SET(DRIVE_SRCS
    CommandLineIMUS.cpp)
    
add_library (rpiServo.cpp)
add_libary (rpiPWM1.cpp)

ADD_EXECUTABLE(CommandLineIMUS ${DRIVE_SRCS})
TARGET_LINK_LIBRARIES(CommandLineIMUS RTIMULib)

INSTALL(TARGETS CommandLineIMUS DESTINATION bin)
