#include <geometry_msgs/Twist.h>
#include <ros/ros.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "publisher_node");
  ros::NodeHandle n;

  ros::Publisher effector =  n.advertise<geometry_msgs::Twist>("cmd_vel", 1000);
  ros::Rate loop_rate(2);

  geometry_msgs::Twist thingout;
  thingout.linear.x = 0.5;
  thingout.angular.z = 0.5;

  while (ros::ok()) {
    effector.publish(thingout);
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}