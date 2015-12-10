#include "Engine.h"
#include "Test_logic.h"
int main(int argc, char *argv[]){
	Test_Logic* test = new Test_Logic();
	Engine e;
	e.addLogic(test);
	e.init();
}
