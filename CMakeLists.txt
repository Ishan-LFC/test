cmake_minimum_required(VERSION 3.5)

project(Assignment_2_Question_4 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Xml)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Xml)

set(PROJECT_SOURCES
        main.cpp
        person.cpp
        person.h
        guestregistration.cpp
        guestregistration.h
        input.cpp
        input.h
        registration.cpp
        registration.h
        registrationlist.cpp
        registrationlist.h
        registrationlistwriter.cpp
        registrationlistwriter.h
        registrationlistxml.cpp
        registrationlistxml.h
        registrationlistxmlstreamreader.cpp
        registrationlistxmlstreamreader.h
        studentregistration.cpp
        studentregistration.h
        tableview.cpp
        tableview.h
        registrationfactory.cpp
        registrationfactory.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Assignment_2_Question_4
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Assignment_2_Question_4 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Assignment_2_Question_4 SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Assignment_2_Question_4
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Assignment_2_Question_4 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt::Xml)

set_target_properties(Assignment_2_Question_4 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS Assignment_2_Question_4
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Assignment_2_Question_4)
endif()
