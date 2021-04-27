# VidRecv

VidRecv is a video receiver for receiving video from a camera sensor in Gazebo
to provide first person view (FPV) in the [Betaloop](https://github.com/Aeroloop/betaloop) flight simulator.

Essentially this has just been pulled from the Topic Viewer in Gazebo so it can
be run without the overhead of the entire Gazebo GUI.

# Build

1. Create directory `build`
2. `cd build`
3. cmake ..
4. `make` which will produce VidRecv


You must have a model that has a camera so the Camera Image can be subscribed to
ie /gazebo/default/iris_demo/iris_demo/gimbal_2d/tilt_link/camera/image
