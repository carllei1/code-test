// robot_manager.h
#ifndef ROBOT_MANAGER_H // include guard
#define ROBOT_MANAGER_H

#include "basic_map.h"
#include "basic_robot.h"
#include "file_reader.h"
#include <memory>
#include <iostream>
#include <algorithm>
#include <sstream>

class RobotManager {
public:
    RobotManager() : map(std::make_unique<BasicMap>()), robot(std::make_unique<BasicRobot>()) {};

    // Starts the robot simulation be reading instructions from file and performing them.
    void run(const std::string &file_path);

    // Moves the robot in the direction it is facing.
    bool move();

    // Turns the robot left.
    bool left();

    // Turns the robot right.
    bool right();

    // Places the robot at the provided coordinates and facing in the provided direction.
    bool place(int x, int y, const Direction &facing);

    // Reports the robot's current position and direction.
    void report();


private:

    // The map that the robot will be traversing on.
    std::unique_ptr<IMap> map;

    // The robot being given instructions to.
    std::unique_ptr<IRobot> robot;

};

#endif /* ROBOT_MANAGER_H */
