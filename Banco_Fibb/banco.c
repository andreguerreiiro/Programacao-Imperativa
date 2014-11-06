#include "stdio.h"
//Mooshak print
void ints_println_basic(const int* a, int n);
//B
int fibonacci_bank(int *a, int x, int y, int n);
void test_fibonacci_bank(void);
//C
int find_sequence(int *a, int n, int t, int max);
void test_find_sequence(void);
//D
int ints_bfind_classic(const int *a, int n, int x);
int find_sequence_dic(int *a, int x, int n, int t, int max);
//D e meio
int find_sequence_better(int *a, int n, int t, int max);
void test_find_sequence_better(void);

//PRINTS THE WAY MOOSHARK WANT'S
void ints_println_basic(const int* a, int n){
    if (n > 0) {
        printf("%d", a[0]); 
        for(int i = 1; i < n ; i++) //i=1
            printf(" %d", a[i]);
    }
    printf("\n");
}

//EX 1 (B)
int fibonacci_bank(int *a, int x, int y, int n){
    *a = x;
    *(a + 1) = y;
    for(int i = 2; i < n; i++){
        a[i] = a[i - 1] + a[i - 2];
    }
    return n;
}

void test_fibonacci_bank(){
    int depo[1000], d0, d1, duration;
    d0 = d1 = duration = 0;
    while( scanf("%d %d %d", &d0, &d1, &duration) != EOF ){
        fibonacci_bank(depo, d0, d1, duration);
        ints_println_basic(depo, duration);
    }
}
//END EX 1 (B)

//EX 2 (C)
int find_sequence(int *a, int n, int t, int max){
  for (int i = 1; i <= max; i++)
    for (int j = i; j <= max; j++)
    {
      int tam = fibonacci_bank(a, i, j, n);
      if (a[tam - 1] == t){
        return n;
      }
    }
  return -1;
}

void test_find_sequence(void){
    int n, t;
    n = t = 0;
    while( scanf("%d %d", &n, &t) != EOF ){
        int a[n];
        if(find_sequence(a, n, t, 1000) > -1){
            ints_println_basic(a, n);
        }else{
            printf("Impossible\n");
        }
    }
}
//END EX 2 (C)

//EX D =================================================

int ints_bfind_classic(const int *a, int n, int x){
    int i = 0;
    int j = n-1;
    while (i <= j)
    {
        int m = i + (j-i) / 2;
        if (x < a[m])
            j = m-1;
        else if (x > a[m])
            i = m+1;
        else
            return m; 
    } 
    return -1; 
}

int find_sequence_dic(int *a, int x, int n, int t, int max){

    for(int y = x; y <= max; y++){
        int tam = fibonacci_bank(a, x, y, n);//array "a" is being created with X,Y and length N
        if( ints_bfind_classic(a, tam, y) == 1 && a[tam - 1] == t ){
            printf("Possible\n");
            for (int i = 0; i < tam; i ++){
                printf("%d\n", a[i]);
            }
            return n;
        }
    }
    return  -1;

}

void test_find_sequence_dic(void){
    int x, n, t, max;
    x = n = t = max = 0;
    while( scanf("%d %d %d %d", &x, &n, &t, &max) != EOF ){
        int a[n];
        if( find_sequence_dic(a, x, n, t, max) > -1){
            ints_println_basic(a, n);
        }else{
            printf("Impossible\n");
        }
    }
}
//BETTER. Much better.
int find_sequence_better(int *a, int n, int t, int max){
    for(int i = 1; i < max; i++){
        if( find_sequence_dic(a, i, n, t, max) > -1 ){
            return n;
        }
    }
    return -1;
}

void test_find_sequence_better(void){
    int x, n, t, max;
    x = n = t = max = 0;
    while( scanf("%d %d %d", &n, &t, &max) != EOF ){
        int a[n];
        if( find_sequence_better(a, n, t, max) > -1){
            ints_println_basic(a, n);
        }else{
            printf("Impossible\n");
        }
    }
}
//EX END D =================================================


//MAIN BEGIN
int main(){
    //test_fibonacci_bank();
    //test_find_sequence();
    //test_find_sequence_dic();
    test_find_sequence_better();
    return 0;
}
//END MAIN













