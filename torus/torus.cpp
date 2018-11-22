#include <iostream>
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
  tdc data[100000];
  TYPE theta;
  TYPE phi;
  int i;

  theta = THETA_MIN;
  do{
    phi = PHI_MIN;
    do{
      data[i].x = i;
      data[i].y = i * 10;
      data[i].z = i * 100;
      phi += PHI_STEP;
    }while(phi < PHI_MAX);
    theta += THETA_STEP;
  }while(theta < THETA_MAX);

//  for (i=0; i<10; i++){
//    std::cout << data[i].x << ", "
//              << data[i].y << ", "
//              << data[i].z << std::endl;
//  }

  return 0;

}
