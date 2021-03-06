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
#pragma config(Motor,  port4,           arm_motor,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port7,           claw_motor,    tmotorServoContinuousRotation, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "../headers/constants.c";
#include "../functions/motor_functions.c";
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*----------------------------------------------------------------------------------------------------*\
|*                                         - Verkefni 5 -                                         		*|
|*                                      ROBOTC on VEX 2.0 CORTEX                                      *|
|*  This program uses the line sensors to follow a line.                                              *|
\*----------------------------------------------------------------------------------------------------*/

task emergency_stop(){
	while (SensorValue[emergency_button] == 0 || vexRT[Btn8U] == 1){
	}
	StopAllTasks();
}

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++

task main(){
	wait1Msec(10000);
	StartTask(emergency_stop);
  while(true)
  {
    if(SensorValue(line_sensor_right) > line_threshold)
    {
      motor[left_motor]  = power;
      motor[right_motor] = no_power;
    }
    if(SensorValue(line_sensor_center) > line_threshold)
    {
      motor[left_motor]  = power;
      motor[right_motor] = power;
    }
    if(SensorValue(line_sensor_left) > line_threshold)
    {
      motor[left_motor]  = no_power;
      motor[right_motor] = power;
    }
  }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
