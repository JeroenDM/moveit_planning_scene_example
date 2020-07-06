#include <string>
#include <memory>

#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit/planning_scene_monitor/planning_scene_monitor.h>

#include <tf2_ros/transform_listener.h>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "planning_scene_example_get_object");
  ros::NodeHandle node_handle;
  ros::AsyncSpinner spinner(1);
  spinner.start();

  const std::string ROBOT_DESCRIPTION{ "robot_description" };

  moveit::planning_interface::PlanningSceneInterface planning_scene_interface;

  auto object_names = planning_scene_interface.getKnownObjectNames();
  for (auto& name : object_names)
  {
    ROS_INFO_STREAM("Collision object: " << name);
  }

  // std::shared_ptr<tf2_ros::Buffer> tf_buffer = std::make_shared<tf2_ros::Buffer>();
  // std::shared_ptr<tf2_ros::TransformListener> tf_listener = std::make_shared<tf2_ros::TransformListener>(*tf_buffer);

  // I'm not sure what the difference is between the two constructors.
  // auto psm = std::make_shared<planning_scene_monitor::PlanningSceneMonitor>(ROBOT_DESCRIPTION, tf_buffer);
  auto psm = std::make_shared<planning_scene_monitor::PlanningSceneMonitor>(ROBOT_DESCRIPTION);

  // update the planning scene monitor with the current state
  bool success = psm->requestPlanningSceneState("/get_planning_scene");
  ROS_INFO_STREAM("Request planning scene " << (success ? "succeeded." : "failed."));

  // keep up to date with new changes
  psm->startSceneMonitor("/move_group/monitored_planning_scene");

  ros::Rate loop_rate(1);

  while (ros::ok())
  {
    psm->getPlanningScene()->printKnownObjects();
    loop_rate.sleep();
  }

  
  ros::shutdown();
  return 0;
}