#include "ros/ros.h"
#include "std_msgs/Int32MultiArray.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "int_vector_publisher");
  ros::NodeHandle nh;
  ros::Publisher pub = nh.advertise<std_msgs::Int32MultiArray>("int_vector", 10);

  ros::Rate rate(10);

  while (ros::ok())
  {
	std_msgs::Int32MultiArray msg;
	msg.data.push_back(1);
	msg.data.push_back(2);
	msg.data.push_back(3);

	pub.publish(msg);

	ros::spinOnce();

	rate.sleep();
  }

  return 0;
}

