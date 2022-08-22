# Home_Service_Robot
Welcome to my final project of the Nanodegree Program Robotic Sofware Engineer at Udacity. This project is a simulation of a "Home Service Robot" and its main purpose is to tell the robot to go to a Pick Up location to pick up an object and then go a Drop Off location to drop off the object. The software used to accomplish this project are ROS, Gazebo, Rviz in a Linux Ubuntu 18.04 with a ROS Kinetic distribution.


## Brief Description of the Packages

- *"my_robot"*: In this package one can find the information about the robot such as the description, the sensors used with its plugins and parameters. Also in the "launch" directory are the launch files such as the amcl.launch (explained below), mapping.launch, world.launch, and the configurations flaunch files for the different Rviz tests.
- "map" has all the information abaout the world, yaml, db (must add the file form this link: https://drive.google.com/file/d/14I7nPg7WkIcz9Ma4G7WWIqwTRd1LCeHW/view?usp=sharing), and map information.
- "rvizconfig" here are the configurations of the rviz corresponding to the different tasks (test_slam, test_navigation, home_service, etc.)
- "teleop_twist_keyboard" was used just to move manually the robot for the SLAM test.
- "scripts" contains all the shell scripts used in the different phases of the project. The most important is the home_service.sh file which runs the final project.
- "add_markers" and "pick_objects" are packages that contains it corresponding nodes. The pick_objects node is responsible for the movement of the robot, whereas add_markers node is used for the visualization of the object. The connection between both nodes is with parameters. So depending on the state of the parameter of the pick_objects there will be an answer from the add_markers node.

## Adaptive Monte Carlo Localization (AMCL)
The Monte Carlo Localazation (MCL) algorithm is broadly used for the localization problems. However, the AMCL algorithm is capable to improve the computational process due to the "adaptative" way to adjust the number of particles over time as the robot moves in the map. There are a lot of parameters in this section and in the [amcl.launch](https://github.com/Emiliotf31/Home_Service_Robot/blob/master/Home_Service_Project/my_robot/launch/amcl.launch) file there are most of the parametes sectioned by "Over All Filters", "Laserscan" and "Odometry". 

Here you can find more about the [AMCL Algorithm for ROS](http://wiki.ros.org/amcl), as well as the whole parameters. 

In order to move the robot one can use the "teleop_twist_keyboard" package, but for the purpose of this project I decided to use a "move_base" package to set a navigation goal position and to make it move to that position. This package is very useful to plan the trajectory, detect occupied or unoccupied areas as well as obstacles, and move the robot around if it gets stuck. Here you can find more about the [move_base package](http://wiki.ros.org/move_base). The [parameters of the "mov_base"](https://github.com/Emiliotf31/Home_Service_Robot/tree/master/Home_Service_Project/my_robot/config) were tuned to get better results in following the path, the inflation zone and the speed of the robot, however, there are more things one can tuned.






