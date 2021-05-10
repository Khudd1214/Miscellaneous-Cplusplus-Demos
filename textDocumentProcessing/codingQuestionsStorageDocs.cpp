#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;

/*
Author - Kenneth Huddleston
Class - CS162 Program 3
Purpose - The purpose of this program is to store and display coding questions to the user. The program will also
provide the user the option to add additional questions to the program and to long term storage (via txt files).
The program will continue until the user chooses to exit.
*/


//constants

const int SIZE = 10;
const int KSIZE = 21;
const int DSIZE = 14;
const int QSIZE = 301;


//Structures

struct questionBank {
	char keyword[KSIZE];
	char difficulty[DSIZE];
	char question[QSIZE];
};

//Prototypes

void addQuestion (questionBank array[], int &  numOfQuestions); // adds a question to the program (not memory)
void storeQuestion (questionBank array[], char destinationFile[], int numOfQuestions); // stores a question in 
										// long term memory
void fileRead(questionBank array[], char fileName[], int & numOfQuestions); // reads in existing questions
									//from source files
int menu(); // collects an integer value from the user that represents what operation they would like to perform
void DisplayByDifficulty (questionBank array1[], questionBank array2[], questionBank array3[],
			  questionBank array4[], int numOfQuestionsFunctions, int numOfQuestionsConditionals,
			  int numOfQuestionsLoops, int numOfQuestionsStructures);
			// Displays questions of a certain difficulty
void DisplayAll (questionBank array1[], questionBank array2[], questionBank array3[],
		 questionBank array4[], int numOfQuestionsFunctions, int numOfQuestionsConditionals,
		 int numOfQuestionsLoops, int numOfQuestionsStructures);
			// Displays all questions currently in the program
int filePrompt (); // Used to collect an int from the user, which is used to specify what file/structure
		// a new question will be stored in.
char promptToStore (); // collects a y/n char response from the user, which is used to determine IF a question
			// should be saved into long term memory

//Main

int main () {
	
	int userSelection; // used in conjuction with menu() to give the user choice of operations

	int numOfQuestionsFunctions = 0; // keeps track of the number of questions in the Functions array
	int numOfQuestionsConditionals = 0; // number of questions used in Conditionals array
	int numOfQuestionsLoops = 0; // number of questions used in Loops array
	int numOfQuestionsStructures = 0; // number of questions used in Structures array

	char fileOne[25] = "functions.txt"; //houses destination file for Functions Questions
	char fileTwo[25] = "conditionals.txt"; //houses destination file for conditional questions
	char fileThree[25] = "loops.txt"; // houses destination file for loop questions
	char fileFour[25] = "structures.txt"; // houses destination file for structure questions

	questionBank functionQuestions[SIZE]; //initializes array of structures
	questionBank conditionalQuestions[SIZE]; //initializes array of structures
	questionBank loopQuestions[SIZE]; //initializes array of structures
	questionBank structureQuestions[SIZE]; //initializes array of structures

	fileRead(functionQuestions, fileOne, numOfQuestionsFunctions);
	fileRead(conditionalQuestions, fileTwo, numOfQuestionsConditionals);
	fileRead(loopQuestions, fileThree, numOfQuestionsLoops);
	fileRead(structureQuestions, fileFour, numOfQuestionsStructures);

	do {

	userSelection = menu();

		switch (userSelection) {

			case 1:
				DisplayAll(functionQuestions, conditionalQuestions, loopQuestions, 
					structureQuestions, numOfQuestionsFunctions, numOfQuestionsConditionals,
					numOfQuestionsLoops, numOfQuestionsStructures);
				break;
			case 2:
				DisplayByDifficulty(functionQuestions, conditionalQuestions, loopQuestions, 
					structureQuestions, numOfQuestionsFunctions, numOfQuestionsConditionals,
					numOfQuestionsLoops, numOfQuestionsStructures);
				break;
			case 3:
				int fileSelection = filePrompt(); //collects user choice of destination file
				char prompt; //asks the user if they will store a question in long term memory
				if (fileSelection == 1) {
					addQuestion(functionQuestions, numOfQuestionsFunctions);
					prompt = promptToStore();
					if (prompt == 'y') {
						storeQuestion(functionQuestions, fileOne, numOfQuestionsFunctions);
					}
				} else if (fileSelection == 2) {
					addQuestion(conditionalQuestions, numOfQuestionsConditionals);
					prompt = promptToStore();
					if (prompt == 'y') {
						storeQuestion(conditionalQuestions, fileTwo, numOfQuestionsConditionals);
					}
				} else if (fileSelection == 3) {
					addQuestion(loopQuestions, numOfQuestionsLoops);
					prompt = promptToStore();
					if (prompt == 'y') {
						storeQuestion(loopQuestions, fileThree, numOfQuestionsLoops);
					}
				} else if (fileSelection == 4) {
					addQuestion(structureQuestions, numOfQuestionsStructures);
					prompt = promptToStore();
					if (prompt == 'y') {
						storeQuestion(structureQuestions, fileFour, numOfQuestionsLoops);
					}
				}
		}
	
	} while (userSelection >= 1 && userSelection <= 3);

	return 0;
}

