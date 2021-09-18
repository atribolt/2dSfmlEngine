cmake_minimum_required(VERSION 3.10)

set(EXAMPLE_NAME Snake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADERS
  Snake.h
)
set(SOURCES
  main.cpp
  Snake.cpp
)

add_executable(${EXAMPLE_NAME}
  ${HEADERS}
  ${SOURCES}
)

target_link_libraries(${EXAMPLE_NAME}
  PRIVATE ${CORE_LIB_NAME}
)
