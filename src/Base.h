#ifndef __Base_H__
#define __Base_H__

//defining base class
class Base 			
{
	public:
		Base* left = 0;
		Base* right = 0;
		//constructors
		Base(){}	
		//function
		void set(Base* l, Base* r) {this->left = l; this->right = r;}
		//void setL(Base* l) {this->left = l;}
		//void setR(Base* r) {this->right = r;}
			virtual bool evaluate() = 0;
 //to check the Exec like if it returns false or true value
                  virtual bool isExec() = 0; 
};


#endif

