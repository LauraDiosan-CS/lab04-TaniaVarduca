#pragma once
#include "GymExercise.h"

class Repo {
private:
	GymExercise exercises[20];
	int n;
public:
	Repo();
	~Repo();
	void addGymExercise(GymExercise g);
	GymExercise* getAll();
	int getSize();
	int findGymExercise(GymExercise g);
	void delGymExercise(GymExercise g);
	void updateGymExercise(GymExercise g, char* name, int noOfSeries, int noOfReps, int weightKg);
	GymExercise getItemFromPos(int i);
};
