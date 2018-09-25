/**
 *  Copyright 2018 Siddhesh Rane
 *  @file    pid.cpp
 *  @author  Siddhesh Rane (srane96)
 *  @date    9/22/2018
 *
 *  @brief PID controller class implementation
 *
 *  @section DESCRIPTION
 *
 *  This source file implements a PID controller class.
 *  The class contains methods to compute target velocity
 *  given setpoint, current velocity and gain parameters.
 *
 */
#include "pid.h"
/**
 * Initialize all values to 0.0
 * if default constructor is called.
 */
PID::PID() {
	this->kp = 0;  ///< proportional gain
	this->ki = 0;  ///< integral gain
	this->kd = 0;  ///< differential gain
	this->prevError = 0;  ///< error at previous time step
	this->integralError = 0;  ///< Accumulation of error over time
}
/**
 * Initialize controller gains
 */
PID::PID(const double &kp, const double& ki, const double& kd) {
	this->kp = kp;  ///< proportional gain
	this->ki = ki;  ///< integral gain
	this->kd = kd;  ///< differential gain
	this->prevError = 0;  ///< error at previous time step
	this->integralError = 0;  ///< Accumulation of error over time

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
	double ctrlInp = kp * error + ki * integralError + (kd/dt) * (error - prevError);
	this->prevError = error;
	return ctrlInp;
}
/**
 * Set new values to member variables of the class
 */
void PID::setParameters(const double &kp, const double& ki, const double& kd) {
	this->kp = kp;
	this->ki = ki;
	this->kd = kd;
}
/// Return value of Ki member variable
double PID::getKi() {
  return this->ki;
}
/// Return value of Kp member variable
double PID::getKp() {
  return this->kp;
}
/// Return value of Kd member variable
double PID::getKd() {
  return this->kd;
}

