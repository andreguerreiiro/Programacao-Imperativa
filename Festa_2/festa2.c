#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <limits.h>

// --------------------

// Festa da Programa̤̣o
// 14 de Novembro
// Autor:
// ID Mooshak:

// --------------------

int max(int x, int y)
{
    return x <= y ? y : x;
}

int min(int x, int y)
{
    return x <= y ? x : y;
}

int ints_get(int *a)
{
    int result = 0;
    int x;
    while (scanf("%d", &x) != EOF)
        a[result++] = x;
    return result;
}

void ints_println_basic(const int *a, int n)
{
    if (n > 0)
    {
        printf("%d", a[0]);
        for (int i = 1; i < n; i++)  // i = 1
            printf(" %d", a[i]);
    }
    printf("\n");
}

int ints_sum(const int *a, int n)
{
    int result = 0;
    for (int i = 0; i < n; i++)
        result += a[i];
    return result;
}

int ints_max(const int *a, int n)
{
    int result = INT_MIN;
    for (int i = 0; i < n; i++)
        if (result < a[i])
            result = a[i];
    return result;
}

int ints_min(const int *a, int n)
{
    int result = INT_MAX;
    for (int i = 0; i < n; i++)
        if (result > a[i])
            result = a[i];
    return result;
}

int ints_equal_arrays(const int *a, const int n, const int *b, int m)
{
    int result = n == m;
    int i = 0;
    while (result && i < n)
        if (a[i] != b[i])
            result = 0;
        else
            i++;
    return result;
}

// --------------------

int doubles_get(double *a)
{
    int result = 0;
    double x;
    while (scanf("%lf", &x) != EOF)
        a[result++] = x;
    return result;
}

void doubles_println_basic(const double *a, int n)
{
    if (n > 0)
    {
        printf("%g", a[0]);
        for (int i = 1; i < n; i++)  // i = 1
            printf(" %g", a[i]);
    }
    printf("\n");
}

double doubles_sum(const double *a, int n)
{
    double result = 0;
    for (int i = 0; i < n; i++)
        result += a[i];
    return result;
}

double doubles_max(const double *a, int n)
{
    double result = -INFINITY;
    for (int i = 0; i < n; i++)
        if (result < a[i])
            result = a[i];
    return result;
}

double doubles_min(const double *a, int n)
{
    double result = +INFINITY;
    for (int i = 0; i < n; i++)
        if (result > a[i])
            result = a[i];
    return result;
}

//====================================== MY CODE
//========================================== A START
int cabaz(int* a, int n, int x){
    int result = 0;
    for(int i = 0; i < n ; i++){
        result += (a[i] / x);
    }
    return result;
}
//========================================== B START

int total_hat_tricks(int* a, int n){
    int result = 0;
    for( int i = 0; i < n; i++){
        if( a[i] >= 3 ){
            result++;
        }
    }
    return result;
}

int hat_trick(int* a, int n, int x){
    int bpos = 0;
    int b[1000 / x];
    
    for( int i = 0; i < n; i+=x ){
        b[bpos++] = total_hat_tricks(a + i, min(x, n - i));
    }
    
    ints_println_basic(b, bpos);
    
    return bpos;
}

//========================================== B END

//========================================== C START
int gas(double* a, int n){
    int peak = -1;
    for(int i = 0; i < n - 1; i++){
        if(a[i + 1] > a[i]){
            peak = i + 1;
        }
    }
    return peak;
}//Correct returns last rise index

int gas_sub(const double* a, int y){
    int result = -1;
    for(int i = 0; i < y - 1; i++){
        if(a[i + 1] < a[i]){
            return i + 1;
        }
    }
    return result;
}
//========================================== C END
void test_problem_A(void){
    int fill, x, arr[1000] = {0};
    fill = x = 0;
    scanf("%d\n", &x);
    int n = ints_get(arr);
    printf("%d\n", cabaz(arr, n, x) );
}

void test_problem_B(void){
    int x, arr[1000];
    x = 0;
    scanf("%d\n", &x);
    int n = ints_get(arr);
    hat_trick(arr, n, x);
}

void test_problem_C(void){
    double arr[1000];
    int n = doubles_get(arr),
        y = gas(arr, n),
        z
    ;
    if(y == -1){
        printf("void\n");
    }else{
        z = gas_sub(arr + y, n - y);
        if(z == -1){
            printf("void\n");
        }else{
            printf("%d\n", n - y - z - 1);
        }
    }
}

// --------------------

int main(void){
    //test_problem_A();
    //test_problem_B();
      test_problem_C();
    return 0;
}
