#include "app.h"	
#include <locale>
#include <windows.h>
#include <io.h>
#include <fcntl.h>

int main() {
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);
	(void)_setmode(_fileno(stdin), _O_U16TEXT);

	APP::MainApp proc;
	while (proc.Is_Running())
	{
		proc.Run();
	}

	return EXIT_SUCCESS;
}