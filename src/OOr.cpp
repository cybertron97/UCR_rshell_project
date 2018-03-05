#include "OOr.h"


//cpp for "||"
bool OOr::isExec(){
return false;
}

bool OOr::evaluate(){
	if(left->evaluate() ){ //checks if left works
		return true;
	}
	else {
		if ( right->evaluate() ){ //checks if right works
			return true;
		}
		else {
			return false;
		}
	}
}

//
