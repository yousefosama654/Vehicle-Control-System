#include <stdio.h>
#include "vehicle.h"
int main()
{
	vehicle car = { OFF,OFF,OFF,0,0,0 };
	printf("%s", "\n\n\n\t\t\t\t\tHello to my program---> >> \n");
	display_list(&car);
/*
 *	lesson I have learned :
 *	1-to pass struct by ref U must use pointer to the struct.
 *	2-if you wanna escape white space Error use scanf(" %c",..).
 *	3-to convert enum to string U must use function and switch.
 *	4-use typedef in the struct,union,enum and other naming to.
 *	5-to show n digits after decimal use (.nf).
 *	6-to exit a program from a function use exit(0) in stdlib;
 */
	return 0;
}


