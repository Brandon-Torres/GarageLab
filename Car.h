#pragma once
#ifndef CAR
#define CAR
#include <iostream>
using namespace std;

class Car
{
private:
	string license_Num;
	int add_Moves = 0;
	
public:
	void set_License(string);
	string get_License();
	void set_Moves();
	int get_Moves();
};
//set the drivers License to the car
void Car::set_License(string carID) 
{
	license_Num = carID;
}
//get the value of the drivers license
string Car::get_License()
{
	return license_Num;
}
void Car::set_Moves()
{
	add_Moves++;
}
int Car::get_Moves()
{
	return add_Moves;
}

#endif