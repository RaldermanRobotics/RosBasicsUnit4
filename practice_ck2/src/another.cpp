#include "geometry_msgs/Twist.h"
#include "ros/ros.h"
#include "std_srvs/Empty.h"



class SubscribeAndPublish {
private:
  ros::NodeHandle n_;
  ros::ServiceServer ss_;
  ros::Publisher pub_;
  ros::Subscriber sub_;

public:
  SubscribeAndPublish(degrees) {

    pub_ = n_.advertise<geometry_msgs::Twist>("/cmd_vel", 1000);


    sub_ = n_.subscribe("/odom", 1, &SubscribeAndPublish::callback);

    ss_ = n_.advertiseService("rotate_robot", callback);
  }

  void callback(const nav_msgs/Odometry &input) {
    PUBLISHED_MESSAGE_TYPE output;
    //.... do something with the input and generate the output...
    pub_.publish(output);
  }

  void information()

}; // End of class SubscribeAndPublish

int main(int argc, char **argv) {
  // Initiate ROS
  ros::init(argc, argv, "rotate_node");

  // Create an object of class SubscribeAndPublish that will take care of
  // everything
  SubscribeAndPublish Thing("rotate_robot_as");

  ros::spin();

  return 0;
}