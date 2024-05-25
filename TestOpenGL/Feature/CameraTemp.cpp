//
// Created by Administrator on 2024/5/25.
//

#include "CameraTemp.h"

float  CameraTemp::deltaTime = 1.0f;

glm::vec3  CameraTemp::cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3  CameraTemp::cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
glm::vec3  CameraTemp::cameraPos = glm::vec3(0.0f, 0.0f, 10.0f);

bool  CameraTemp::firstMouse = true;
float  CameraTemp::yaw = -90.0f;    // yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
float  CameraTemp::pitch = 0.0f;
float  CameraTemp::lastX = 800.0f / 2.0;
float  CameraTemp::lastY = 600.0 / 2.0;
float  CameraTemp::fov = 45.0f;
