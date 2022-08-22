#include <ros/ros.h>
#include <visualization_msgs/Marker.h>


int main( int argc, char** argv )
{
  
  
  ros::init(argc, argv, "add_markers_single");
  ros::NodeHandle n;
  ros::Rate r(1);
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);

  // Set our initial shape type to be a cube
  uint32_t shape = visualization_msgs::Marker::CUBE;

  visualization_msgs::Marker pick_obj;
  visualization_msgs::Marker drop_obj;

  // Set the frame ID and timestamp.  See the TF tutorials for information on these.
  pick_obj.header.frame_id = "map";
  pick_obj.header.stamp = ros::Time::now();
  drop_obj.header.frame_id = "map";
  
  // Set the namespace and id for this marker.  This serves to create a unique ID
  // Any marker sent with the same namespace and id will overwrite the old one
  pick_obj.ns = "add_markers_single";
  pick_obj.id = 0;
  drop_obj.ns = "add_markers_single";
  drop_obj.id = 1;

  // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
  pick_obj.type = shape;
  drop_obj.type = shape;

  // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
  pick_obj.action = visualization_msgs::Marker::ADD;
	drop_obj.action = visualization_msgs::Marker::ADD;

  // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
  pick_obj.pose.position.x = 0.74;
  pick_obj.pose.position.y = 1.5;
  pick_obj.pose.position.z = 0;
  pick_obj.pose.orientation.x = 0.0;
  pick_obj.pose.orientation.y = 0.0;
  pick_obj.pose.orientation.z = 0.0;
  pick_obj.pose.orientation.w = 1.0;
  
  drop_obj.pose.position.x = -0.127;
  drop_obj.pose.position.y = -1.97;
  drop_obj.pose.position.z = 0;
  drop_obj.pose.orientation.x = 0.0;
  drop_obj.pose.orientation.y = 0.0;
  drop_obj.pose.orientation.z = 0.0;
  drop_obj.pose.orientation.w = 1.0;

  // Set the scale of the marker -- 1x1x1 here means 1m on a side
  pick_obj.scale.x = 0.1;
  pick_obj.scale.y = 0.1;
  pick_obj.scale.z = 0.1;

  drop_obj.scale.x = 0.1;
  drop_obj.scale.y = 0.1;
  drop_obj.scale.z = 0.1;

  // Set the color -- be sure to set alpha to something non-zero!
  pick_obj.color.r = 0.0f;
  pick_obj.color.g = 1.0f;
  pick_obj.color.b = 0.0f;
  pick_obj.color.a = 1.0;

  drop_obj.color.r = 0.0f;
  drop_obj.color.g = 1.0f;
  drop_obj.color.b = 0.0f;
  drop_obj.color.a = 1.0;
  
  pick_obj.lifetime = ros::Duration();
  
  ros::Duration(1.0).sleep();
  ROS_INFO("Setting the Object");
  marker_pub.publish(pick_obj);

  ros::Duration(5.0).sleep();
  pick_obj.action = visualization_msgs::Marker::DELETE;
  marker_pub.publish(pick_obj);
  ROS_INFO("Object picked up.");
  
  ros::Duration(5.0).sleep();
  drop_obj.header.stamp = ros::Time::now();
  drop_obj.lifetime = ros::Duration();
  marker_pub.publish(drop_obj);
  ROS_INFO("Object dropped off.");

  ros::Duration(10.0).sleep();

  return 0;
}
