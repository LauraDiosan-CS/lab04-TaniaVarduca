#pragma once
#include "GymExercise.h"
#include "Repo.h"
#include "Service.h"

class UI {
private:
	Service s;
public:
	UI();
	~UI();
	void printMenu();
	void addGymExercise(Service&s);
	void getAll(Service&s);
	void delGymExercise(Service& s);
	void updateGymExercise(Service& s);
	void filterGymExercises(Service& s);
	void delExercises(Service& s);
};
