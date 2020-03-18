#include "Operations.h"
void filterGymExercises(int x, GymExercise exercises[], int n, char* name, int noOfSeries, int noOfReps, int weightKg, GymExercise result[], int& resultLen)
{
	resultLen = 0;
	for (int i = 0; i < n; i++)
	{
		if ((exercises[i].getNoOfSeries()) * (exercises[i].getNoOfReps()) * (exercises[i].getWeightKg())>x)
		{
			result[resultLen++] = exercises[i];
		}
	}
}

void filterGymExercisesWithRepo(int x, Repo r, int n, char* name, int noOfSeries, int noOfReps, int weightKg, GymExercise result[], int& resultLen)
{
	resultLen = 0;
	GymExercise* initialExercises = r.getAll();
	return filterGymExercises(x, initialExercises, n, name, noOfSeries, noOfReps, weightKg, result, resultLen);
}

void delExercises(Repo r, GymExercise exercises[], int n, char* name, int noOfSeries, int noOfReps, int weightKg) {
	for (int i = 0; i < n; i++) {
		if (exercises[i].getWeightKg() * exercises[i].getNoOfReps() < 5) {
			r.delGymExercise(exercises[i]);
			n--;
		}
	}
}

void delExercisesWithRepo(Repo r, int n, char* name, int noOfSeries, int noOfReps, int weightKg) {
	GymExercise* initialExercises = r.getAll();
	return delExercises(r, initialExercises, n, name, noOfSeries, noOfReps, weightKg);
}