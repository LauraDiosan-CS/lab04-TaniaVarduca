#pragma once
//name, noOfSeries, noOfReps, weightKg
#include <ostream>
using namespace std;

class GymExercise {
private:
	char* name;
	int noOfSeries;
	int noOfReps;
	int weightKg;
public:
	GymExercise();
	GymExercise(char* name, int noOfSeries, int noOfReps, int weightKg);
	GymExercise(const GymExercise& g);
	~GymExercise();
	char* getName();
	int getNoOfSeries();
	int getNoOfReps();
	int getWeightKg();
	void setName(char* name);
	void setNoOfSeries(int noOfSeries);
	void setNoOfReps(int noOfReps);
	void setWeightKg(int weightKg);
	GymExercise& operator=(const GymExercise& g);
	bool operator==(const GymExercise& g);
	friend ostream& operator<<(ostream& os, const GymExercise& g);
};
