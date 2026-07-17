cmake_minimum_required(VERSION 3.30)
project(hello_world LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(HELLO_WORLD_BUILD_TESTS "Build unit tests" ON)

if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "" FORCE)
endif()

add_library(hello_world STATIC
  src/hello_world.cpp
)
target_include_directories(hello_world PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_compile_features(hello_world PUBLIC cxx_std_23)

add_executable(hello_world_app src/main.cpp)
target_link_libraries(hello_world_app PRIVATE hello_world)

if(MSVC)
  target_compile_options(hello_world PRIVATE /W4 /WX)
  target_compile_options(hello_world_app PRIVATE /W4 /WX)
else()
  target_compile_options(hello_world PRIVATE -Wall -Wextra -Wpedantic -Werror)
  target_compile_options(hello_world_app PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()

enable_testing()
if(HELLO_WORLD_BUILD_TESTS)
  file(GLOB_RECURSE HELLO_WORLD_TEST_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.test.cpp"
  )

  if(HELLO_WORLD_TEST_SOURCES)
    find_package(GTest CONFIG REQUIRED)
    add_executable(hello_world_tests ${HELLO_WORLD_TEST_SOURCES})
    target_link_libraries(hello_world_tests PRIVATE hello_world GTest::gtest_main)
    target_include_directories(hello_world_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
    target_compile_features(hello_world_tests PRIVATE cxx_std_23)
    if(MSVC)
      target_compile_options(hello_world_tests PRIVATE /W4 /WX)
    else()
      target_compile_options(hello_world_tests PRIVATE -Wall -Wextra -Wpedantic -Werror)
    endif()
    include(GoogleTest)
    gtest_discover_tests(hello_world_tests)
  endif()
endif()
