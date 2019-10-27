#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() : k_p_{0.0}, k_i_{0.0}, k_d_{0.0}, p_error_{0.0}, i_error_{0.0}, d_error_{0.0}, pre_cte_{0.0}, first_update_{true}, int_cte_{0.0} {}

PID::~PID() {}

void PID::Init(double k_p, double k_i, double k_d)
{
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  k_p_ = k_p;
  k_i_ = k_i;
  k_d_ = k_d;
}

double PID::Control(double cte)
{
  if (first_update_)
  {
    pre_cte_ = cte;
  }
  double diff_cte = cte - pre_cte_;
  pre_cte_ = cte;

  int_cte_ += cte;
  double steer = -k_p_ * cte - k_d_ * diff_cte - k_i_ * int_cte_;
  if (steer > 1.0)
  {
    steer = 1.0;
  }
  if (steer < -1.0)
  {
    steer = -1.0;
  }
  return steer;
}

void PID::UpdateError(double cte)
{
  /**
   * TODO: Update PID errors based on cte.
   */
}

double PID::TotalError()
{
  /**
   * TODO: Calculate and return the total error
   */
  return 0.0; // TODO: Add your total error calc here!
}