#include "PointTwoD.h"
#include <string>

//constructor without parameter
PointTwoD::PointTwoD(){
	x = 0;
	y = 0;
	civIndex = 0.0;
}

//constructor with parameter
PointTwoD::PointTwoD(int x_cord, int y_cord, LocationData locData){
	x = x_cord;
	y = y_cord;
	locationData = locData;
}

//getter for x-ordinate
int PointTwoD::getX(){
	return x;
}

//getter for y-ordinate
int PointTwoD::getY(){
	return y;
}

//getter for locationData
LocationData PointTwoD::getLocationData(){
	return locationData;
}

//getter for civIndex
float PointTwoD::getCivIndex(){
	return civIndex;	
}

//setter for x-ordinate
void PointTwoD::setX(int x_cord){
	x = x_cord;
}

//setter for y-ordinate
void PointTwoD::setY(int y_cord){
	y = y_cord;
}

//setter for locationData
void PointTwoD::setLocationData(LocationData locData){
	locationData = locData;
}

//setter for civIndex
void PointTwoD::setCivIndex(int c_index){
	civIndex = c_index;
}

//function for calculating Civ Index by calling static function of class LocationData
void PointTwoD::calcCivIndex(){
	civIndex = LocationData::computeCivIndex(locationData.sunType, locationData.noOfEarthLikePlanets, locationData.noOfEarthLikeMoons, locationData.aveParticulateDensity, locationData.avePlasmaDensity);
}

//returns a String, containing the name of each attribute and its value respectively
string PointTwoD::toString(){
	return "x: "+to_string(x)+",\ny: "+to_string(y)+",\n"+locationData.toString()+",\nCivIndex: "+to_string(civIndex);
}