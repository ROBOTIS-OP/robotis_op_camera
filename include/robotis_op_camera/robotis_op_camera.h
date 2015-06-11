#ifndef ROBOTIS_OP_CAMERA_NODE_H_
#define ROBOTIS_OP_CAMERA_NODE_H_


// Roobotis framework
#include <LinuxDARwIn.h>

//ROS
#include <ros/ros.h>
#include <sensor_msgs/Image.h>
#include <image_transport/image_transport.h>
#include <dynamic_reconfigure/server.h>
#include <robotis_op_camera/robotis_op_cameraConfig.h>
#include <camera_info_manager/camera_info_manager.h>

namespace robotis_op
{
class RobotisOPCameraNode
{
public:

    RobotisOPCameraNode(ros::NodeHandle &nh);
    ~RobotisOPCameraNode(void);
    void publishImage(image_transport::CameraPublisher *pub);
    void dynamicReconfigureCb(robotis_op_camera::robotis_op_cameraConfig &config, uint32_t level);

protected:
    sensor_msgs::Image image_msg_;
    camera_info_manager::CameraInfoManager camera_manager_;
};
}

#endif

