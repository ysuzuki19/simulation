#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
#define THETA_START 12.0
#define START_TIME 0.00
#define DT 0.01
#define END_TIME 100.00
#define G 9.8
#define L 10.0
#define M 2.0
#define MU 0.01

main(){
  const int data_num = (END_TIME-START_TIME+1)/DT;//データ数を格納する変数
  int plot_num = 0;//プロット数をカウントする変数,number of plot 
  double *time;//時間を格納する配列.array of time
  time = new double[data_num+1];
  double *theta;//角度θを格納する配列,array of degree
  theta = new double[data_num];
  double *theta_dot;//角度θの微分を格納する配列,array of degree/secont
  theta_dot = new double[data_num];
  double theta_dot_dot = 0.0;

  theta[0] = THETA_START;
  theta_dot[0] = 0.0;
  for(double t=START_TIME; t<END_TIME; t+=DT){
    time[plot_num] = t;
    theta_dot_dot = - G/L*sin(theta[plot_num]/2.0/M_PI) - MU*theta_dot[plot_num];
    theta_dot[plot_num+1] = theta_dot[plot_num] + theta_dot_dot*DT;
    theta[plot_num+1] = theta[plot_num] + theta_dot[plot_num+1]*DT;
    plot_num ++ ; 
  }//単振り子の方程式

  ofstream fout("single_pendulum.txt");
  for(int i=0; i<plot_num; i++){
    fout << time[i] << ", " << theta[i] << endl;  
  }//出力
  fout.close();
}
