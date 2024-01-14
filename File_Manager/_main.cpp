#include "app.h"	
#include <conio.h>

int main() {

	APP::MainApp proc;
	while (proc.Is_Running())
	{
		proc.Run();
		std::cout << "\nPress any key to continue...";
		char key = _getch();
		system("cls");
	}

	return 0;
}