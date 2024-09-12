project(core VERSION 0.1 LANGUAGES CXX)

file(GLOB PROJECT_SOURCES "*.cpp" "*.h" "*.hpp" "*.cc" "*.c" "*.ui")

add_library(core STATIC ${PROJECT_SOURCES})
