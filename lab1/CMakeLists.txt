cmake_minimum_required(VERSION 3.10)
project(Lab01)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавление опций компиляции
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror=maybe-uninitialized")

# Установка Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.0
  TLS_VERIFY false
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Основная библиотека
add_library(${CMAKE_PROJECT_NAME}_lib src/bit_counter.cpp)

# Основная программа
add_executable(${CMAKE_PROJECT_NAME}_exe src/main.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME}_exe PRIVATE ${CMAKE_PROJECT_NAME}_lib)

# Включение директорий
target_include_directories(${CMAKE_PROJECT_NAME}_lib PUBLIC include)
target_include_directories(${CMAKE_PROJECT_NAME}_exe PUBLIC include)

# Тесты
enable_testing()
add_executable(tests tests/test_bit_counter.cpp)
target_link_libraries(tests ${CMAKE_PROJECT_NAME}_lib gtest_main)

# Добавление тестов в тестовый набор
add_test(NAME Lab01Tests COMMAND tests)