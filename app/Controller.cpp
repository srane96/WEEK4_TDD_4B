/// Copyright 2018 <Copyright Owner- Siddhesh Rane>
#include "../include/Controller.h"
/**
 * @brief Default PID Controller
 */
PID::PID() {
  this->kp = 0.0;
  this->ki = 0.0;
  this->kd = 0.0;
}
/**
 * @brief Constructor with initial values
 * @param kp - proportional gain
 * @param ki - integral gain
 * @param kd - differential gain
 */
PID::PID(double kp, double ki, double kd) {
  this->kp = kp;
  this->ki = ki;
  this->kd = kd;
}
PID::~PID() {
}
/**
 * @brief calculate new velocity
 * @param setPoint - target velocity
 * @param currentVel - current velocity
 * @return new velocity
 */
double PID::compute(double setPoint, double currentVel) {
  return -1;
}
/**
 * @brief set gain values for PID
 * @param kp - proportional gain
 * @param ki - integral gain
 * @param kd - differential gain
 */
void PID::setParameters(int kp, int ki, int kd) {
  this->kp = kp;
  this->ki = ki;
  this->kd = kd;
}
/**
 * @brief get value of ki
 * @return Ki value of PID
 */
int PID::getKi() {
  return this->ki;
}
/**
 * @brief get value of kp
 * @return kp value of PID
 */
int PID::getKp() {
  return this->kp;
}
/**
 * @brief get value of kd
 * @return kd value of PID
 */
int PID::getKd() {
  return this->kd;
}

