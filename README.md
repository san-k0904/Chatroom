**TASK DESCRIPTION**

used ROS to create a chatroom where messages for each user get updated real time.


**APPROACH**

Created a ROS package called Chatroom_pkg inside ROS_tasks/Chatroom catkin workspace which contains: 

    • one node ,chat_node,which acts as both Subscriber and Publisher.
    • A custom message Chat.msg which contains two strings fields username and message
    • I made use of thread library to ensure that message publishing and message callbacks both use different threads ensuring that there is real-time update for all the users and the message get’s displayed on their screen as soon as it is published on the topic.
    • Both the subscriber and the publisher for all users are connected to the topic /whatsapp .
    • In the launch file chatroom.launch I added 3 users of the node type chat_node such that on running roslaunch 3 instances of chat_node gets started in 3 different terminals by using genome-terminal –command under the launch-prefix tag.
    • To ensure that all 3 nodes have different names and their is no conflict I changed their namespace.
    • Once roslaunch is executed 3 different terminals get opened up where each first asks the users to enter their username and then waits for them to type their message. If a user publishes a message on the /whatsapp topic the message is immediately displayed on the screen of all the active users. 


**rqt_graph:**

<img width="892" alt="user3chat_node" src="https://github.com/MRM-AIA-TP-2025/MRM_SankalpKatyayanan/assets/149009136/16b8e4df-d327-4051-a26c-bd68246eb8e6">

**YOUTUBE link:**

https://youtu.be/zze8_rGOztk
