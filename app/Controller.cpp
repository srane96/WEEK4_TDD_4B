#include "../include/Controller.h"

PID::PID(double kp, double ki, double kd) {
  this->kp = kp;
  this->ki = ki;
  this->kd = kd;
}

PID::~PID() {

}

double PID::compute(double setPoint, double currentVel) {
  return -1;
}
void PID::setParameters(int kd, int kp, int kd) {
  this->kp = kp;
  this->ki = ki;
  this->kd = kd;
}
int PID::getKi() {
  return this->ki;
}
int PID::getKp() {
  return this->kp;
}
int PID::getKd() {
  return this->kd;
}

