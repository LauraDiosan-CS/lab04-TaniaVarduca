#pragma once
#include "GymExercise.h"
#include "Repo.h"

class Service {
private:
	Repo r; 
public:
	Service();
	~Service();
	void addGymExercise(GymExercise& g);
	GymExercise* getAll();
	void delGymExercise(GymExercise g);
	void updateGymExercise(GymExercise& g, char* name, int noOfSeries, int noOfReps, int weightKg);
	GymExercise getItemFromPos(int i);
	int getSize();
	void filterGymExercises(int x, Service& s, int n, GymExercise result[], int& resultLen);
	void delExercises(Service& s, int& n);
};
