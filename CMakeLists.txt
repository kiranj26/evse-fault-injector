cmake_minimum_required(VERSION 3.10)
project(EVSEFaultInjector VERSION 1.0.0 LANGUAGES CXX)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set Boost paths
set(BOOST_ROOT /usr/local/Cellar/boost/1.84.0)
set(BOOST_INCLUDEDIR ${BOOST_ROOT}/include)
set(BOOST_LIBRARYDIR ${BOOST_ROOT}/lib)

# Find Boost libraries
find_package(Boost 1.84 REQUIRED COMPONENTS system)

if (Boost_FOUND)
    message(STATUS "Boost found!")
    message(STATUS "Boost include dir: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost libraries: ${Boost_LIBRARIES}")
    include_directories(${Boost_INCLUDE_DIRS})
    link_directories(${BOOST_LIBRARYDIR})
else()
    message(FATAL_ERROR "Boost not found!")
endif()

# Add the executable
add_executable(evse_fault_injector
    src/main.cpp
    src/websocket_server.cpp
)

# Include directories and link libraries
target_include_directories(evse_fault_injector PUBLIC include)
target_link_libraries(evse_fault_injector Boost::system)
