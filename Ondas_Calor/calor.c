#include "assert.h"
#include "stdio.h"

void unit_test_count_heat_waves(void);
int doubles_get(double*);
int double_count_while_greater_or_equal(double* a, int n, double x);
int count_heat_waves(double *a, int n, double x);

int main(){
    unit_test_count_heat_waves();
    return 0;
}

void unit_test_count_heat_waves(void)
{
  double a[30] = {5,7,7,7,7, 3,3,4,7,7, 3,3,6,7,7, 8,8,7,8,5, 4,4,9,9,9, 2,2,9,8,7};
  assert(count_heat_waves(a, 30, 6) == 4);
  assert(count_heat_waves(a, 30, 8) == 1);
  assert(count_heat_waves(a, 30, 10) == 0);
  double b[10] = {5,5,5,5,5, 5,5,5,5,5};
  assert(count_heat_waves(b, 10, 6) == 0);
  assert(count_heat_waves(b, 10, 5) == 1);
  assert(count_heat_waves(b, 10, 4) == 1);
  double c[20] = {1,5,6,1,5, 6,7,1,5,6, 7,8,1,5,6, 7,8,9,1,2};
  assert(count_heat_waves(c, 20, 5) == 3);
  assert(count_heat_waves(c, 20, 6) == 2);
  assert(count_heat_waves(c, 20, 7) == 1);
  assert(count_heat_waves(c, 20, 8) == 0);
  double d[7] = {5,5,5,4,5,5,5};
  assert(count_heat_waves(d, 7, 5) == 2);
  assert(count_heat_waves(d+1, 6, 5) == 1);
  assert(count_heat_waves(d, 6, 5) == 1);
  assert(count_heat_waves(d+1, 5, 5) == 0);
} 

int doubles_get(double* a){
    int i = 0;
    double x;
    while(scanf("%lf", &x) != EOF){
        a[i++] = x;
    }
    return i;
}

int double_count_while_greater_or_equal(double* a, int n, double x){
    int result = 0;
    while(result < n && a[result] >= x){
        result++;
    }
    return result;
}

int count_heat_waves(double *a, int n, double x){
    
    int count = 0,
        i = 0,
        tmp = 0;
    
    while(i < n){
        tmp = double_count_while_greater_or_equal(a + i, n, x);
        if(tmp >= 3){
            i += tmp;
            count++;
            tmp = 0;
        }else{
            i++;
        }
    }
    return count;
}











