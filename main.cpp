//
//  main.cpp
//  robot-simulator
//
//

#include "robot_manager.h"

int main(int argc, char *argv[]) {
    std::cout << "Welcome to robot simulator!!" << std::endl;
    
    if(argc != 2) {
        std::cout << "Invalid number of arguments." << std::endl;
        return 0;
    }
    
    auto robot_manager = RobotManager();
    robot_manager.run(argv[1]);
    return 0;
    }
