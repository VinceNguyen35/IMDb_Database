#include "BST.h"

void BST::add(Movie newMovie)
{
	Node *newNode = new Node;
	newNode->movie = newMovie;
	newNode->left = NULL;
	newNode->right = NULL;
	add(newNode, root);
}

void BST::add(Node *&newNode, Node *&tree)
{
	if (tree == NULL)
	{
		tree = newNode;
	}
	else if (newNode->movie <= tree->movie)
	{
		add(newNode, tree->left);
	}
	else
	{
		add(newNode, tree->right);
	}
}

void BST::print()
{
	print(root);
	cout << endl;
}

void BST::print(Node *tree)
{
	if (tree != NULL)
	{
		cout << tree->movie << " ";
		print(tree->left);
		print(tree->right);
	}
}

void BST::clear(Node *tree)
{
	if (tree != NULL)
	{
		clear(tree->left);
		clear(tree->right);
		delete tree;
	}
}

void BST::contains()
{
	int val;
	cout << "How would you like to search for your movie?" << endl;
	cout << "1. Search by title" << endl;
	cout << "2. Search by decade" << endl;
	cout << "3. Search by rating" << endl;
	cout << "4. Search by stars" << endl;
	cout << "5. Search by actors" << endl;

	inputValSearch(val);
	if (val == 1)
	{
		cout << "Enter your title:" << endl;
		string searchTitle;
		cin.ignore();
		getline(cin, searchTitle);
		containsTitle(searchTitle, root);
	}
	if (val == 2)
	{
		cout << "Enter your decade:" << endl;
		int decade;
		cin >> decade;
		containsDecade(decade, root);
	}
	if (val == 3)
	{
		cout << "Enter your rating:" << endl;
		string searchRating;
		cin.ignore();
		getline(cin, searchRating);
		containsRating(searchRating, root);
	}
	if (val == 4)
	{
		cout << "Enter your star rating:" << endl;
		string searchStars;
		cin.ignore();
		getline(cin, searchStars);
		containsStars(searchStars, root);
	}
	if (val == 5)
	{
		cout << "Enter your Actor's name:" << endl;
		string searchActor;
		cin.ignore();
		getline(cin, searchActor);
		containsActor(searchActor, root);
	}
}
bool BST::containsTitle(string title, Node *tree)
{
	if (tree != NULL)
	{
		if (title == tree->movie.getTitle())
		{
			cout << tree->movie;
			return true;
		}
		else if (title < tree->movie.getTitle())
		{
			return containsTitle(title, tree->left);
		}
		else
		{
			return containsTitle(title, tree->right);
		}
	}
	return false;
}

bool BST::containsDecade(int decade, Node *tree)
{
	if (tree != NULL)
	{
		int convertedYear = 0;
		for (int i = 0; i < tree->movie.getYear().size(); i++)
		{
			string converter = tree->movie.getYear();
			char a = converter.at(i);
			converter.erase(i);
			convertedYear = convertedYear + (a - 48) * pow(10, 3 - i);
		}
		if (decade/10 == convertedYear/10)
		{
			cout << tree->movie;
			return containsDecade(decade, tree->left);
			return containsDecade(decade, tree->right);
			return true;
		}
		else if (decade / 10 < convertedYear / 10)
		{
			return containsDecade(decade, tree->left);
		}
		else
		{
			return containsDecade(decade, tree->right);
		}
	}
	return false;
}

bool BST::containsRating(string rating, Node *tree)
{
	if (tree != NULL)
	{
		if (rating == tree->movie.getRating())
		{
			cout << tree->movie;
			if (tree->left != NULL)
			{
				return containsRating(rating, tree->left);
			}
			if (tree->right != NULL)
			{
				return containsRating(rating, tree->right);
			}
			return true;
		}
		else if (rating < tree->movie.getRating())
		{
			return containsRating(rating, tree->left);
		}
		else
		{
			return containsRating(rating, tree->right);
		}
	}
	return false;
}

bool BST::containsStars(string stars, Node *tree)
{
	if (tree != NULL)
	{
		if (stars == tree->movie.getStars())
		{
			cout << tree->movie;
			if (tree->left != NULL)
			{
				return containsStars(stars, tree->left);
			}
			if (tree->right != NULL)
			{
				return containsStars(stars, tree->right);
			}
			return true;
		}
		else if (stars < tree->movie.getStars())
		{
			return containsStars(stars, tree->left);
		}
		else
		{
			return containsStars(stars, tree->right);
		}
	}
	return false;
}

