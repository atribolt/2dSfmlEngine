cmake_minimum_required(VERSION 3.10)

project(SfmlLinux LANGUAGES CXX)

set(CORE_LIB_NAME Sfml2dEngine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
  src/Entity.cpp
  src/AnimEngine.cpp
  src/AnimObject.cpp
  src/EventEngine.cpp
  src/EventHandler.cpp
  src/Engine.cpp
  src/PaintEngine.cpp
  src/Game.cpp
  src/Object.cpp
  src/Container.cpp
  src/Resources/Resource.cpp
  src/Resources/ResourceManager.cpp
)
set(HEADERS
  include/Entity.h
  include/Common.h
  include/AnimEngine.h
  include/AnimObject.h
  include/EventEngine.h
  include/EventHandler.h
  include/Engine.h
  include/PaintEngine.h
  include/Game.h
  include/Object.h
  include/Typedefs.h
  include/Container.h
  include/Resources/Resource.h
  include/Resources/ResourceManager.h
)

add_library(${CORE_LIB_NAME} SHARED
  ${SOURCES}
  ${HEADERS}
)

target_compile_definitions(${CORE_LIB_NAME}
  PUBLIC SFML_DINAMYC
)

target_link_libraries(${CORE_LIB_NAME}
  PUBLIC sfml-window
  PUBLIC sfml-graphics
  PUBLIC sfml-system
)

include_directories(include)

add_subdirectory(Examples)
add_subdirectory(Tools)
