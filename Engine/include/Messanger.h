#ifndef MESSANGER_H
#define MESSANGER_H
#include "Tools.h"
struct ID{
	public:
		ID(int systemIndex=0,int index=0):systemIndex(systemIndex),index(index){}
		int systemIndex;
		int index;
		int type;
};
class Messanger{
	public:
		virtual void receiveMessange(unsigned int messageID,std::vector<int> data) = 0;
		void sendMessage(ID id,unsigned int messageID,std::vector<int> date);
};
#endif
