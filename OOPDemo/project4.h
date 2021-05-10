#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

/*
Author: Kenneth Huddleston, Class: CS162
Purpose: This is the main header file for programming assignment number 4. This file contains the class interface and the structure contents for a catalogue of break activities.
*/

struct activity_details
{
		char * activity_name;		 // Change this later to use dynamic memory
		char description[131];		 // Brief description of the activity
		char why_important[101];	 // Prompt for the user to enter why the activity is important. Why do it on spring break?
		char length_of_time[11];	 // How long will the activity take? Stored as an array of characters.
		double cost_of_activity;	 // The cost of the activity.
		activity_details();		 // constructor
		~activity_details();		 // destructor
		void read_activity();		 // read's a single activity
		void display_activity();	 // display's a single activity
	
};

struct node {
	activity_details data;
	node * next;
	
};

class break_activity
{

	public:
		break_activity(); 	//constructor
		~break_activity();	//destructor - deallocate the dynamic memory
//		void read_all();	//read's activities from the user until they hit the capacity of the array
		void display_all();	//display's all stored activities for the array
		void InsertAtEnd();	//Inserts item information into a Linear Linked List
		void goAgain(); 	//Does the user want to enter enother item?
	private:

//		activity_details * list;	// a pointer used to dynamically allocate memory to the array
		node * head;
		int counter;			// used to count the number of entries read in from the user
		int length;			// used to measure the maximum size of the array
		


};
