// basic_robot.h
#ifndef BASIC_ROBOT_H // include guard
#define BASIC_ROBOT_H

#include "i_robot.h"

class BasicRobot : public IRobot {
public:

    // Commented in base class.
    Coordinates calculate_move_position() const override;

    // Commented in base class.
    void move() override;

    // Commented in base class.
    Coordinates get_current_position() const override;

    // Commented in base class.
    void turn_left() override;

    // Commented in base class.
    void turn_right() override;

    // Commented in base class.
    Direction get_current_direction() const override;

    // Commented in base class.
    bool has_been_placed() const override;

    // Commented in base class.
    void place(const Coordinates &coordinates, const Direction &direction) override;

    BasicRobot() : current_position({-1, -1}), current_direction(Direction::UNKNOWN) {};


private:
    // Robot's current position in x,y coordinate format.
    Coordinates current_position;

    // The current direction that the robot is facing and will move towards.
    Direction current_direction;

    // Specifies whether the robot has been given specific coordinates and direction.
    bool been_placed = false;

};

#endif /* BASIC_ROBOT_H */
