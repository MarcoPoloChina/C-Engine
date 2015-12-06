#ifndef INPUT_SYSTEM_H
#define INPUT_SYSTEM_H
#include "../Tools.h"
struct InputListener{
	int keyCode;	
	bool mouse;
	bool pressed;
	int mouseX;
	int mouseY;
};
class InputSystem{
	public:
		InputSystem(){init();}
		void init();
		void update();
	private:
		std::vector<InputListener> _inputListeners;
		std::vector<InputListener> _currentInputListeners;
};
#endif
