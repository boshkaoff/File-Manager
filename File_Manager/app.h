#pragma once
#include <iostream>
#include <string>
#include "ui.h"
#include "files_logic.h"

namespace APP {

	class MainApp : public UI::uiClass, public F_LOGIC::filesLogic {
	public:
		void Run() { Start(); }
		bool Is_Running() {	return is_enabled; }
		void Exit() { is_enabled = false; }

	private:

		int state = 0;
		std::string current_path = "C:\\";
		bool is_enabled = true;
		void Start();
	};
}