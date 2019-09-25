#ifndef BST_H
#define BST_H

#include "Movie.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/**Declaration for the BST class*/
class BST
{
	private:
		/**Contents of the Node*/
		struct Node
		{
			/**The main content of the Node*/
			Movie movie;
			/**The left child of the Node*/
			Node *left;
			/**The right child of the Node*/
			Node *right;
		};
		/**The root of the entire tree*/
		Node *root;
		/**
		Adds a new Node to the tree
		@param Node *& is the new Node being added
		@param Node *& is the tree's location
		*/
		void add(Node *&, Node *&);
		/**
		Print's the contents of the Node
		@param Node * the location of the Node to locate the value
		*/
		void print(Node *);
		/**
		Clears the entire tree
		@param Node * is the starting location for clearing
		*/
		void clear(Node *);
		/**
		Checks if the tree contains a movie bassed on title
		Prints the movie out if the tree contains the title
		@param string the title to check for
		@param Node * is the starting location for checking
		@return bool whether the tree contains the movie
		*/
		bool containsTitle(string, Node *);
		/**
		Checks if the tree contains a movie based on a decade range
		Prints the movie out if the tree contains the decade range
		@param int is the decade to search for
		@param Node * is the starting location for checking
		@return bool whether the tree contains the movie in the decade range
		*/
		bool containsDecade(int, Node *);
		/**
		Checks if the tree contains a movie based on a safety rating
		Prints the movie out if the tree contains the safety rating
		@param string is the safety rating to search for
		@param Node * is the sarting location for checking
		@return bool whether the tree contains the movie based on the safety rating
		*/
		bool containsRating(string, Node *);
		/**
		Checks if the tree contains a movie based on the audience approval rating
		Prints the movie out if the tree contains the audience approval rating
		@param string is the audience approval rating to seach for
		@param Node * is the starting location for checking
		@return bool whether the tree contains the movie based on the audience approval rating
		*/
		bool containsStars(string, Node *);
		/**
		Checks if the tree contains a movie with a specific actor
		Prints out all movies containing the actor's name
		@param string the actor to search for
		@param Node * is the starting location for checking
		@return bool whether the tree contains any movies with the actor
		*/
		bool containsActor(string, Node *);
		/**
		Removes a movie based on title
		@param string the title to search and remove from the tree
		@param Node * is the starting location to search for the title
		*/
		void remove(string, Node *&);
		/**
		Deletes a Node with a specific title
		@param Node *& the Node and its contents being deleted
		*/
		void deleteNode(Node *&);
		/**
		Prints the entire tree sorted
		@param Node * the starting point for printing
		*/
		void printSorted(Node *);
		/**
		Searches for a movie to add an actor to
		@param string the title to search for
		@param Node * the starting location to search for the title
		@return Movie the movie with the title
		*/
		Movie titleToAddActor(string, Node *);
		/**
		Gets the size of the tree
		@param Node * the starting location of the tree
		@return int the size of the tree
		*/
		int size(Node *);
		/**
		Gets the movie from the Node
		@param Node * the Node to get the contents from
		@return Movie the movie in the Node
		*/
		Movie getMovie(Node *);
	public:
		/**Default tree constructor*/
		BST()
		{
			root = NULL;
		}
		/**Destructor for the tree*/
		~BST()
		{
			clear(root);
		}
		/**
		Checks if the tree is empty
		@return bool whether the tree is empty
		*/
		bool isEmpty()
		{
			return root == NULL;
		}
		/**
		Facade to add a new movie to the tree
		@param Movie is the new movie being added
		*/
		void add(Movie);
		/**Prints the tree from top to bottom*/
		void print();
		/**Clears the entire tree*/
		void clear()
		{
			clear(root);
		}
		/**Facade to search for a movie*/
		void contains();
		/**
		Facade to remove a movie based on title
		@param string is the title to search for removal
		*/
		void remove(string);
		/**Reads in the content from a text file*/
		void readFile();
		/**Prints the tree in sorted order*/
		void printSorted();
		/**
		Validates the input for which method to search with
		@param int & is the value being checked
		*/
		void inputValSearch(int &);
		/**
		Facade to add an actor to a movie
		@param string the title to search for when adding an actor
		@return Movie the movie to add the actor to
		*/
		Movie titleToAddActor(string);
		/**
		Facade to the size of the tree
		@return int the size of the tree
		*/
		int size();
		/**
		Facade to getting the movie in a Node
		@return the movie in a Node
		*/
		Movie getMovie();
};
#endif