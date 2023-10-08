#include "ros/ros.h"
#include "std_srvs/Empty.h"
#include <geometry_msgs/Twist.h>

ros::Publisher thing;
geometry_msgs::Twist thing2;

bool my_callback(std_srvs::Empty::Request &req, std_srvs::Empty::Response &res)

{
  ROS_INFO("The created service has been called");
  thing2.linear.x = .2;
  thing2.angular.z = .2;
  thing.publish(thing2);
  ROS_INFO("Created service has finished");
  return true;
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "service_server");
  ros::NodeHandle name;

  ros::ServiceServer my_service =
      name.advertiseService("/move_bb8_circle", my_callback);
  thing = name.advertise<geometry_msgs::Twist>("cmd_vel", 1000);
  ROS_INFO("The Service for moving bb 8 is ready");
  ros::spin();

  return 0;
}