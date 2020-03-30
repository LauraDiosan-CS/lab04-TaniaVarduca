#include "GymExercise.h"
#include <cstddef>
#include <string.h>
#include <ostream>
#include <iostream>
using namespace std;

//constructor default(fara param)
GymExercise::GymExercise() {
	this->name = NULL;
	this->noOfSeries = 0;
	this->noOfReps = 0;
	this->weightKg = 0;
}

//constructor cu param
GymExercise::GymExercise(const char* name, int noOfSeries, int noOfReps, int weightKg)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, 1 + strlen(name), name);
	this->noOfSeries = noOfSeries;
	this->noOfReps = noOfReps;
	this->weightKg = weightKg;
}

//constructor de copiere
GymExercise::GymExercise(const GymExercise& g) {
	if (g.name) {
		this->name = new char[strlen(g.name) + 1];
		strcpy_s(this->name, 1 + strlen(g.name), g.name);
	}
	this->noOfSeries = g.noOfSeries;
	this->noOfReps = g.noOfReps;
	this->weightKg = g.weightKg;
}

//destructor
GymExercise::~GymExercise() {
	if (name) delete[]name;
	name = NULL;
	noOfSeries = -1;
	noOfReps = -1;
	weightKg = -1;
}

//getter pentru nume
char* GymExercise::getName() {
	return this->name;
}

//getter pentru noOfSeries
int GymExercise::getNoOfSeries() {
	return this->noOfSeries;
}

//getter pentru noOfReps
int GymExercise::getNoOfReps() {
	return this->noOfReps;
}

//getter pentru weightKg
int GymExercise::getWeightKg() {
	return this->weightKg;
}

//setter pentru nume
void GymExercise::setName(const char* name)
{
	if (this->name) {
		delete[] this->name;
	}
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

//setter pentru noOfSeries
void GymExercise::setNoOfSeries(int noOfSeries) {
	this->noOfSeries = noOfSeries;
}

//setter pentru noOfReps
void GymExercise::setNoOfReps(int noOfReps) {
	this->noOfReps = noOfReps;
}

//setter pentru weightKg
void GymExercise::setWeightKg(int weightKg) {
	this->weightKg = weightKg;
}

//suprascrie operatorul "=" pentru un element de tip GymExercise
GymExercise& GymExercise::operator=(const GymExercise& g) {
	if (this == &g) return *this; //self-assignment
	if (name) delete[] name;
	if (g.name) {
		this -> name = new char[strlen(g.name) + 1];
		strcpy_s(name, strlen(g.name) + 1, g.name);
	}
	noOfSeries = g.noOfSeries;
	noOfReps = g.noOfReps;
	weightKg = g.weightKg;
	return *this;
}

//operatorul de egalitate
bool GymExercise:: operator==(const GymExercise& g) {
	return strcmp(this->name, g.name) == 0 && this->noOfSeries == g.noOfSeries && this->noOfReps == g.noOfReps && this->weightKg == g.weightKg;
}

//pt afisare
ostream& operator<<(ostream& os, const GymExercise& g)
{
	os <<"Nume - " <<g.name << ", noOfSeries - " << g.noOfSeries << ", noOfReps - " << g.noOfReps << ", weightKg - " << g.weightKg;
	return os;
}