cmake_minimum_required(VERSION 3.5)

project(VyNixDrive VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets OpenGLWidgets OpenGL)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets OpenGLWidgets OpenGL)
find_package(Qt6 REQUIRED COMPONENTS Svg)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(VyNixDrive
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        Renderer/openglwidget.h Renderer/openglwidget.cpp
        Renderer/Core/Vertex.h
        Renderer/shader.h Renderer/shader.cpp
        Assets/Shaders/Triangle.frag
        Assets/Shaders/Triangle.vert
        Renderer/vertexbuffer.h Renderer/vertexbuffer.cpp
        Renderer/vertexlayout.h
        Renderer/vertexlayout.cpp
        Renderer/vertexarray.h Renderer/vertexarray.cpp
        UI/Navigation/navigationbar.h UI/Navigation/navigationbar.cpp
        UI/Screens/homescreen.h UI/Screens/homescreen.cpp
        UI/Screens/screen.h UI/Screens/screen.cpp
        UI/Screens/hvacscreen.h UI/Screens/hvacscreen.cpp
        UI/Screens/ambientscreen.h UI/Screens/ambientscreen.cpp
        UI/Navigation/navigationitem.h UI/Navigation/navigationitem.cpp
        UI/Navigation/NavigationPage.h
        Assets/Resources.qrc
        Assets/Icons/ambient.svg Assets/Icons/camera.svg Assets/Icons/home.svg Assets/Icons/hvac.svg Assets/Icons/music.svg Assets/Icons/settings.svg Assets/Icons/tpms.svg
        Renderer/elementbuffer.h Renderer/elementbuffer.cpp
        Renderer/Math/Vec2.h
        Renderer/Math/Vec3.h
        Renderer/Math/Transform.h
        Renderer/camera.h Renderer/camera.cpp
        Renderer/renderer.h Renderer/renderer.cpp
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET VyNixDrive APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(VyNixDrive SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(VyNixDrive
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_include_directories(VyNixDrive PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(VyNixDrive PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::OpenGLWidgets
    Qt${QT_VERSION_MAJOR}::OpenGL
    Qt6::Svg
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.VyNixDrive)
endif()
set_target_properties(VyNixDrive PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS VyNixDrive
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(VyNixDrive)
endif()

add_custom_command(TARGET VyNixDrive POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/Assets
    $<TARGET_FILE_DIR:VyNixDrive>/Assets
)
