#ifndef _EXEC_H_
#define _EXEC_H_

#include "Base.h"
#include <vector>

//use a vector and then convert 
//execute header file
class Exec : public Base {
	private:
		std::vector<char*> v;
		
	public:
		Exec():Base() {}
		Exec(std::vector<char*> p); //take first element of command
bool evaluate(); //execute the command
		bool runTest(std::vector<char*> testVector);
		bool isExec();
};
#endif
//
