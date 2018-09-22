#include <gtest/gtest.h>
#include "pid.h"

/**
 * Test class initialization
 */
TEST(PIDTest, classInitialization) {
  PID dummyPID;
  dummyPID.setParameters(1.5, 10.2, 25.2);

  EXPECT_EQ(1.5, dummyPID.getKp());
  EXPECT_EQ(10.2, dummyPID.getKi());
  EXPECT_EQ(25.2, dummyPID.getKd());
}
/**
 * Test compute method
 */
TEST(PIDTest, computeControlInput) {

  PID dummyPID(1.5, 10.2, 25.2);

  double setPoint = 5.0;
  double currentVelocity = 2.0;

  EXPECT_NEAR(7564.806, dummyPID.compute(setPoint, currentVelocity), 10.0);
}