//functions

int menu () { // returns userSelection value to power loop in main
	int userSelection = 0; // stores user value locally.
	do {
		cout << "-------------------------------------------------------------" << endl;
		cout << "1. View all available questions" << endl;
		cout << "2. View questions by difficulty" << endl;
		cout << "3. Add a new question to the program (not long term storage)" << endl;
		cout << "4. Exit the program" << endl;
		cout << "-------------------------------------------------------------" << endl;

		cout << "Please select an option : ";
		cin >> userSelection;
		cin.ignore(100, '\n');
		
	} while (!(userSelection > 0 && userSelection < 5));
	return userSelection;
}

void fileRead(questionBank array[], char fileName[], int & numOfQuestions) {


	ifstream file_in;

	int i = numOfQuestions; // number of questions stored locally, then referenced back to main
	int j = 0; // index counter

	file_in.open(fileName);

	if (file_in) {
		
		file_in.get(array[j].keyword, KSIZE, ':');
		file_in.ignore(100, ':');

		while (file_in && !file_in.eof() && j < SIZE)
		{
			file_in.get(array[j].difficulty, 14, ':');
			file_in.ignore(100, ':');
			file_in.get(array[j].question, 310, '\n');
			file_in.ignore(310, '\n');
			++j;
			++i;
			file_in.get(array[j].keyword, KSIZE, ':');
			file_in.ignore(100, ':');
			
		}
	}

	numOfQuestions = i;
	file_in.close();
}
void addQuestion (questionBank array[], int & numOfQuestions) {

	int i = numOfQuestions; // number of questions stored locally, then referenced back to main


	cout << "Please enter a keyword that describes your question (max of 10 characters) : ";
	cin.get(array[i].keyword, KSIZE - 1, '\n');
	cin.ignore(100, '\n');
	cout << "Please enter the difficulty grade for your question (easy, intermediate, or difficult) : ";
	cin.get(array[i].difficulty, DSIZE - 1, '\n');
	cin.ignore(100, '\n');
	cout << "Please enter your question (100 characters max) : ";
	cin.get(array[i].question, QSIZE - 1, '\n');
	cin.ignore(400, '\n');

	++i;
	numOfQuestions = i;
}
void storeQuestion (questionBank array[], char destinationFile[], int numOfQuestions) {

	ofstream file_out;
	file_out.open(destinationFile, ios::app);
	if (file_out && numOfQuestions > 0) {
		file_out << array[numOfQuestions-1].keyword << ":"
			 << array[numOfQuestions-1].difficulty << ":"
			 << array[numOfQuestions-1].question << endl;
	} else {	
		file_out << array[numOfQuestions].keyword << ":"
			 << array[numOfQuestions].difficulty << ":"
			 << array[numOfQuestions].question << endl;
	}
	file_out.close();
}
void DisplayAll (questionBank array1[], questionBank array2[], questionBank array3[],
		 questionBank array4[], int numOfQuestionsFunctions, int numOfQuestionsConditionals,
		 int numOfQuestionsLoops, int numOfQuestionsStructures)
{
	
	for (int i=0; i<numOfQuestionsFunctions; ++i) {
		cout << array1[i].keyword << endl;
		cout << array1[i].difficulty << endl;
		cout << array1[i].question << endl;
		cout << "---------------------------" << endl;
	}
	
	for (int i=0; i<numOfQuestionsConditionals; ++i) {
		cout << array2[i].keyword << endl;
		cout << array2[i].difficulty << endl;
		cout << array2[i].question << endl;
		cout << "---------------------------" << endl;
	}
	for (int i=0; i<numOfQuestionsLoops; ++i) {
		cout << array3[i].keyword << endl;
		cout << array3[i].difficulty << endl;
		cout << array3[i].question << endl;
		cout << "---------------------------" << endl;
	}
	for (int i=0; i<numOfQuestionsStructures; ++i) {
		cout << array4[i].keyword << endl;
		cout << array4[i].difficulty << endl;
		cout << array4[i].question << endl;
		cout << "---------------------------" << endl;

	}
}

