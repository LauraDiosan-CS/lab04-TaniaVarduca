#include "UI.h"
#include <iostream>
using namespace std;

//constructor
UI::UI()
{
	this->s;
}

//destructor
UI::~UI()
{
}

//afisare meniu
void UI::printMenu()
{
	cout << "1. Adaugare." << endl;
	cout << "2. Afisare" << endl;
	cout << "3. Update" << endl;
	cout << "4. Stergere" << endl;
	cout << "5. Afisare exercitii care au noOfSeries * noOfReps * weightKg > X" << endl;
	cout << "6. Eliminare exercitii care au weightKg * noOfReps < 5" << endl;
	cout << "7. Iesire." << endl;
}

//adaugare element de tip GymExercise
void UI::addGymExercise(Service& s)
{
	char name[100];
	int noOfSeries; int noOfReps; int weightKg; int n = 0;
	cout << "Dati numele: ";
	cin >> name;
	cout << "Dati noOfSeries: ";
	cin >> noOfSeries;
	cout << "Dati noOfReps: ";
	cin >> noOfReps;
	cout << "Dati weightKg: ";
	cin >> weightKg;
	GymExercise g(name, noOfSeries, noOfReps, weightKg);
	s.addGymExercise(g); n++;
	cout << endl;
}

//afisare toate elementele de tip GymExercise
void UI::getAll(Service&s)
{
	cout << endl << "Exercitiile sunt: " << endl;
	for (int i = 0; i < s.getSize(); i++) {
		cout << s.getAll()[i] << " ";
		cout << endl;
	}

	cout << endl;
}

//stergere element de tip GymExercise
void UI::delGymExercise(Service& s)
{
	cout << "Sterge exercitiul cu numarul: ";
	int i; cin >> i; int n = s.getSize();
	s.delGymExercise(s.getItemFromPos(i - 1)); n -= 1;
}

//modificare element de tip GymExercise
void UI::updateGymExercise(Service &s)
{
	cout << "Update la exercitiul cu numarul: "; int i; cin >> i;
	GymExercise g = s.getItemFromPos(i - 1);
	cout << "new name: "; char  newName[10];  cin >> newName;
	cout << "new noOfSeries: "; int newNoOfSeries;  cin >> newNoOfSeries;
	cout << "new noOfReps: "; int newNoOfReps;  cin >> newNoOfReps;
	cout << "new weightKg: "; int newWeightKg;  cin >> newWeightKg;
	s.updateGymExercise(g, newName, newNoOfSeries, newNoOfReps, newWeightKg);
}

//afisare elemente dupa filtrare
void UI::filterGymExercises(Service& s)
{
	int x; int resultLen = 0; GymExercise result[10];
	cout << "Dati X: " << endl;
	cin >> x;
	int n = s.getSize();
	s.filterGymExercises(x, s, n, result, resultLen);
	cout << endl << "Exercitiile sunt: " << endl;
	for (int i = 0; i < resultLen; i++) {
		cout << result[i] << " ";
		cout << endl;
	}
	cout << endl;
}

//stergere elemente cu noOfReps * weightKg < 5
void UI::delExercises(Service& s)
{
	int n = s.getSize();
	s.delExercises(s, n);
}
