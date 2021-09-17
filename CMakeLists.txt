cmake_minimum_required(VERSION 3.10)

project(SfmlLinux LANGUAGES CXX)

set(APP_NAME SfmlLinux)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES 
  main.cpp
  Entity.cpp
  AnimEngine.cpp
  AnimObject.cpp
  EventEngine.cpp
  EventHandler.cpp
  Engine.cpp
  PaintEngine.cpp
  Game.cpp
  Object.cpp
  Resources.cpp
  Container.cpp
  Snake/Snake.cpp
)
set(HEADERS
  Entity.h
  Common.h
  AnimEngine.h
  AnimObject.h
  EventEngine.h
  EventHandler.h
  Engine.h
  PaintEngine.h
  Game.h
  Object.h
  Resources.h
  Typedefs.h
  Container.h
  Snake/Snake.h
)

add_executable(${APP_NAME}
  ${SOURCES}
  ${HEADERS}
)

target_compile_definitions(${APP_NAME}
  PUBLIC SFML_DINAMYC
)

target_link_libraries(${APP_NAME}
  PUBLIC sfml-window
  PUBLIC sfml-graphics
  PUBLIC sfml-system
)
