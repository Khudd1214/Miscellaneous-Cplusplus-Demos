#include <iostream>
#include <cstring>
using namespace std;

/*
Author - Kenneth Huddleston
Class - CS162
Program - Project #2, Processing Arrays
Details - The purpose of this program is to take a paragraph and a word from the user. The word will then be used
as the basis of a search through the paragraph. The program will count the number of times the user input Word is
present inside the user input paragraph. So "This is an amazing program, is it not?" searched for "is" will
return 2.
*/

void promptParagraph (char paragraph[]); // prompts the user for a paragraph.
void promptWord (char word[]); // prompts the user for a word.
int wordCount (char paragraph[], char word[]); // counts the number of times the word is present in the paragraph.
char goAgain (); // asks the user if they would like to search for another word in the same paragraph.

int main () {

	char response;		// stores the 'y' or 'n' response to the goAgain() function.
	char word[26];		// stores a user input word up to 25 characters (leaving one for the whack zero).
	char paragraph[501];	// stores a user input paragraph of up to 500 characters (leaving one for \zero).

	promptParagraph(paragraph);
	do {
		promptWord(word);

		cout << "This word appears " <<  wordCount(paragraph, word) << " time(s)." <<  endl;

		response = goAgain();

	} while (tolower(response) != 'n');

	return 0;
}


// prompts the user for a paragraph.
void promptParagraph (char paragraph[]) {
	cout << "Please enter a paragraph to search through (max length 500): ";
	cin.get(paragraph, 500);
	cin.ignore(100, '\n');

	
	int sizeOfParagraph = strlen(paragraph);	// stores the size of paragraph, which will be used in the
							// if condition/for loops later in the function.

	for (int i=0; i < sizeOfParagraph; ++i) {
		paragraph[i] = tolower(paragraph[i]);
	}
}

// prompts the user for a word, which will be used to search the paragraph.
void promptWord (char word[]) {
	cout << "Please enter a word to search for (max length 25): ";
	cin.get(word, 25);
	cin.ignore(100, '\n');
	
	int sizeOfWord = strlen(word);		// stores the size of the word, which will be used to structure
						// the if conditions/for loops later in the function.

	for (int i=0; i < sizeOfWord; ++i) {
		word[i] = tolower(word[i]);
	}
}

// counts the number of times the 'word' appears in the 'paragraph'.
int wordCount (char paragraph[], char word[]) {

	int sameLetterCount = 0;			// counts the number of letters common between the user
							// entered 'word' and the current iteration of the
							// 'paragraph' array. The sameLetterCount is used to check
							// when a common letter becomes a common word.

	int wordCount = 0;				// When the sameLetterCount hits the same number as the
							// length of the user entered word, the word count is
							// incremented by one. This variable is returned at the end
							// of the function.

	int sizeOfParagraph = strlen(paragraph);	// used to structure the condition of the first for loop
							// in this function.

	int sizeOfWord = strlen(word);			// used to structure the condition of the second for loop
							// in this function.
	
	for (int i=0; i < sizeOfParagraph; ++i) {
		for (int j=0; j < sizeOfWord; ++j) {
			if (word[j] == paragraph[i+j]) {
				sameLetterCount += 1;
			}

		}
		if (sameLetterCount == sizeOfWord && (paragraph[i + sizeOfWord] == ' ' ||
						paragraph[i + sizeOfWord] == ',' ||
						paragraph[i + sizeOfWord] == '.' ||
						i + sizeOfWord >= sizeOfParagraph
						) && i > 0 && paragraph[i - 1] == ' ') {
			wordCount += 1;
			sameLetterCount = 0;

		} else if (sameLetterCount == sizeOfWord && (paragraph[i + sizeOfWord] == ' ' ||
                                                paragraph[i + sizeOfWord] == ',' ||
                                                paragraph[i + sizeOfWord] == '.' ||
                                                i + sizeOfWord >= sizeOfParagraph
                                                ) && i == 0) {
			wordCount += 1;
			sameLetterCount = 0;
		
		} else {
			sameLetterCount = 0;
		}
	}

	return wordCount;
}

// Gives the use the option to use the same paragraph and perform another search.
// Result is returned to main, where it's used to structure a loop.
char goAgain() {
	char response;  	// stores and returns the user response of 'y' or 'n'. Used to structure
				// do-while loop back in main.

	cout << "Would you like to search for another word in this paragraph? (enter y/n) : ";
	cin >> response;
	cin.ignore(100, '\n');

	return response;
}
