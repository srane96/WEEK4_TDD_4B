/// Copyright 2018 <Copyright Owner- Siddhesh Rane>
#include "../include/Controller.h"
/**
 * Initialize all values to 0.0
 * if default constructor is called.
 */
PID::PID() {
  this->kp = 0.0;
  this->ki = 0.0;
  this->kd = 0.0;
}
PID::PID(double kp, double ki, double kd) {
  this->kp = kp;
  this->ki = ki;
  this->kd = kd;
}
PID::~PID() {
}
/**
 * Calculate target velocity using Kp, Ki
 * and Kd member variables
 */
double PID::compute(double setPoint, double currentVel) {
  return -1;
}
/**
 * Set new values to member variables of the class
 */
void PID::setParameters(int kp, int ki, int kd) {
  this->kp = kp;
  this->ki = ki;
  this->kd = kd;
}
/// Return value of Ki member variable
int PID::getKi() {
  return this->ki;
}
/// Return value of Kp member variable
int PID::getKp() {
  return this->kp;
}
/// Return value of Kd member variable
int PID::getKd() {
  return this->kd;
}

