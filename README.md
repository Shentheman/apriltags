# apriltags
* ROS wrapper for the Swatbotics C++ port of the AprilTag visual
fiducial detector.  
* The Swatbotics port uses OpenCV and CGAL for improved performance.  
http://github.com/swatbotics/apriltags-cpp
* The AprilTag system was originally developed by the April laboratory at the University of Michigan.
http://april.eecs.umich.edu/wiki/index.php/AprilTags  
  * E. Olson, *"AprilTag: A robust and flexible visual fiducial system"*, IEEE International Conference on Robotics and Automation (ICRA), 2011.


## Installation
* Install dependencies: `$ sudo aptitude install libcgal-dev`
* Clone **both** this repo - [apriltags](https://github.com/Shentheman/apriltags/tree/irg-raw3-6) and [apriltag-cpp](https://github.com/Shentheman/apriltags-cpp/tree/irg-raw3-6) into your catkin workspace and `catkin build`

## Print some AprilTags
* Images of the default tag family can be found in `./tags/36h11.ps`
  * To open this postscript file:  
    ```
    $ sudo apt-get install gv
    $ gv 36h11.ps
    ```
  * **Note** that you cannot just open that `.ps` file using Preview or Skim on Mac since the resolution would be very low. Please use **Adobe Acrobat** on any platform or **gv** on Linux to open and print it.
* Alternatively you can download images of the tags from [here](https://april.eecs.umich.edu/wiki/index.php/AprilTags)
  * There are `.tgz` files for each family, including a `.ps` file with one tag per page.

## Configuration
* Edit the launch file `apriltags.launch`
  * Set the default tag file parameter to be the width of the black square of the tags you printed out, e.g. 46mm
    ```
    $ param name="~default_tag_size" value="0.046"
    ```
    * The software will compute the Z by comparing the original `default_tag_size` and the actual tag size in the view of the camera.
    * Note that the tag has a white margin on the outside. Note that this `default_tag_size` is the length of a side of the black square, **inside but not including** the white margin.
  * If your webcam does not publish images to the default topic name, you may need to edit these 2 parameters:
    ```
    $ remap from="~image" to="/camera/rgb/image_rect"
    $ remap from="~camera_info" to="/camera/rgb/camera_info"
    ```
  * For the Kinect2, they should be set too:  
    ```
    $ remap from="~image" to="/kinect2/hd/image_color_rect"  
    $ remap from="~camera_info" to="/kinect2/hd/camera_info"  
    ```

## Usage
* `$ roslaunch apriltags apriltags.launch`
* To check if the node can detect your printed tag: `$ rostopic echo /apriltags/detections`

