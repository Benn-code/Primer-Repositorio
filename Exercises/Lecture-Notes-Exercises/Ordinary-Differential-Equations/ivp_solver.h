#pragma once

#include <iostream>
#include <valarray>
#include <functional>


// function template to work with "any" type //Euler Algorithm
template <class deriv_t, class system_t, class printer_t>
void integrate_euler(deriv_t fderiv, system_t & s, double tinit, double tend, double dt, printer_t writer)
{
    // vector to store derivs
    system_t dsdt(s.size());

    // time loop
    for(double t = tinit; t <= tend; t = t + dt) { // NOTE: Last time step not necessarily tf
        // compute derivs
        fderiv(s, dsdt, t);

        // compute new state. NOTE: Not using components, assuming valarray or similar
        s = s + dt*dsdt; // Euler

        // write new state
        writer(s, t);
      }
}


// function template to work with "any" type // Heun Algorithm
template <class deriv_t, class system_t, class printer_t>
void integrate_heun(deriv_t fderiv, system_t & s, double tinit, double tend, double dt, printer_t writer)
{
    // vector to store derivs
    system_t k1, k2;
    k1.resize(s.size());
    k2.resize(s.size());

    // time loop
    for(double t = tinit; t <= tend; t = t + dt) { // NOTE: Last time step not necessarily tf
        // compute derivs
        fderiv(s, k1, t);
        fderiv(s + dt*k1, k2, t + dt);

        // compute new state. NOTE: Not using components, assuming valarray or similar
        s = s + dt*(k1 + k2)/2; // Heun

        // write new state
        writer(s, t);
      }
}

// function template to work with "any" type // Runge-Kutta 4th Order Algorithm
template <class deriv_t, class system_t, class printer_t>
void integrate_rk4(deriv_t fderiv, system_t & s, double tinit, double tend, double dt, printer_t writer)
{
    // Vectors to store the k-values (slopes)
    system_t k1, k2, k3, k4;
    k1.resize(s.size());
    k2.resize(s.size());
    k3.resize(s.size());
    k4.resize(s.size());

    // Auxiliary state vectors for intermediate calculations
    system_t s_temp(s.size()); 

    // Time loop
    for(double t = tinit; t <= tend; t = t + dt) { // NOTE: Last time step not necessarily tf
        // 1. Calculate k1
        // k1 = f(t, y)
        fderiv(s, k1, t);

        // 2. Calculate k2
        // k2 = f(t + dt/2, y + (dt/2)*k1)
        s_temp = s + (dt/2.0) * k1;
        fderiv(s_temp, k2, t + dt/2.0);

        // 3. Calculate k3
        // k3 = f(t + dt/2, y + (dt/2)*k2)
        s_temp = s + (dt/2.0) * k2;
        fderiv(s_temp, k3, t + dt/2.0);

        // 4. Calculate k4
        // k4 = f(t + dt, y + dt*k3)
        s_temp = s + dt * k3;
        fderiv(s_temp, k4, t + dt);

        // 5. Compute new state using the weighted average of k1, k2, k3, k4
        // s(t+dt) = s(t) + (dt/6)*(k1 + 2*k2 + 2*k3 + k4)
        s = s + (dt/6.0) * (k1 + 2.0*k2 + 2.0*k3 + k4);

        // Write new state
        writer(s, t);
    }
}