bool BST::containsActor(string actor, Node *tree)
{
	if (tree != NULL)
	{
		for (int i = 0; i < tree->movie.getActors().size(); i++)
		{
			if (actor == tree->movie.getActors()[i])
			{
					cout << tree->movie;
					return true;
			}
			else if (actor < tree->movie.getActors()[i])
			{
				return containsActor(actor, tree->left);
			}
			else
			{
				return containsActor(actor, tree->right);
			}
		}
	}
	return false;
}

void BST::remove(string title)
{
	remove(title, root);
}

void BST::remove(string title, Node *&tree)
{
	if (tree != NULL)
	{ //search for node
		if (title < tree->movie.getTitle())
		{
			remove(title, tree->left);
		}
		else if (title > tree->movie.getTitle())
		{
			remove(title, tree->right);
		}
		else
		{
			deleteNode(tree);
		}
	}
}

void BST::deleteNode(Node *&delNode)
{
	if (delNode != NULL)
	{
		if (delNode->right == NULL)
		{ //0 or left child
			Node *temp = delNode->left;
			delete delNode;
			delNode = temp;
		}
		else if (delNode->left == NULL)
		{//right child
			Node *temp = delNode->right;
			delete delNode;
			delNode = temp;
		}
		else
		{ //both children
			Node *temp = delNode->right;
			while (temp->left != NULL)
			{
				temp = temp->left;
			}
			temp->left = delNode->left;
			temp = delNode->right;
			delete delNode;
			delNode = temp;
		}
	}
}

void BST::inputValSearch(int &num)
{
	while (true)
	{
		if (cin >> num)
		{
			if (num >= 1 && num <= 5)
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

void BST::readFile()
{
	fstream file;
	string input;
	file.open("movies.txt", ios::in);
	if (file)
	{
		BST::Node *n;
		n = this->root;
		while (getline(file, input))
		{
			int location = input.find("/");
			string title = input.substr(0, location);
			input.erase(0, location);
			location = input.find("/");
			string year = input.substr(0, location);
			input.erase(0, location);
			location = input.find("/");
			string rating = input.substr(0, location);
			input.erase(0, location);
			location = input.find("/");
			string length = input.substr(0, location);
			input.erase(0, location);
			location = input.find("/");
			string stars = input.substr(0, location);
			input.erase(0, location);
			location = input.find("\end");
			string actorsList = input.substr(0, location);
			input.erase(0, location);

			vector <string> actors;

			while (actorsList.size() != 0)
			{
				int startingPoint = 0;
				int locationActors = actorsList.find("\end");
				string actorName = actorsList.substr(0, locationActors);
				actorsList.erase(0, locationActors);
				for (int i = 0; i < actorName.size(); i++)
				{
					if (actorName.at(i) == ',')
					{
						actors.push_back(actorName.substr(startingPoint, i));
						startingPoint = i;
					}
				}
				actorName.erase(0, startingPoint);
				actors.push_back(actorName);
			}
			Movie movie = Movie(title, year, rating, length, stars, actors);
			add(movie);
		}
		file.close();
	}
	else
	{
		cout << "Could Not Open File." << endl;
	}
}

void BST::printSorted()
{
	printSorted(root);
	cout << endl;
}

void BST::printSorted(Node *tree)
{
	if (tree != NULL)
	{
		printSorted(tree->left);
		cout << tree->movie << endl;
		printSorted(tree->right);
	}
}

Movie BST::titleToAddActor(string title)
{
	return titleToAddActor(title, root);
}

Movie BST::titleToAddActor(string title, Node *tree)
{
	if (tree != NULL)
	{
		if (title == tree->movie.getTitle())
		{
			return tree->movie;
		}
		else if (title < tree->movie.getTitle())
		{
			return titleToAddActor(title, tree->left);
		}
		else
		{
			return titleToAddActor(title, tree->right);
		}
	}
}

int BST::size()
{
	return size(root);
}

int BST::size(Node *tree)
{
	int count = 0;
	if (tree != NULL)
	{
		count = 1;
		count += size(tree->left);
		count += size(tree->right);
	}
	return count;
}

Movie BST::getMovie()
{
	return getMovie(root);
}

Movie BST::getMovie(Node *tree)
{
	return tree->movie;
}