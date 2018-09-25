#include <gtest/gtest.h>
#include "pid.h"

/**
 * Test class initialization
 */
TEST(PIDTest, classInitialization) {
  PID dummyPID;
  dummyPID.setParameters(15.0, 50.5, 2.0);

  EXPECT_EQ(15.0, dummyPID.getKp());
  EXPECT_EQ(50.5, dummyPID.getKi());
  EXPECT_EQ(2.0, dummyPID.getKd());
}
/**
 * Test compute method
 */
TEST(PIDTest, computeControlInput) {

  PID dummyPID(20.2, 30.3, 1.1);

  double setPoint = 5.0;
  double currentVelocity = 2.5;

  EXPECT_NEAR(401.25, dummyPID.compute(setPoint, currentVelocity), 10.0);
}
