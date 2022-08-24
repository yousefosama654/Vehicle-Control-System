#include<stdio.h>
#include <stdlib.h>
#include "vehicle.h"
// function definition start
void setTrafficColor(vehicle* car)
{
	char user_choice_control;
	printf("What is the traffic color sir ? \n");
	printf("\ta-Red.\n");
	printf("\tb-Orange.\n");
	printf("\tc-Green.\n");
	scanf_s(" %c", &user_choice_control);
	switch (user_choice_control)
	{
	case 'a':
		car->speed = 0;
		break;
	case 'b':
		car->speed = 30;
		break;
	case 'c':
		car->speed = 100;
		break;
	default:
		car->speed = -1;
		break;
	}
	display_menu(car);
	return;
}
void setRoomTemp(vehicle* car)
{
	snit32 input_temp;
	// local var in the function stack
	printf("Enter the room temperature sir..\n");
	scanf_s("%d", &input_temp);
	if (input_temp < 10 || input_temp > 30)
	{
		car->AC_state = ON;
		car->room_temp = 20;
	}
	else
	{
		car->AC_state = OFF;
	}
	display_menu(car);
	return;
}
void setEngineTemp(vehicle* car)
{
	snit32 input_temp;
	printf("Enter the engine temperature sir..\n");
	scanf_s("%d", &input_temp);
	if (input_temp < 100 || input_temp>150)
	{
		car->Engine_Temperature_Controller = ON;
		car->engine_temp = 125;
	}
	else
	{
		car->Engine_Temperature_Controller = OFF;
	}
	display_menu(car);
	return;
}
void checkSpeed(vehicle* car)
{
	if (car->speed == 30)
	{
		if (car->AC_state == OFF)
		{
			car->AC_state = ON;
			car->room_temp = (5.0 / 4) * car->room_temp + 1;
		}
		if (car->Engine_Temperature_Controller == OFF)
		{
			car->Engine_Temperature_Controller = ON;
			car->engine_temp = (5.0 / 4) * car->engine_temp + 1;
		}
	}
	return;
}
char* transfer(state a)
{
	switch (a)
	{
	case OFF:
		return "OFF";
		break;
	case ON:
		return "ON";
		break;
	default:
		return "Undefined";
		break;
	}
}
void display_system(vehicle* car)
{
	printf("The Engine State is %s\n", transfer(car->engine_state));
	printf("The AC State is %s\n", transfer(car->AC_state));
	printf("The Engine Temperature Controller is %s\n", transfer(car->Engine_Temperature_Controller));
	printf("The Vehicle  Speed is %d\n", car->speed);
	printf("The Room Temperature is %.2f\n", car->room_temp);
	printf("The Engine Temperature is %.2f\n", car->engine_temp);
	return;
}
void Quit_system(vehicle* car)
{
	display_system(car);
	printf("\nthe system is OFF\n");
	exit(0);
}
void display_list(vehicle* car)
{
	char user_choice_control;
	do
	{
		printf("\nwhat you want to do sir ?? \n");
		printf("\ta.turn on the vehicle engine\n");
		printf("\tb.turn off the vehicle engine\n");
		printf("\tc.quit the system\n");
		scanf_s(" %c", &user_choice_control);
	} while (user_choice_control == 'b');
	if (user_choice_control == 'c')
	{
		Quit_system(car);
	}
	else if (user_choice_control == 'a')
	{
		display_menu(car);
	}
}
void display_menu(vehicle* car)
{
	checkSpeed(car);
	display_system(car);
	char user_choice_control;
	printf("Here is the menu sir... \n");
	printf("\ta-turn off the engine.\n");
	printf("\tb-Set the traffic light color.\n");
	printf("\tc-Set the room temperature.\n");
	printf("\td-Set the engine temperature.\n");
	scanf_s(" %c", &user_choice_control);
	switch (user_choice_control)
	{
	case'a':
		display_list(car);
		break;
	case 'b':
		setTrafficColor(car);
		break;
	case 'c':
		setRoomTemp(car);
		break;
	case 'd':
		setEngineTemp(car);
		break;
	default:
		printf("please enter a valid choice\n");
	}
	return;
}
// function definition end