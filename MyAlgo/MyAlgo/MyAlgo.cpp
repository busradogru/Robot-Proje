#include "MyAlgo.h"
#include <stdio.h>      
#include <stdlib.h>
bool __stdcall Algo1(int S, int L, int R, int Init, float& VL, float& VR) {

	float Output = PIDKontrolSistemi();

	if (Output <= -1) {
		VR = 1100 + Output * 10;
		VL = 1100 - Output * 10;
	}
	else if (Output >= 1) {
		VR = 1100 + Output * 10;
		VL = 1100 - Output * 10;
	}
	else {
		VR = 1100 + Output * 10;
		VL = 1100 - Output * 10;
	}
	if (VR > 127) {
		VR = 60;
	}
	else if (VR < 127)
		VR = 5;
	if (VL > 127)
		VL = 60;
	else if (VL < 127)
		VL = 5;
	return true;
}


bool  __stdcall Algo2(int S, int L, int R, int Init, int& VL, int& VR) {
	VL = 120;
	VR = 120;
	return true;
}
bool  __stdcall Algo3(int S, int L, int R, int Init, int& VL, int& VR) {
	VL = 120;
	VR = 120;
	return true;
}
bool  __stdcall Algo4(int S, int L, int R, int Init, int& VL, int& VR) {
	VL = 120;
	VR = 120;
	return true;
}
bool __stdcall Algo5(int S, int L, int R, int Init, int& VL, int& VR) {
	VL = 120;
	VR = 120;
	return true;

}
bool __stdcall Algo6(int S, int L, int R, int Init, int& VL, int& VR) {
	VL = 120;
	VR = 120;
	return true;
}
bool __stdcall Algo7(int S, int L, int R, int Init, int& VL, int& VR) {
	VL = 120;
	VR = 120;
	return true;
}


float PIDKontrolSistemi() {
	return 0.0;
}
unsigned long millis()
{
	return 0;
}


unsigned long lastTime;
double Input, Setpoint;
double errSum, lastErr;
double kp, ki, kd;
unsigned long now = millis();
void Compute() {

	Input = 922;
	/*How long since we last calculated*/

	double timeChange = (double)(now - lastTime);

	/*Compute all the working error variables*/
	double error = Setpoint - Input;
	errSum += (error * timeChange);
	double dErr = (error - lastErr) / timeChange;

	/*Compute PID Output*/
	static double Output;
	Output = kp * error + ki * errSum + kd * dErr;

	/*Remember some variables for next time*/
	lastErr = error;
	lastTime = now;


}
void SetTunings(double Kp, double Ki, double Kd)
{
	kp = Kp;
	ki = Ki;
	kd = Kd;

}

