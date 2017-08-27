#include "PID.h"
#include <iostream>
#include <math.h>
// using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    // coefficients
    Kp_ = Kp;
    Ki_ = Ki;
    Kd_ = Kd;

    p_error = 0;
    i_error = 0;
    d_error = 0;

    prev_cte = 0;
    first_measurement = true;
}

void PID::UpdateError(double cte) {
    if(first_measurement)
    {
        prev_cte = cte;
        first_measurement = false;
    }
    
    p_error = cte;
    i_error += cte;
    d_error = cte - prev_cte;
}

double PID::TotalError() {
    std::cout << p_error << ", " << i_error << "," << d_error << ": " << -Kp_ * p_error - Ki_ * i_error - Kd_ * d_error << "!\n";
    return -Kp_ * p_error - Ki_ * i_error - Kd_ * d_error;
}

double PID::Normalize(double steer_value){
    return atan2(sin(steer_value), cos(steer_value)) / M_PI;
}
