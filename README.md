### Skill based system for ROS (SkiROS) - simple UAV library from the RVMI lab, Aalborg University Copenhagen, Denmark

[www.rvmi.aau.dk(RVMI webpage)](http://homes.m-tech.aau.dk/mrp/skiros/)

Last readME update: 21/09/2016  

**Compatibility**: Has been tested with Ubuntu 14.04 and ROS Indigo.

The repository is a collection of plugins for the SkiROS system, for more information refer to the SkiROS package readME.  

This repository provide SkiROS with a minimal collection of plugins to simulate the high-level behavior of an UAV.

### Included (meta)packages 
* **skiros_simple_uav**: ontology extention plus specific launch file and scene  
* **simple_uav_conditions**: holds fly, landed and LowBattery conditions  
* **simple_uav_primitives**: holds monitor_battery primitive  
* **simple_uav_skills**: holds flyAltidude, land, drive_uav, pick_uav and place_uav skills  

### Dependencies
* **skiros**
* **skiros_std_lib**

### Quick start
To launch the system:

* roslaunch skiros_simple_uav skiros_simple_uav.launch




