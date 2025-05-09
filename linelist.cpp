#include <iostream>
#include "linelist.h"

LineList::LineList()
{ // constructor 
	// create two LineNode objects 
	LineNode *line = new LineNode;
	LineNode *line2 = new LineNode;

	line -> info = topMessage;
	currLine = line;
	currLineNum = 1; 
	length = 0;
	line2 -> info = bottomMessage;
	currLine -> back = NULL;
	currLine -> next = line2;
	line2 -> back = line;
	line2 -> next = NULL;
}

void LineList::goToTop() 
{
	// Post : Advances currLine to line 1
	
	// iterate backwards until top message 
	while (currLine -> info != topMessage)
		currLine = currLine -> back;

	currLine = currLine -> next;
	currLineNum = 1;
}

void LineList::goToBottom() 
{
	// Post : Advances currLine to last line

	// iterate forwards until bottom message 
	while (currLine -> info != bottomMessage)
		currLine = currLine -> next;

	currLine = currLine -> back;
	currLineNum = length;
}

void LineList::insertLine(string newLine)
{
	// post : newLine has been inserted after the current line

	if (currLine -> info == bottomMessage) { // check if currLine is at bottomMessage 
           movePrevLine();
		
	}

	LineNode *line = new LineNode; // creare a new LineNode 

	line -> info = newLine;
	line -> back = currLine;
	line -> next = currLine -> next;

	currLine -> next -> back = line;
	currLine -> next = line;

	currLine = currLine -> next;
	currLineNum++;
	length++;
}

void LineList::deleteLine()
{
	// post : deletes the current line leaving currentLine
	//	  pointing to line following

	if ( (currLine -> info != topMessage) &&
	     (currLine -> info != bottomMessage) ) // checks if currLine is neither top nor bottom message 
	{
		LineNode *line = currLine; // temp pointer to currLine 

		currLine -> next -> back = currLine -> back;
		currLine -> back -> next = currLine -> next;
		currLine = currLine -> next;
	
		delete line; // free up memory 

		if (currLineNum == length)
			currLineNum--;

		length--;

		if (currLine -> info == topMessage)
			currLine = currLine -> next;

		if (currLine -> info == bottomMessage)
			currLine = currLine -> back;
	}
}

void LineList::printList() 
{
	int lineNum = 1;

	LineNode *mark = currLine;
	int markNum = currLineNum;

	goToTop();

	LineNode *line = currLine;
	// iterate through list and print 
	while (line -> info != bottomMessage)
	{
		cout << lineNum << "> " << line -> info << endl;
		line = line -> next;
		lineNum++;
	}
	// restores OG values 	
	currLine = mark;
	currLineNum = markNum;
}

string LineList::getCurrLine() const
{
	return (currLine -> info);
}

void LineList::moveNextLine()
{
	// Post : Advances currLine (unless already at last line)

	if ( (currLine -> next != NULL) && 
	     (currLine -> info != bottomMessage) ) // check if there is a next line and the currLine is not bottom message 
	{
	 	currLine = currLine -> next;
	 	currLineNum++;
	}

}

void LineList::movePrevLine()
{
	// Post : Advances currLine (unless already at last line)

	if ( (currLine -> back != NULL) &&
	     (currLine -> info != topMessage) ) // check if there is a previous like and if the current line is not top message 
	{
	 	currLine = currLine -> back;
	 	currLineNum--;
	}
}

int LineList::getCurrLineNum() const
{
	return currLineNum;
}

int LineList::getLength() const
{
	return length;
}
