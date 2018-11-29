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
 * C++ sourse file that implements PID class.
 */
#include "../include/pid.h"
/**
 * Initialize all values to 0.0
 * if default constructor is called.
 */
PID::PID() {
	this->kp = 0;  				///< proportional gain
	this->ki = 0;  				///< integral gain
	this->kd = 0;  				///< differential gain
	this->prevError = 0;  		///< error at previous time step
	this->integralError = 0;  	///< Accumulation of error over time
	this->ctrlOp = 0;			///< Control Output from the PID controller
}
/**
 * Initialize controller gains
 */
PID::PID(const double &kp, const double& ki, const double& kd) {
	this->kp = kp;  			///< proportional gain
	this->ki = ki;  			///< integral gain
	this->kd = kd;  			///< differential gain
	this->prevError = 0;  		///< error at previous time step
	this->integralError = 0;  	///< Accumulation of error over time
	this->ctrlOp = 0;			///< Control Output from the PID controller

}
/// Default destructor
PID::~PID() {
}
/**
 * Calculate target velocity using Kp, Ki
 * and Kd member variables
 */
double PID::compute(const double& setPoint, const double& currentVel) {
	double error = setPoint - currentVel;
	this->integralError += error;
	this->ctrlOp = kp * error + ki * integralError + (kd/dt) * (error - prevError);
	this->prevError = error;
	return ctrlOp;
}
/**
 * Set new values to member variables of the class
 */
void PID::setParameters(const double &kp, const double& ki, const double& kd) {
	this->kp = kp;
	this->ki = ki;
	this->kd = kd;
}

/**
 * Set the kp variable to new value
 */
void PID::setKp(const double &kp) {
	this->kp = kp;
}

/**
 * Set the kd variable to new value
 */
void PID::setKd(const double &kd) {
	this->kd = kd;
}

/**
 * Set the kd variable to new value
 */
void PID::setKi(const double &ki) {
	this->ki = ki;
}

/**
 * Set the dt variable to new value
 */
void PID::setDt(const double &dt) {
	this->dt = dt;
}

/**
 * Return value of Ki member variable
 */
double PID::getKi() {
  return this->ki;
}
/**
 *  Return value of Kp member variable
 */
double PID::getKp() {
  return this->kp;
}
/**
 * Return value of Kd member variable
 */
double PID::getKd() {
  return this->kd;
}
/**
 * Return the current control output of the PID controller
 */
double PID::getCtrlOp(){
	return this->ctrlOp;
}
/**
 * Return the value of dt member variable
 */
double PID::getDt() {
	return this->dt;
}
/**
 * Implement kp tuner
 */
double PID::adjustTunedKp(const double& max) {
  double rKp = tuner->getRandomKp(max);
  if (rKp > 100 || rKp < 0)
    kp = 50;
  else
    kp = rKp;

  return kp;
}
/**
 * Implement kd tuner
 */
double PID::adjustTunedKd(const double& max) {
  double rKd = tuner->getRandomKd(max);
  if (rKd > 100 || rKd < 0)
    kd = 50;
  else
    kd = rKd;

  return kd;
}
/**
 * Implement kd tuner
 */
double PID::adjustTunedKi(const double& max) {
  double rKi = tuner->getRandomKi(max);
  if (rKi > 100 || rKi < 0)
    ki = 50;
  else
    ki = rKi;

  return ki;
}
