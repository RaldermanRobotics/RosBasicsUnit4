#include <ros/ros.h>
#include <std_msgs/Int32.h>

void counterCallback(const std_msgs::Int32::ConstPtr& msg)
{
  ROS_INFO("%d", msg->data);
}

int main(int argc, char** argv) {

    ros::init(argc, argv, "variable");
    ros::NodeHandle nh;
    
    ros::Subscriber sub = nh.subscribe("count", 1000, counterCallback);
    
    ros::spin();
    
    return 0;
}