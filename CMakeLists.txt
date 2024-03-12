cmake_minimum_required(VERSION 3.24)
project(maze)
 #set (CMAKE_CXX_FLAGS “${CMAKE_CXX_FLAGS} -g”)
include_directories(code libgraphics simpleGUI)

aux_source_directory(Code Src)
aux_source_directory(libgraphics Lib)
aux_source_directory(simpleGUI Gui)
add_executable(maze ${Src} ${Lib} ${Gui})