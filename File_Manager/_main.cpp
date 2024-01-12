#include "app.h"	
#include <conio.h>

int main() {

	APP::MainApp proc;
	do {
		proc.Run();
		std::cout << "\nPress any key to continue...";
		char key = _getch();
		system("cls");
	} while (proc.Is_Running());

	return 0;
}