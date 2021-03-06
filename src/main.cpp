//including all the libraries 
#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "Exec.h" //executing class
#include "Base.h" //base function
#include "Conn.h" //connector class
#include "AAnd.h" //finding "&&" in the command line
#include "OOr.h"  //finding "||" in the command line
#include "cSemi.h" //finding the ";" from the command line 
using namespace std;
//destroying the base vector list to clear the memory class 
void destroy(Base *curr){
    if(curr) {
    destroy(curr->left);
    destroy(curr->right);
    delete curr;
		}
}
//finds the semicolon and removes it to process the 
void rmSemi(vector<char*> &finishedVect)
{
        char* last = finishedVect.back(); //pushing vector back
		last[strlen(last) - 1] = 0;		
		return;		
}
//removes left parenthesis
void rmPL(vector<char*> &modVect)
{
    char* left = modVect.back();
    memmove(left, left+0, strlen(left));
    
    return;
}
//removes right parenthesis
void rmPR(vector<char*> &modVect)
{
    char* right = modVect.back();
    right[strlen(right) - 1] = 0;
    
    return;
}



//creating the tree to put in the command  
Base* createTree(vector<vector<char*> > v){

  const char* command;	
	queue<vector<char*> > q;
	stack<vector<char*> > conStack; //connector
	for( unsigned int i = 0; i < v.size(); i++) {
			command = (const char *)(v.at(i).at(0));
			if (*command != '&' && *command != '|' && *command != ';'&& *command != '(' && *command != ')' )
			{
				q.push(v.at(i) ); //checking the & and the orr and semicolon 
			}
			else if (*command == '&' || *command == '|' || *command == ';' ){ 
				if (conStack.empty() ){
					conStack.push(v.at(i) );
					continue;
				}

			else if (*(conStack.top().at(0)) != '('  ) {
					q.push(conStack.top());
					conStack.pop();
				}
				conStack.push(v.at(i));	
			}
			
			else if (*command == '(' ){
				conStack.push(v.at(i));
			}
			else if (*command == ')' ){
					while (*(conStack.top().at(0)) != '(' ) {
								q.push(conStack.top());
								conStack.pop();
					}
					conStack.pop();
			}
	}	
	//exiting the loop or exiting the rshell
	while (!conStack.empty() ) {
				q.push(conStack.top());
				conStack.pop();
	}

	stack<Base*> myStack;while (!myStack.empty()) {
			myStack.pop();
		}
	Base* A;
	while (!q.empty()) {
		command = (const char*)(q.front().at(0));
		if ( *command == '&' ) { A = new AAnd(); }
		else if ( *command == '|' ) { A = new OOr(); }
		else if ( *command == ';' ) { A = new cSemi(); }
		else { A = new Exec(q.front() ); }
		
		if (A->isExec()) {
				myStack.push(A);
		}
		else {
			Base* right = myStack.top();
			
			myStack.pop();
			
			Base* left = myStack.top();
			myStack.pop();
			A->set(left, right);
			myStack.push(A);
		}
			
		q.pop();
	}

	Base* root = myStack.top();
	while (!myStack.empty()) {
			myStack.pop();
	}
	return root;
}

