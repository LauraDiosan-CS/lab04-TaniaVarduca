#pragma once
#include "Repo.h"
#include "GymExercise.h"

void filterGymExercises(int x, GymExercise exercises[], int n, char* name, int noOfSeries, int noOfReps, int weightKg, GymExercise result[], int& resultLen);
void filterGymExercisesWithRepo(int x, Repo r, int n, char* name, int noOfSeries, int noOfReps, int weightKg, GymExercise result[], int& resultLen);
void delExercises(Repo r, GymExercise exercises[], int n, char* name, int noOfSeries, int noOfReps, int weightKg);
void delExercisesWithRepo(Repo r, int n, char* name, int noOfSeries, int noOfReps, int weightKg);

