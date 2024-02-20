
#include "gtest/gtest.h"
#include "robot_manager.h"


TEST(MapTest, NegativeXY) {

    const auto map = BasicMap();
    EXPECT_FALSE( map.is_valid_move({-1,-1}));
}

TEST(MapTest, NegativeX) {

    const auto map = BasicMap();
    EXPECT_FALSE( map.is_valid_move({-1,1}));
}

TEST(MapTest, NegativeY) {

    const auto map = BasicMap();
    EXPECT_FALSE( map.is_valid_move({1,-1}));
}

TEST(MapTest, PositiveXY) {

    const auto map = BasicMap();
    EXPECT_TRUE( map.is_valid_move({1,1}));
}

TEST(MapTest, PositiveXZeroY) {

    const auto map = BasicMap();
    EXPECT_TRUE( map.is_valid_move({1,0}));
}

TEST(MapTest, ZeroXPositiveY) {
    const auto map = BasicMap();
    EXPECT_TRUE( map.is_valid_move({0,1}));
}

TEST(MapTest, ZeroXY) {
    const auto map = BasicMap();
    EXPECT_TRUE( map.is_valid_move({0,0}));
}

TEST(MapTest, OutOfBoundsXPositiveY) {
    const auto map = BasicMap();
    EXPECT_FALSE( map.is_valid_move({5,1}));
}

TEST(MapTest, PositiveXOutOfBoundsY) {
    const auto map = BasicMap();
    EXPECT_FALSE( map.is_valid_move({1,5}));
}

TEST(MapTest, OutOfBoundsXY) {
    const auto map = BasicMap();
    EXPECT_FALSE( map.is_valid_move({5,5}));
}

TEST(MapTest, MinimumXY) {
    const auto map = BasicMap();
    EXPECT_FALSE( map.is_valid_move({INT_MIN,INT_MIN}));
}

TEST(MapTest, MaximumXY) {
    const auto map = BasicMap();
    EXPECT_FALSE( map.is_valid_move({INT_MAX,INT_MAX}));
}

TEST(MapTest, ZeroMapXY) {
    const auto map = BasicMap(0,0);
    EXPECT_TRUE( map.is_valid_move({0,0}));
}