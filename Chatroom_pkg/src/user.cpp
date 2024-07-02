#include "ros/ros.h"
#include "Chatroom_pkg/Chat.h"
#include <iostream>
#include <thread>

using namespace std;

void chatterCallback(const Chatroom_pkg::Chat::ConstPtr& msg){
    ROS_INFO("%s:%s", msg->username.c_str(), msg->message.c_str());
}

void publishMessages(ros::Publisher& publisher, const string& user) {
    string message;
    while (ros::ok()) {
        getline(cin, message);

        Chatroom_pkg::Chat msg;
        msg.username = user;
        msg.message = message;
        publisher.publish(msg);
    }
}

int main(int argc, char **argv){
    ros::init(argc, argv, "chat_node");
    ros::NodeHandle nh;

    string user;
    cout << "Enter Username: ";
    getline(cin, user);

    ros::Publisher publisher = nh.advertise<Chatroom_pkg::Chat>("/whatsapp", 1000);
    ros::Subscriber subscriber = nh.subscribe<Chatroom_pkg::Chat>("/whatsapp", 1000, chatterCallback);

    thread publishingThread(publishMessages, ref(publisher), user);

    ros::spin();

    publishingThread.join();

    return 0;
}
