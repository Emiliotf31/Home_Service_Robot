# Home_Service_Robot
Final project of the Nanodegree Program as a Robotic Software Engineer

Here I used 7 packages in order to accomplish this project.

- "my_robot" contains the world, robot xacro file, plugins, launch files, etc.
- "map" has all the information abaout the world, yaml, db (must add the file form this link: https://drive.google.com/file/d/14I7nPg7WkIcz9Ma4G7WWIqwTRd1LCeHW/view?usp=sharing), and map information.
- "rvizconfig" here are the configurations of the rviz corresponding to the different tasks (test_slam, test_navigation, home_service, etc.)
- "teleop_twist_keyboard" was used just to move manually the robot for the SLAM test.
- "scripts" contains all the shell scripts used in the different phases of the project. The most important is the home_service.sh file which runs the final project.
- "add_markers" and "pick_objects" are packages that contains it corresponding nodes. The pick_objects node is responsible for the movement of the robot, whereas add_markers node is used for the visualization of the object. The connection between both nodes is with parameters. So depending on the state of the parameter of the pick_objects there will be an answer from the add_markers node.
