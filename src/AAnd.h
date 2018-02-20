#ifndef _AAND_H_
#define _AAND_H_
#include "Conn.h"
//header file for "&&" 
class AAnd : public Conn {
		public:
			AAnd(): Conn() {}
			//AAnd(Base* left, Base* right) : Conn(left, right) {}
			bool evaluate();
			bool isExec();
			};
										#endif
			
