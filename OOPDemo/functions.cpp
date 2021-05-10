#include "project4.h"

/*

My name is Kenneth Huddleston and this is the execution file for project 4 in CS162.
The purpose of this file is to contain the implementation of the class and structure interfaces, contained in the header file.

My data members are:

	char activity_name[41];		 // Change this later to use dynamic memory
	char description[131];		 // Brief description of the activity
	char why_important[101];	 // Prompt for the user to enter why the activity is important. Why do it on spring break?
	char length_of_time[11];	 // How long will the activity take? Stored as an array of characters.
	double cost_of_activity;	 // The cost of the activity.
*/


// This is the activity_details constructor, used to store activity info entered by the user
activity_details::activity_details()
{
	activity_name = NULL;
	description[0] = '\0';
	why_important[0] = '\0';
	length_of_time[0] = '\0';
	cost_of_activity = 0.00;
}

// this is the activity_details destructor
activity_details::~activity_details()
{
	delete [] activity_name;
}

// this is the break_activity class constructor
break_activity::break_activity()
{	
//	list = new activity_details[length]; 
	head = NULL;
	counter = 0;
}

// this is the break_activity class destructor

break_activity::~break_activity()
{
	node * temp = head -> next;
	while (temp != NULL) {
		delete head;
		head = temp;
		temp = temp -> next;
	}
}

// execution of function that reads a single activity input from the user
void activity_details::read_activity()
{
	char temp[41]; //used to temporarily store the name of the activity before transferring to a dynamically sized array
	cout << "Please enter the name of your activity : " << endl;
	cin.get(temp, 40, '\n');
	activity_name = new char[strlen(temp)+1];
	strcpy(activity_name, temp);

	cin.ignore(100, '\n');
	cout << "Enter a description of your activity (maximum of 130 characters) : " << endl;
	cin.get(description, 130, '\n');
	cin.ignore(100, '\n');
	cout << "Why is it important to do this activity on your break? (maximum of 100 characters) : " << endl;
	cin.get(why_important, 100, '\n');
	cin.ignore(100, '\n');
	cout << "How long would your activity take to complete? (maximum of 10 characters) : " << endl;
	cin.get(length_of_time, 10, '\n');
	cin.ignore(100, '\n');
	cout << "Please enter the estimated cost of this activity (enter this as a decimal with no dollar sign. For instance, 500.00) : " << endl;
	cin >> cost_of_activity;
	cin.ignore(100, '\n');

}

void break_activity::InsertAtEnd () {
	if (head == NULL) {
		head = new node;
		head->data.read_activity();
		head->next = NULL;
	} else {
		node * current = head;
		while (current -> next != NULL) {
			current = current -> next;
		}
		current->next = new node;
		current = current->next; //traverse to this node
		current->data.read_activity();
		current->next = NULL;
	}
}

void break_activity::goAgain () {
	char response = 'y'; //does the user want to enter another activity?
	cout << "Would you like to add another acitivity? (enter 'y' for yes and 'n' for no) : ";
	cin >> response;
	cin.ignore(100, '\n');
	while (tolower(response) == 'y') {
		InsertAtEnd();
		cout << "Would you like to add another acitivity? (enter 'y' for yes and 'n' for no) : ";
		cin >> response;
		cin.ignore(100, '\n');
	}
}

// execution of function that reads input from the user up until the maximum array size is met.
/*
void break_activity::read_all()
{
	char response = 'y';  //does the user want to enter another activity?
	while (tolower(response) == 'y' && counter < length) {
		
		list[counter].read_activity();
		++counter;
		cout << "again?";
		cin >> response;
		cin.ignore(100, '\n');
	}
}
*/
// display's a single activity to the user
void activity_details::display_activity()
{

	cout << activity_name << '\n' << description << '\n' << why_important << '\n' << length_of_time << '\n' << "$" << cost_of_activity << endl;

}

// calls's the display_activity function to display all stored activities to the user
void break_activity::display_all()
{
	/*
	for (int i=0; i < counter; ++i) {
		list[i].display_activity();	 
	}
	*/
	node * current = head;
	while (current != NULL) {	
		current -> data.display_activity();
		current = current -> next;
	}

}

