#pragma config(Sensor, in1,    arm_potentiometer, sensorPotentiometer)
#pragma config(Sensor, in2,    light_sensor,   sensorReflection)
#pragma config(Sensor, in6,    line_sensor_right, sensorLineFollower)
#pragma config(Sensor, in7,    line_sensor_center, sensorLineFollower)
#pragma config(Sensor, in8,    line_sensor_left, sensorLineFollower)
#pragma config(Sensor, dgtl1,  ultrasonicSonar, sensorSONAR_cm)
#pragma config(Sensor, dgtl3,  arm_limit,      sensorTouch)
#pragma config(Sensor, dgtl4,  emergency_button, sensorTouch)
#pragma config(Sensor, dgtl8,  left_encoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl10, right_encoder,  sensorQuadEncoder)
#pragma config(Motor,  port2,           right_motor,   tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port3,           left_motor,    tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port5,           arm_motor,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port7,           claw_motor,    tmotorServoContinuousRotation, openLoop)

#include "../headers/constants.c";
#include "../functions/motor_functions.c";
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*----------------------------------------------------------------------------------------------------*\
|*                                         - Verkefni 2 C -                                           *|
|*                                      ROBOTC on VEX 2.0 CORTEX                                      *|
|*                                                                                                    *|
|*  This program instructs your robot to move forward 0.5m, turn left 90 degrees, drive forward 0.5m, *|
|*  turn right 90 degrees, drive forward 0.5m, turn right 90 degrees and lastly drive forward 0.5m.		*|
|*		//   d = 4" or 2.54*45                                                                          *|
|*		//   d = 10.16                                                                                  *|
|*		//   Ummal_hj = d * Pi                                                                          *|
|*		//   Ummal_hj = 10.16 * 3.14 = 31.9                                                             *|
|*		//   Base_dist = 50cm/Umml_hj*360                                                               *|
|*		//   50/31.9*360 = 564.26*|                                                                     *|
\*----------------------------------------------------------------------------------------------------*/

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main(){
	reset_encoder();
	drive(BASEDIST,true);
	stop_motors();
	reset_encoder();
	wait1Msec(500);
	turn(90, true);
	stop_motors();
	reset_encoder();
	wait1Msec(500);
	for (int i=1;i<3;i++){
	drive(BASEDIST,true);
	stop_motors();
	reset_encoder();
	wait1Msec(500);
	turn(90, false);
	stop_motors();
	reset_encoder();
	wait1Msec(500);
	}
	drive(BASEDIST,true);
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
