/*  
 * @author : Gökhan Özeloğlu
 *
 * @date : 8.9.2018
 *
 * @code : Variadic Function implementation
 *
 * @email : gozeloglu@gmail.com
 *  */


#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_INT_VALUE -2147483648
#define MAX_INT_VALUE 2147483647
#define MIN_ELEMENT 1
#define MAX_ELEMENT 100


/* 
 * Takes the indefinite size arity and a variable number of arguments as a parameter.
 * Finds the summation of the numbers with using stdarg.h libraries's functiions. 
 * */
int sum(int count, ...) {
	va_list argument_pointer;
	va_start(argument_pointer, count);

	int total = 0;

	for (int i = 0 ; i < count ; i++) {
		total += va_arg(argument_pointer, int);
	}
	va_end(argument_pointer);

	return total;
}

int find_max(int count, ...) {
	va_list argument_pointer;
	va_start(argument_pointer, count);
	
	int highest_value = MIN_INT_VALUE;
	for (int i = 0 ; i < count ; i++) {
		int tmp = va_arg(argument_pointer, int);
		if (tmp > highest_value) {
			highest_value = tmp;
		}
	}
	va_end(argument_pointer);

	return highest_value;
}

int find_min(int count, ...) {
	va_list argument_pointer;
	va_start(argument_pointer, count);

	int lowest_value = MAX_INT_VALUE;
	for (int i = 0 ; i < count ; i++) {
		int tmp = va_arg(argument_pointer, int);
		if (tmp < lowest_value) {
			lowest_value = tmp;				
		}	
	}
	va_end(argument_pointer);

	return lowest_value;
}


/* 
 * Sends the five random numbers to variadic functions.
 *
 * */
void send_five_parameters() {
	int i = 0;
	int array[5];

	array[0] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
	array[1] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
	array[2] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
	array[3] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
	array[4] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;

	while (i < 5) {
		printf("Number %d : %d\n", (i), array[i++]);
	}
	printf("Sum of the number: %d\n", sum(5, array[0], array[1], array[2], array[3], array[4]));
	printf("Maximum value of the array: %d\n", find_max(5, array[0], array[1], array[2], array[3], array[4], array[5]));
	printf("Minimum value of the array: %d\n", find_min(5, array[0], array[1], array[2], array[3], array[4], array[5]));
}

/* 
 * Sends the three random numbers to variadic functions.
 * */
void send_three_parameters() {
	int i = 0;
	int array[3];

	array[0] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
	array[1] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
	array[2] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
	
	while (i < 3) {
		printf("Number %d : %d\n", (i) , array[i++]);
	}

	printf("Sum of the numbers: %d\n", sum(3, array[0], array[1], array[2]));
	printf("Maximum value of the array: %d\n", find_max(3, array[0], array[1], array[2]));
	printf("Minimum value of the array: %d\n", find_min(3, array[0], array[1], array[2]));
}

int main(int argc, char const *argv[]) {
	send_five_parameters();
	send_three_parameters();
}
