#include "app.h"	

int main() {

	std::locale::global(std::locale(""));
	APP::MainApp proc;
	while (proc.Is_Running())
	{
		proc.Run();
	}

	return 0;
}