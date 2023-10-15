#include "geometry_msgs/Twist.h"
#include "nav_msgs/Odometry.h"
#include "ros/ros.h"
#include "std_srvs/Empty.h"

class Rotate {

  ros::NodeHandle node;
  // actionlib::SimpleActionServer<actionlib::TestAction> as_;
  // std::string action_name_;
  // actionlib::TestFeedback information_;
  // actionlib::TestResult result_;

  // need to make custom of degrees... maybe success...
  // needed messages
  int degrees;
  bool success;

  geometry_msgs::Twist rotate_msg_;

  // remember to make custom int "degrees" for the package
  bool simplecallback(std_srvs::degrees::Request &req,
                      std_srvs::success::Response &res) {
    req.degrees = req.degrees * 3.14 / 180;
    ROS_INFO("You have choosen to rotate the robot");
    return true;
  }
  void odomCb(const nav_msgs::Odometry::ConstPrt &msg) {
    int orient_z_initial = msg->pose.pose.orientation.z;
    int angular_z_initial = msg->twist.twist.angular.z;
  }

  ros::Publisher rotate_pub =
      node.advertise<geometry_msgs::Twist>("cmd_vel", 1000);

  int counter = 0

                if counter < 4 {
    //  ros::Rate loop_rate(.25); don't think it need to be here... likely to
    //  remove

    geometry_msgs::Twist angular_accel;
    angular_accel.angular.z =
        (req.degrees - orient_z_initial - (angular_z_initial * 4)) / 16;
    // us angular moment equation at t = 4
    ros::Time beginTime = ros::Time::now();
    ros::Duration secondsIWantToSendMessagesFor = ros::Duration(4);
    ros::Time endTime = beginTime + secondsIWantToSendMessagesFor;
  }

  while (ros::Time::now() < endTime) {
    rotate_pub.publish(angular_accel);

    // Time between messages, so you don't blast out an thousands of
    // messages in your 3 secondperiod
    ros::Duration(0.1).sleep();
  }
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "Rotate_robot");

  Rotate your_choice("rotate_robot_ss");
  ros::spin();

  return 0;
}