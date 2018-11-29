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
 * @file tuner.h
 * @version 1.0
 * @author Siddhesh Rane
 * @brief main class for emergency rescue robot
 *
 * @section DESCRIPTION
 *
 * This is C++ program that defines source file for Tuner class.
 */
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "tuner.h"
Tuner::Tuner() {
  std::cout << "Tuner object created" << std::endl;
}
Tuner::~Tuner() {
}
double Tuner::getRandomKp(const double& max) {
  srand(time(NULL));
  double kp = rand() % int(max) + 1;
  return kp;
}
double Tuner::getRandomKi(const double& max) {
  srand(time(NULL));
  double ki = rand() % int(max) + 1;
  return ki;
}
double Tuner::getRandomKd(const double& max) {
  srand(time(NULL));
  double kd = rand() % int(max) + 1;
  return kd;
}
