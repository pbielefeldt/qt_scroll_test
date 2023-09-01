cmake_minimum_required(VERSION 3.5)
project(TextFileViewer)

#######################################################
# To build, create a directory and use CMake and make.
# You must have the required Qt libs installed.
#     mkdir build; cd build
#     cmake ..
#     make
# To run, execute
#     ./TextFileViewer
# (make sure you have a GUI)
#######################################################

# Find the Qt5 package
find_package(Qt5Widgets REQUIRED)

# Set your source file(s)
set(SOURCES main.cpp)

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link against Qt5 libraries
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
