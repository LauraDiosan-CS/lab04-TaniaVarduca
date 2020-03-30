#include "Operations.h"

void filterGymExercisesWithRepo(int x, Repo &r, int n, GymExercise result[], int& resultLen)
{
	resultLen = 0;
	/*GymExercise* exercises = r.getAll();
	for (int i = 0; i < n; i++)
	{
		if ((exercises[i].getNoOfSeries()) * (exercises[i].getNoOfReps()) * (exercises[i].getWeightKg())>x)
		{
			result[resultLen] = exercises[i];
			resultLen++;
		}
	}*/
	for (int i = 0; i < n; i++) {
		GymExercise crtEx = r.getItemFromPos(i);

		if ((crtEx.getNoOfSeries()) * (crtEx.getNoOfReps()) * (crtEx.getWeightKg()) > x) {
			result[resultLen] = crtEx;
			resultLen++;
		}
	}
}

void delExercisesWithRepo(Repo &r, int &n) {
	GymExercise* exercises = r.getAll();
	int i = 0;
	while(i<n)
	//for (int i = 0; i < n; i++) 
	{
		if (exercises[i].getWeightKg() * exercises[i].getNoOfReps() < 5) {
			r.delGymExercise(exercises[i]);
			n--;
		}
		i++;
	}
}