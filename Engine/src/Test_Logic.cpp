#include "Test_logic.h"
void Test_Logic::update(double dt){
	std::cout << "Testing" << std::endl;
}
void Test_Logic::init(){

}
void Test_Logic::destroy(){

}
Test_Logic* Test_Logic::clone()const{
	Test_Logic* test_logic_ptr = new Test_Logic();
	test_logic_ptr->init();
	return test_logic_ptr;
}
