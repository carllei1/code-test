#include "gtest/gtest.h"
#include "robot_manager.h"


TEST(RobotManagerTest, PlaceRobotValidOriginCoordinates) {

    auto robotManager = RobotManager();
    EXPECT_TRUE(robotManager.place(0,0,Direction::NORTH));
}

TEST(RobotManagerTest, PlaceRobotValidCoordinates) {

    auto robotManager = RobotManager();
    EXPECT_TRUE(robotManager.place(3,3,Direction::NORTH));
}

TEST(RobotManagerTest, PlaceRobotValidXEdgeCoordinates) {

    auto robotManager = RobotManager();
    EXPECT_TRUE(robotManager.place(4,3,Direction::NORTH));
}

TEST(RobotManagerTest, PlaceRobotValidYEdgeCoordinates) {

    auto robotManager = RobotManager();
    EXPECT_TRUE(robotManager.place(3,4,Direction::NORTH));
}

TEST(RobotManagerTest, PlaceRobotValidXYEdgeCoordinates) {

    auto robotManager = RobotManager();
    EXPECT_TRUE(robotManager.place(4,4,Direction::NORTH));
}

TEST(RobotManagerTest, PlaceRobotInvalidCoordinates) {

    auto robotManager = RobotManager();
    EXPECT_FALSE(robotManager.place(-1,-1,Direction::NORTH));
}

TEST(RobotManagerTest, PlaceRobotOutOfBoundsCoordinates) {

    auto robotManager = RobotManager();
    EXPECT_FALSE(robotManager.place(5,5,Direction::NORTH));
}

TEST(RobotManagerTest, PlaceRobotOutOfBoundsXCoordinate) {

    auto robotManager = RobotManager();
    EXPECT_FALSE(robotManager.place(5,3,Direction::NORTH));
}

TEST(RobotManagerTest, PlaceRobotOutOfBoundsYCoordinate) {

    auto robotManager = RobotManager();
    EXPECT_FALSE(robotManager.place(3,5,Direction::NORTH));
}

TEST(RobotManagerTest, UnplacedRobotMove) {

    auto robotManager = RobotManager();
    EXPECT_FALSE(robotManager.move());
}

TEST(RobotManagerTest, UnplacedRobotTurnLeft) {

    auto robotManager = RobotManager();
    EXPECT_FALSE(robotManager.left());
}

TEST(RobotManagerTest, UnplacedRobotTurnRight) {

    auto robotManager = RobotManager();
    EXPECT_FALSE(robotManager.right());
}

TEST(RobotManagerTest, PlacedRobotMove) {

    auto robotManager = RobotManager();
    robotManager.place(1,1,Direction::NORTH);
    EXPECT_TRUE(robotManager.move());
}

TEST(RobotManagerTest, PlacedRobotTurnLeft) {

    auto robotManager = RobotManager();
    robotManager.place(1,1,Direction::NORTH);

    EXPECT_TRUE(robotManager.left());
}

TEST(RobotManagerTest, PlacedRobotTurnRight) {

    auto robotManager = RobotManager();
    robotManager.place(1,1,Direction::NORTH);

    EXPECT_TRUE(robotManager.right());
}

TEST(RobotManagerTest, PlacedRobotMoveToYEdge) {

    auto robotManager = RobotManager();
    robotManager.place(1,3,Direction::NORTH);
    EXPECT_TRUE(robotManager.move());
}

TEST(RobotManagerTest, PlacedRobotMoveToXEdge) {

    auto robotManager = RobotManager();
    robotManager.place(3,1,Direction::EAST);
    EXPECT_TRUE(robotManager.move());
}

TEST(RobotManagerTest, PlacedRobotMoveToXYEdge) {

    auto robotManager = RobotManager();
    robotManager.place(3,3,Direction::EAST);
    EXPECT_TRUE(robotManager.move());
    EXPECT_TRUE(robotManager.left());
    EXPECT_TRUE(robotManager.move());
}

TEST(RobotManagerTest, PlacedRobotMoveToYZero) {

    auto robotManager = RobotManager();
    robotManager.place(1,1,Direction::SOUTH);
    EXPECT_TRUE(robotManager.move());
}

TEST(RobotManagerTest, PlacedRobotMoveToXZero) {

    auto robotManager = RobotManager();
    robotManager.place(1,1,Direction::WEST);
    EXPECT_TRUE(robotManager.move());
}

TEST(RobotManagerTest, PlacedRobotMoveToXYOrigin) {

    auto robotManager = RobotManager();
    robotManager.place(1,1,Direction::WEST);
    EXPECT_TRUE(robotManager.move());
    EXPECT_TRUE(robotManager.left());
    EXPECT_TRUE(robotManager.move());
}

TEST(RobotManagerTest, PlacedRobotMoveToYNegative) {

    auto robotManager = RobotManager();
    robotManager.place(1,0,Direction::SOUTH);
    EXPECT_FALSE(robotManager.move());
}

TEST(RobotManagerTest, PlacedRobotMoveToXNegative) {

    auto robotManager = RobotManager();
    robotManager.place(0,1,Direction::WEST);
    EXPECT_FALSE(robotManager.move());
}

TEST(RobotManagerTest, PlacedRobotMoveToYOutOfBounds) {

    auto robotManager = RobotManager();
    robotManager.place(1,4,Direction::NORTH);
    EXPECT_FALSE(robotManager.move());
}

TEST(RobotManagerTest, PlacedRobotMoveToXOutOfBounds) {

    auto robotManager = RobotManager();
    robotManager.place(4,1,Direction::EAST);
    EXPECT_FALSE(robotManager.move());
}