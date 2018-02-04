// Skynet HK-Aerial - Devon Garrett.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>

//prevents unnecesary repetition of code
using std::cout;
using std::endl;

int main()
{
	cout << "Enemy is finding a new position..." << endl;
	//generates a number between 1 and 64 for enemy position
	srand(time(0));
	int topLimit = 64;
	int bottomLimit = 1;
	int enemyBase = rand() % topLimit + bottomLimit;
	cout << "The enemy base is hidden in Sector #" << enemyBase << " of the 8x8 grid." << endl << endl;

	cout << "Initializing HK-Ariel Drone Protocol..." << endl;
	//initializes all variables for the drone search program
	int numberOfGuesses = 0;
	bool targetFound = false;

	//loop to repeatedly search until enemy is found
	while (targetFound == false)
	{
		int currentGuess = ((topLimit - bottomLimit) / 2) + bottomLimit;
		numberOfGuesses++; //increases guess count
		cout << "=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=" << endl;
		cout << "HK-Aerial Drone currently searching Sector #" << currentGuess << endl;

		//determines if the current guess was higher or lower than the actual location and adjusts search based on this
		if (enemyBase > currentGuess) 
		{
			bottomLimit = currentGuess + 1;
			cout << "The scan of Sector #" << currentGuess << " provided information that showed the base to be in a higher sector." << endl;
			cout << "HK-Aerial Drone is now searching in Sectors #" << bottomLimit << " - #" << topLimit << endl;
		}
		else if (enemyBase < currentGuess)
		{
			topLimit = currentGuess - 1;
			cout << "The scan of Sector #" << currentGuess << " provided information that showed the base to be in a lower sector." << endl;
			cout << "HK-Aerial Drone is now searching in Sectors #" << bottomLimit << " - #" << topLimit << endl;
		}
		else if (enemyBase = currentGuess)
		{
			cout << "Target has ben found in Sector #" << currentGuess << endl;
			cout << "A strike force has been sent to elimminate the targets." << endl;
			cout << "It took the HK-Aerial Drone " << numberOfGuesses << " sector scan(s) in order to find the targets." << endl << endl;
			targetFound = true;
		}
		else
		{
			cout << "Drone has malfunctioned!" << endl;
			cout << "A request has been sent to maintnece." << endl <<endl;
			targetFound = true;
		}
	}

	system("pause");

    return 0;
}