void DisplayByDifficulty (questionBank array1[], questionBank array2[], questionBank array3[],
		 questionBank array4[], int numOfQuestionsFunctions, int numOfQuestionsConditionals,
		 int numOfQuestionsLoops, int numOfQuestionsStructures)

{

	char difficultySelect[13]; //choose the difficulty to sort questions with
	cout << "Please enter easy, intermediate, or hard : ";
	cin.get(difficultySelect, 100, '\n');
	cout << "---------------------------" << endl;

	for (int i=0; i<numOfQuestionsFunctions; ++i) {
		if (strcmp(difficultySelect, array1[i].difficulty) == 0)
		{
			cout << array1[i].keyword << endl;
			cout << array1[i].difficulty << endl;
			cout << array1[i].question << endl;
			cout << "---------------------------" << endl;
		}	
	}
	for (int i=0; i<numOfQuestionsConditionals; ++i) {
		if (strcmp(difficultySelect, array2[i].difficulty) == 0)
		{
			cout << array2[i].keyword << endl;
			cout << array2[i].difficulty << endl;
			cout << array2[i].question << endl;
			cout << "---------------------------" << endl;
		}	
	}
	for (int i=0; i<numOfQuestionsLoops; ++i) {
		if (strcmp(difficultySelect, array3[i].difficulty) == 0)
		{
			cout << array3[i].keyword << endl;
			cout << array3[i].difficulty << endl;
			cout << array3[i].question << endl;
			cout << "---------------------------" << endl;
		}	
	}
	for (int i=0; i<numOfQuestionsStructures; ++i) {
		if (strcmp(difficultySelect, array4[i].difficulty) == 0)
		{
			cout << array4[i].keyword << endl;
			cout << array4[i].difficulty << endl;
			cout << array4[i].question << endl;
			cout << "---------------------------" << endl;
		}	
	}
}

int filePrompt () {

	int selection = 0; //integer represents user choice, stored back in main to power loop

	do {
	cout << "-------------------------------------------------------------" << endl;
	cout << "1. Function" << endl;
	cout << "2. Conditional" << endl;
	cout << "3. Loop" << endl;
	cout << "4. Structure" << endl;
	cout << "-------------------------------------------------------------" << endl;

	cout << "Please choose a question type (enter the corresponding number) : ";
	cin >> selection;
	cin.ignore(100, '\n');

	
	} while (selection > 4 || selection < 1);

	return selection;
}

char promptToStore () {

	char promptToStore; // y/n character to represent yes/no. Used to power loop back in main.
	cout << "Would you like to save this question in long-term memory (enter y/n)? : ";
	cin >> promptToStore;
	cin.ignore(100, '\n');
	promptToStore = tolower(promptToStore);
	
	return promptToStore;
}
