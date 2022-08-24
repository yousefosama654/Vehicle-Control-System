#pragma once
typedef enum { false, true }bool;
typedef enum { OFF, ON }state;
typedef  int snit32;
typedef float float32;
typedef struct {
	state engine_state;
	state AC_state;
	state Engine_Temperature_Controller;
	snit32 speed;
	float32 room_temp;
	float32 engine_temp;
}vehicle;