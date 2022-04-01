#include<stdio.h>
#include<stdbool.h>
#include<Windows.h>
#include"vech_struct.h"
void start_system(state* vech);
void update_system(state* p);
void back_to_menu(state* vech, int n);
void quit_system(state* vech);
// assuming that the menu will be read by my sorting
void set_traffic_light(state* p)
{
	char light;
		printf("--->>>please enter the traffic light INFO--->>>\n");
		do
		{
			printf("O---Orange---\n");
			printf("R---Red---\n");
			printf("G---Green---\n");
			scanf_s(" %c",&light);

		} while (light != 'g' && light != 'o' && light != 'r');
		if (light == 'o')
			p->Vehicle_speed = 30;
		else if (light == 'g')
			p->Vehicle_speed = 100;
		else if (light == 'r')
			p->Vehicle_speed = 0;
		else
			p->Vehicle_speed = 2121212121;
		back_to_menu(p, 2);
}
void update_system(state* p)
{

	if(p->Vehicle_speed==30)
	{ 
	if (!p->AC_state)
	{
		p->AC_state = 1;
		p->Room_temperature = (5 / 4.0) * (p->Room_temperature) + 1;
	}
	if (!p->Engine_Temperature_Controller_State)
	{
		p->Engine_Temperature_Controller_State = 1;
		p->Engine_Temperature = (5 / 4.0) * (p->Engine_Temperature) + 1;
	}

	}

}
void set_room_temp(state* p)
{

	int temp;
	printf("please enter the room temperature INFO\n");
	scanf_s("%d", &temp);
	if (temp < 10 || temp>30)
	{
		p->AC_state = 1;
		p->Room_temperature = 20;
	}
	else
	{
		p->AC_state = 0;
		p->Room_temperature=temp;
	}
		back_to_menu(p,3);
}
void set_engine_temperature(state* p)
{
	int temp;
	printf("Please Enter The Engine Temperature INFO\n");
	scanf_s("%d", &temp);
	if (temp < 100 || temp>150)
	{
		p->Engine_Temperature_Controller_State = 1;
		p->Engine_Temperature = 125;
	}
	else
	{
		p->Engine_Temperature_Controller_State = 0;
		p->Engine_Temperature=temp;
	}
}
char* transfer(bool x)
{
	char *on = "ON";
	char* off = "OFF";
	return  x ? on: off ;
}
void printstate( state *vec)
{
	printf("--->>>here is the state of your vehicle--->>>\n");
	printf("the Engine State is = %s \n ", transfer(vec->Engine_state));
	printf("the AC State is = %s \n ", transfer(vec->AC_state));
	printf("the Engine Temperature Controller State is = %s \n ", transfer(vec->Engine_Temperature_Controller_State));
	printf("the Engine Temperature is = %d \n ", vec->Engine_Temperature);
	printf("the  Temperature is = %d \n ",vec->Room_temperature);
	printf("the vehicle Speed is = %d \n ",vec->Vehicle_speed);
}
void back_to_menu(state* vech, int n)
{

	if (n == 2)
	{
		char sel;
		printf("---->>>>sensors set menu------>>>>>\n");
		printf("a.Turn off the engine \n");
		printf("c.Set the room temperature(Temperature Sensor) \n");
		printf("d.Set the engine temperature(Engine Temperature Sensor) \n");
		scanf_s(" %c", &sel);
		switch (sel)
		{
		case'a':
			start_system(vech);
			break;
		case'c':
			set_room_temp(vech);
			break;
		case'd':
			set_engine_temperature(vech);
			break;
		}
	}
	if(n==3)
	{
		char sel;
		printf("---->>>>sensors set menu------>>>>>\n");
		printf("a.Turn off the engine \n");
		printf("d.Set the engine temperature(Engine Temperature Sensor ) \n");
		scanf_s(" %c", &sel);
		switch (sel)
		{
		case'a':
			start_system(vech);
			break;
		case'd':
			set_engine_temperature(vech);
			break;
		}

	}

}
void selector_Func(state* vech)
{
	// back to menu with a default value
	char sel;
	printf("---->>>>sensors set menu------>>>>>\n");
	printf("a.Turn off the engine \n");
	printf("b.Set the traffic light color \n");
	printf("c.Set the room temperature(Temperature Sensor) \n");
	printf("d.Set the engine temperature(Engine Temperature Sensor) \n");
	scanf_s(" %c",&sel);
	switch (sel)
	{
	case'a':
		start_system(vech);
		break;
	case'b':
		set_traffic_light(vech);
		break;
	case'c':
		set_room_temp(vech);
		break;
	case'd':
		set_engine_temperature(vech);
		break;
	default:
		start_system(vech);
	}
	
}
void start_system(state*vech)
{

	char asking ;
	printf("%s", "--->>>hello to my program--->>>\n");
	do
	{
		printf("--->>>what you want to do sir --->>> \n");
		printf("a.turn on the vehicle engine\n");
		printf("b.turn off the vehicle engine\n");
		printf("c.quit the system\n");
		scanf_s(" %c", &asking);
	} 
	while (asking == 'b');
	if (asking == 'a')
	{
		printf("the vehicle engine is on rightnow\n");
		PlaySound(TEXT("song"), NULL, SND_SYNC);
		vech->Engine_state = 1;
		printstate(vech);
		selector_Func(vech);
	}
	else if (asking == 'c')
		quit_system(vech);
}
void quit_system(state *vech)
{
	vech->Engine_state = 0;
	printf("Quit the sysytem --->>>\n");
	PlaySound(TEXT("carstop"), NULL, SND_SYNC);
	printstate(vech);
	exit(0);
}
int main()
{
	 state vech = {0,0,0,0,0,0};
	 start_system(&vech);
	 update_system(&vech);
	 printstate(&vech);
	return 0;
}