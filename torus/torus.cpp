#include <iostream>
#include <fstream>
#include <cmath>

typedef double TYPE;

const TYPE A = 1.0;
const TYPE R = 2.0;
const TYPE THETA_MIN = 0;
const TYPE THETA_MAX = 2*M_PI;
const TYPE THETA_STEP = 0.1*M_PI;
const TYPE PHI_MIN = 0;
const TYPE PHI_MAX = 2*M_PI;
const TYPE PHI_STEP = 0.1*M_PI;

// Three Dimensional Coodinates
typedef struct {
  TYPE x;
  TYPE y;
  TYPE z;
} tdc;

main(){
  const TYPE 
  int data_num = i+1;
  tdc data[100000];
  TYPE theta;
  TYPE phi;
  int i;

  i = 0;
  theta = THETA_MIN;
  do{
    phi = PHI_MIN;
    do{
      data[i].x = (A+R*cos(theta))*cos(phi);
      data[i].y = (A+R*cos(theta))*sin(phi);
      data[i].z = R*sin(theta);
      phi += PHI_STEP;
      i++;
    }while(phi < PHI_MAX);
    theta += THETA_STEP;
  }while(theta < THETA_MAX);

  std::ofstream fout("torus.txt");
  for (i=0; i<data_num; i++){
    fout << std::fixed << data[i].x << ", "
         << data[i].y << ", "
         << data[i].z << std::endl;
  }
  fout.close();

}
