#include <nav_msgs/Odometry.h>
#include <ros/ros.h>
#include <working_odom/Age.h>

// void counterCallback(const nav_msgs::Odometry::ConstPtr &msg) {
//   ROS_INFO("%d", msg->header.frame_id.c_str());
//  ROS_INFO("%f",msg->twist.twist.linear.x);
//  ROS_)INFO("%f", msg->pose.pose.position.x);
//}

int main(int argc, char **argv) {

  ros::init(argc, argv, "dataSub");
  ros::NodeHandle nh;

  ros::Publisher pub = nh.advertise<working_odom::Age>("age_info", 1000);
  ros::Rate loop_rate(2);

  working_odom::Age age;
  age.year = 5;
  age.months = 10;
  age.days = 21;

  while (ros::ok()) {
    pub.publish(age);
    ros::spinOnce();
    loop_rate.sleep();
  }

  // ros::init(argc, argv, "dataSub");
  // ros::NodeHandle othing;

  // ros::Subscriber scribething = othing.subscribe("odom", 1000,
  // counterCallback);

  // ros::spin();

  return 0;
}