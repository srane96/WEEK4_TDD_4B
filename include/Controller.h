/**
 * Copyright 2018 <Copyright Owner- Siddhesh Rane>
 * @class PID
 *
 * @brief PID controller for mobile robot
 *
 * This class defines basic PID controller that
 * can calculate target velocity given the setpoint
 * and current velocity
 *
 * @author Siddhesh Rane
 *
 *
 */
#ifndef INCLUDE_CONTROLLER_H_
#define INCLUDE_CONTROLLER_H_
#include <iostream>
class PID {
 private:
  double kp;  ///< proportional gain
  double ki;  ///< integral gain
  double kd;  ///< differential gain
 public:
  /// PID default constructor
  PID();
  /// PID constructor with initial control values
  PID(double kp, double ki, double kd);
  /// PID destructor
  ~PID();
  double compute(double setPoint, double currentVel);
  void setParameters(int kp, int ki, int kd);
  int getKi();
  int getKp();
  int getKd();
};
#endif  // INCLUDE_CONTROLLER_H_
