cmake_minimum_required	(VERSION 3.5)
get_filename_component 	(PROJECT_NAME ${CMAKE_CURRENT_LIST_DIR} NAME) 
project	(${PROJECT_NAME})

add_definitions(-std=c++14)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_LIST_DIR}/cmake")

#set the Qt5's location
set(CMAKE_PREFIX_PATH "/home/zjl/QT_Install/5.9/gcc_64")
set(Qt5_DIR "${CMAKE_PREFIX_PATH}/lib/cmake/Qt5")
set(Qt5Widgets_DIR "${CMAKE_PREFIX_PATH}/lib/cmake/Qt5Widgets")
set(Qt5Network_DIR "${CMAKE_PREFIX_PATH}/lib/cmake/Qt5Network")
set(Qt5LinguistTools_DIR "${CMAKE_PREFIX_PATH}/lib/cmake/Qt5LinguistTools")  

#find Torch
set(Torch_DIR /home/zjl/libtorch/share/cmake/Torch)  # 我的 libtorch 的路径
find_package(Torch REQUIRED)

#find OpenCV
find_package(OpenCV REQUIRED)
message(STATUS "OpenCV library status:")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")
include_directories(${OpenCV_INCLUDE_DIRS})


include_directories (./include)  #这个是自己家的头文件目录，比如helper.h等等
include_directories(${OpenCV_INCLUDE_DIRS}
					/home/zjl/libtorch/include
                    /home/zjl/libtorch/include/torch/csrc/api/include/
                    )

#find Qt5          
find_package(Qt5 COMPONENTS Concurrent Multimedia REQUIRED Widgets)
qt5_wrap_cpp( MOC widget.h)
qt5_wrap_ui( UIC widget.ui)



add_executable (${PROJECT_NAME} main.cpp mp3.h mp3.cpp dtwrecoge.h dtwrecoge.cpp handfinder.h handfinder.cpp connectthread.h connectthread.cpp setparam.cpp setparam.h setparam.ui widget.cpp widget.h widget.ui)

target_link_libraries(${PROJECT_NAME}  Qt5::Widgets Qt5::Concurrent Qt5::Multimedia ${CMAKE_CURRENT_LIST_DIR}/lib/libtofsdk.so  ${OpenCV_LIBS} ${TORCH_LIBRARIES} pthread dl rt)



message(STATUS)
message(STATUS "General configuration for ${PROJECT_NAME}")
message(STATUS "======================================================================")
message(STATUS "Platform:")
message(STATUS "  Arch / OS:				${CMAKE_HOST_SYSTEM_PROCESSOR} / ${CMAKE_HOST_SYSTEM_NAME} ${CMAKE_HOST_SYSTEM_VERSION}")
message(STATUS "  C/C++ Compiler:			${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "======================================================================")
message(STATUS)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)
