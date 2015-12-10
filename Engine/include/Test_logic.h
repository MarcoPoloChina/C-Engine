#ifndef TEST_COMPOMENT
#define TEST_COMPOMENT
#include "Tools.h"
#include "Logic.h"
class Test_Logic : public Logic{
public:
		Test_Logic():Logic("Test_Logic"){}
		virtual void update(double dt);
		virtual void init();
		virtual void destroy();
		virtual Test_Logic* clone() const;
	private:
};
#endif
