# MoveIt planning scene monitor example

This example shows how to create a [PlanningSceneMonitor](g/melodic/api/moveit_ros_planning/html/classplanning__scene__monitor_1_1PlanningSceneMonitor.html) instance that is up to date with the planning scene published by a move group node.

## Running the example
For example, launch the move group node for the panda robot:
```
 roslaunch panda_moveit_config demo.launch
```

And add a collision object with the script from this tutorial:
```
rosrun planning_scene_example add_collision_objects
```

Output:
```
ros.moveit_core.robot_model: Loading robot model 'panda'...
ros.moveit_ros_planning_interface.move_group_interface: Ready to take commands for planning group panda_arm.
ros.planning_scene_example: Using box name: box1
ros.planning_scene_example.tutorial: Add an object into the world
ros.planning_scene_example: Collision object: box1
```

Now, run the example node:
```
rosrun planning_scene_example access_planning_scene 
```

And you should see `box1` is present in the output:
```
-----------------------------------------
PlanningScene Known Objects:
  - Collision World Objects:
 	- box1
  - Attached Bodies:
-----------------------------------------
```

Using the same `add_collision_objects`, you can also add objects with a specific name given as command line argument. For example we can add another collision object `other_box`, while the `access_planning_scene` is still running in another terminal.
```
rosrun planning_scene_example add_collision_objects other_box
```
In the terminal where the `access_planning_scene` is running, the collision scene should now contain two collision objects:
```
-----------------------------------------
PlanningScene Known Objects:
  - Collision World Objects:
 	- box1
	- other_box
  - Attached Bodies:
-----------------------------------------
```