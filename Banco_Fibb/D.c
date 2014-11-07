#include "stdio.h"


void test(void);
void ints_println_basic(const int*, int);
int fibonacci_bank(int*,int,int,int);
int find_sequence_dic(int *a, int x, int n, int t, int max);
int find_sequence_better(int *a, int n, int t, int max);

//PRINTS THE WAY MOOSHARK WANT'S
void ints_println_basic(const int* a, int n){
    if (n > 0) {
        printf("%d", a[0]);
        for(int i = 1; i < n ; i++) //i=1
            printf(" %d", a[i]);
    }
    printf("\n");
}

int fibonacci_bank(int *a, int x, int y, int n){
    *a = x;
    *(a + 1) = y;
    for(int i = 2; i < n; i++){
        a[i] = a[i - 1] + a[i - 2];
    }
    return n;
}

int find_sequence_dic(int *a, int x, int n, int t, int max){
    int i = x;
    int j = max;
    
    while (i <= j){
        int m = i + (j-i) / 2,
            z = fibonacci_bank(a, x, m, n)
        ;
        if (a[z - 1] > t)
            j = m-1;
        else if (a[z - 1] < t)
            i = m+1;
        else
            return m;
    }
    return -1;
}

int find_sequence_better(int *a, int n, int t, int max){
    int z = 0;
    for(int i = 0; i < max; i++){
        z = find_sequence_dic(a,i,n,t,max);
        if(z >= 0){
            return z;
        }
    }
    return -1;
}


void test_find_sequence_better(void){
    long max = 100000;
    int n,t,result;
    n = t = result = 0;
    while( scanf("%d %d", &n, &t) != EOF) {
        int a[n];
        result = find_sequence_better(a, n, t, max);
        if(result == -1){
            printf("Impossible\n");
        }else{
            ints_println_basic(a, n);
        }
    }
}

int main(void){
    test_find_sequence_better();
    return 0;
}