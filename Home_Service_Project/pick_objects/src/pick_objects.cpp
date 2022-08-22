#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

// Define a client for to send goal requests to the move_base server through a SimpleActionClient
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv){
  
  bool picked_up = false;
  
  // Initialize the pick_objects node
  ros::init(argc, argv, "pick_objects");
  ros::NodeHandle n;

  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

  // Wait 5 sec for move_base action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  move_base_msgs::MoveBaseGoal pick;

  float pickup[3] = {0.5, 1.5, 1.0};

  // set up the frame parameters
  pick.target_pose.header.frame_id = "map";
  pick.target_pose.header.stamp = ros::Time::now();
  
  n.setParam("pick_up", false);
  n.setParam("drop_off", false);

  // Define a position and orientation for the robot to reach
  pick.target_pose.pose.position.x = pickup[0];
  pick.target_pose.pose.position.y = pickup[1];
  pick.target_pose.pose.orientation.w = pickup[2];

   // Send the goal position and orientation for the robot to reach
  ROS_INFO("Sending coordinates to Pick Up Zone");
  ac.sendGoal(pick);

  // Wait an infinite time for the results
  ac.waitForResult();

  // Check if the robot reached its goal
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
  {
    ROS_INFO("Already in Pick Up Zone");
    n.setParam("pick_up", true);
    picked_up = true;
  }
  else
    ROS_INFO("Unable to reach the Pick Up Zone");
  
  
  ros::Duration(5.0).sleep();
  
  
   if (picked_up)
   {
     move_base_msgs::MoveBaseGoal drop;
     
     float dropoff[3] = {-0.5, -2, 1.0};
     
     drop.target_pose.header.stamp = ros::Time::now();
     drop.target_pose.header.frame_id = "map";
     
     // Define a position and orientation for the robot to reach
     drop.target_pose.pose.position.x = dropoff[0];
     drop.target_pose.pose.position.y = dropoff[1];
     drop.target_pose.pose.orientation.w = dropoff[2];
     
     // Send the goal position and orientation for the robot to reach
     ROS_INFO("Sending coordinates to Drop Off Zone");
     ac.sendGoal(drop);
     
     // Wait an infinite time for the results
     ac.waitForResult();
     
     if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
     {
       ROS_INFO("Already in Drop Off Zone");
      n.setParam("drop_off", true);
     }
     else
       ROS_INFO("Unable to reach the Drop Off Zone");
   }

  return 0;
}
