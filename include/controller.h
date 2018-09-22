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
#ifndef WEEK4_TDD_4B_INCLUDE_CONTROLLER_H_
#define WEEK4_TDD_4B_INCLUDE_CONTROLLER_H_
#include <iostream>
class PID {
 private:
  double kp;  ///< proportional gain
  double ki;  ///< integral gain
  double kd;  ///< differential gain

 public:
  /**
   * @brief Default PID Controller
   */
  PID();
  /**
   * @brief Constructor with initial values
   * @param kp - proportional gain
   * @param ki - integral gain
   * @param kd - differential gain
   */
  PID(const double &kp, const double& ki, const double& kd);
  /// PID destructor
  ~PID();
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
};
#endif  // WEEK4_TDD_4B_INCLUDE_CONTROLLER_H_
