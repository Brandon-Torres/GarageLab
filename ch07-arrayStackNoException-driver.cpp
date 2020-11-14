#pragma once
#include <iostream>
#include <string>
#include "ArrayStack.h"
#include "Car.h"
#include "Garage.h"
#include <fstream>
using namespace std;

void stackTester(Garage& garageClone,char car_Action_Doing, string license_Plate)
{
		
	switch(car_Action_Doing)
	{
	case 'A':
		//car arriving so add the car to the lane
		garageClone.add_Car(license_Plate);
		 break;
	case 'D':
		garageClone.remove_Car(license_Plate);
		 break;
	}

}  // end stackTester

int main()
{

	cout << "Testing the Array-Based Stack:" <<endl;

	ifstream inFile;
	inFile.open("TextFile1.txt");
	string license;
	char action;
	//create a Garage
	Garage controller;

	while (!inFile.eof())
	{
		//read in car action doing and license plate number
		inFile >> action >> license;
		//send the garage created and details of car that just came in
		stackTester(controller,action, license);
	}
	//print total number of times Cars moved
	controller.print();

	inFile.close();

	system("PAUSE");
   return 0;
}  // end main
