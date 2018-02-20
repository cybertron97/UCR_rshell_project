#ifndef _CONN_H_
#define _CONN_H_
#include "Base.h"

//connecting header. Used by other headers
class Conn : public Base {
public:	
		Conn() : Base(){}
		//Conn(Base* l, Base* r): left(l), right(r){}
		virtual bool evaluate() = 0;
		virtual bool isExec() = 0;
};

#endif

