/*
* Amanuel Fufa, Caleb Brace, Caleb McGraw
* CIS 227
* Week 7
*
* 1/27/21 - 3/8/21
*/

#include <iostream>
#include "Header.h"

//Namespaces
using namespace std;



//Globals

//Function Declaration

//Function Definition
int main(int argc, char* argv[]) {

	//inputs

	int menuChoice;
	int wordChoice;
	string initials;

	string guess;
	string wordToDisplay;
	GameHandler gamer;
	
		//initials
		cout << "Please input your 3 initials: ";
		cin >> initials;

		initials = initials.substr(0, 3);

		gamer.setInitials(initials);

	while (true) {

		

		//Menu
		cout << "\n\n1: Get a word from an array\n" <<
			"2: Get word from text file\n" <<
			"3: Reset Initials\n" <<
			"4: High Scores\n"
			"5: To Exit\n" <<
			"Please Select an Option from the List: ";
		cin >> menuChoice;

		bool checkedScope = gamer.ValidateMenuScope(menuChoice);


		while (checkedScope) {

			//Switch & Cases for Menu
			switch (menuChoice) {

				//Case 1: Run from integrated array
			case 1:

				//Get # for word
				cout << "Choose a number (1-12): ";
				cin >> wordChoice;

				//if number is between 1-12 run
				if (gamer.ValidateArrayScope(wordChoice)) {



					do {
						//if true then private array
						gamer.hide(true, wordChoice);

						cout << "Please enter your guess" << endl;
						cin >> guess;

						//check if users guess was valid
						gamer.checkGuess(guess);


					} while (gamer.gameState());

					gamer.display(true, wordChoice);

					checkedScope = false;
					break;

					//else out of range
				}
				else {
					cout << endl << "out of range" << endl << endl;


					checkedScope = false;
					break;

				}


				//Run From File
			case 2:

				//Get # for word
				cout << "Choose a number (1-12): ";
				cin >> wordChoice;

				//if number is between 1-12 run
				if (gamer.ValidateArrayScope(wordChoice)) {



					do {

						// if false then file 
						gamer.hide(false, wordChoice);

						cout << "Please enter your guess" << endl;
						cin >> guess;

						//check if users guess was valid
						gamer.checkGuess(guess);

					} while (gamer.gameState());

					gamer.display(false, wordChoice);

					checkedScope = false;
					break;

					//else out of range
				}
				else {
					cout << endl << "out of range" << endl << endl;

					checkedScope = false;
					break;

				}


				//Case 3: reset initials
			case 3:
				//initials
				cout << "Please input your 3 initials: ";
				cin >> initials;

				initials = initials.substr(0, 3);

				gamer.setInitials(initials);
				
				checkedScope = false;
				break;


				//output highscores
			case 4:
				gamer.readScoreFile();
				checkedScope = false;
				break;

				//Case 5: Exit Program
			case 5:
				exit(0);

				//Else: go to menu
			default:
				checkedScope = false;
				break;
			}
		}
	}
}