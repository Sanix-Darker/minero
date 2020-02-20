cmake_minimum_required(VERSION 3.12)

project(minero)

add_definitions("-std=c++11")
find_package(Boost COMPONENTS python37 REQUIRED)
find_package(PythonInterp 3.7.3)
find_package(PythonLibs 3.7.3)

include("./build/conanbuildinfo.cmake")
conan_basic_setup()

add_library(${PROJECT_NAME}
                SHARED
                module.cpp
                minero.cpp)

file(GLOB
        headers
        *.hpp)

# set(OBJS
#         ${CMAKE_CURRENT_SOURCE_DIR}/minero.dir/SHA256.cpp.o
# )

target_include_directories(${PROJECT_NAME} PRIVATE ${Boost_INCLUDE_DIRS} ${PYTHON_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} ${PYTHON_LIBRARIES} ${CONAN_LIBS})

# To build an eecutable
# add_executable(${PROJECT_NAME} minero.cpp)
target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")

# set_source_files_properties(
#   ${OBJS}
#   PROPERTIES
#   EXTERNAL_OBJECT true
#   GENERATED true
# )

message("install ${Python_SITELIB}")