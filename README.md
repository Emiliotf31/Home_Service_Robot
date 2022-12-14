# Home_Service_Robot (Write Up)
Welcome to my final project of the Nanodegree Program Robotic Sofware Engineer at Udacity. This project is a simulation of a "Home Service Robot" and its main purpose is to tell the robot to go to a Pick Up location to pick up an object and then go a Drop Off location to drop off the object. The software used to accomplish this project are ROS, Gazebo, Rviz in a Linux Ubuntu 18.04 with a ROS Kinetic distribution.


## Brief Description of the Packages

- *"my_robot"*: In this package one can find the information about the robot such as the description, the sensors used with its plugins and parameters. Also in the "launch" directory are the launch files such as the amcl.launch (explained below), mapping.launch, world.launch, and the configurations flaunch files for the different Rviz tests.
- *"map"*: It has all the information abaout the world, yaml, db ([must add the file form this link](https://drive.google.com/file/d/14I7nPg7WkIcz9Ma4G7WWIqwTRd1LCeHW/view?usp=sharing)), and map information.
- *"rvizconfig"*: Here are the configurations of the rviz corresponding to the different tasks (test_slam, test_navigation, home_service, etc.)
- *"teleop_twist_keyboard"*: This package was used just to move manually the robot for the SLAM test.
- *"scripts"*: It contains all the shell scripts used in the different phases of the project. The most important is the home_service.sh file which runs the final project.
- *"add_markers"* and *"pick_objects"*: Both are packages that contains it corresponding nodes. The pick_objects node is responsible for the movement of the robot, whereas add_markers node is used for the visualization of the object. The connection between both nodes is with parameters. So depending on the state of the parameter of the pick_objects there will be an answer from the add_markers node.


## Real-Time Appearance-Based Mapping (RTAB-Map)
This is a powerful algorithm to map the environment where the robot is situated.It is RGB-D, Stereo and Lidar Graph-Based SLAM and as it based on Graph SLAM it can solves the Full SLAM problem, which means the algorithm recovers the entire path and map. This algorithm is broadly used for dynamic environments, here is a link to understand more about [RTAB-Map for ROS](http://wiki.ros.org/rtabmap_ros).

With the use of this package and its node, it can be possible to obtain a map of my world, so then it can be set as an input for the AMCL algorithm. The [mapping.launch](https://github.com/Emiliotf31/Home_Service_Robot/blob/master/Home_Service_Project/my_robot/launch/mapping.launch) file has everything the algo needs to work. The parameters set on this project worked perfectly fine with my robot and enviroment, however, one can tune this parameters to get better results.

## Adaptive Monte Carlo Localization (AMCL)
The Monte Carlo Localazation (MCL) algorithm is broadly used for the localization problems. However, the AMCL algorithm is capable to improve the computational process due to the "adaptative" way to adjust the number of particles over time as the robot moves in the map. There are a lot of parameters in this section and in the [amcl.launch](https://github.com/Emiliotf31/Home_Service_Robot/blob/master/Home_Service_Project/my_robot/launch/amcl.launch) file there are most of the parametes sectioned by "Over All Filters", "Laserscan" and "Odometry". 

Here you can find more about the [AMCL Algorithm for ROS](http://wiki.ros.org/amcl), as well as the whole parameters. 

In order to move the robot one can use the "teleop_twist_keyboard" package, but for the purpose of this project I decided to use a "move_base" package to set a navigation goal position and to make it move to that position. This package is very useful to plan the trajectory, detect occupied or unoccupied areas as well as obstacles, and move the robot around if it gets stuck. Here you can find more about the [move_base package](http://wiki.ros.org/move_base). The [parameters of the "move_base"](https://github.com/Emiliotf31/Home_Service_Robot/tree/master/Home_Service_Project/my_robot/config) were tuned to get better results in following the path, the inflation zone and the speed of the robot, however, there are more things one can tuned.


## Pick-Up and Drop-Off
The main purpose of this project is divided into 4 actions:
- Go to the Pick-Up location.
- Pick up the object.
- Go to the Drop-Off location.
- Drop off the object.

The first and third actions are applied with the [pick_objects.cpp](https://github.com/Emiliotf31/Home_Service_Robot/blob/master/Home_Service_Project/pick_objects/src/pick_objects.cpp) node, meanwhile the second and fourth actions are applied with the [add_markers.cpp](https://github.com/Emiliotf31/Home_Service_Robot/blob/master/Home_Service_Project/add_markers/src/add_markers.cpp) file.

First the add_markers.cpp node is called to place the object in the Pick-Up position and then the pick_object.cpp node is called to send to the robot the goal position and make navigate through the world. After the robot has reached the Pick-Up zone the parameter "pick-up" is set to true in the pick_object.cpp node and the add_markers.cpp node get the parameter "pick_up" to tru in order to delete or pick up the object. Hence the new position is sent to the robot as the Drop-Off location, once the robot has reached the location the parameter "drop_off" is set to true in the "pick_objects.cpp" node and the "add_markers.cpp" node get the parameter "drop_off" to true so the new object appears or is dropped off in the Drop-Off location.

