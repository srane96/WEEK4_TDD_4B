#include <gtest/gtest.h>
#include <memory>
#include "pid.h"

std::shared_ptr<PID> dummyPID;

TEST(PIDTest, classInitialization) {
  dummyPID = std::make_shared<PID>();
//  dummyPID->setParameters(1.5, 10.2, 25.2);

  EXPECT_EQ(1.5, dummyPID->getKp());
  EXPECT_EQ(10.2, dummyPID->getKi());
  EXPECT_EQ(25.2, dummyPID->getKd());
}

//TEST(PIDTest, computeControlInput) {
//
//  PID dummyPID(1.5, 10.2, 25.2);
//
//  double setPoint = 5.0;
//  double currentVelocity = 2.0;
//
//  EXPECT_NEAR(7564.806, dummyPID.compute(setPoint, currentVelocity), 10.0);
//}
