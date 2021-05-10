/*Kenneth Huddleston
CS162
01-11-2021
Program #1
This is a simple calculator coded in C++. The goal of this program is to take the number 'total' (which is 
initialized at 0), and allow the user to perform basic mathmatic operations with that number. Currently 
supports addition, subtraction, division, multiplication, and exponential operations. This calculator 
currently supports both integer  and float values. Doubles are used as the primary data type for the 
sake of versatility and accuracy.
*/

#include <iostream>
#include <cmath>
using namespace std;

void printMenu() { 
/* The purpose of this function is to print out a user-friendly menu that will guide the user through the 
functions of the program. */
	cout << "------------------------" << endl;
	cout << "0. Exit Progam " << endl;
	cout << "1. Addition " << endl;
	cout << "2. Subtraction " << endl;
	cout << "3. Multiplication " << endl;
	cout << "4. Division " << endl;
	cout << "5. Exponential Math" << endl;
	cout << "------------------------" << endl;

}

double sum(double total, double input) { 
//The goal of this function is to add the current total with the user inputted number. 
	double result = 0; //This is the return variable for the function. 
	result = total + input;
	return result;
}

double difference (double total, double input) { 
//The goal of this function is to take the current stored total and subtract the number entered by the user. 
	double result = 0; //This is the return variable for the function.
	result = total - input;
	return result;
}

double product (double total, double input) { 
//The goal of this function is to multiply the user entered number by the current stored total. 
	double result = 0; //This is the return variable for the function.
	result = total * input;
	return result;
}

double quotient (double total, double input) { 
//The goal of this function is to take the user stored total and divide it by any number provided by the user. 
	double result = 0; //This is the return variable for the function. 
	result = total / input;
	return result;
}

double exponential (double total, double input) { 
//The goal of this function is to take the current stored total and apply a user provided exponent value. 
//I.E. if the total is 3 and the user provides 2, the return will be 9. 
	double result = 0; //This is the return variable for the function. 
	result = pow(total, input);
	return result;
}

int main () {
	int selection = 0; //Selection will be used to specify which operation the user would like to perform 
	double total = 0; 
	//total variable will keep a running total for the user. Only flushed when program is exited. 

	do {
	        printMenu();
        	cout << "Your current total is " << total << "." << endl;
        	cout << "Please enter the number of the operation you would like to perform : ";
		cin >> selection;
		if (selection <= 0 || selection >= 6) 
		{
			cout << "Your final total is " << total << "." << endl;
			cout << "Terminating Program ... " << endl;
		} 
		else 
		{
		
			double input; //input will be the user entered int or float that arithmetic is performed on 
			cout << "Please enter a number : ";
			cin >> input;
			if (selection == 1) 
			{
				total = sum(total, input);
			} 
			else if (selection == 2) 
			{
				total = difference(total, input);
			} 
			else if (selection == 3) 
			{
				total = product(total, input);
			} 
			else if (selection == 4) 
			{
				total = quotient(total, input);
			} 
			else if (selection == 5) 
			{
				total = exponential(total, input);
			} 
			else 
			{
				cout << "Sorry. That was not a valid input." << endl;
			}
		}
	} while (selection > 0 && selection <=5);


	return 0;
}
