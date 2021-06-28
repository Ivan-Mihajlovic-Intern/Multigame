cmake_minimum_required(VERSION 3.5)

project(GameSpace VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check https://doc.qt.io/qt/deployment-android.html for more information.
# They need to be set before the find_package( ...) calls below.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
        src/main.cpp
        src/mainwindow.cpp
        src/mainwindow.h
        src/mainwindow.ui
        src/game.cpp
        src/game.h
        Demolition/demolition.cpp
        FlappyBird/background.cpp
        FlappyBird/flappybird.cpp
        FlappyBird/player.cpp
        FlappyBird/obstacle.cpp
        FlappyBird/score.cpp
        Pong/pong.cpp
        Demolition/demolition.h
        FlappyBird/background.h
        FlappyBird/flappybird.h
        FlappyBird/obstacle.h
        FlappyBird/player.h
        FlappyBird/score.h
        Pong/pong.h
        Demolition/demolition.ui
        FlappyBird/flappybird.ui
        Pong/pong.ui
)

set(RESOURCES rsc.qrc)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(GameSpace
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        ${RESOURCES}
    )
else()
    if(ANDROID)
        add_library(GameSpace SHARED
            ${PROJECT_SOURCES}
            ${RESOURCE}
        )
    else()
        add_executable(GameSpace
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(GameSpace PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(GameSpace PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(GameSpace)
endif()
