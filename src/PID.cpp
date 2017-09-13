#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;

  sum_cte = 0.0;
}

void PID::UpdateError(double cte) {
  sum_cte += cte;
  p_error = -Kp * cte;
  // delta_t = 1, so no need to divide (cte - cte_prev)/delta_t
  d_error = Kd * (cte - cte_prev);
  i_error = Ki * sum_cte;
  cte_prev = cte;
}

double PID::TotalError() {
  return p_error - d_error - i_error;
}

