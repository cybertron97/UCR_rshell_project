#ifndef _CSEMI_H_
#define _CSEMI_H_
#include "Conn.h"

//header file for ";"
class cSemi : public Conn {
		public:
			cSemi():Conn() {}
			//cSemi(Base* left, Base* right) : Conn(left, right) {}
			bool evaluate(); 			
			bool isExec();
};
#endif

