#pragma config(Sensor, in1,    rightLifterd,   sensorPotentiometer)
#pragma config(Sensor, in2,    leftLifterd,    sensorPotentiometer)
#pragma config(Motor,  port2,           lefttopMotor,  tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port3,           leftbotMotor,  tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port4,           righttopMotor, tmotorVex393, openLoop)
#pragma config(Motor,  port5,           rightbotMotor, tmotorVex393, openLoop)
#pragma config(Motor,  port6,           rightLifer,    tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port7,           leftLifter,    tmotorVex393, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"		//Main competition background code...do not modify!

int drivingThreshhold = 10;
int RpotLevel = SensorValue[rightLifterd];
int LpotLevel = SensorValue[leftLifterd];
void driveMotors();
void checkPot();
void strafe();
void lifter();


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
	AutonomousCodePlaceholderForTesting();	// Remove this function call once you have "real" code.
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
	while (true)
	{
		driveMotors();
		strafe();
		lifter();
		checkPot();
	}

}


void driveMotors()
{

	// Left Wheels
	if (abs(vexRT(Ch3)) > drivingThreshhold)
	{
		motor[lefttopMotor] = vexRT(Ch3) * 10; // Decrease the number to make the motor faster
		motor[leftbotMotor] = vexRT(Ch3) * 10; // Decrease the number to make the motor faster
	}
	else
	{
		motor[lefttopMotor] = 0; // If the joystick's value is below the driving threshhold, turn the motor off
		motor[leftbotMotor] = 0; // If the joystick's value is below the driving threshhold, turn the motor off
	}


	// Right Wheels
	if (abs(vexRT(Ch2)) > drivingThreshhold)
	{
		motor[righttopMotor] = vexRT(Ch2) * 10; // Decrease the number to make the motor faster
		motor[rightbotMotor] = vexRT(Ch2) * 10; // Decrease the number to make the motor faster
	}
	else
	{
		motor[righttopMotor] = 0; // If the joystick's value is below the driving threshhold, turn the motor off
		motor[leftbotMotor] = 0; // If the joystick's value is below the driving threshhold, turn the motor off
	}
}

void strafe()
{

	if ((abs(vexRT(Ch1)) > drivingThreshhold)
	{
		motor[righttopMotor] = vexRT(Ch1) * 10;
		motor[leftbotMotor] = vexRT(Ch1) * 10;
		motor[rightbotMotor] = - (vexRT(Ch1)) * 10;
		motor[lefttopMotor] = - (vexRT(Ch1)) * 10;
	}
	if ((abs(vexRT(Ch1)) < - (drivingThreshhold))
	{
		motor[rightbotMotor] = vexRT(Ch1) * 10;
		motor[lefttopMotor] = vexRT(Ch1) * 10;
		motor[righttopMotor] = - (vexRT(Ch1)) * 10;
		motor[leftbotMotor] = - (vexRT(Ch1)) * 10;
	}
	else
	{
		motor[righttopMotor] = 0;
		motor[leftbotMotor] = 0;
		motor[rightbotMotor] = 0;
		motor[lefttopMotor] = 0;

}
}
void lifter()
{
	if (vexRT(Btn5U) == 1)
	{
		if (RpotLevel > 0 || LpotLevel < 63)
		{
			motor[leftLifter] = 50;
			motor[rightLifer] = 50;
			checkPot();
		}
		else
		{
			motor[leftLifter] = 0;
			motor[rightLifer] = 0;
		}
	}

		if (vexRT(Btn6U) == 1)
		{
			if (RpotLevel < 60 || LpotLevel > 0)
			{
				motor[leftLifter] = -50;
				motor[rightLifer] = -50;
				checkPot();
			}
			else
			{
				motor[leftLifter] = 0;
				motor[rightLifer] = 0;
			}
		}
	}


void checkPot()
{
	RpotLevel = SensorValue[rightLifterd];
	LpotLevel = SensorValue[leftLifterd];
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

/*
if (vexRT(Btn5D) == 1)
{
motor[lefttopMotor] = -100;
motor[leftbotMotor] = 100;
motor[righttopMotor] = -100;
motor[rightbotMotor] = 100;
}
else
{
motor[lefttopMotor] = 0;
motor[leftbotMotor] = 0;
motor[righttopMotor] = 0;
motor[rightbotMotor] = 0;
}

if (vexRT(Btn6D) == 1)
{
motor[lefttopMotor] = 100;
motor[leftbotMotor] = -100;
motor[righttopMotor] = 100;
motor[rightbotMotor] = -100;
}
else
{
motor[lefttopMotor] = 0;
motor[leftbotMotor] = 0;
motor[righttopMotor] = 0;
motor[rightbotMotor] = 0;
}



if (vexRT(Btn5U) == 1)
{
motor[lifterrightMotor] = 0;
wait1Msec(500);
motor[lifterrightMotor] = 127;
wait1Msec(500);
}




void strafe()
{

	if (vexRT(Btn5D) == 1)
	{
		motor[lefttopMotor] = -75;
		motor[leftbotMotor] = 75;
		motor[righttopMotor] = -75;
		motor[rightbotMotor] = 75;
	}
	else if (vexRT(Btn6D) == 1)
	{
		motor[lefttopMotor] = 75;
		motor[leftbotMotor] = -75;
		motor[righttopMotor] = 75;
		motor[rightbotMotor] = -75;
	}
	else
	{
		motor[lefttopMotor] = 0;
		motor[leftbotMotor] = 0;
		motor[righttopMotor] = 0;
		motor[rightbotMotor] = 0;
	}

}
*/
