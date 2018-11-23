#include <iostream>
#include <fstream>
#include <cmath>

typedef double TYPE;

const TYPE A = 5.0;
const TYPE R = 2.0;
const TYPE STEP = 0.02;
const TYPE THETA_MIN = 0;
const TYPE THETA_MAX = 2*M_PI;
const TYPE THETA_STEP = STEP*M_PI;
const TYPE PHI_MIN = 0;
const TYPE PHI_MAX = 2*M_PI;
const TYPE PHI_STEP = STEP*M_PI;


main(){
  std::ofstream fout("torus.txt");

  TYPE theta = THETA_MIN;
  do{
    TYPE phi = PHI_MIN;
    do{
      fout << (A+R*cos(theta))*cos(phi) << ", "
           << (A+R*cos(theta))*sin(phi) << ", "
           << R*sin(theta) << std::endl;
      phi += PHI_STEP;
    }while(phi < PHI_MAX);
    theta += THETA_STEP;
  }while(theta < THETA_MAX);

  fout.close();
  return 0;
}
