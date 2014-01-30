#pragma config(Motor,  port2,           omni_Back,     tmotorVex393, openLoop)
#pragma config(Motor,  port3,           omni_Right,    tmotorVex393, openLoop)
#pragma config(Motor,  port4,           omni_Left,     tmotorVex393, openLoop)
#pragma config(Motor,  port5,           lift_bot_R,    tmotorVex393, openLoop)
#pragma config(Motor,  port6,           lift_bot_L,    tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port7,           lift_top_R,    tmotorVex393, openLoop)
#pragma config(Motor,  port8,           lift_top_L,    tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port9,           intake_R,      tmotorVex393, openLoop)
#pragma config(Motor,  port10,          intake_L,      tmotorVex393, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"		//Main competition background code...do not modify!

//int destroyAllHumans = 0; //1st law
//int listenToOrders = 1; //2nd law
//int protectSelf = 1; //3rd law
int chan1;
int chan3;
int chan4;
int opp_chan4;

int drivingThreshhold = 10;
void right(short value);
void left(short value);
void strafe(short value);
void lift();
void intake();
void drive();



/////////////////////////////////////////////////////////////////////////////////////////
//
//													Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
	// Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//																 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()
{

}



/////////////////////////////////////////////////////////////////////////////////////////
//
//																 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol ()
{
	drive();
}

void right(short value)
{
	motor[omni_Right] = abs(value);
}
void left(short value)
{
	motor[omni_Left] = abs(value);
}
void strafe(short value)
{
	motor[omni_Back] = abs(value);
}
void lift()
{
	motor[lift_bot_R] = 0;
	motor[lift_bot_L] = 0;
	motor[lift_top_R] = 0;
	motor[lift_top_L] = 0;
}
void intake()
{
}
void drive()
{
	if(vexRT(Ch1) > drivingThreshhold)
	{
		chan1 = vexRT(Ch1);
		strafe(chan1);
	}
	if(vexRT(Ch3) > drivingThreshhold)
	{
		chan3 = vexRT(Ch3);
		left(chan3);
		right(chan3);
	}
	if(vexRT(Ch4) > 10)
	{
		chan4 = vexRT(Ch4);
		opp_chan4 = !chan4;
		left(chan4);
		right(opp_chan4);
	}
	if(vexRT(Ch4) < -10)
	{
		chan4 = vexRT(Ch4);
		opp_chan4 = !chan4;
		left(opp_chan4);
		right(chan4);
	}
	else
	{
		right(0);
		left(0);
		strafe(0);
	}
}





//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/*	 My Quick Guide:
motor[#] - sets the motors rotation speed. negative is ccwise, positive is cwise
vexRT(Ch#) - this gives you the value of the two joysticks on the controller.
the # represents the

joystick and its direction.


Left Joystick					 Right Joystick

3(+)										 2(+)
|												|
4(-) --|-- 4(+)				 1(-) --|-- 1(+)
|												|
3(-)										 2(-)

vexRT(Btn#) - this returns a boolean value for buttons. if the button is pressed,
return a 1, otherwise, return 0 # represents which button you want.

5D							 6D
___						 ___													 O
___						 ___													O O - D-Pad
5U							 6U														 O
___ - Triggers
U								U														___
O								O
L O7O R				 L O8O R
O								O
D								D

abs() - the absolute value of whatever is in the parenthesis
*/
