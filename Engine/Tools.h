#ifndef TOOLS_H
#define TOOLS_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include "Status.h"
class Tools{
	public:
		static int genId();
		static char* loadFile(std::string);
	private:
		static int _id_counter;
};
#endif
