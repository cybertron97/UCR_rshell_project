#include "Exec.h"
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;


//execute file
Exec::Exec(std::vector<char*> s) { //create vector
v=s; } 

bool Exec::isExec() {//check if true
return true;
}
bool Exec::runTest(vector<char*> testV){ //testing function
	int checkers = strcmp(testV.at(0), "test");
        int bracket_checker = strcmp(testV.at(0), "[");	


	if (checkers == 0) {    //remove "test"
        testV.erase(testV.begin()); 
	}
else if (bracket_checker == 0)
	{
	    testV.erase(testV.begin()); //need to check the first "]"
	    testV.pop_back(); //not to introduce another if-else statement and then inclrease malloc but just to use the pop_back
	}
struct stat statF; //required for stat() system call
int statFChecker = stat(testV.back(), &statF);
	
	if (statFChecker == -1) {//see if doesn't exist
cout << "(False)" << endl;
		return false;
	}	
 //checks file 
 if (strcmp(testV.at(0), "-f") == 0){
			if (S_ISREG(statF.st_mode) != 0){
				cout << "(True)" << endl;
				return true;
			}
			else {
				cout << "(False)" << endl;
				return false;
			}
	}
//checks directory 
if (strcmp(testV.at(0), "-d") == 0){
			if (S_ISDIR(statF.st_mode) != 0){
				cout << "(True)" << endl;
				return true;
			}
			else {
				cout << "(False)" << endl;
				return false;
			}
		
	}
	
	cout << "(True)" << endl;
	return true;

// "-e"	should always be one since its a default case
 	cout << "(True)" << endl;
 		return true;



}


bool Exec::evaluate(){ //actual evaluate function
if (v.size() == 0) { //if size is 0, return false
return false;
	}
	else if ( strcmp(v.at(0), "test") == 0 || strcmp(v.at(0), "[") == 0) { //it checks if there's a testing command (already did in the earlier assignment)
	//it also checks if it has the first bracket  ) 
return runTest(v);
	}
	else if (strcmp(v.at(0), "exit") == 0  ) {
		_exit(0);
	}

	v.push_back(NULL); 			
	char **command = &v[0]; 

pid_t pid = fork(); //fork it
if (pid == 0){ 
	
		
		if (execvp(command[0],command) == -1) {
			perror ("exec");
			return false;
		}
	}
	
	if (pid > 0) { 
		
		if ( waitpid(0, NULL, 0) == -1 ) {
			perror ("wait");
		}
	}
	return true;
}

 



