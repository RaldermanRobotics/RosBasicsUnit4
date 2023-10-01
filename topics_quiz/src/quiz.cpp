#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

// going to try to just write it up from scratch//

int main(int argc, char **argv) {
  ros::init(argc, argv, "topics_quiz_node");
  ros::NodeHandle nh;
  // simple visual breack//
  ros::Publisher tocmdvel = nh.advertise<geometry_msgs::Twist>("cmd_vel", 1000);
  ros::Rate loop_rate(2);

  geometry_msgs::Twist vel;
  vel.linear.x = 0.5;
  vel.angular.z = 0.5;

  while (ros::ok()) {
    tocmdvel.publish(vel);
    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}