#include "GymExercise.h"
#include "Repo.h"
#include "Service.h"
#include <iostream>
#include <assert.h>
#include "tests.h"
using namespace std;

//teste constructori
void testConstructors() {
	GymExercise g1; //constructor implicit
	assert((g1.getName() == NULL) && (g1.getNoOfSeries() == 0) && (g1.getNoOfReps() == 0) && (g1.getWeightKg() == 0));
	char a[5] = "a";
	GymExercise g2(a, 5, 10, 80); //constructor cu param
	assert((strstr(g2.getName(), "a")) && (g2.getNoOfSeries() == 5) && (g2.getNoOfReps() == 10) && (g2.getWeightKg() == 80));
	GymExercise g3(g2); //constructor de copiere
	assert(g3 == g2);
}

//teste setteri, getteri
void testSetGet() {
	GymExercise g; char a[5] = "a";
	g.setName(a);
	g.setNoOfSeries(1);
	g.setNoOfReps(3);
	g.setWeightKg(40);
	assert((strstr(g.getName(), "a")) && (g.getNoOfSeries() == 1) && (g.getNoOfReps() == 3) && (g.getWeightKg() == 40));
}

//test operator de egalitate
void testEqual() { 
	char a[5] = "a"; char b[5] = "b";
	GymExercise g1(a, 3, 1, 5);
	GymExercise g2(b, 12, 43, 7);
	g1 = g2;
	assert((strstr(g1.getName(), "b"))&&(g1.getNoOfSeries() == 12) && (g1.getNoOfReps() == 43) && (g1.getWeightKg() == 7));
}

//teste repository
void testRepo() {
	Repo r; 
	char a[10] = "a"; char b[10] = "b";
	GymExercise g(a, 10, 20, 30);
	r.addGymExercise(g); //adaugare
	assert(r.getSize() == 1); //dimensiune
	GymExercise g1(a, 11, 51, 34);
	r.addGymExercise(g1);
	assert(r.getSize() == 2);	
	GymExercise* res; res = r.getAll(); //getAll
	assert(res[0] == g && res[1] == g1);
	r.delGymExercise(g1); //stergere
	assert(r.getSize() == 1);	
	assert((strstr(g.getName(), "a")) && (g.getNoOfSeries() == 10) && (g.getNoOfReps() == 20) && (g.getWeightKg() == 30));
	r.updateGymExercise(g, b, 20, 50, 100);	//update
	assert((strstr(r.getItemFromPos(0).getName(), "b"))&&(r.getItemFromPos(0).getNoOfSeries() == 20) && (r.getItemFromPos(0).getNoOfReps() == 50) && (r.getItemFromPos(0).getWeightKg() == 100));
	assert(r.findGymExercise(r.getItemFromPos(0)) == 0); //gasire pozitie a unui elem GymExercise
}

//teste service
void testService()
{
	Service s;
	char a[10] = "a"; char b[10] = "b";
	GymExercise g(a, 10, 20, 30); //creare obiect de tip GymExercise 
	s.addGymExercise(g); //adaugare 
	assert(s.getSize() == 1);
	GymExercise g1(a, 11, 51, 34); 
	s.addGymExercise(g1); 
	assert(s.getSize() == 2);
	GymExercise* res; res = s.getAll(); //getAll
	assert(res[0] == g && res[1] == g1);
	s.delGymExercise(g1); //stergere
	assert(s.getSize() == 1);
	assert((strstr(g.getName(), "a")) && (g.getNoOfSeries() == 10) && (g.getNoOfReps() == 20) && (g.getWeightKg() == 30));
	s.updateGymExercise(g, b, 20, 50, 100); //update 
	assert((strstr(s.getItemFromPos(0).getName(), "b")) && (s.getItemFromPos(0).getNoOfSeries() == 20) && (s.getItemFromPos(0).getNoOfReps() == 50) && (s.getItemFromPos(0).getWeightKg() == 100));
	GymExercise g2(a, 1, 2, 1); 
	s.addGymExercise(g2); 

	//teste proprietati
	GymExercise result[10]; int lenResult = 0;
	s.filterGymExercises(100, s, s.getSize(), result, lenResult); //filtrare GymExercises cu noOfSeries * noOfReps * weightKg > X
	assert(lenResult == 1);
	assert((strstr(result[0].getName(), "b")) && (result[0].getNoOfSeries() == 20) && (result[0].getNoOfReps() == 50) && (result[0].getWeightKg() == 100));
	int n = s.getSize();
	s.delExercises(s, n); //stergere GymExercises cu weightKg * noOfReps < 5
	assert(n == 1);
	res = s.getAll();
	assert((strstr(res[0].getName(), "b")) && (res[0].getNoOfSeries() == 20) && (res[0].getNoOfReps() == 50) && (res[0].getWeightKg() == 100));
}

//apelare teste si mesaje de succes
void tests() {
	cout << "first tests ..." << endl;
	testConstructors();
	testSetGet();
	testEqual();
	testRepo();
	testService();
	cout << "all tests are ok ... good job!" << endl << endl;
}
