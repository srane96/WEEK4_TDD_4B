/**
 * 3-clause BSD License
 *
 * Copyright (c) 2018  Siddhesh Rane
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
 * @file main.cpp
 * @version 1.0
 * @author Siddhesh Rane
 * @brief main class for emergency rescue robot
 *
 * @section DESCRIPTION
 *
 * This is C++ program that gmock main function which starts all the tests.
 */
#include <iostream>
#include "../include/pid.h"
#include "../include/tuner.h"
int main() {
  double currVel, desVel;
  PID dummyPID(0.1, 0.5, 0.01);
  std::cout << "PID Implementation using user given values" << std::endl;
  std::cout << "Enter Current and desired velocity: ";
  std::cin >> currVel >> desVel;
  std::cout << "The necessary control input: "
            << dummyPID.compute(desVel, currVel) << std::endl;
  ///  -------------Automatic tuning selection------------------
  std::cout << "PID Implementation using values given by Tuner" << std::endl;
  Tuner tuner;
  PID pidAuto(&tuner);
  std::cout << "Enter Current and desired velocity: ";
  std::cin >> currVel >> desVel;
  /// Use Tuner object to get random Kp
  pidAuto.setKp(pidAuto.adjustTunedKp(10));
  /// Use Tuner object to get random Kd
  pidAuto.setKd(pidAuto.adjustTunedKd(20));
  /// Use Tuner object to get random Ki
  pidAuto.setKi(pidAuto.adjustTunedKi(10));
  std::cout << "The necessary control input: "
            << dummyPID.compute(desVel, currVel) << std::endl;
  return 0;
}
