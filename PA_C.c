#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_FLIGHTS 10000


/* ----------- Estrutura de voos ----------------- */

typedef struct{
  const char *destination;
  int frequencia;
} Voos;

typedef struct {
  const char *code;
  const char *destination;
  int departure;
} Flight;

Flight flight(const char *code, const char *destination, int departure)
{
  Flight result;
  result.code = code;
  result.destination = destination;
  result.departure = departure;
  return result;
}

/* ----------- Leitura de ficheiro de Voos --------------- */

char *str_dup(const char *s)
{
  char *result = (char *) malloc(strlen(s) + 1);
  strcpy(result, s);
  return result;
}

int flights_read(FILE *f, Flight *a)
{
  int result = 0;
  char code[16];
  char destination[64];
  int departure;
  while (fscanf(f, "%d%s%s", &departure, code, destination) != EOF)
    a[result++] = flight(str_dup(code), str_dup(destination), departure);
  return result;
}

/* ----------- Impressao de Array de voos ----------------- */

void flights_write(FILE *f, Flight *a, int n){
  for (int i = 0; i < n; i++)
    fprintf(f, "[%d][%s][%s]\n", a[i].departure, a[i].code, a[i].destination);
}

void voos_print(FILE *f, Voos *a, int n){
  for (int i = 0; i < n; i++)
    fprintf(f, "%s %d\n", a[i].destination, a[i].frequencia);
}

/* ----------- Ordenacao de Array de voos por destino ----------------- */

void flights_exchange(Flight *a, int x, int y)
{
  Flight m = a[x];
  a[x] = a[y];
  a[y] = m;
}

typedef int(*Flight_cmp)(Flight, Flight);

int flight_cmp_by_destination_departure(Flight x, Flight y)
{
  int result = strcmp(x.destination, y.destination);
  if (result == 0)
    result = y.departure - x.departure;
  return result;
}

int flight_cmp_by_code(Flight x, Flight y){
  return strcmp(x.code, y.code);
}

void flights_isort_gen(Flight *a, int n, Flight_cmp cmp){
  for (int i = 1; i < n; i++){
    int j = i;
    while (j > 0 && cmp(a[j-1], a[j]) > 0){
      flights_exchange(a, j-1, j);
      j--;
    }
  }
}

/* ----------- Problema C ----------------- */


Voos voos(const char *destination, int frequencia){
	Voos result;
	result.destination = destination;
	result.frequencia = frequencia;
	return result;
}

int flight_count_while_equal(Flight *a, int n){
  int result = 0;
  while (result < n && strcmp(a[0].destination, a[result].destination) == 0){
    result++;
  }
  return result;
}

int destinos_mais_frequentes(Flight *a, int n, Voos *b){
  int result = 0,
    i = 0,
    x = 0
  ;
  while ( i < n){ 
    x = flight_count_while_equal(a + i , n - i);
    b[result++] = voos(a[i].destination, x);
    if( x > 0){
      i += x;
    }
  }
  return result;
}

typedef int(*Flight_cmp_d)(Voos, Voos);

void flights_exchange_dest(Voos *a, int x, int y)
{
  Voos m = a[x];
  a[x] = a[y];
  a[y] = m;
}

int flight_cmp_by_freq_cidade(Voos x, Voos y){
  int result = y.frequencia - x.frequencia;
  // if (result == 0)
  //   result = y.destination - x.destination;   //????????????????
  return result;
}

void flights_isort_d(Voos *a, int n, Flight_cmp_d cmp){
  for (int i = 1; i < n; i++){
    int j = i;
    while (j > 0 && cmp(a[j-1], a[j]) > 0){
      flights_exchange_dest(a, j-1, j);
      j--;
    }
  }
}


void test_destinos_mais_frequentes(char *filename){
  FILE *f = fopen(filename, "r");
  assert(f != NULL);
  Flight flights[MAX_FLIGHTS];
  int n_flights = flights_read(f, flights);
  flights_isort_gen(flights, n_flights, flight_cmp_by_destination_departure);
  //flights_write(stdout, flights, n_flights);
  Voos arr1[MAX_FLIGHTS];
  int n_new = destinos_mais_frequentes(flights, n_flights, arr1);
  flights_isort_d(arr1, n_new, flight_cmp_by_freq_cidade);
  voos_print(stdout, arr1, n_new);
}

int main(int argc, char* argv[]){
  test_destinos_mais_frequentes(argv[1]);
  return 0;
}
