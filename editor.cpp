#include <iostream>
#include <cstdlib> // C standard library for exit(1) 
#include <fstream> // for c++ files 
#include <string>
#include "linelist.h"

using namespace std;

// method headers 
int Command(LineList& L, char *argv[]); 
void finishUp(LineList &L, char *argv[]);
void readFromFile(LineList&L, const char *filename);


int main(int argc, char *argv[]) { // main method 
	if(argc == 1) { // no filename provided
		cerr << "No filename provided."  << endl;
		exit(1); // exit with error code 
	}
	
	LineList L; // create a LineList object 
	
	readFromFile(L, argv[1]); // read contents of file	
	L.printList(); // print contents of L
	L.goToBottom(); // move currLine to bottom of list 
	
	Command(L, argv); // call to Command

	return 0;
}

void readFromFile(LineList& L, const char *filename) { // method to read info from file and input into L object
	ifstream infile(filename); // open file for input
	if(!infile) {
		exit(1);
	}

	string buffer;
	while(getline(infile,buffer)) { // read from file
		L.insertLine(buffer); // insert to L object 
	}
	infile.close(); // close for input
}

void finishUp(LineList& L, char *filename) { // method for case 'E' to save info back to file and exit
	ofstream file(filename);
	if(!file) {
		cout << "File cannot be accessed." << endl;
		exit(1);
	}
	
	L.goToTop();
	while (L.getCurrLineNum() <= L.getLength()) {
		file << L.getCurrLine() << "\n";
		L.moveNextLine();
	}
	
	file.close();		
}

int Command(LineList& L, char* argv[]) { // method to handle user input for specific cases 
	string line;	
	char command;

	do {
		cout << L.getCurrLineNum() << ">"; // responsible for line#>
		cin >> command; // reads in user command 
		
		switch(command) {
			case 'I': { // insert a new line  
				cout << L.getCurrLineNum() + 1 << ">";
				cin.ignore(); // ignore remaining characters
				getline(cin, line); // reads in user line to be inserted 
				L.insertLine(line);
				break;
			}
			case 'D': // delete current line  
				L.deleteLine();
				break;
			case 'L':// print L object  
				L.printList();
				break;
			case 'P':// move to previous line 
				L.movePrevLine();
				break;
			case 'N':// move to next line 
				L.moveNextLine();
				break;
			case 'E':  // save to file and exit 
				finishUp(L, argv[1]);
				break;
		} 
	} while (command != 'E'); // continues until user enters E 
}
