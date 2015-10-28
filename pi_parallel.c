#include <stdio.h>
#include <omp.h>
#include <time.h>
#define CHUNKSIZE 100;
static long num_steps = 1000000;

double step;


void main() {
  int i, chunk;
  double x[num_steps];
  double pi;
  double sum = 0.0;
  step = 1.0/(double) num_steps;
  clock_t t1, t2;
 t1=clock(); 
#pragma omp parallel shared(x) private(i) 
   {
#pragma omp sections  reduction(+:sum) //nowait
  {
#pragma omp section
  for (i = 0; i < num_steps; i++) 
    x[i] = (i + 0.5)*step;
  }}
   chunk = CHUNKSIZE;
  #pragma omp omp for schedule(dynamic,chunk) nowait 
    for (i = 0; i < num_steps; i++)
    sum = sum + 4.0/(1.0 + x[i]*x[i]);
  
  
  pi = step * sum;
   t2=clock();
  printf("pi [%lf] step [%lf] sum[%lf]\n", pi, step,sum);
  printf("pi parallel time %f\n", (((float)t2 - (float)t1) / 1000000.0F ) * 1000);
  
}
