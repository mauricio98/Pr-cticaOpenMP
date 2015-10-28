#include <stdio.h>
#include <omp.h>
#include <time.h>


static long num_steps = 1000000;

double step;

void main() {
  
  int i; 
  double x, pi;
  double sum = 0.0;
  step = 1.0/(double) num_steps;
  clock_t t1, t2;
  t1=clock();
  for (i = 0; i < num_steps; i++) {
    x = (i + 0.5)*step;
    sum = sum + 4.0/(1.0 + x*x);
  }
  pi = step * sum;
  t2=clock();
  printf("pi [%lf] step [%lf] sum[%lf]\n", pi, step,sum);
  printf("pi secuential time %f\n", (((float)t2 - (float)t1) / 1000000.0F ) * 1000);
  
}
