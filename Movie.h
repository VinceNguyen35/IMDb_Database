#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**Declaration for the Movie class*/
class Movie
{
	private:
		/**Title of the movie*/
		string title;
		/**Release year of the movie*/
		string year;
		/**Safety rating of the movie*/
		string rating;
		/**Length of the movie*/
		string length;
		/**Audience approval rating of the movie*/
		string stars;
		/**All the actors of the movie*/
		vector <string> actors;
	public:
		/**Default movie constructor*/
		Movie();
		/**
		Creates a movie object
		@param string is the movie title
		@param string is the movie's release year
		@param string is the safety rating of the movie
		@param string is the length of the movie
		@param string is the audience approval rating of the movie
		@param vector <string> is the list of actors in the movie
		*/
		Movie(string, string, string, string, string, vector <string>);
		/**
		Gets the movie's title
		@return string the movie's title
		*/
		string getTitle() { return title; }
		/**
		Gets the movie's release year
		@return string the movie's release year
		*/
		string getYear() { return year; }
		/**
		Get's the safety rating of the movie
		@return string the movie's safety rating
		*/
		string getRating() { return rating; }
		/**
		Gets the length of the movie
		@return string the length of the movie
		*/
		string getLength() { return length; }
		/**
		Gets the audience approval rating of the movie
		@return string the audience approval rating of the movie
		*/
		string getStars() { return stars; }
		/**
		Gets the list of actors in the movie
		@return vector <string> the list of actors in the movie
		*/
		vector <string> getActors() { return actors; }
		/**Adds the name of an actor to a movie*/
		void addActor();
		/**
		Removes an actor from a movie
		@param vector <string> & is the list of actors from a movie to search for the actor's name for removal
		*/
		void removeActor(vector <string> &);
		/**
		Validates how many actors to add
		@param int & is the value to be checked
		*/
		void inputValActors(int &);
		/**
		Checks to make sure the movie titles are in order
		@param Movie is the movie being compared
		@return bool whether the movies being compared are in alphabetical order
		*/
		bool operator < (Movie);
		/**
		Checks to make sure the movie titles are not in order
		@param Movie is the movie being compared
		@return bool whether the movies being compared are not in alphabetical order
		*/
		bool operator > (Movie);
		/**
		Checks if the movie titles are the same
		@param Movie is the movie being compared
		@return bool whether the movies being compared have the same titles
		*/
		bool operator == (Movie);
		/**
		Checks if the movie titles are similar
		@param Movie is the movie being compared
		@return bool whether the movies being compared have similar titles
		*/
		bool operator <= (Movie);
		/**
		Extends the usage of the "cout" operator
		@param ostream &out is what is being spewed out with the "cout" operator
		@param Movie &movie is the movie being processed for spewing out
		@return ostream & the content of the movie being spewed out
		*/
		friend ostream &operator << (ostream &out, Movie &movie);
		/**Extends the usage of the "cin" operator
		@param istream &in is what is being put into the "cin" operator
		@param Movie &movie is the movie being processed for inputting
		@return istream & the new movie created after inputting
		*/
		friend istream &operator >> (istream &in, Movie &movie);
};
#endif