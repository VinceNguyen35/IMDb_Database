// EXTRA CREDIT.cpp : Defines the entry point for the console application.
//

#include "Movie.h"
#include "BST.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

/**
Checks the user's main menu input is valid
@param int &num is the user's input
*/
void inputValMenu(int &num)
{
	while (true)
	{
		if (cin >> num)
		{
			if (num >= 1 && num <= 7)
			{
				break;
			}
			else
			{
				cout << "Invalid Input" << endl;
			}
		}
		else
		{
			cin.clear(); //clear out invalid input
			string invalid;
			cin >> invalid;
			cout << "Invalid Input" << endl;
		}
	}
}

/**Main function of the program*/
int main()
{
	BST bst;
	bst.readFile();

	bool menu = true;
	while (menu)
	{
		cout << "What would you like to do?" << endl;
		cout << "1. Add a New Movie" << endl;
		cout << "2. Delete Movie" << endl;
		cout << "3. Add an Actor to a Movie" << endl;
		cout << "4. Delete Actor from a Movie" << endl;
		cout << "5. Display All Movies in Alphabetical Order" << endl;
		cout << "6. Find a Movie" << endl;
		cout << "7. Quit" << endl;

		int menuOption;
		inputValMenu(menuOption);

		if (menuOption == 1)
		{
			Movie movie;
			cin >> movie;
			bst.add(movie);
		}
		if (menuOption == 2)
		{
			cout << "Enter your movie title:" << endl;
			string titleRemove;
			cin.ignore();
			getline(cin, titleRemove);
			bst.remove(titleRemove);
		}
		if (menuOption == 3)
		{
			cout << "Enter a movie title:" << endl;
			string titleSearch;
			Movie movie;
			cin.ignore();
			getline(cin, titleSearch);
			movie = bst.titleToAddActor(titleSearch);
			bst.remove(titleSearch);
			movie.addActor();
			bst.add(movie);
		}
		if (menuOption == 4)
		{
			cout << "Enter a movie title:" << endl;
			string titleSearch;
			Movie movie;
			cin.ignore();
			getline(cin, titleSearch);
			movie = bst.titleToAddActor(titleSearch);
			bst.remove(titleSearch);
			movie.removeActor(movie.getActors());
			bst.add(movie);
		}
		if (menuOption == 5)
		{
			bst.printSorted();
		}
		if (menuOption == 6)
		{
			bst.contains();
		}
		if (menuOption == 7) //writes back to the file before quitting
		{
			fstream file;
			file.open("movies.txt", ios::out | ios::trunc);
			if (file)
			{
				for (int i = 0; i < bst.size(); i++)
				{
					Movie movie = bst.getMovie();
					file << movie.getTitle() << "/" << movie.getYear() << "/" << movie.getRating() << "/" << movie.getLength() << "/" << movie.getStars() << "/";
					for (int j = 0; j < movie.getActors().size(); j++)
					{
						vector <string> list = movie.getActors();
						file << list[i] << ",";
					}
					file << endl;
				}
				file.close();
			}
			else
			{
				cout << "Error Opening File" << endl;
			}
			break;
		}
	}
	cin.get(); //stops the program to see the final result
    return 0;
}
