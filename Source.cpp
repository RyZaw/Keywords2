//Keywords II Code Breaker Training Simulation Program
//A more advanced and challenging version of the Code Breaker Training Simulation Program.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;
using std::cout;
using std::cin;

int main(){

// Display Title of program to user
	cout << "Welcome to the Code Breaker Training Simulation 2.0\n";
// Ask the recruit to login using thier name
	string name;
	cout << "\nPlease enter your name: ";
// Hold the recruit's name in a var, and address them by it throughout the simulation.
	cin >> name;
// Display an overview of what Keywords II is to the recruit 
	cout << "\nWelcome, " << name << ", to Code Breaker\n";
	cout << "Training Simulation: Keywords II\n";
	cout << "In this training, there will be three scrambled words\n";
	cout << "in which you will have to figure out.\n";
	cout << "You have 3 tries for each word.\n";
// Display an directions to the recruit on how to use Keywords
	cout << "Enter 'hint' for help.\n";
	cout << "Enter 'quit' to quit the game.\n";
// Create a collection of 10 words you had wrote down manually
	vector<string>WORDS;
	WORDS.push_back("TRAINING");
	WORDS.push_back("COURAGE");
	WORDS.push_back("INTELLIGENCE");
	WORDS.push_back("TYRANT");
	WORDS.push_back("CHECKMATE");
	WORDS.push_back("ILLEGAL");
	WORDS.push_back("CALCULATED");
	WORDS.push_back("CUSTODY");
	WORDS.push_back("PREPARATION");
	WORDS.push_back("COMPANION");
// Create an int var to count the number of simulations being run starting at 1
	int simCount = 1;

//Placeholder for program execution to come back too
	simulation:

// Display the simulation # is staring to the recruit. 
	cout << "Simulation " << simCount << " initializing.....\n";
	cout << "====================================================\n";
// Pick new 3 random words from your collection as the secret code word the recruit has to guess. 
	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(WORDS.begin(), WORDS.end());
	
//Words to guess and the hints
	const string word1 = WORDS[1];
	const string word2 = WORDS[2];
	const string word3 = WORDS[3];
	
//Number of tries
	int numOfTries = 10;
	int tries = 0;

//Keeps track of the words.
	string soFar1(word1.size(), '-');
	string soFar2(word2.size(), '-');
	string soFar3(word3.size(), '-');

//Keeps track of the letters.
	string usedLetters1 = "";
	string usedLetters2 = "";
	string usedLetters3 = "";
	
// While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret words
	//First Word
	cout << "\nTraining Simulation: Word One\n";
	while ((tries < numOfTries) && ((soFar1 != word1))) {
		//     Tell recruit how many incorrect guesses he or she has left
		cout << "\nYou have " << (numOfTries - tries);
		cout << " guesses left.\n";
		//     Show recruit the letters he or she has guessed
		cout << "You have used the following letters:\n" << usedLetters1 << endl;
		//     Show player how much of the secret word he or she has guessed
		cout << "The word is: \n" << soFar1 << "\n" << endl;

		//     Get recruit's next guess
		cout << "\nEnter your guess: ";
		char guess;
		cin >> guess;
		guess = toupper(guess);

		//     While recruit has entered a letter that he or she has already guessed
		while (usedLetters1.find(guess) != string::npos) {
			cout << "\nYou have already guessed " << guess << endl;
			cout << "Enter your guess: ";
			//	Get recruit ’s guess
			cin >> guess;
			guess = tolower(guess);
		}
		//     Add the new guess to the group of used letters
		usedLetters1 += guess;
		//     If the guess is in the secret word
		//          Tell the recruit the guess is correct
		//          Update the word guessed so far with the new letter
		//     Otherwise
		//          Tell the recruit the guess is incorrect
		//          Increment the number of incorrect guesses the recruit has made
		if (word1.find(guess) != string::npos) {
			cout << "\n" << guess << " is in this word.\n";
			for (unsigned int i = 0; i < word1.length(); i++) {
				if (word1[i] == guess) {
					soFar1[i] = guess;
				}
			}
		}
		else {
			cout << "Apologizes, " << guess << " isn't in this word.\n";
			++tries;
		}
	}

	//This checks to see if the person has guessed the whole word
	//	and if true, there will be an output for
	//	saying you've completed the word
	//	as well as output the word for you to see.
	if (soFar1 == word1) {
		cout << "\nYou have completed the first word.\n";
		cout << "The word is: \n" << soFar1 << "\n" << endl;
	}

	//Second Word
	//	This checks if the User has ended the game
	//	with the incorrect guesses
	//	otherwise
	//	will output the second word simulation
	if (tries < numOfTries) {
		cout << "\nTraining Simulation: Word Two\n";
	}
	while ((tries < numOfTries) && (soFar2 != word2)) {
		//     Tell recruit how many incorrect guesses he or she has left
		cout << "\nYou have " << (numOfTries - tries);
		cout << " guesses left.\n";
		//     Show recruit the letters he or she has guessed
		cout << "You have used the following letters:\n" << usedLetters2 << endl;
		//     Show player how much of the secret word he or she has guessed
		cout << "The word is: \n" << soFar2 << endl;

		//     Get recruit's next guess
		cout << "\nEnter your guess: ";
		char guess;
		cin >> guess;
		guess = toupper(guess);

		//     While recruit has entered a letter that he or she has already guessed
		while (usedLetters2.find(guess) != string::npos) {
			cout << "\nYou have already guessed " << guess << endl;
			cout << "Enter your guess: ";
			//	Get recruit ’s guess
			cin >> guess;
			guess = tolower(guess);
		}
		//     Add the new guess to the group of used letters
		usedLetters2 += guess;
		//     If the guess is in the secret word
		//          Tell the recruit the guess is correct
		//          Update the word guessed so far with the new letter
		//     Otherwise
		//          Tell the recruit the guess is incorrect
		//          Increment the number of incorrect guesses the recruit has made
		if (word2.find(guess) != string::npos) {
			cout << "\n" << guess << " is in this word.\n";
			for (unsigned int i = 0; i < word2.length(); i++) {
				if (word2[i] == guess) {
					soFar2[i] = guess;
				}
			}
		}
		else {
			cout << "Apologizes, " << guess << " isn't in this word.\n";
			++tries;
		}
	}

	//This checks to see if the person has guessed the whole word
	//	and if true, there will be an output for
	//	saying you've completed the word
	//	as well as output the word for you to see.
	if (soFar2 == word2) {
		cout << "\nYou have completed the second word.\n";
		cout << "The word is: \n" << soFar2 << "\n" << endl;
	}

	//Third Word
	//	This checks if the User has ended the game
	//	with the incorrect guesses
	//	otherwise
	//	will output the Third word simulation
	if (tries < numOfTries) {
		cout << "\nTraining Simulation: Word Three\n";
	}
	while ((tries < numOfTries) && (soFar3 != word3)) {
		//     Tell recruit how many incorrect guesses he or she has left
		cout << "\nYou have " << (numOfTries - tries);
		cout << " guesses left.\n";
		//     Show recruit the letters he or she has guessed
		cout << "You have used the following letters:\n" << usedLetters3 << endl;
		//     Show player how much of the secret word he or she has guessed
		cout << "The word is: \n" << soFar3 << endl;

		//     Get recruit's next guess
		cout << "\nEnter your guess: ";
		char guess;
		cin >> guess;
		guess = toupper(guess);

		//     While recruit has entered a letter that he or she has already guessed
		while (usedLetters3.find(guess) != string::npos) {
			cout << "\nYou have already guessed " << guess << endl;
			cout << "Enter your guess: ";
			//	Get recruit ’s guess
			cin >> guess;
			guess = tolower(guess);
		}
		//     Add the new guess to the group of used letters
		usedLetters3 += guess;
		//     If the guess is in the secret word
		//          Tell the recruit the guess is correct
		//          Update the word guessed so far with the new letter
		//     Otherwise
		//          Tell the recruit the guess is incorrect
		//          Increment the number of incorrect guesses the recruit has made
		if (word3.find(guess) != string::npos) {
			cout << "\n" << guess << " is in this word.\n";
			for (unsigned int i = 0; i < word3.length(); i++) {
				if (word3[i] == guess) {
					soFar3[i] = guess;
				}
			}
		}
		else {
			cout << "Apologizes, " << guess << " isn't in this word.\n";
			++tries;
		}
	}

	//This checks to see if the person has guessed the whole word
	//	and if true, there will be an output for
	//	saying you've completed the word
	//	as well as output the word for you to see.
	if (soFar3 == word3) {
		cout << "\nYou have completed the third word.\n";
		cout << "The word is: \n" << soFar3 << "\n" << endl;
	}

	cout << "\n";
	// If the recruit has made too many incorrect guesses
	//     Tell the recruit that he or she has failed the Keywords II course.
	if (tries == numOfTries) {
		cout << "\nYou have failed the Training Simulation.\n";
		cout << "Software terminating.....\n";
		cout << "Please Standby......\n\n";
	}
	// Otherwise
	//     Congratulate the recruit on guessing the secret words
	else {
		cout << "\nCongratulations, "<< name <<", you have guess all of the words in this simulation.\n";
		cout << "Software terminating.....\n";
		cout << "Please Standby......\n\n";
	}
	
	//This outputs the words that was involved in this Training Simulation
	cout << "The words were: " << word1 << ", " << word2 << ", " << word3 << endl;

	// Ask the recruit if they would like to run the simulation again
	cout << "Would you like to start another\n";
	cout << "Training Simulation? Y/N" << endl;
	char YN;
	cin >> YN;
	cout << "\n";

	// If the recruit wants to run the simulation again
	//     Increment the number of simiulations ran counter
	//     Move program execution back up to // Display the simulation # is staring to the recruit. 
	if (toupper(YN) == 'Y') {
		++simCount;
		goto simulation;
	}
	// Otherwise 
	//     Display End of Simulations to the recruit
	//     Pause the Simulation with press any key to continue
	else {
		cout << "\n=======================================================";
		cout << "\nYou have reached the end\n";
		cout << "of this Training Simulation.\n";
		cout << name << " signing out.....\n";
		cout << "Simulation terminating.....\n";
		cout << "Please Standby......\n\n";
	}

	//This pauses the system to where User
	//	can press any key to exit the simulation.
	system("pause");
	return 0;
}