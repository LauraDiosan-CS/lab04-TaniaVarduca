#include <iostream>
#include "Tests.h"
#include "Service.h"
#include "UI.h"
using namespace std;

int main()
{
	tests();
	bool k = true;
	Service s; UI ui;
	ui.printMenu();
	char a[5] = "a"; char b[5] = "b"; char c[5] = "c";
	GymExercise g(a, 2, 3, 1); GymExercise g1(b, 10, 5, 6); GymExercise g2(c, 8, 2, 0);
	s.addGymExercise(g); s.addGymExercise(g1); s.addGymExercise(g2);
	while (k)
	{
		int option = 0;
		cin >> option;
		if (option == 1)
		{
			ui.addGymExercise(s);
			ui.printMenu();
			continue;
		}
		if (option == 2)
		{
			ui.getAll(s);
			ui.printMenu();
			continue;
		}
		if (option == 3)
		{
			ui.updateGymExercise(s);
			ui.getAll(s);
		    ui.printMenu();
			continue;
		}
		if (option == 4)
		{
			ui.delGymExercise(s);
			ui.getAll(s);
			ui.printMenu();
			continue;
		}
		if (option == 5)
		{
			ui.filterGymExercises(s);
			ui.printMenu();
			continue;
		}
		if (option == 6)
		{
			ui.delExercises(s);
			ui.getAll(s);
			ui.printMenu();
			continue;
		}
		if (option == 7)
			k = false;
	}
}

