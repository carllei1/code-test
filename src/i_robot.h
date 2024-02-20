// i_robot.h
#ifndef I_ROBOT_H // include guard
#define I_ROBOT_H

#include <string>
#include "coordinates.h"

enum class Direction {
    NORTH,
    EAST,
    SOUTH,
    WEST,
    UNKNOWN
};

// Helper function that converts a Direction to a string.
static std::string direction_to_string(const Direction &direction) {
    switch (direction) {
        case Direction::NORTH:
            return "North";
            break;
        case Direction::EAST:
            return "East";
            break;
        case Direction::SOUTH:
            return "South";
            break;
        case Direction::WEST:
            return "West";
            break;
        default:
            return "Invalid direction";
            break;
    }
}

// Helper function that converts a string to a Direction.
static Direction string_to_direction(const std::string &direction) {
    if (direction == "NORTH") {
        return Direction::NORTH;
    } else if (direction == "EAST") {
        return Direction::EAST;
    } else if (direction == "SOUTH") {
        return Direction::SOUTH;
    } else if (direction == "WEST") {
        return Direction::WEST;
    } else {
        return Direction::UNKNOWN;
    }
}


class IRobot {
public:

    // Calculates the robot's new coordinates if it were to move.
    // NOTE: This does not move the robot.
    virtual Coordinates calculate_move_position() const = 0;

    // Moves the robot based on direction and
    virtual void move() = 0;

    // Gets the robot's current position.
    virtual Coordinates get_current_position() const = 0;

    // Turns the direction of the robot to the left.
    virtual void turn_left() = 0;

    // Turns the direction of the robot to the right.
    virtual void turn_right() = 0;

    // Gets the current directions that the robot is facing.
    virtual Direction get_current_direction() const = 0;

    // Checks if the robot has been placed on the map.
    virtual bool has_been_placed() const = 0;

    // Place the robot on the given coordinates facing in the given direction.
    virtual void place(const Coordinates &coordinates, const Direction &direction) = 0;

    virtual ~IRobot() = default;

};

#endif /* I_ROBOT_H */
