#ifndef LOGIC_H
#define LOGIC_H
#include "Component.h"
class Logic: public Component{
	public:
		Logic(std::string name):_name(name){}
		virtual void update(double dt) = 0;
		virtual void init() = 0;
		virtual void destroy() = 0;
		virtual Logic* clone() const = 0;
		std::string getName(){return _name;}
		~Logic(){}
	private:
		std::string _name;
};
#endif
