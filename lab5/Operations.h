#pragma once
#include "Repo.h"
#include "GymExercise.h"

//void filterGymExercises(int x, GymExercise exercises[], int n, GymExercise result[], int& resultLen);
void filterGymExercisesWithRepo(int x, Repo &r, int n, GymExercise result[], int& resultLen);
void delExercisesWithRepo(Repo &r, int &n);
