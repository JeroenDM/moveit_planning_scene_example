cmake_minimum_required(VERSION 2.8.3)
project(planning_scene_example)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  moveit_core
  moveit_ros_planning
  moveit_ros_planning_interface
  moveit_visual_tools
  roscpp
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES planning_scene_example
#  CATKIN_DEPENDS moveit_core moveit_ros_planning moveit_ros_planning_interface moveit_visual_tools roscpp
#  DEPENDS system_lib
)

###########
## Build ##
###########

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(add_collision_objects  src/add_collision_objects.cpp)

target_link_libraries(add_collision_objects
  ${catkin_LIBRARIES}
)

add_executable(access_planning_scene  src/access_planning_scene.cpp)

target_link_libraries(access_planning_scene
  ${catkin_LIBRARIES}
)