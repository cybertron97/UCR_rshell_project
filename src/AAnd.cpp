#include "AAnd.h"
//cpp for "&&"
bool AAnd::isExec() {
return false;
}

bool AAnd::evaluate() {
	if(left->evaluate() ) { //checks if left worked
		if(right->evaluate() ){ //if so, return true
			return true;
		}
		else {
			return false;
		}
	}
	return false; //else return false
}

//
