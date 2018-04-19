#include <iostream>
#include <string>
#include <math.h>

#include "MissionPlan.h"
#include "PointTwoD.cpp"
#include "LocationData.cpp"

using namespace std;

//constructor without parameter
MissionPlan::MissionPlan(){
	option = 0;
	totalTravelDistance = 0.0;
	countRecords = 0;
	headQX = 0;
	headQY = 0;
}

//sorting the records in descending order of civIndex
void MissionPlan::sortExplorationDestinations(){
	int i,j;
	//sorting the records
	for (i=0; i < countRecords - 1; i++){
		for (j = 0; j < countRecords-i-1; j++){
			if (pointTwoD[j].getCivIndex() < pointTwoD[j+1].getCivIndex()){
				PointTwoD temp = pointTwoD[j];
				pointTwoD[j] = pointTwoD[j+1];
				pointTwoD[j+1] = temp; 
			}
		}
	}
}

//returns travelDistance by calculating it from given formula
float MissionPlan::getTravelDistance(){
	sortExplorationDestinations();
	for (int i=0; i < countRecords; i++){
		//if more than 5 records, don't add distance of them
		if (i > 4){
			break;
		}
		//d = squareroot( (x2 - x1)^2 + (y2 - y1)^2 )	==> (x2, y2) == (headQX, headQY)
		totalTravelDistance += sqrt(pow((headQX-pointTwoD[i].getX()),2)+pow((headQY-pointTwoD[i].getY()),2));
	}
	//dist from HQ to star system and from star system back to HQ, that's why multiplied with 2
	return 2*totalTravelDistance;
}

//main function which sets up all necessary iteractions to perform its task
void MissionPlan::main(){
	//sentiment for loop
	bool quit = false;
	//loop until 5 is selected to quit the program
	while(!quit){
		cout << "-------------------------------------------------" << endl;
		cout << "Welcome to Mission Plan Program!" << endl << endl;
		cout << "1) Input statistical data" << endl;
		cout << "2) Compute civ. index value (for all records)" << endl;
		cout << "3) Print top 5 exploration destinations" << endl;
		cout << "4) Print total travel distance" << endl;
		cout << "5) Quit" << endl << endl;

		cout << "Please enter your choice: ";
		cin >> option;
		cout << endl;

		int x, y, noOfELP, noOfELM, aveParDen, avePlaDen;
		string sType;

		//evaluating the user choice
		switch (option){
			//reading the statistical data from user
			case 1:
				cout << "[ Input statistical data ]" << endl;
				cout << "Please enter x-ordinate: ";
				cin >> x;
				cout << "Please enter y-ordinate: ";
				cin >> y;
				cin.ignore();
				cout << "Please enter sun type: ";
				getline(cin, sType);
				cout << "Please enter no. of earth-like planets: ";
				cin >> noOfELP;
				cout << "Please enter no. of earth-like moons: ";
				cin >> noOfELM;
				cout << "Please enter ave. particulate density (%-tage): ";
				cin >> aveParDen;
				cout << "Please enter ave. plasma density (%-tage): ";
				cin >> avePlaDen;
				cout << endl << "Record successfully stored. Going back to main menu..." << endl;
				countRecords++;
				break;
			//calculating civIndex for all records
			case 2:
				for (int i = 0; i < countRecords; i++){
					pointTwoD[i].calcCivIndex();
				}
				cout << "Computation completed! ("<< countRecords <<" records were updated)" << endl;
				break;
			//Printing top 5 explorations on basis of CivIndex
			case 3:
				cout << "Total no. of records available = " << countRecords << endl;
				cout << "Printing top 5 exploration destinations ..." << endl;
				sortExplorationDestinations();
				for (int i = 0; i < 5; i++){
					if (pointTwoD[i].getX() != 0 || pointTwoD[i].getY() != 0){
						cout << i+1 << ") Civ Idx: "<< pointTwoD[i].getCivIndex() <<" at sector (" << pointTwoD[i].getX() << "," << pointTwoD[i].getY() << ")"<< endl;
					} else {
						cout << "<no other records available>" << endl;
					}
				}
				cout << endl << "Done!" << endl;
				break;
			//Printing total travel distance
			case 4:
				cout << "Total (approx) travel distance = " << getTravelDistance()*100 <<" million km" << endl;
				break;
			//Quitting the program
			case 5:
				quit = true;
				break;
			//If choice is not between (1-5)
			default:
				cout << "[Error] Invalid option is selected." << endl;
		}

		//add records only if option 1 is selected obv.
		if (option == 1){
			LocationData l_Data(sType, noOfELP, noOfELM, aveParDen, avePlaDen);
			locData[countRecords-1] = l_Data;
			PointTwoD point(x, y, l_Data);
			pointTwoD[countRecords-1] = point;
		}
	}
}