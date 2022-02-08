cmake_minimum_required(VERSION 3.16)
project(PhyssicLib LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILER "/usr/bin/g++-10")


#Build source lib.
file(GLOB_RECURSE MY_APP_SRC ${CMAKE_CURRENT_SOURCE_DIR}/sources/*.cpp)
file(GLOB_RECURSE MY_APP_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/headers/*.hpp)
add_library(src_lib SHARED ${MY_APP_SRC} ${MY_APP_HEADERS})
target_include_directories(src_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/sources)
target_include_directories(src_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/headers)
target_compile_options(src_lib PUBLIC
  $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
  $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wfatal-errors -pedantic -fPIC -Wconversion -g>
)
set_target_properties(src_lib PROPERTIES LINKER_LANGUAGE CXX)

file(GLOB_RECURSE MY_APP_TEST_SRC ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
add_executable(main ${MY_APP_TEST_SRC})
target_link_libraries(main src_lib)