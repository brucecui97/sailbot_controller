#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sailbot/SailRudderRad.h>
#include <sstream>
ros::Publisher sailRudderPub;

//replace message type with alex's custom message
void chatterCallback(const sailbot::SailRudderRad::ConstPtr  & msg)
{
  std::string a = "avbdsadsa";
  ROS_INFO("sail angle heard %s\n", std::to_string(msg->sail_angle).c_str());
  ROS_INFO("rudder angle heard %s\n", std::to_string(msg->rudder_angle).c_str());
    
    sailbot::SailRudderRad msg1;
    msg1.sail_angle = 2 + msg->sail_angle;
    msg1.rudder_angle = 5+ msg->rudder_angle;

    ROS_INFO("some stuff");
    sailRudderPub.publish(msg1);
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "listener");

  ros::NodeHandle n;

  sailRudderPub = n.advertise<sailbot::SailRudderRad>("sail_rudder_angle", 1000);

//replace topic name with alex's sensor topic
  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);

  ros::spin();

  return 0;
}