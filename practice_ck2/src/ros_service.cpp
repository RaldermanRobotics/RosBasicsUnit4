#include "geometry_msgs/Twist.h"
#include "ros/ros.h"
#include "std_srvs/Empty.h"

class Rotate {

  ros::NodeHandle node;
  actionlib::SimpleActionServer<actionlib::TestAction> as_;
  std::string action_name_;
  actionlib::TestFeedback information_;
  actionlib::TestResult result_;

  int degrees_;
  bool success_;

  ros::Rate rate_;
  ros::Publisher rotate_pub_;
  geometry_msgs::Twist rotate_msg_;
  ros::Subscriber odom_read_;
  

      bool
      simplecallback(std_srvs::Empty::Reuest &req,
                     std_srvs::Empty::Response &res) {
    ROS_INFO("You have choosen to rotate the robot");
    return true;
  }
}