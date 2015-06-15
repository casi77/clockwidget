cmake_minimum_required (VERSION 2.6)
  project(clockwidget)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if( "$ENV{QT_ROOT}" STREQUAL "" )
  set( QT_ROOT ${CMAKE_HOME_DIRECTORY}/../qt-5.0)
endif()

if( EXISTS ${QT_ROOT}/bin AND IS_DIRECTORY ${QT_ROOT}/bin )
  set( ENV{PATH} "${QT_ROOT}/bin:$ENV{PATH}" )
endif()
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Widgets Quick Qml Network REQUIRED)

QT5_WRAP_UI(UIS_HDRS mainwindow.ui)
qt5_add_resources(RESOURCES resource.qrc)
add_executable(clockwidget main.cpp mainwindow.cpp udpclient.cpp udpserver.cpp ${RESOURCES} ${UIS_HDRS})


 target_link_libraries( ${PROJECT_NAME} ${Qt5Widgets_LIBRARIES})
 target_link_libraries( ${PROJECT_NAME} ${Qt5Quick_LIBRARIES})
