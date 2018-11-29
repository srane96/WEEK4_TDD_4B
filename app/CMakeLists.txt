add_executable(pid-controller main.cpp pid.cpp tuner.cpp)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
)
