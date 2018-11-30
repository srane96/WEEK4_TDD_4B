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
 * @file pid.cpp
 * @version 1.0
 * @author Siddhesh Rane
 * @brief main class for emergency rescue robot
 *
 * @section DESCRIPTION
 *
 * Source header file for PID controller class.
 */
#ifndef WEEK4_TDD_4B_INCLUDE_CONTROLLER_H_
#define WEEK4_TDD_4B_INCLUDE_CONTROLLER_H_
#include <iostream>
#include "tuner.h"
class PID {
 private:
  double dt = 0.01;  		///< time step
  double kp;  				///< proportional gain
  double ki;  				///< integral gain
  double kd;  				///< differential gain
  double prevError;  		///< error at previous time step
  double integralError;  	///< Accumulation of error over time
  double ctrlOp;			///< Control Output from the PID controller
  Tuner* tuner;
 public:
  /**
   * @brief Default PID Controller
   */
  PID();
  /**
   * @brief Constructor with initial values
   * @param ttuner - reference to Tuner class8
   */
  explicit PID(Tuner* ttuner)
      : tuner(ttuner),
        kp(0),
        ki(0),
        kd(0),
        prevError(0),
        integralError(0),
        ctrlOp(0) {
  }
  /**
   * @brief Constructor with initial values
   * @param kp - proportional gain
   * @param ki - integral gain
   * @param kd - differential gain
   */
  PID(const double &Kp, const double& Ki, const double& Kd);
  /// PID destructor
  ~PID();
  /**
   * @return void
   */
  double adjustTunedKp(const double& max);
  /**
   * @return void
   */
  double adjustTunedKd(const double& max);
  /**
   * @return void
   */
  double adjustTunedKi(const double& max);
  /**
   * @brief calculate new velocity using setpoint
   *        and current velocity
   * @param setPoint - target velocity
   * @param currentVel - current velocity
   * @return new velocity
   */
  double compute(const double& setPoint, const double& currentVel);
  /**
   * @brief set gain values for PID class
   * @param kp - proportional gain
   * @param ki - integral gain
   * @param kd - differential gain
   */
  void setParameters(const double &kp, const double& ki, const double& kd);
  /**
   * @brief set value of kp
   * @param Kp - proportional gain
   */
  void setKp(const double &kp);
  /**
   * @brief set value of kd
   * @param Kd - differential gain
   */
  void setKd(const double &kd);
  /**
   * @brief set value of ki
   * @param ki - integral gain
   */
  void setKi(const double &ki);
  /**
   * @brief set the dt value
   * @param dt - duration of each time step
   */
  void setDt(const double &dt);
  /**
     * @brief get value of ki
     * @return Ki value of PID
     */
  double getKi();
  /**
   * @brief get value of kp
   * @return kp value of PID
   */
  double getKp();
  /**
   * @brief get value of kd
   * @return kd value of PID
   */
  double getKd();
  /**
   * @brief get the value current value of Control Output from PID controller
   * @return ctrlOp value of PID
   */
  double getCtrlOp();
  /**
   * @brief get the value of dt
   * @return dt value of PID
   */
  double getDt();

};
#endif  // WEEK4_TDD_4B_INCLUDE_CONTROLLER_H_
