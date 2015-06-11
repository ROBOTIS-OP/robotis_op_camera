#include <robotis_op_camera/robotis_op_camera.h>
#include <string.h>

int main(int argc, char** argv)
{
    ROS_INFO("Starting robotis_op_camera_node...");
    ros::init(argc, argv, "image_publisher");
    ros::NodeHandle nh;

    int rate;
    std::string topic;
    nh.param("rate", rate, int(20));
    nh.param("topic", topic,  std::string("/robotis_op/image"));

    ros::Rate loop_rate(rate);

    robotis_op::RobotisOPCameraNode camera_node(nh);
    image_transport::ImageTransport it(nh);
    image_transport::CameraPublisher pub = it.advertiseCamera(topic.c_str(), 1);

    dynamic_reconfigure::Server<robotis_op_camera::robotis_op_cameraConfig> srv;
    dynamic_reconfigure::Server<robotis_op_camera::robotis_op_cameraConfig>::CallbackType cb;
    cb = boost::bind(&robotis_op::RobotisOPCameraNode::dynamicReconfigureCb,&camera_node, _1, _2);
    srv.setCallback(cb);
    ROS_INFO("Robotis_op_camera_node successfully started");

    while (nh.ok()) {
        camera_node.publishImage(&pub);
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}

