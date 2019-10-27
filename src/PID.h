#ifndef PID_H
#define PID_H

class PID
{
public:
  /**
   * Constructor
   */
  PID();

  /**
   * Destructor.
   */
  virtual ~PID();

  /**
   * Initialize PID.
   * @param (Kp_, Ki_, Kd_) The initial PID coefficients
   */
  void Init(double k_p, double k_i, double k_d);

  /**
   * compute steering control
   */
  double Control(double cte);
  /**
   * Update the PID error variables given cross track error.
   * @param cte The current cross track error
   */
  void UpdateError(double cte);

  /**
   * Calculate the total PID error.
   * @output The total PID error
   */
  double TotalError();

private:
  /**
   * PID Errors
   */
  double p_error_;
  double i_error_;
  double d_error_;

  double cte_std_dev_;
  /**
   * PID Coefficients
   */
  double k_p_;
  double k_i_;
  double k_d_;

  double pre_cte_;
  double int_cte_;
  bool first_update_;
};

#endif // PID_H