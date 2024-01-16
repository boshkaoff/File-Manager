#include "app.h"	
#include <locale>
#include <windows.h>

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	APP::MainApp proc;
	while (proc.Is_Running())
	{
		proc.Run();
	}

	return EXIT_SUCCESS;
}