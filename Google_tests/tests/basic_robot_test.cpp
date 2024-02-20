#include "gtest/gtest.h"
#include "robot_manager.h"


TEST(RobotTest, UnplacedRobot) {
    const auto robot = BasicRobot();
    EXPECT_FALSE( robot.has_been_placed());
}

TEST(RobotTest, UnplacedRobotGetDirection) {
    const auto robot = BasicRobot();
    EXPECT_EQ( robot.get_current_direction(), Direction::UNKNOWN);
}

TEST(RobotTest, UnplacedRobotGetCoordinates) {
    const auto robot = BasicRobot();
    Coordinates unplaced = {-1,-1};
    EXPECT_EQ(robot.get_current_position(), unplaced);
}

TEST(RobotTest, UnplacedRobotCalculateCoordinates) {
    const auto robot = BasicRobot();
    Coordinates unplaced = {-1,-1};
    EXPECT_EQ(robot.calculate_move_position(), unplaced);
}

TEST(RobotTest, UnplacedRobotMove) {
    auto robot = BasicRobot();
    Coordinates unplaced = {-1,-1};
    robot.move();
    EXPECT_EQ(robot.get_current_position(), unplaced);
}

TEST(RobotTest, UnplacedRobotTurnLeft) {
    auto robot = BasicRobot();
    robot.turn_left();
    EXPECT_EQ( robot.get_current_direction(), Direction::UNKNOWN);
}

TEST(RobotTest, UnplacedRobotTurnRight) {
    auto robot = BasicRobot();
    robot.turn_right();
    EXPECT_EQ( robot.get_current_direction(), Direction::UNKNOWN);
}

TEST(RobotTest, PlaceRobot) {
    auto robot = BasicRobot();
    const Coordinates placed = {0,0};
    robot.place(placed, Direction::NORTH);

    EXPECT_TRUE(robot.has_been_placed());
    EXPECT_EQ( robot.get_current_direction(), Direction::NORTH);
    EXPECT_EQ(robot.get_current_position(), placed);

}

TEST(RobotTest, PlacedRobotMove) {
    auto robot = BasicRobot();
    const Coordinates placed = {0,0};
    const Coordinates expected_position = {0,1};
    robot.place(placed, Direction::NORTH);
    robot.move();

    EXPECT_EQ(robot.get_current_position(), expected_position);
    EXPECT_EQ( robot.get_current_direction(), Direction::NORTH);
}

TEST(RobotTest, PlacedRobotTurnLeft) {
    auto robot = BasicRobot();
    const Coordinates placed = {0,0};
    const Coordinates expected_position = {0,0};
    robot.place(placed, Direction::NORTH);
    robot.turn_left();

    EXPECT_EQ(robot.get_current_position(), expected_position);
    EXPECT_EQ( robot.get_current_direction(), Direction::WEST);

}

TEST(RobotTest, PlacedRobotDoubleTurnLeft) {
    auto robot = BasicRobot();
    const Coordinates placed = {0,0};
    const Coordinates expected_position = {0,0};
    robot.place(placed, Direction::NORTH);
    robot.turn_left();
    robot.turn_left();


    EXPECT_EQ(robot.get_current_position(), expected_position);
    EXPECT_EQ( robot.get_current_direction(), Direction::SOUTH);

}

TEST(RobotTest, PlacedRobotTurnRight) {
    auto robot = BasicRobot();
    const Coordinates placed = {0,0};
    const Coordinates expected_position = {0,0};
    robot.place(placed, Direction::NORTH);
    robot.turn_right();

    EXPECT_EQ(robot.get_current_position(), expected_position);
    EXPECT_EQ( robot.get_current_direction(), Direction::EAST);

}

TEST(RobotTest, PlacedRobotDoubleTurnRight) {
    auto robot = BasicRobot();
    const Coordinates placed = {0,0};
    const Coordinates expected_position = {0,0};
    robot.place(placed, Direction::NORTH);
    robot.turn_right();
    robot.turn_right();


    EXPECT_EQ(robot.get_current_position(), expected_position);
    EXPECT_EQ( robot.get_current_direction(), Direction::SOUTH);

}

TEST(RobotTest, PlacedRobotCalculateCoordinatesNorth) {
    auto robot = BasicRobot();
    Coordinates placed = {1,1};
    Coordinates calculated_move = {1,2};
    robot.place(placed, Direction::NORTH);

    EXPECT_EQ(robot.calculate_move_position(), calculated_move);
    EXPECT_EQ(robot.get_current_direction(), Direction::NORTH);
    EXPECT_EQ(robot.get_current_position(), placed);
}

TEST(RobotTest, PlacedRobotCalculateCoordinatesSouth) {
    auto robot = BasicRobot();
    Coordinates placed = {1,1};
    Coordinates calculated_move = {1,0};
    robot.place(placed, Direction::SOUTH);

    EXPECT_EQ(robot.calculate_move_position(), calculated_move);
    EXPECT_EQ(robot.get_current_direction(), Direction::SOUTH);
    EXPECT_EQ(robot.get_current_position(), placed);
}

TEST(RobotTest, PlacedRobotCalculateCoordinatesEast) {
    auto robot = BasicRobot();
    Coordinates placed = {1,1};
    Coordinates calculated_move = {2,1};
    robot.place(placed, Direction::EAST);

    EXPECT_EQ(robot.calculate_move_position(), calculated_move);
    EXPECT_EQ(robot.get_current_direction(), Direction::EAST);
    EXPECT_EQ(robot.get_current_position(), placed);
}

TEST(RobotTest, PlacedRobotCalculateCoordinatesWest) {
    auto robot = BasicRobot();
    Coordinates placed = {1,1};
    Coordinates calculated_move = {0,1};
    robot.place(placed, Direction::WEST);

    EXPECT_EQ(robot.calculate_move_position(), calculated_move);
    EXPECT_EQ(robot.get_current_direction(), Direction::WEST);
    EXPECT_EQ(robot.get_current_position(), placed);
}

TEST(RobotTest, PlacedRobotCalculateCoordinatesUnknown) {
    auto robot = BasicRobot();
    Coordinates placed = {1,1};
    robot.place(placed, Direction::UNKNOWN);

    EXPECT_EQ(robot.calculate_move_position(), placed);
    EXPECT_EQ(robot.get_current_direction(), Direction::UNKNOWN);
    EXPECT_EQ(robot.get_current_position(), placed);
}