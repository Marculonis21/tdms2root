cmake_minimum_required(VERSION 3.5)

project(tdms2root)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Release)

# find_package(ROOT REQUIRED COMPONENTS MathCore MathMore)
find_package(ROOT 6.16 CONFIG REQUIRED)

# set(CMAKE_CXX_FLAGS "-pthread -std=c++17 -m64 -I/home/marculonis/Downloads/root/include -L/home/marculonis/Downloads/root/lib -lCore -lImt -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lROOTVecOps -lTree -lTreePlayer -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lThread -lMultiProc -lROOTDataFrame -Wl,-rpath,/home/marculonis/Downloads/root/lib -pthread -lm -ldl -rdynamic")
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

file(GLOB PROJECT_SOURCES
    ${CMAKE_SOURCE_DIR}/src/tdmsReader/*.cpp
    ${CMAKE_SOURCE_DIR}/src/tdmsReader/*.hh
    ${CMAKE_SOURCE_DIR}/src/tdmsReader/*.h
    ${CMAKE_SOURCE_DIR}/src/*.cpp
    ${CMAKE_SOURCE_DIR}/src/*.hpp)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

target_link_libraries(${PROJECT_NAME} ROOT::MathCore)
target_link_libraries(${PROJECT_NAME} ROOT::MathMore)
target_link_libraries(${PROJECT_NAME} ROOT::Tree)
