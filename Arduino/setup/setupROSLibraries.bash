#!/bin/bash
# PROGRAMMER: Frederick Wachter
# DATE CREATED: 2016-05-24
# PURPOSE: Setup workspace for Arudino to work with ROS
# REFERENCE: http://wiki.ros.org/rosserial_arduino/Tutorials/Arduino%20IDE%20Setup


# Notify user that this file has not been finished yet
echo "This file has not been finished... Exiting."
exit


#=========================================
#---------- PRE-SETUP CHECKING -----------
#=========================================
# Ask the user if they are sure they would like to continue the setup
# REFERENCE: http://stackoverflow.com/questions/1885525/how-do-i-prompt-a-user-for-confirmation-in-bash-script
read -p "Are you sure you would like to continue with the setup (y/n)? " response
case "$response" in 
  y|Y ) echo "Continuing setup... ";;
  n|N ) echo "Exiting setup... " && echo "Exited setup." && exit;;
  * ) echo "invalid response. Please use 'y' for Yes and 'n' for No" && exit;;
esac

echo "Started building workspace... " # notify the user the setup has started

#----------------------------------------
#-- Need to start in correct directory --
#------- Note Created: 2016-05-24 -------
#----------------------------------------

#======================================
#---------- VERIFY INSTALLS -----------
#======================================
echo "[Part 1/2] Verifying installs... " # notify the user that installs will potentially be made

sudo apt-get update # update potential install list

#------------------------------------------
#-- Need to ask user is ROS is installed --
#-------- Note Created: 2016-05-24 --------
#------------------------------------------

# Install ROS Serial Capabilities
sudo apt-get install ros-indigo-rosserial-arduino -y
sudo apt-get install ros-indigo-rosserial -y

#======================================
#---------- SETUP WORKSPACE -----------
#======================================
echo "[Part 2/2] Setting up workspace... " # notify user the setup has started

# Make Directories
mkdir Arduino # create Arduino directory
mkdir Arduino/sketchbook # create directory for Arduino sketches
mkdir Arduino/sketchbook/libraries # create directory for Arduino libraries
mkdir Arduino/arduino_ws # create directory for the Arduino ROS workspace
mkdir Arduino/arduino_ws/src # crease src folder for the Arudino ROS workspace

# Add Repositories
cd Arduino/arduino_ws # go to Arduino workspace
git clone https://github.com/ros-drivers/rosserial.git src/rosserial # clone ROS-Arduino repo into Arduino workspace

# Build ROS Serial Files into Workspace
catkin_make
catkin_make install
source install/setup.bash

#----------------------------------
#-- Do I need to start ROS core? --
#---- Note Created: 2016-05-24 ----
#----------------------------------

# Add ROS Serial Library to Arduino Library
cd ../sketchbook/libraries # switch to libraries folder of Arduino
rm -rf ros_lib # remove ros_lib if it exists
rosrun rosserial_arduino make_libraries.py . # create ros_lib and related files

echo "Finished building workspace." # notify the user the setup has finished

#======================================
#---------- USER DIRECTIONS -----------
#======================================
# Directions for the user on what to do next
echo ""
echo "You will need to restart Arduino (if open) for the changes to take effect."
echo "Change the sketchbook directory of Arduino to <path>/Arduino/sketchbook"
echo "  NOTE: <path> is the location of the Arduino folder that was created"
echo "        To change the sketchbook directory, click File > Preferences"
echo ""


