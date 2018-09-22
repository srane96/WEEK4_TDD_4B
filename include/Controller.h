#ifndef INCLUDE_CONTROLLER_H
#define INCLUDE_CONTROLLER_H
#include <iostream>
class PID {
 private:
  double kp;
  double ki;
  double kd;
 public:
  PID(double kp = 0.0, double ki = 0.0, double kd = 0.0);
  ~PID();
  double compute(double setPoint, double currentVel);
  void setParameters(int kd, int kp, int kd);
  int getKi();
  int getKp();
  int getKd();
};
#endif // INCLUDE_CONTROLLER_H
