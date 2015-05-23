cmake_minimum_required(VERSION 3.2)
project(Windows)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -Wconversion")

set(SOURCE_FILES
    Button.cpp
    Button.h
    Color.cpp
    Color.h
    Desktop.cpp
    Desktop.h
    DragAndDropButton.cpp
    DragAndDropButton.h
    DragAndDropInterface.h
    Element.cpp
    Element.h
    Icon.h
    Label.cpp
    Label.h
    main.cpp
    MoveWindowBar.cpp
    MoveWindowBar.h
    Point.h
    SDL_Main.cpp
    SDL_Main.h
    Surface.cpp
    Surface.h
    Window.cpp
    Window.h
    WindowItemInterface.h)

    FIND_LIBRARY(SDL2_LIBRARY SDL2)
    FIND_LIBRARY(SDL2_TTF_LIBRARY SDL2_ttf)
    SET(LIBS ${SDL2_LIBRARY} ${SDL2_TTF_LIBRARY})

    INCLUDE_DIRECTORIES(${SDL2_LIBRARY}/Headers ${SDL2_TTF_LIBRARY}/Headers)

add_executable(Windows ${SOURCE_FILES})
TARGET_LINK_LIBRARIES(Windows ${LIBS})
