cmake_minimum_required(VERSION 3.0.0)
project(SWEN2 VERSION 0.1.0)

include(CTest)
enable_testing()

FILE(GLOB MySources src/*.cpp)
add_executable(SWEN2 ${MySources})
include_directories(include)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
