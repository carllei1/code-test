#include "basic_robot.h"

Coordinates BasicRobot::calculate_move_position() const {
    if (!been_placed) {
        return current_position;
    }

    switch (current_direction) {
        case Direction::NORTH:
            return {current_position.x, current_position.y + 1};
            break;

        case Direction::WEST:
            return {current_position.x - 1, current_position.y};
            break;

        case Direction::SOUTH:
            return {current_position.x, current_position.y - 1};
            break;

        case Direction::EAST:
            return {current_position.x + 1, current_position.y};
            break;

        default:
            return current_position;
    }
}

void BasicRobot::move() {
    if (been_placed) {
        current_position = calculate_move_position();
    }
}

Coordinates BasicRobot::get_current_position() const {
    return current_position;
}

void BasicRobot::turn_left() {
    if (!been_placed) {
        return;
    }

    switch (current_direction) {
        case Direction::NORTH:
            current_direction = Direction::WEST;
            break;

        case Direction::WEST:
            current_direction = Direction::SOUTH;
            break;

        case Direction::SOUTH:
            current_direction = Direction::EAST;
            break;

        case Direction::EAST:
            current_direction = Direction::NORTH;
            break;

        default:
    }
}

void BasicRobot::turn_right() {
    if (!been_placed) {
        return;
    }

    switch (current_direction) {
        case Direction::NORTH:
            current_direction = Direction::EAST;
            break;

        case Direction::EAST:
            current_direction = Direction::SOUTH;
            break;

        case Direction::SOUTH:
            current_direction = Direction::WEST;
            break;

        case Direction::WEST:
            current_direction = Direction::NORTH;
            break;

        default:
    }
}

Direction BasicRobot::get_current_direction() const {
    return current_direction;
}

bool BasicRobot::has_been_placed() const {
    return been_placed;
}

void BasicRobot::place(const Coordinates &coordinates, const Direction &direction) {
    current_position = coordinates;
    current_direction = direction;
    been_placed = true;
}
