#include "Camera.h"
#include "esp_camera.h"

void Camera::init() {
    // ESP32-CAM config here
}

void Camera::capture() {
    camera_fb_t *fb = esp_camera_fb_get();
    if (!fb) return;

    // send/store frame
    esp_camera_fb_return(fb);
}