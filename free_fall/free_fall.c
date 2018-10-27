#include <stdio.h>

// 重力加速度の設定
#define G 9.8
// 速度の初期値の設定
#define V0 0.0
// 時間の刻み幅の設定
#define TIME_STEP 1.0
// 計測する時間の設定
#define TIME_MAX 10.0

int main(){
  // 経過時間を表す変数
  double time;
  // 速度を表す変数（初期値を代入しておく）
  double v = V0;
  // 位置を表す変数
  double x = 0;
  
  for (time = 0; time < TIME_MAX; time += TIME_STEP){
    v += G * TIME_STEP;
    x = V0*time + G*time*time/2.0;
    printf("%f, %f\n", time, x);
  }
  return 0;
}
