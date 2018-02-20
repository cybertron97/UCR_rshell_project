#include "cSemi.h"
#include <cstddef>

//cpp file for ";"
bool cSemi::isExec(){
return false;
}

bool cSemi::evaluate() {
	left->evaluate(); //evaluate left
	bool s=	right->evaluate(); //evaluate right, then check if it goes through or not
	if (s){
		return true;
	}
	return false;
}

