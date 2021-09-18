cmake_minimum_required(VERSION 3.10)

set(TOOL_NAME ResourceManager)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADERS
  ResourceManager.h
)
set(SOURCES
  main.cpp
  ResourceManager.cpp
)

add_executable(${TOOL_NAME}
  ${HEADERS}
  ${SOURCES}
)

target_link_libraries(${TOOL_NAME}
  PRIVATE ${CORE_LIB_NAME}
)