int main()
{
 bool checker = true;
	while(checker){
		vector< vector<char*> > commandVector;   //

		string userInput = "";	
		cout << "$ ";	
		getline(cin, userInput); 
		string temp = userInput.substr(0,4);
		if (temp == "exit")
		{
			return 0;
		}
		

		userInput = userInput.substr(0, userInput.find("#"));

		// to check the entered user input, if not the same then returns back an error
		int count1 = 0, count2 = 0;
		for (int i = 0; i < userInput.size(); ++i)
		{
	    		if (userInput.at(i) == '(')
	    		{ count1 += 1; }
	    		if (userInput.at(i) == ')')
	    		{ count2 += 1; }
		}
		if (count1 != count2)
		{
	    		cout<< "Error: Please check the syntax!"<<endl; 
	    		continue;
		}

	
		char str[userInput.size()];	//creates character array with string size
		strcpy(str,userInput.c_str());	//turn string into character string and store in str[]
		char* pch;	//used to point at tokens
		pch = strtok(str, " ");
		char* last_letter = &(pch[strlen(pch)-1]); // points at las character
		char* first_letter = pch;
		bool connectorTrue = false; // checks if previous parse was a connector 
		
		//creating vector characters
		char* orsign = new char('|');
		char* andsign = new char('&');
		char* semi = new char(';');
		char* pleft = new char('('); 
        	char* pright = new char(')');
	
		vector<char*> andSign;
		andSign.push_back(andsign);
		vector<char*> orSign;
		orSign.push_back(orsign);	
		vector<char*> semiSign;
		semiSign.push_back(semi);
		vector<char*> prleft;
		prleft.push_back(pleft);
		vector<char*> prright;
		prright.push_back(pright);		

		while (pch != NULL)
		{
		 	if(commandVector.size() == 0) 	
		 	{
				vector<char*> tempVect;
				tempVect.push_back(pch); // like separating semicolon from the function
				commandVector.push_back(tempVect);
				connectorTrue = false;

				while (*(first_letter) == '(') // if it starts with a (
				{
					commandVector.insert(commandVector.begin(), prleft); //a vector containing (() is pushed to first row of the commandVector
					rmPL( commandVector.back() ); // pass in the current vector of char* that just got pushed in
					connectorTrue = false;
					first_letter = commandVector.back().at(0);
				}	


				if (*(last_letter) == ';') //if it ends with ; 
				{
						rmSemi( commandVector.back() ); 
						commandVector.push_back(semiSign); 
						connectorTrue = true; //sets it as a previous connector 
				} 
				
				
				
		 	}	

//checked from youtube: the fork and pushback functions 
			else
			{
						if(connectorTrue)
						{
							vector<char*> tempVect; //making a temporary vector to check if the connector function works 
							tempVect.push_back(pch); // a vector containing command/argument is made
							commandVector.push_back(tempVect); //added as a new row
							connectorTrue = false;
							
							if (*(first_letter) == '(') // if it starts with a (
							{
								while (*(first_letter) == '(')
								{
									commandVector.insert(commandVector.begin() + (commandVector.size() - 1), prleft); //a vector containing (() is pushed to first row of the cmdVector
									rmPL( commandVector.back() ); // pass in the current vector of char* that just got pushed in
									connectorTrue = false;
									first_letter = commandVector.back().back();
								}
							}	
							
							if (*(last_letter) == ';') //if it ends with ; 
							{
								rmSemi( commandVector.back() ); //
								commandVector.push_back(semiSign); //
								connectorTrue = true;
							}
						}
						
						else if ( *(last_letter) == '&' ) // if the last letter is '&' then it pushes back as a previous connector
						{
							commandVector.push_back(andSign);
							connectorTrue = true; 
						}
						else if ( *(last_letter) == '|' ) // if the lastletter is | then it sets the vector as previous connector 
						{
							commandVector.push_back(orSign);
					 	 	connectorTrue = true; 
						}
						
	

						else 
						{
							if ( *(last_letter) == ';' ) //lastletter is ;
							{
								commandVector.back().push_back(pch);
								rmSemi( commandVector.back() );
								commandVector.push_back(semiSign);
								connectorTrue = true; 
							}
							
							else if ( *(last_letter) == ')' ) // lastletter is )
							{
								int Par2 = commandVector.size() - 1;
								commandVector.back().push_back(pch);
								while ( *(last_letter) == ')' ) // lastletter is )
								{
									rmPR( commandVector.at(Par2) );
									commandVector.push_back(prright);
									connectorTrue = false;
									char* temporary_lter = commandVector.at(Par2).back();
									last_letter = &(temporary_lter[strlen(temporary_lter)-1]);
								}
							}
				
							else
							{ 
						 		commandVector.back().push_back(pch);
							}
						}	
			}//end of else from pushing back the semi 

			pch = strtok(NULL," "); //next token
			if (pch != NULL)
			{
				last_letter = &(pch[strlen(pch)-1]);
				first_letter = pch;
			}

		}//end 


/*
 *   There's some ongoing issue with the loop command for the precedence operators 
 *   so the fix was to remove the beginning the precedecnce operators 
 *   
 */
for (int i = 0; i < commandVector.size(); ++i)
		{
			if (*(commandVector.at(i).front()) == NULL)
			{
				commandVector.at(i).erase(commandVector.at(i).begin());
			}
		}






		Base* rooot = createTree(commandVector);
		rooot->evaluate(); //evaluating the tree
		destroy(rooot); //destroying the vector to clear of memory 
	} 

return 0;
}
