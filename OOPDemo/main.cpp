/*
Author: Kenneth Huddleston
Class: CS162

Purpose: This is the main file for project 4 in CS162. The purpose of this file is to create an object of break_activity which will be used to read in user input and display contents
back to the user.
*/

#include "project4.h"

int main ()
{
	break_activity list;
	list.InsertAtEnd();
	list.goAgain();
	list.display_all();

	return 0;

}
