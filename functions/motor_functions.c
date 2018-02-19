
void drive(int dist,bool bf){
	// ef bf = True, dir = 1, else, dir = -1
	int dir = (bf)? (1): (-1);
	while(dist > abs(SensorValue[right_encoder])){

		if(abs(SensorValue[right_encoder]) == abs(SensorValue[left_encoder])) // If right_encoder has counted the same amount as left_encoder:
		{
			// Move Forward
			motor[right_motor] = 80*dir;		    // Right Motor is run at power level 80
			motor[left_motor]  = 80*dir;		    // Left Motor is run at power level 80
		}
		else if(abs(SensorValue[right_encoder]) > abs(SensorValue[left_encoder]))	// If left_encoder has counted more encoder counts
		{
			// Turn slightly right
			motor[right_motor] = 60*dir;		    // Right Motor is run at power level 60
			motor[left_motor]  = 80*dir;		    // Left Motor is run at power level 80
		}
		else	// Only runs if left_encoder has counted more encoder counts
		{
			// Turn slightly left
			motor[right_motor] = 80*dir;		    // Right Motor is run at power level 80
			motor[left_motor]  = 60*dir;		    // Left Motor is run at power level 60
		}
	}
}

void turn(int dist,bool bf){
	int encoder_value = abs(SensorValue[right_encoder]) + abs(SensorValue[left_encoder]);
	while(dist*BASETURN > abs(SensorValue[right_encoder])){

		if(bf)
		{
			motor[right_motor] = 60;
			motor[left_motor]  = -60;
		}
		else
		{

			motor[right_motor] = -60;
			motor[left_motor]  = 60;
		}
	}
}

void reset_encoder(){
	SensorValue[right_encoder] = 0;
	SensorValue[left_encoder] = 0;
}
void stop_motors(){
	motor[right_motor]=0;
	motor[left_motor]=0;
	motor[claw_motor]=0;
	motor[arm_motor]=0;
}
