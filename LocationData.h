//header for LocationData.cpp

#pragma once

#include <string>
using namespace std;

//class declaration
class LocationData {
	private:
		string sunType;
		int noOfEarthLikePlanets;
		int noOfEarthLikeMoons;
		float aveParticulateDensity;
		float avePlasmaDensity;

		//Assessor (getter) functions
		string getSunType();
		int getNoOfEarthLikePlanets();
		int getNoOfEarthLikeMoons();
		float getAveParticulateDensity();
		float getAvePlasmaDensity();

		//Mutator (setter) functions
		void setSunType(string sType);
		void setNoOfEarthLikePlanets(int noOfELP);
		void setNoOfEarthLikeMoons(int noOfELM);
		void setAveParticulateDensity(float aveParDen);
		void setAvePlasmaDensity(float avePlaDen);

		static float computeCivIndex(string sType, int noOfELP, int noOfELM, float aveParDen, float avePlaDen);
		//returns a String, containing the name of each attribute and its value respectively
		string toString();

	public:
		//Constructors
		LocationData();
		LocationData(string sType, int noOfELP, int noOfELM, float aveParDen, float avePlaDen);
		
		//allowing PointTwoD class to access its private members
		friend class PointTwoD;
};