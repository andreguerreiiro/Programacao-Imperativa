#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#define MAX_FLIGHTS 10000
#define MAX_LINE_LENGTH 10000

typedef int(*Flight_cmp)(Flight, Flight);

char *str_dup(const char *s){
    char *result = (char*) malloc(strlen(s) + 1);
    strcpy(result, s);
    return result;
}

typedef struct {
	const char *code;
	const char *destination;
	int departure;
} Flight; 

Flight flight(const char *code, const char *destination, int departure){
	Flight result;
	result.code = code;
	result.destination = destination;
	result.departure = departure;
	return result;
}

int flights_read(FILE *f, Flight *a){
	int result = 0;
	char code[16];
	char destination[64];
	int departure;
	while (fscanf(f, "%d%s%s", &departure, code, destination) != EOF)
		a[result++] = flight(str_dup(code), str_dup(destination), departure);
	return result;
}

void flights_write(FILE *f, Flight *a, int n){
	for (int i = 0; i < n; i++)
		fprintf(f, "[%d][%s][%s]\n",
			a[i].departure, a[i].code, a[i].destination);
}

void test_flights_read_write(void){
	FILE *f = fopen("partidas_faro.txt", "r");
	assert(f != NULL);
	Flight flights[MAX_FLIGHTS];
	int n_flights = flights_read(f, flights);
	flights_write(stdout, flights, n_flights);
}

int flights_find_to_destination(Flight *a, int n, char *destination, int *b){
	int result = 0;
	for (int i = 0; i < n; i++)
		if (strcmp(a[i].destination, destination) == 0)
			b[result++] = i;
	return result;
} 

void flights_write_some(FILE *f, Flight *a, int *b, int n){
	for (int i = 0; i < n; i++)
		fprintf(f, "[%d][%s][%s]\n",
			a[b[i]].departure, a[b[i]].code, a[b[i]].destination);
}

void test_flight_flights_find_to_destination(void){
	FILE *f = fopen("partidas_lisboa.txt", "r");
	assert(f != NULL);
	Flight flights[MAX_FLIGHTS];
	int n_flights = flights_read(f, flights);
	char line[MAX_LINE_LENGTH];
	while (scanf("%s", line) != EOF){
		int b[n_flights];
		int n = flights_find_to_destination(flights, n_flights, line, b);
		flights_write_some(stdout, flights, b, n);
	}
}

void test_flights_read_write_better(char *filename){
	FILE *f = fopen(filename, "r");
	assert(f != NULL);
	Flight flights[MAX_FLIGHTS];
	int n_flights = flights_read(f, flights);
	char line[MAX_LINE_LENGTH];
	while (scanf("%s", line) != EOF){
		int b[n_flights];
		int n = flights_find_to_destination(flights, n_flights, line, b);
		flights_write_some(stdout, flights, b, n);
	}
}

void test_flight_flights_find_to_destination_better(char *filename){
	FILE *f = fopen(filename, "r");
	assert(f != NULL);
	Flight flights[MAX_FLIGHTS];
	int n_flights = flights_read(f, flights);
	char line[MAX_LINE_LENGTH];
	while (scanf("%s", line) != EOF){
		int b[n_flights];
		int n = flights_find_to_destination(flights, n_flights, line, b);
		flights_write_some(stdout, flights, b, n);
	}
}

void flights_exchange(Flight *a, int x, int y){
	Flight m = a[x];
	a[x] = a[y];
	a[y] = m;
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

// int flight_cmp_by_destination(Flight x, Flight y){
// 	int result = strcmp(x.destination, y.destination);
// 	if (result == 0)
// 		result = strcmp(x.code, y.code);
// 	return result;
// }

// int flight_cmp_by_code(Flight x, Flight y){
// 	return strcmp(x.code, y.code);
// }

// void test_flights_isort_gen(char *filename, Flight_cmp cmp){
// 	FILE *f = fopen(filename, "r");
// 	assert(f != NULL);
// 	Flight flights[MAX_FLIGHTS];
// 	int n_flights = flights_read(f, flights);
// 	flights_isort_gen(flights, n_flights, cmp);
// 	flights_write(stdout, flights, n_flights);
// } 

/*int main(int argc, char **argv)
{
 char x = 'A';
 char *filename = "partidas_faro.txt";
 if (argc > 1)
 x = *argv[1];
 if (x == 'A')
 test_flights_read_write();
 else if (x == 'B')
 test_flight_flights_find_to_destination();
 else if (x == 'C')
 test_flights_read_write_better(argc > 2 ? argv[2] : filename);
 else if (x == 'D')
 test_flight_flights_find_to_destination_better
 (argc > 2 ? argv[2] : filename);
 else
 printf("%c Invalid option.\n", x);
 return 0;
} */

int main(int argc, char **argv){
	char x = 'A';
	char *filename = "partidas_faro.txt";
	if (argc > 1)
		x = *argv[1];
	if (x == 'A')
		test_flights_read_write();
	else if (x == 'B')
		test_flight_flights_find_to_destination();
	else if (x == 'C')
		test_flights_read_write_better(argc > 2 ? argv[2] : filename);
	else if (x == 'D')
		test_flight_flights_find_to_destination_better(argc > 2 ? argv[2] : filename);
	// else if (x == 'E')
	// 	test_flights_isort_gen(argc > 2 ? argv[2] : filename);
	else
		printf("%c Invalid option.\n", x);
	return 0;
