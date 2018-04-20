
void drive(int dist,bool bf){
	int dir = (bf)? (1): (-1);
	while(dist > abs(SensorValue[right_encoder])){

		if(abs(SensorValue[right_encoder]) == abs(SensorValue[left_encoder]))
		{
			motor[right_motor] = 80*dir;
			motor[left_motor]  = 80*dir;
		}
		else if(abs(SensorValue[right_encoder]) > abs(SensorValue[left_encoder]))
		{
			motor[right_motor] = 60*dir;
			motor[left_motor]  = 80*dir;
		}

		else
		{
			motor[right_motor] = 80*dir;
			motor[left_motor]  = 60*dir;
		}
	}
}

void turn(int dist,bool bf){
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

void stop_arm(){
	motor[arm_motor]=0;
}

void stop_wait1sec(){
	stop_motors();
	wait1Msec(1000);
}
