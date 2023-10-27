cmake_minimum_required(VERSION 2.8.3)
project(roskcci)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

find_package(catkin REQUIRED COMPONENTS
  nav_msgs
  roscpp
  sensor_msgs
  std_msgs
  tf
  turtlebot3_msgs
  geometry_msgs
  cv_bridge
  image_transport
)
include_directories(
 # include
  ${catkin_INCLUDE_DIRS} 
  ${OpenCV_INCLUDE_DIRS}
)

catkin_package(
#  INCLUDE_DIRS include
  LIBRARIES roskcci
  CATKIN_DEPENDS nav_msgs roscpp sensor_msgs std_msgs tf turtlebot3_msgs geometry_msgs
#  DEPENDS system_lib
)

## Qt
set(CMAKE_PREFIX_PATH "/home/ubuntu/Qt5.14.2/5.14.2/gcc_64")
set(ModuleList 
    Core
    Gui
    Widgets
    Network
)

foreach(QtModule ${ModuleList})
    set(Qt5${QtModule}_DIR ${CMAKE_PREFIX_PATH}/lib/cmake/Qt5${QtModule})
    message("foreach-> Qt5${QtModule}_DIR : ${Qt5${QtModule}_DIR}")

    set(QT_LIBRARIES ${QT_LIBRARIES} Qt5::${QtModule})
endforeach()
message("${QT_LIBRARIES}")

find_package(Qt5 REQUIRED ${ModuleList})
find_package(Qt5Widgets REQUIRED })
find_package(OpenCV)

file(GLOB QT_FORMS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ui/*.ui)
file(GLOB QT_RESOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.qrc)
file(GLOB_RECURSE QT_MOC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS include/roskcci/*.hpp include/roskcci/*.h)

qt5_add_resources(APP_RESOURCES ${CMAKE_CURRENT_LIST_DIR}/weatherinfo.qrc)

QT5_WRAP_UI(QT_FORMS_HPP ${QT_FORMS})
QT5_WRAP_CPP(QT_MOC_HPP ${QT_MOC})

file(GLOB_RECURSE QT_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS src/*.cpp)

add_executable(rosqt ${SOURCE} ${QRC_FILES} ${QT_SOURCES} ${QT_RESOURCES_CPP} ${QT_FORMS_HPP} ${QT_MOC_HPP} )
target_link_libraries(rosqt ${QT_LIBRARIES} ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})
install(TARGETS rosqt RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
