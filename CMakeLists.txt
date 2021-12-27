cmake_minimum_required(VERSION 3.5)

project(Server LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Core)
find_package(Boost REQUIRED COMPONENTS)

include_directories(SYSTEM /usr/include/boost)
message(${Boost_INCLUDE_DIRS})
#add_library(asio IMPORTED INTERFACE)
#target_compile_options(asio INTERFACE ASIO_STANDALONE)
#target_include_directories(asio INTERFACE /usr/include/boost/)
#set_property(TARGET boost::asio INTERFACE_INCLUDE_DIRECTORIES)

add_executable(Server
  main.cpp
  server.cpp
  connection_handler.cpp
)
target_link_libraries(Server Qt5::Core ${Boost_LIBRARIES} pthread)
#target_link_libraries(asio INTERFACE pthread)
#target_compile_definitions(asio PUBLIC ASIO_STANDALONE)
