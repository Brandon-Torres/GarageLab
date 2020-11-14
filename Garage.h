#pragma once
#ifndef GARAGE
#define GARAGE
#include <iostream>
#include "Car.h"
#include "ArrayStack.h"
#include "StackInterface.h"

using namespace std;

class Garage
{
private:
	//pointers to represent the lanes and street
	ArrayStack<Car> *lane1;
	ArrayStack<Car> *lane2;
	ArrayStack<Car> *street;
	//pointer to point to each lane and manage the adding and removing 
	ArrayStack<Car> *section_Pointer = NULL;

public:
	Garage();
	void add_Car(string );
	void remove_Car(string);
	void print();
};
Garage::Garage()
{
	lane1 = new ArrayStack<Car>();
	lane2 = new ArrayStack<Car>();
	street = new ArrayStack<Car>();
}
//pass the car arriving license info to the Garage to add car into lane
void Garage::add_Car(string license_Plate)
{
	//create a new car object to hold new cars information
	Car newCar;
	//give newCar coming into garages license number
	newCar.set_License(license_Plate);
	//assign a universal pointer to point to lane1 to try to push car on stack
	section_Pointer = lane1;
	//push new car into lanes
	cout << "Pushing " << newCar.get_License() << endl;
	//lane1 push
	bool success = section_Pointer->push(newCar);
	//if car successfully added to lane1 get out 
	if (success)
	{
		cout << "Successfully pushed " << newCar.get_License() << " onto lane1 " << endl;
		return;
	}
	//if first lane no room, point to second lane and push there
	section_Pointer = lane2;
	//lane2 push 
	success = section_Pointer->push(newCar);
	//if car successfully added to lane2 get out 
	if (success)
	{
		cout << "Successfully pushed " << newCar.get_License() << " onto lane2 " << endl;
		return;
	}
	//if both lanes are full dismiss car
	cout << "Failed to push " << newCar.get_License() << " onto lane1 and lane2 no room " << endl;
}
void Garage::remove_Car(string license_Num)
{
	//point to first lane
	section_Pointer = lane1;
	//make success false assuming we find it we switch to true 
	bool success = false;
	//pop cars off lane1 until find license
	while (!section_Pointer->isEmpty())
	{
		//create a car object to temporarly hold and compare license removing
		Car viewCar = section_Pointer->peek();
		if (viewCar.get_License() == license_Num)
		{
			//if found pop off and get out 
			section_Pointer->pop();
			cout << "Car successfully left" << endl;
			success = true;
				break;
		}
		else 
		{
			viewCar.set_Moves();	//increase moves by 1
			street->push(viewCar);
			section_Pointer->pop();
			cout << "Car successfully pushed to street" << endl;
			cout << "Total number of times car moved: " << viewCar.get_Moves();
		}
			
	}

	//put all the cars back into lane1
	while(!street->isEmpty())
	{
		lane1->push(street->peek());
		street->pop();
		cout << "Car successfully pushed back into lane 1 " << endl;
	}

	if (success)
		return;

	// point to first lane
		section_Pointer = lane2;
	//pop cars off lane1 until find license
	while (!section_Pointer->isEmpty())
	{
		Car viewCar = section_Pointer->peek();
		if (viewCar.get_License() == license_Num)
		{
			//if found pop off and get out 
			section_Pointer->pop();
			cout << "Car successfully left" << endl;
			success = true;
			break;
		}
		else
		{
			viewCar.set_Moves();//increase moves by 1
			street->push(viewCar);
			section_Pointer->pop();
			cout << "Car successfully pushed to street " << endl;
			cout << "Total number of times car moved: " << viewCar.get_Moves();
		}
	}

	//put all the cars back into lane2
	while (!street->isEmpty())
	{
		Car car = street->peek();
		car.set_Moves(); //increase moves by 1 
		lane2->push(car);
		street->pop();
		cout << "Car successfully pushed into lane 2 " << endl;
		cout << "Total number of times car moved: " << car.get_Moves();
	}

}
void Garage::print()
{

	while (!lane1->isEmpty())
	{
		Car car_Printer = lane1->peek();
		lane1->pop();
		cout << "Car " << car_Printer.get_License() << "moved: " << car_Printer.get_Moves() << endl;
	}

	while (!lane2->isEmpty())
	{
		Car car_Printer = lane2->peek();
		lane2->pop();
		cout << "Car " << car_Printer.get_License() << "moved: " << car_Printer.get_Moves() << endl;
	}

}
#endif