#include "Tools.h"
int Tools::_id_counter = 0;
bool Tools::_debug = true;
int Tools::genId(){
	return _id_counter++;
}
char* Tools::loadFile(std::string path){
	std::ifstream infile(path.c_str());
	if(infile){
		infile.seekg(0,infile.end);
		int length = infile.tellg();
		infile.seekg(0,infile.beg);
		char* buffer = new char[length];
		infile.read(buffer, length);
		infile.close();
		return buffer;
	}
	std::cout << "Error couldn't find :" << path << " file" << std::endl;
	return NULL;

}
void Tools::PrintDebug(std::string string){
	if(_debug){
		std::cout << "DEBUG: " << string << std::endl;
	}
}
