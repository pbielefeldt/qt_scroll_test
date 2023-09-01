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

# Find Qt5 package
find_package(Qt5 COMPONENTS Widgets REQUIRED)
set(CMAKE_AUTOMOC ON)

# Add your source files
set(SOURCES
    main.cpp
    FileTab.cpp   # Add FileTab.cpp to the source files
)

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link the Qt5 Widgets library
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)