#include "Service.h"
#include <iostream>
#include <algorithm>
using namespace std;

//constructor fara param
Service::Service() {
	this->r;
}

//destructor
Service::~Service() {
}

//adauga un element de tip GymExercise
void Service::addGymExercise(GymExercise& g) {
	r.addGymExercise(g);
}

//returneaza toate elementele de tip GymExercise
GymExercise* Service::getAll() {
	return r.getAll();
}

//sterge un element de tip GymExercise 
void Service::delGymExercise(GymExercise g) {
	r.delGymExercise(g);
}

//modifica un element de tip GymExercise 
void Service::updateGymExercise(GymExercise& g, char* name, int noOfSeries, int noOfReps, int weightKg) {
	r.updateGymExercise(g, name, noOfSeries, noOfReps, weightKg);
}

//returneaza elementul de tip GymExercise de pe o anumita pozitie
GymExercise Service::getItemFromPos(int i) {
	return r.getItemFromPos(i);
}

//returneaza dimensiunea repo-ului
int Service::getSize() {
	return r.getSize();
}

//filtreaza elementele de tip GymExercise dupa proprietatea: noOfSeries * noOfReps * weightKg > X
void Service::filterGymExercises(int x, Service& s, int n, GymExercise result[], int& resultLen)
{
	resultLen = 0;
	for (int i = 0; i < n; i++) {
		GymExercise crtEx = s.getItemFromPos(i);

		if ((crtEx.getNoOfSeries()) * (crtEx.getNoOfReps()) * (crtEx.getWeightKg()) > x) {
			result[resultLen] = crtEx;
			resultLen++;
		}
	}
}

//sterge elementele de tip GymExercise care au weightKg * noOfReps < 5
void Service::delExercises(Service& s, int& n) {
	GymExercise* exercises =s.getAll();
	int i = 0;
	while (i < n)
	{
		if (exercises[i].getWeightKg() * exercises[i].getNoOfReps() < 5) {
			s.delGymExercise(exercises[i]);
			n--;
		}
		else
			i++;
	}
}



