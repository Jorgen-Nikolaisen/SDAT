#include <gtest/gtest.h>
#include "../Sensor.cpp"
#include "../Missile_Controls.cpp"


class TargetCoordinatesTest : public ::testing::Test{
protected:
    Target_Coordinates target;

    TargetCoordinatesTest() : target(0.0, 0.0) {}

    void SetUp() override{}

    void TearDown() override{}
};

TEST_F(TargetCoordinatesTest, GetLatLong) {
    EXPECT_DOUBLE_EQ(0.0, target.getLat());
    EXPECT_DOUBLE_EQ(0.0, target.getLong());
}

TEST_F(TargetCoordinatesTest, GetCurrentDistance){
    Target_Coordinates anotherTarget(1.0, 1.0);
    double expected_distance = 156.9;
    EXPECT_NEAR(expected_distance, target.getCurrentDistance(1.0, 1.0), expected_distance / 100 * 1);
}

// Testing the Motion class
class MotionTest : public ::testing::Test {
protected:
    MissileControls controls;
    Target_Coordinates position;
    Motion motion;

    MotionTest() : controls(1.0, 1.0),
                   position(0.0, 0.0),
                   motion(controls, position) {}

    void SetUp() override {
        // Set up necessary state for tests
    }

    void TearDown() override {
        // Clean up after tests
    }
};

TEST_F(MotionTest, SetVelocity) {
    // Test if the setVelocity correctly updates the velocity
    motion.setVelocity(100.0);

    EXPECT_DOUBLE_EQ(100.0, motion.getVelocity());
}

/*
TEST_F(MotionTest, SetBearing) {
    // Test if the setBearing correctly computes and sets the bearing
    double lat1 = 0.0, lon1 = 0.0;
    double lat2 = 1.0, lon2 = 1.0;
    double expected_bearing = ...; // Calculate the expected bearing based on known values
    EXPECT_NEAR(expected_bearing, motion.setBearing(lat1, lon1, lat2, lon2), 0.001);
}
*/
