/**
 * 3-clause BSD License
 *
 * Copyright (c) 2018 Siddhesh Rane
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that
 * the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this list of conditions and the
 * following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and
 * the following disclaimer in the documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or
 * promote products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 *
 * @file test.cpp
 * @version 1.0
 * @author Siddhesh Rane
 * @brief main class for emergency rescue robot
 *
 * @section DESCRIPTION
 *
 * This is a C++ program that implements gmock tests.
 */
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/pid.h"
#include "../include/tuner.h"
using ::testing::Return;
using ::testing::_;
using ::testing::AtLeast;
/**
 * @brief Create a mock class for Tuner
 * @details Tuner is an abstract class that returns random
 *          value of kp, kd and ki less than max value provided.
 */
class MockTuner : public Tuner {
 public:
  MOCK_METHOD1(getRandomKp, double(const double& max));
  MOCK_METHOD1(getRandomKd, double(const double& max));
  MOCK_METHOD1(getRandomKi, double(const double& max));
};
/**
 * @brief Test class initialization
 */
TEST(PIDTest, classInitialization) {
  PID dummyPID;
  dummyPID.setParameters(15.0, 50.5, 2.0);

  EXPECT_EQ(15.0, dummyPID.getKp());
  EXPECT_EQ(50.5, dummyPID.getKi());
  EXPECT_EQ(2.0, dummyPID.getKd());
}
/**
 * @brief Test compute method
 */
TEST(PIDTest, computeControlInput) {
  PID dummyPID(20.2, 30.3, 1.1);
  double setPoint = 5.0;
  double currentVelocity = 2.5;
  EXPECT_NEAR(401.25, dummyPID.compute(setPoint, currentVelocity), 10.0);
}

/**
 * @brief Test Individual PID parameter (Kp, kd, ki) initiation routines
 */
TEST(PIDTest, setIndividualParams) {
  PID dummyPID;
  dummyPID.setKp(15.0);
  dummyPID.setKd(50.5);
  dummyPID.setKi(2.0);
  dummyPID.setDt(0.01);
  EXPECT_EQ(15.0, dummyPID.getKp());
  EXPECT_EQ(50.5, dummyPID.getKd());
  EXPECT_EQ(2.0, dummyPID.getKi());
  EXPECT_EQ(0.01, dummyPID.getDt());
}
/**
 * @brief Test retrieve control output from PID method
 */
TEST(PIDTest, getControlOutput) {
  PID dummyPID(20.2, 30.3, 1.1);
  double setPoint = 5.0;
  double currentVelocity = 2.5;
  dummyPID.compute(setPoint, currentVelocity);
  EXPECT_NEAR(401.25, dummyPID.getCtrlOp(), 10.0);
}
/**
 * @brief Check if mock object methods are being called
 */
TEST(PIDTest, callTunerMethodsTest) {
  MockTuner mTuner;
  /// Expect atleast one call for getRandomKp
  EXPECT_CALL(mTuner, getRandomKp(_)).Times(AtLeast(1));
  /// Expect atleast one call for getRandomKd
  EXPECT_CALL(mTuner, getRandomKd(_)).Times(AtLeast(1));
  /// Expect atleast one call for getRandomKi
  EXPECT_CALL(mTuner, getRandomKi(_)).Times(AtLeast(1));
  PID pid(&mTuner);
  pid.adjustTunedKp(50);
  pid.adjustTunedKd(10);
  pid.adjustTunedKi(260);
}
/**
 * @brief Implement GMOCK test for adjustTunedKp method in PID
 * @details If Kp value returned by tuner is less than 0 or more than
 *          100 then pid would set kp equal to 50.
 *          Else pid would set kp value to value returned by tuner
 *          as it is.
 */
TEST(PIDTest, adjustTunedKpTest) {
  MockTuner mTuner;
  EXPECT_CALL(mTuner, getRandomKp(_)).Times(5).WillOnce(Return(12.0)).WillOnce(
      Return(35.5)).WillOnce(Return(-2)).WillOnce(Return(150)).WillOnce(
      Return(96.2));
  PID pid(&mTuner);
  EXPECT_DOUBLE_EQ(12.0, pid.adjustTunedKp(60.0));
  EXPECT_DOUBLE_EQ(35.5, pid.adjustTunedKp(40.0));
  EXPECT_DOUBLE_EQ(50, pid.adjustTunedKp(10.0));
  EXPECT_DOUBLE_EQ(50, pid.adjustTunedKp(4.0));
  EXPECT_DOUBLE_EQ(96.2, pid.adjustTunedKp(45.0));
}
/**
 * @brief Implement GMOCK test for adjustTunedKd method in PID
 * @details If Kd value returned by tuner is less than 0 or more than
 *          100 then pid would set kp equal to 50.
 *          Else pid would set kd value to value returned by tuner
 *          as it is.
 */
TEST(PIDTest, adjustTunedKdTest) {
  MockTuner mTuner;
  EXPECT_CALL(mTuner, getRandomKd(_)).Times(5).WillOnce(Return(2.0)).WillOnce(
      Return(130.2)).WillOnce(Return(-55)).WillOnce(Return(150)).WillOnce(
      Return(16.2));
  PID pid(&mTuner);
  EXPECT_DOUBLE_EQ(2.0, pid.adjustTunedKd(10.0));
  EXPECT_DOUBLE_EQ(50.0, pid.adjustTunedKd(145.0));
  EXPECT_DOUBLE_EQ(50.0, pid.adjustTunedKd(20.0));
  EXPECT_DOUBLE_EQ(50.0, pid.adjustTunedKd(400.0));
  EXPECT_DOUBLE_EQ(16.2, pid.adjustTunedKd(45.0));
}
/**
 * @brief Implement GMOCK test for adjustTunedKi method in PID
 * @details If Ki value returned by tuner is less than 0 or more than
 *          100 then pid would set kp equal to 50.
 *          Else pid would set ki value to value returned by tuner
 *          as it is.
 */
TEST(PIDTest, adjustTunedKiTest) {
  MockTuner mTuner;
  EXPECT_CALL(mTuner, getRandomKi(_)).Times(5).WillOnce(Return(-5.0)).WillOnce(
      Return(100.5)).WillOnce(Return(22)).WillOnce(Return(10)).WillOnce(
      Return(3.6));
  PID pid(&mTuner);
  EXPECT_DOUBLE_EQ(50.0, pid.adjustTunedKi(2.0));
  EXPECT_DOUBLE_EQ(50.0, pid.adjustTunedKi(115.0));
  EXPECT_DOUBLE_EQ(22, pid.adjustTunedKi(30.0));
  EXPECT_DOUBLE_EQ(10, pid.adjustTunedKi(40.0));
  EXPECT_DOUBLE_EQ(3.6, pid.adjustTunedKi(4.0));
}
