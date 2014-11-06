#include <stdio.h>
#include <math.h>
#include <assert.h>
#define ANOS 7200
#define TEMPHW 30 /*temperatura minima para uma onda de calor */

int doubles_get(double *a) 
/* le os registos de temperatura diarios para um array */
{
	int result = 0;
	double x;
	while (scanf("%lf", &x) != EOF)
		a[result++] = x;
	return result;
}

int doubles_count_while_greater_or_equal(const double *a, int n, double x)
/* conta a o numero de dias em que a temperatura foi superior a x graus */
{
	int result = 0;
	while (result < n && a[result] >= x)
		result++;
	return result;
}


int count_heat_waves(double *a, int n, double x) 
/* conta o numero de vezes em que houve 3 dias ou mais seguidos com x ou mais graus */
{
	int result = 0, i = 0;
	while (i < n)
	{
		int hw = doubles_count_while_greater_or_equal(a + i, n, TEMPHW);
		if (hw >= 3)
		{
			i += hw;
			result ++;
		}
		i++;
	}
	return result;
}

void test_count_heat_waves(void)
{
	double arr1[ANOS];
	double x = TEMPHW;
	scanf("%lf", &x);	
	int n = doubles_get(arr1);
	printf("%d\n", count_heat_waves(arr1,n,x));
}


int main(void)
{
	test_count_heat_waves();
	return 0;
}#include <stdio.h>
#include <math.h>
#include <assert.h>
#define ANOS 7200
#define TEMPHW 30 /*temperatura minima para uma onda de calor */

int doubles_get(double *a) 
/* le os registos de temperatura diarios para um array */
{
	int result = 0;
	double x;
	while (scanf("%lf", &x) != EOF)
		a[result++] = x;
	return result;
}

int doubles_count_while_greater_or_equal(const double *a, int n, double x)
/* conta a o numero de dias em que a temperatura foi superior a x graus */
{
	int result = 0;
	while (result < n && a[result] >= x)
		result++;
	return result;
}


int count_heat_waves(double *a, int n, double x) 
/* conta o numero de vezes em que houve 3 dias ou mais seguidos com x ou mais graus */
{
	int result = 0, i = 0;
	while (i < n)
	{
		int hw = doubles_count_while_greater_or_equal(a + i, n, TEMPHW);
		if (hw >= 3)
		{
			i += hw;
			result ++;
		}
		i++;
	}
	return result;
}

void test_count_heat_waves(void)
{
	double arr1[ANOS];
	double x = TEMPHW;
	scanf("%lf", &x);	
	int n = doubles_get(arr1);
	printf("%d\n", count_heat_waves(arr1,n,x));
}


int main(void)
{
	test_count_heat_waves();
	return 0;
}#include <stdio.h>
#include <math.h>
#include <assert.h>
#define ANOS 7200
#define TEMPHW 30 /*temperatura minima para uma onda de calor */

int doubles_get(double *a) 
/* le os registos de temperatura diarios para um array */
{
	int result = 0;
	double x;
	while (scanf("%lf", &x) != EOF)
		a[result++] = x;
	return result;
}

int doubles_count_while_greater_or_equal(const double *a, int n, double x)
/* conta a o numero de dias em que a temperatura foi superior a x graus */
{
	int result = 0;
	while (result < n && a[result] >= x)
		result++;
	return result;
}


int count_heat_waves(double *a, int n, double x) 
/* conta o numero de vezes em que houve 3 dias ou mais seguidos com x ou mais graus */
{
	int result = 0, i = 0;
	while (i < n)
	{
		int hw = doubles_count_while_greater_or_equal(a + i, n, TEMPHW);
		if (hw >= 3)
		{
			i += hw;
			result ++;
		}
		i++;
	}
	return result;
}

void test_count_heat_waves(void)
{
	double arr1[ANOS];
	double x = TEMPHW;
	scanf("%lf", &x);	
	int n = doubles_get(arr1);
	printf("%d\n", count_heat_waves(arr1,n,x));
}


int main(void)
{
	test_count_heat_waves();
	return 0;
}
