set(CMAKE_AUTOMOC ON)

cmake_minimum_required(VERSION 3.5)
project(VidRecv)

find_package(Qt5Widgets)
find_package(Qt5Core)
find_package(gazebo REQUIRED)

add_definitions(${Qt5Core_DEFINITIONS})

include_directories(
	include 
	"/home/wil/workspace/sitl/fpv"
	${Qt5Core_INCLUDE_DIRS}  
	${GAZEBO_INCLUDE_DIRS}
)

link_directories(
	${GAZEBO_LIBRARY_DIRS}
	)
#"/home/wil/workspace/gazebo/build/gazebo"
#"/home/wil/workspace/gazebo/build/gazebo/gui"
list(APPEND CMAKE_CXX_FLAGS ${GAZEBO_CXX_FLAGS})

set(source
	${PROJECT_SOURCE_DIR}/main.cc
	${CMAKE_CURRENT_SOURCE_DIR}/ImageFrame.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/ImageView.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/ImagesView.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/TopicView.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/TextView.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/ViewFactory.cc
)
set (headers
  ${headers}
  ${CMAKE_CURRENT_SOURCE_DIR}/ImageFrame.hh
  ${CMAKE_CURRENT_SOURCE_DIR}/ImageView.hh
  ${CMAKE_CURRENT_SOURCE_DIR}/ImagesView.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/TextView.hh
  ${CMAKE_CURRENT_SOURCE_DIR}/TopicView.hh
  #  ${CMAKE_CURRENT_SOURCE_DIR}/ImageFramePrivate.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/ViewFactory.hh
)
#add_subdirectory("gazebo/gui/viewers")

add_executable(${PROJECT_NAME} ${source} ${headers})

target_link_libraries(
${PROJECT_NAME}
 ${GAZEBO_LIBRARIES}
 ${Qt5Core_LIBRARIES}
 ${Qt5Widgets_LIBRARIES}
 ${Boost_LIBRARIES}
 ${IGNITION-TRANSPORT_LIBRARIES}
 pthread
)
