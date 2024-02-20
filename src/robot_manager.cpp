#include "robot_manager.h"

void RobotManager::run(const std::string &file_path) {
    auto file_reader = FileReader();
    const auto instructions = file_reader.read_file(file_path);

    if (instructions.empty()) {
        std::cout << "Unable to read instructions from file path: " << file_path << std::endl;
        return;
    }

    for (const auto &instruction: instructions) {
        if (instruction == "MOVE") {
            move();
        } else if (instruction == "LEFT") {
            left();
        } else if (instruction == "RIGHT") {
            right();
        } else if (instruction == "REPORT") {
            report();
        } else if (instruction.starts_with("PLACE")) {

            std::stringstream ss(instruction);
            std::string specifier;
            std::vector<std::string> specifiers;
            while (ss >> specifier) {
                specifiers.push_back(specifier);
            }

            try {
                const int x = std::stoi(specifiers.at(1));
                const int y = std::stoi(specifiers.at(2));
                const auto direction = string_to_direction(specifiers.at(3));
                if(direction == Direction::UNKNOWN) {
                    throw std::runtime_error("Unable to determine the direction: " + specifiers.at(3));
                } else {
                    place(x, y, direction);
                }
            } catch (const std::exception &ex) {
                std::cout << "Invalid PLACE instruction: " << ex.what() << std::endl;
            }
        } else {
            std::cout << "Invalid Instruction." << std::endl;
        }

    }
}

void RobotManager::report() {
    if (!robot->has_been_placed()) {
        std::cout << "The robot has not been placed." << std::endl;
        return;
    }

    const auto coordinates = robot->get_current_position();
    const auto direction = robot->get_current_direction();

    std::cout << "The robot is currently at coordinates: " << coordinates.x
              << ", " << coordinates.y << " facing " << direction_to_string(direction) << std::endl;

}

bool RobotManager::left() {
    if (!robot->has_been_placed()) {
        std::cout << "Robot can't turn since the robot has not been placed." << std::endl;
        return false;
    } else {
        robot->turn_left();
        return true;
    }

}

bool RobotManager::right() {
    if (!robot->has_been_placed()) {
        std::cout << "Robot can't turn since the robot has not been placed." << std::endl;
        return false;
    } else {
        robot->turn_right();
        return true;
    }
}

bool RobotManager::place(int x, int y, const Direction &facing) {
    if (!map->is_valid_move({x, y})) {
        std::cout << "Robot can't be placed since it would be out of bounds." << std::endl;
        return false;
    } else {
        robot->place({x, y}, facing);
        return true;
    }
}


bool RobotManager::move() {

    if (!robot->has_been_placed()) {
        std::cout << "Robot can't be moved since the robot has not been placed." << std::endl;

        return false;
    }

    const auto attempted_move = robot->calculate_move_position();

    if (map->is_valid_move(attempted_move)) {
        robot->move();
        return true;
    } else {
        std::cout << "Robot can't be moved since it would be out of bounds." << std::endl;
        return false;
    }

}
