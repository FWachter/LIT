/*
PROGRAMMER: Frederick Wachter
DATE CREATED: 2016-05-23
LAST MODIFIED: 2016-05-23
PURPOSE: Test receiving a ROS message on Arduino
REFERENCE: http://wiki.ros.org/rosserial_arduino/Tutorials/Blink
*/

/*----- INCLUDED LIBRARIES -----*/
#include <ros.h> // ROS libarary
#include <std_msgs/Empty.h> // Empty message library

/*----- INITIATE ROS PARAMETERS AND CALLBACKS -----*/
ros::NodeHandle nh; // ROS node handler

void messageCallback(const std_msgs::Empty& toggle_msg) {
  digitalWrite(13,HIGH-digitalRead(13); // blink LED
}

ros::Subscriber<std_msgs::Empty> toggle_LED("toggle_led",$messageCallback); // setup subscriber

void setup() {
  Serial.begin(9600);

  /*----- SETUP ROS -----*/
  nh.initNode(); // initilaize the Arduino ROS node
  nh.subscribe(toggle_LED); // subscribe to the toggle_led topic
}

void loop() {
  nh.spinOnce(); // allow time for checking if message received
  delay(1); // throttle message checking
}


