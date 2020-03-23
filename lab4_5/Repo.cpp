#include "Repo.h"
#include <iostream>
using namespace std;

//constructor fara param
Repo::Repo() {
	this->n = 0;
}

//destructor
Repo::~Repo() {
	this->n = 0;
}

//adaugarea unui element de tip GymExercise
void Repo::addGymExercise(GymExercise g) {
	this->exercises[this->n++] = g;
}

//returneaza toate elementele de tip GymExercise
GymExercise* Repo::getAll() {
	return this->exercises;
}

//returneaza dimensiunea repo-ului
int Repo::getSize() {
	return n;
}

//returneaza pozitia unui element de tip GymExercise
int Repo::findGymExercise(GymExercise g) {
	int i = 0;

	while (i < n) {
		if (exercises[i] == g) return i;
		i++;
	}
	return -1;
}

//sterge un element de tip GymExercise 
void Repo::delGymExercise(GymExercise g) {
	int i = findGymExercise(g);
	if (i != -1) {
		exercises[i] = exercises[n - 1];
		n--;
	}

}

//modifica un element de tip GymExercise
void Repo::updateGymExercise(GymExercise g, char* name, int noOfSeries, int noOfReps, int weightKg) {
	int i = findGymExercise(g);
	exercises[i].setName(name);
	exercises[i].setNoOfSeries(noOfSeries);
	exercises[i].setNoOfReps(noOfReps);
	exercises[i].setWeightKg(weightKg);
}

//returneaza elementul de tip GymExercise de pe o anumita pozitie
GymExercise Repo::getItemFromPos(int i) {
	return exercises[i];
}