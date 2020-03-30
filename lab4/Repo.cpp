#include "Repo.h"
#include <iostream>
using namespace std;

Repo::Repo() {
	this->n = 0;
}
Repo::~Repo() {
	this->n = 0;
}
void Repo::addGymExercise(GymExercise g) {
	this->exercises[this->n++] = g;
	//cout << "Adaugat!" << endl << endl;
}

GymExercise* Repo::getAll() {
	return this->exercises;
}

int Repo::getSize() {
	return n;
}

int Repo::findGymExercise(GymExercise g) {
	int i = 0;

	while (i < n) {
		if (exercises[i] == g) return i;
		i++;
	}
	return -1;
}

void Repo::delGymExercise(GymExercise g) {
	int i = findGymExercise(g);
	if (i != -1) {
		exercises[i] = exercises[n - 1];
		n--;
	}
	
}

void Repo::updateGymExercise(GymExercise g, char* name, int noOfSeries, int noOfReps, int weightKg) {
	int i = findGymExercise(g);
	exercises[i].setName(name);
	exercises[i].setNoOfSeries(noOfSeries);
	exercises[i].setNoOfReps(noOfReps);
	exercises[i].setWeightKg(weightKg);
}

GymExercise Repo::getItemFromPos(int i) {
	return exercises[i];
}