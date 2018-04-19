#include "LocationData.h"
#include <string>
#include <string.h>

//Constructor Without parameters
LocationData::LocationData(){
	sunType = "";
	noOfEarthLikePlanets = 0;
	noOfEarthLikeMoons = 0;
	aveParticulateDensity = 0.0;
	avePlasmaDensity = 0.0;
}

//constructor with parameters
LocationData::LocationData(string sType, int noOfELP, int noOfELM, float aveParDen, float avePlaDen){
	sunType = sType;
	noOfEarthLikePlanets = noOfELP;
	noOfEarthLikeMoons = noOfELM;
	aveParticulateDensity = aveParDen;
	avePlasmaDensity = avePlaDen;
}

//getter for sunType
string LocationData::getSunType(){
	return sunType;
}

//getter for noOfEarthLikePlanets
int LocationData::getNoOfEarthLikePlanets(){
	return noOfEarthLikePlanets;
}

//getter for noOfEarthLikeMoons
int LocationData::getNoOfEarthLikeMoons(){
	return noOfEarthLikeMoons;
}

//getter for aveParticulateDensity
float LocationData::getAveParticulateDensity(){
	return aveParticulateDensity;
}

//getter for avePlasmaDensity
float LocationData::getAvePlasmaDensity(){
	return avePlasmaDensity;
}

//setter for sunType
void LocationData::setSunType(string sType){
	sunType = sType;
}

//setter for noOfEarthLikePlanets
void LocationData::setNoOfEarthLikePlanets(int noOfELP){
	noOfEarthLikePlanets = noOfELP;
}

//setter for noOfEarthLikeMoons
void LocationData::setNoOfEarthLikeMoons(int noOfELM){
	noOfEarthLikeMoons = noOfELM;
}

//setter for aveParticulateDensity
void LocationData::setAveParticulateDensity(float aveParDen){
	aveParticulateDensity = aveParDen;
}

//setter for avePlasmaDensity
void LocationData::setAvePlasmaDensity(float avePlaDen){
	avePlasmaDensity = avePlaDen;
}

//returns a String, containing the name of each attribute and its value respectively
string LocationData::toString(){
	return "sunType: "+sunType+",\nnoOfEarthLikePlanets: "+to_string(noOfEarthLikePlanets)+",\nnoOfEarthLikeMoons: "+to_string(noOfEarthLikeMoons)+",\naveParticulateDensity: "+to_string(aveParticulateDensity)+",\navePlasmaDensity: "+to_string(avePlasmaDensity);
}

//static function for computing civilization index
float LocationData::computeCivIndex(string sType, int noOfELP, int noOfELM, float aveParDen, float avePlaDen){
	int sunTypePercent = 0;
	if (strcmp(sType.c_str(), "Type O") == 0){
		sunTypePercent = 30;
	} else if(strcmp(sType.c_str(), "Type B") == 0){
		sunTypePercent = 45;
	} else if(strcmp(sType.c_str(), "Type A") == 0){
		sunTypePercent = 60;
	} else if(strcmp(sType.c_str(), "Type F") == 0){
		sunTypePercent = 75;
	} else if(strcmp(sType.c_str(), "Type G") == 0){
		sunTypePercent = 90;
	} else if(strcmp(sType.c_str(), "Type K") == 0){
		sunTypePercent = 80;
	} else if(strcmp(sType.c_str(), "Type M") == 0){
		sunTypePercent = 70;
	} else{
		cout << "[Error] SunType unknown." << endl;
	}

	//formula for civ.Index
	float civIndex = ((sunTypePercent/100.0)-((aveParDen+avePlaDen)/200.0))*(noOfELP+noOfELM);
	return civIndex;
}