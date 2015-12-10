#ifndef COMPONENT_H
#define COMPONENT_H
#include "Messanger.h"
class Component{
	public:
		Component():active(true){}
		bool active;
		ID getID(){return _id;}
	private:
		ID _id;
};
#endif
