//header for PointTwoD.cpp

#pragma once

#include "LocationData.h"
#include <string>
using namespace std;

//class declaration
class PointTwoD {
	private:
		int x;
		int y;
		LocationData locationData;
		float civIndex;
	public:
		//constructors
		PointTwoD();
		PointTwoD(int x_cord, int y_cord, LocationData locData);

		//Assessor (getter) functions
		int getX();
		int getY();
		LocationData getLocationData();
		float getCivIndex();

		//Mutator (setter) functions
		void setX(int x_cord);
		void setY(int y_cord);
		void setLocationData(LocationData locData);
		void setCivIndex(int c_index);

		//updating civ index
		void calcCivIndex();
		//String, containing the name of each attribute and its value respectively
		string toString();
};