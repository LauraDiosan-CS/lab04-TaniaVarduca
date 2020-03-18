#include "GymExercise.h"
#include "Repo.h";
#include <iostream>
#include <assert.h>
using namespace std;

void testConstructors() {
	//static (fixed) objects
	cout << "first tests ..." << endl;
	GymExercise g1; //implicit constructor
	assert((g1.getName() == NULL) && (g1.getNoOfSeries() == 0) && (g1.getNoOfReps() == 0) && (g1.getWeightKg() == 0));
	char *a = new char[5];
	GymExercise g2(a, 5, 10, 80); //constr with param
	assert( (g2.getNoOfSeries() == 5) && (g2.getNoOfReps() == 10) && (g2.getWeightKg() == 80));
	GymExercise g3(a, 10, 3, 5); //conversion constr
	assert( (g3.getNoOfSeries() == 10) && (g3.getNoOfReps() == 3) && (g3.getWeightKg() == 5));
}
void testSetGet() {
	GymExercise g;
	g.setNoOfSeries(1);
	g.setNoOfReps(3);
	g.setWeightKg(40);
	assert((g.getNoOfSeries() == 1) && (g.getNoOfReps() == 3) && (g.getWeightKg() == 40));
}

void testEqual() { //assignemnt
	char* a = new char[5];
	GymExercise g1(a, 3, 1, 5);
	GymExercise g2(a, 12, 43, 7);
	g1 = g2;
	assert((g1.getNoOfSeries() == 12) && (g1.getNoOfReps() == 43) && (g1.getWeightKg() == 7));
}

void testRepo() {
	Repo r;
	char* a = new char[5];
	GymExercise g(a, 10, 20, 30);
	r.addGymExercise(g);
	assert(r.getSize() == 1);
	GymExercise g1(a, 11, 51, 34);
	r.addGymExercise(g1);
	assert(r.getSize() == 2);
	r.delGymExercise(g1);
	assert(r.getSize() == 1);
	assert((g.getNoOfSeries() == 10) && (g.getNoOfReps() == 20) && (g.getWeightKg() == 30));
	r.updateGymExercise(g, a, 20, 50, 100);
	//assert((g.getNoOfSeries() == 20) && (g.getNoOfReps() == 50) && (g.getWeightKg() == 100));
	cout << "all tests are ok ... good job!" << endl << endl;
}