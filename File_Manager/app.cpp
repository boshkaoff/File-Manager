#include "app.h"


void APP::MainApp::Start()
{
	current_path = F_LOGIC::filesLogic::GetPath();
	state = UI::uiClass::CallMainUI(current_path);
	if (state == 7) { Exit(); std::cout << "Bye!"; return; }
	F_LOGIC::filesLogic::CallMainFL(state);
	state = 0;
}
