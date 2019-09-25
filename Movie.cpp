#include "Movie.h"

Movie::Movie()
{
	title = "Nothing";
	year = "Nothing";
	rating = "Nothing";
	length = "Nothing";
	stars = "Nothing";
	actors.push_back("Nothing");
}

Movie::Movie(string newTitle, string newYear, string newRating, string newLength, string newStars, vector <string> newActors)
{
	title = newTitle;
	year = newYear;
	rating = newRating;
	length = newLength;
	stars = newStars;
	actors = newActors;
}

void Movie::addActor()
{
	cout << "Enter the Actor's name you would like to add:" << endl;
	string newName;
	cin.ignore();
	getline(cin, newName);
	actors.push_back(newName);
}

void Movie::removeActor(vector <string> &actors)
{
	cout << "Enter the Actor's name you would like to remove:" << endl;
	string newName;
	cin.ignore();
	getline(cin, newName);
	for (int i = 0; i < actors.size(); i++)
	{
		if (newName == actors[i])
		{
			actors.erase(actors.begin() + i);
		}
	}
}

void Movie::inputValActors(int &num)
{
	while (true)
	{
		if (cin >> num)
		{
			if (num >= 0)
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

bool Movie::operator < (Movie movie)
{
	int i = 0;
	while (i != movie.title.size() && i != this->title.size())
	{
		char a;
		char b;
		if (this->title.at(i) > 90)
		{
			a = this->title.at(i) - 32;
		}
		else
		{
			a = this->title.at(i);
		}
		if (movie.title.at(i) > 90)
		{
			b = movie.title.at(i) - 32;
		}
		else
		{
			b = movie.title.at(i);
		}
		if (a == b)
		{
			i++;
		}
		else
		{
			return a < b;
		}
	}
	return this->title.size() < movie.title.size();
}

bool Movie::operator > (Movie movie)
{
	return this->title != movie.title && this->title < movie.title;
}

bool Movie::operator == (Movie movie)
{
	return this->title == movie.title;
}

bool Movie::operator <= (Movie movie)
{
	return this->title == movie.title || this->title < movie.title;
}

ostream &operator << (ostream &out, Movie &movie)
{
	out << movie.title << "/" << movie.year << "/" << movie.rating << "/" << movie.length << "/" << movie.stars << "/";
	for (int i = 0; i < movie.actors.size(); i++)
	{
		out << movie.actors[i] << ", ";
	}
	return out;
}

istream &operator >> (istream &in, Movie &movie)
{
	string newTitle;
	string newYear;
	string newRating;
	string newLength;
	string newStars;
	vector <string> newActors;
	cout << "Enter the movie's title:" << endl;
	in.ignore();
	getline(in, newTitle);
	movie.title = newTitle;
	cout << "Enter the movie's release year:" << endl;
	getline(in, newYear);
	movie.year = newYear;
	cout << "Enter the movie's rating:" << endl;
	getline(in, newRating);
	movie.rating = newRating;
	cout << "Enter the movie's length:" << endl;
	getline(in, newLength);
	movie.length = newLength;
	cout << "Enter the movie's stars:" << endl;
	getline(in, newStars);
	movie.stars = newStars;

	cout << "How many actors would you like to add to this movie?" << endl;
	int add;
	movie.inputValActors(add);

	for (int i = 0; i < add; i++)
	{
		cout << "Enter the Actor's name:" << endl;
		string newName;
		cin.ignore();
		getline(cin, newName);
		newActors.push_back(newName);
	}
	movie.actors = newActors;

	return in;
}