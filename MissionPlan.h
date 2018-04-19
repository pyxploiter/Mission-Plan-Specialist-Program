//header for MissionPlan.cpp

#pragma once
#include "LocationData.h"
#include "PointTwoD.h"

//class declaration
class MissionPlan {
	private:
		int option;
		float totalTravelDistance;
		LocationData locData[20];
		PointTwoD pointTwoD[20];
		int headQX;
		int headQY;
		int countRecords;
	public:
		MissionPlan();
		void main();
		void sortExplorationDestinations();
		float getTravelDistance();
};