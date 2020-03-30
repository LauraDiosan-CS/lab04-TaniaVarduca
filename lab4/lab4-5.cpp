#include <iostream>
#include "Tests.h"
#include "GymExercise.h"
#include "Repo.h"
#include "Operations.h"

using namespace std;


void printMenu()
{
	cout << "1. Adaugare." << endl;
	cout << "2. Afisare" << endl;
	cout << "3. Update" << endl;
	cout << "4. Stergere" << endl;
	cout << "5. noOfSeries * noOfReps * weightKg > X" << endl;
	cout << "6. Eliminare exercitii care au weightKg * noOfReps < 5" << endl;
	cout << "7. Iesire." << endl;
}

int main()
{
	testConstructors();
	testSetGet();
	testEqual();
	testRepo();
	char name[100];
	int noOfSeries; int noOfReps; int weightKg; int n = 0; 
	bool k = true;  
	Repo r;
	printMenu();
	while (k)
	{
		int option = 0;
		cin >> option;
		if (option == 1)
		{
			cout << "Dati numele: ";
			cin >> name;
			cout << "Dati noOfSeries: ";
			cin >> noOfSeries;
			cout << "Dati noOfReps: ";
			cin >> noOfReps;
			cout << "Dati weightKg: ";
			cin >> weightKg;
			GymExercise g(name, noOfSeries, noOfReps, weightKg);
			r.addGymExercise(g); n++;
			cout << endl; printMenu();
			continue;
		}
		if (option == 2)
		{
			cout << "Exercitiile sunt: " << endl;
			for (int i = 0; i < n; i++) {
				cout << r.getAll()[i] << " ";
				cout << endl;
			}
			cout << endl;
			printMenu();
			continue;
		}
		if (option == 3)
		{
			cout << "Update la exercitiul cu numarul: "; int i; cin >> i;
			GymExercise g = r.getItemFromPos(i-1);
			//cout << "new name: "; char *newName;  cin >> newName;
			cout << "new noOfSeries: "; int newNoOfSeries;  cin >> newNoOfSeries;
			cout << "new noOfReps: "; int newNoOfReps;  cin >> newNoOfReps;
			cout << "new weightKg: "; int newWeightKg;  cin >> newWeightKg;
			r.updateGymExercise(g, name, newNoOfSeries, newNoOfReps, newWeightKg);
			cout << endl; printMenu();
			continue;
		}
		if (option == 4)
		{
			cout << "Sterge exercitiul cu numarul: ";
			int i; cin >> i;
			r.delGymExercise(r.getItemFromPos(i - 1)); n -= 1;
			cout << endl; printMenu();
			continue;
		}
		if (option == 5)
		{
			int x; int resultLen = 0; GymExercise result[10];
			cout << "Dati X: " << endl;
			cin >> x;
			//filterGymExercisesWithRepo(x, r, n, name, noOfSeries, noOfReps, weightKg, result, resultLen);
			cout << "Exercitiile sunt: " << endl;
			for (int i = 0; i < resultLen; i++) {
				cout << result[i] << " ";
				cout << endl;
			}
			cout << endl;
			printMenu();
			continue;
		}
		if (option == 6)
		{
			//delExercisesWithRepo(r, n, name, noOfSeries, noOfReps, weightKg);
			printMenu();
			continue;
		}
		if (option == 7)
			k = false;
	}
}
