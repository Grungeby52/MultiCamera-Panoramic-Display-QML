cmake_minimum_required(VERSION 3.16)

project(MultiCameraPanoramicDisplayQML VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick Core Concurrent REQUIRED)
find_package(OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS})
qt_add_executable(appMultiCameraPanoramicDisplayQML
    main.cpp
    opencvimageprovider.cpp
    opencvimageprovider.h
    cameracapture.cpp
    cameracapture.h
    startprocess.cpp
    startprocess.h
    frameoperations.cpp
    frameoperations.h
    CamFrameId.h
)

qt_add_qml_module(appMultiCameraPanoramicDisplayQML
    URI MultiCameraPanoramicDisplayQML
    VERSION 1.0
    QML_FILES main.qml
    RESOURCES build/Desktop_Qt_6_5_3_GCC_64bit-Release/HDR/00511_OpenfootageNET_Panorama_low.hdr
    RESOURCES build/Desktop_Qt_6_5_3_GCC_64bit-Release/HDR/00511_OpenfootageNET_Panorama_low.hdr build/Desktop_Qt_6_5_3_GCC_64bit-Release/HDR/1.hdr
    RESOURCES build/Desktop_Qt_6_5_3_GCC_64bit-Release/HDR/00511_OpenfootageNET_Panorama_low.hdr build/Desktop_Qt_6_5_3_GCC_64bit-Release/HDR/1.hdr build/Desktop_Qt_6_5_3_GCC_64bit-Release/HDR/2.png
    RESOURCES build/Desktop_Qt_6_5_3_GCC_64bit-Release/HDR/3.jpg
    RESOURCES build/Desktop_Qt_6_5_3_GCC_64bit-Release/HDR/3.hdr
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appMultiCameraPanoramicDisplayQML PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appPanoramicTestQML
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appMultiCameraPanoramicDisplayQML
    PRIVATE Qt6::Quick
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Concurrent
    ${OpenCV_LIBS})


include(GNUInstallDirs)
install(TARGETS appMultiCameraPanoramicDisplayQML
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
