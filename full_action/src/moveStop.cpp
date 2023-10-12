#include <actionlib/client/simple_action_client.h>
#include <ardrone_as/ArdroneAction.h> // Note: "Action" is appended
#include <geometry_msgs/Twist.h>
#include <ros/ros.h>

int nImage = 0;

void doneCb(const actionlib::SimpleClientGoalState &state,
            const ardrone_as::ArdroneResultConstPtr &result) {
  ROS_INFO("[State Result]: %s", state.toString().c_str());
  ROS_INFO("The Action has been completed");
  ros::shutdown();
}

// Called once when the goal becomes active
void activeCb() { ROS_INFO("Goal just went active"); }

void feedbackCb(const ardrone_as::ArdroneFeedbackConstPtr &feedback) {
  ROS_INFO("[Feedback] image n.%d received", nImage);
  ++nImage;
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "move");
  ros::NodeHandle n;
  actionlib::SimpleActionClient<ardrone_as::ArdroneAction> client(
      "ardrone_action_server", true);
  client.waitForServer();

  ardrone_as::ArdroneGoal goal;
  goal.nseconds = 10;
  client.sendGoal(goal, &doneCb, &activeCb, &feedbackCb);
  // client.waitForResult();

  ros::Rate loop_rate(2);
  actionlib::SimpleClientGoalState state_result = client.getState();
  ROS_INFO("[State Result]: %s", state_result.toString().c_str());

  ros::Publisher effector = n.advertise<geometry_msgs::Twist>("cmd_vel", 1000);

  geometry_msgs::Twist thingout;
  thingout.linear.x = 0.5;
  thingout.angular.z = 0.5;

  geometry_msgs::Twist nomove;
  nomove.linear.x = 0;
  nomove.angular.z = 0;

  while (state_result == actionlib::SimpleClientGoalState::ACTIVE ||
         state_result == actionlib::SimpleClientGoalState::PENDING) {
    ROS_INFO("hopefully moving");
    effector.publish(thingout);
    ros::spinOnce();
    loop_rate.sleep();
    state_result = client.getState();
    ROS_INFO("[State Result]: %s", state_result.toString().c_str());
  }

  if (state_result == actionlib::SimpleClientGoalState::SUCCEEDED) {
    ROS_INFO("Success and we're stopping");
    effector.publish(nomove);
    ros::spinOnce();
    loop_rate.sleep();
    state_result = client.getState();
    ROS_INFO("[State Result]: %s", state_result.toString().c_str());
  }
  return 0;
}
