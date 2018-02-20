#ifndef _OOR_H_
#define _OOR_H_
#include "Conn.h"

//header for "||"
class OOr : public Conn { 
		public: 
			OOr(): Conn() {}
//OOr(Base* left, Base* right) : Conn(left, right) {}
bool evaluate();
			bool isExec();
	};
#endif

//
