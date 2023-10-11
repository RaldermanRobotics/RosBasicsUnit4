#include <actionlig/client/simple_action_client.h>
#include <ardrone_as/ArdroneAction.h>

int thingImage = 0;

void doneCb(const actionlib::SimpleClientGoalState &state,
            const ardrone_as::ArdroneResultConstPrt &result) {
  ROS_INFO("The thing is complet");
  ros::shutdown();
}

void activeBb() { ROS_INFOR("Goat went") }

void feedbackCb(const ardrone_as::ArdroneFeedbackConstPtr &feedback) {
  ROS_INFO("[Feedback] thing n.%d received", thingImage);
  thingImage = thingImage + 1;
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "waiting for result");
  actionlib::SimpleActionClient<ardrone_as::ArdronAction> client(
      "ardrone_action_ser", true);
  client.waitForServer();

  ardrone_as::ArdroneGoal goal;
  goal.nseconds = 10;

  client.sendGoal(goal, &doneCb, &activeCb, &feddbackCb);
}