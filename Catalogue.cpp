//============================================================================
// Name        : Catalogue.cpp
// Author      : Khadeja Khalid & Tiffany Tran
// Version     : Tuesday, February 27, 2018
//============================================================================
#include <iostream>
#include "HashTable.h"
#include "Book.h"
#include <fstream>
#include <string>
#include <sstream>

#include "BST.h"

using namespace std;

int prompt();
void openFile(BST<Book> &bst, HashTable &ht);

int main()
{

	HashTable ht;
	BST<Book> bst;

	int choice;				// menu selection
	string title, author;		// book info for menu operations
	double price;
	unsigned isbn;

	cout << "Welcome to the Best Reads App!\n";

	openFile(bst, ht);

	do{
		choice = prompt();

		switch(choice)
		{
			case 1:			// browse
				cout << "Here is an alphabetical list of the books in our catalogue:\n\n";
				bst.inOrderPrint(cout);
				break;

			case 2:			// insert
			{
				cout << "Enter the title: ";
				cin.ignore();
				getline(cin, title);
				cout << "Enter the author: ";
				getline(cin, author);
				cout << "Enter the price: ";
				cin >> price;
				cout << "Enter the ISBN: ";
				cin >> isbn;

				Book b2(title, author, price, isbn);
				ht.insert(b2);
				bst.insert(b2);
				cout << endl << title << " has been added to the catalogue\n";

			}
			break;

			case 3:			// remove
			{
				double price = 0.0;
				unsigned isbn = 0;
				cout << "Enter the title of the book to remove: ";
				cin.ignore();
				getline(cin, title);
				cout << "Enter the author: ";
				getline(cin, author);

				Book b3(title, author, price, isbn);
				ht.remove(b3);
				bst.remove(b3);
				cout << endl << title << " has been removed from the catalogue\n";
			}
			break;

			case 4:			//search
			{
				cout << "Enter the title of the book: ";
				cin.ignore();
				getline(cin, title);
				cout << "Enter the author: ";
				getline(cin, author);

				Book b4(title, author, price, isbn);
				if(ht.search(b4) != -1)
					cout << endl << title << " is in the catalogue\n";
				else
					cout << endl << title << " is not in the catalogue\n";
			}
			break;

			case 5:        // quit
			{
				ofstream outFile;
				outFile.open("catalogue2.txt");
				bst.inOrderPrint(outFile);
				outFile.close();
				cout << "Happy Reading!\n";
			}
		}

	} while(choice != 5);

	return 0;
}

// prompt user for choice. loops while choice is invalid.
// returns valid choice number
int prompt()
{

	string input = "0";

	do{
		cout << "\nWhat would you like to do?\n"
			 << "1. Browse catalogue by title\n"
			 << "2. Insert a new book\n"
			 << "3. Remove a book\n"
			 << "4. Search for a book\n"
			 << "5. Quit\n\n"
			 << "Enter your choice: ";
		cin >> input;
		cout << endl;

		if(!isdigit(input[0]))
		{
			cout << "Please enter numbers not letters.\n";
			input = "0";
		}
		else if(!(input == "1" || input == "2" || input == "3" || input == "4" || input == "5"))
		{
			cout << "Invalid input.\n";
			input = "0";
		}


	}while(input == "0");	// loop while choice is invalid (choice == 0)

	int choice = atoi(input.c_str());

	return choice;

}

// reads in Books from "catalogue.txt" file and inserts them into the
// binary search tree and hash table parallel-ly
void openFile(BST<Book> &bst, HashTable &ht)
{
	string title, author;			// book info for menu operations
	double price;
	unsigned isbn;
	ifstream file;

	file.open("Catalogue.txt");

	if(!file)
	{
		cout << "\nError opening file.\n";
		assert(!file.fail());	// halt program w/ error message
	}

	else
	{

		while(getline(file, title))
		{
			getline(file, author);
			file >> price >> isbn;

			Book b(title, author, price, isbn);
			bst.insert(b);
			ht.insert(b);

			file >> ws;
		}

		file.close();
	}
}
/*
Welcome to the Best Reads App!

What would you like to do?
1. Browse catalogue by title
2. Insert a new book
3. Remove a book
4. Search for a book
5. Quit

Enter your choice: 8

Invalid input.

What would you like to do?
1. Browse catalogue by title
2. Insert a new book
3. Remove a book
4. Search for a book
5. Quit

Enter your choice: 10

Invalid input.

What would you like to do?
1. Browse catalogue by title
2. Insert a new book
3. Remove a book
4. Search for a book
5. Quit

Enter your choice: one

Please enter numbers not letters.

What would you like to do?
1. Browse catalogue by title
2. Insert a new book
3. Remove a book
4. Search for a book
5. Quit

Enter your choice: two

Please enter numbers not letters.

What would you like to do?
1. Browse catalogue by title
2. Insert a new book
3. Remove a book
4. Search for a book
5. Quit

Enter your choice: 1

Here is an alphabetical list of the books in our catalogue:

A Face like Glass by Frances Hardinge
$15.95
ISBN#: 4455443

A Room with a View by E.M. Forster
$7.50
ISBN#: 1177889

Bleak House by Charles Dickens
$8.99
ISBN#: 3567897

Fangirl by Rainbow Rowell
$10.79
ISBN#: 2413725

Jane Eyre by Charlotte Bronte
$7.90
ISBN#: 2345674

Lady Audley's Secret by Mary Elizabeth Braddon
$5.50
ISBN#: 1212134

Middlemarch by George Elliot
$12.50
ISBN#: 1256743

Murder on the Orient Express by Agatha Christie
$2.99
ISBN#: 9837583

Our Souls at Night by Kent Haruf
$11.99
ISBN#: 7847489

Outlander by Diana Galbadon
$19.95
ISBN#: 5466565

Ramona Blue by Julie Murphy
$9.99
ISBN#: 9328311

Rebecca by Daphe Dumaurier
$5.50
ISBN#: 3242382

The Hunger Games by Suzanne Collins
$6.90
ISBN#: 4232322

The Time in Between by Maria Duenas
$9.86
ISBN#: 4345344

The Woman in White by Wilkie Collins
$10.75
ISBN#: 3256789


What would you like to do?
1. Browse catalogue by title
2. Insert a new book
3. Remove a book
4. Search for a book
5. Quit

Enter your choice: 2

Enter the title: Harry Potter
Enter the author: J.K Rowling
Enter the price: 8.99
Enter the ISBN: 4222222

Harry Potter has been added to the catalogue

What would you like to do?
1. Browse catalogue by title
2. Insert a new book
3. Remove a book
4. Search for a book
5. Quit

Enter your choice: 1

Here is an alphabetical list of the books in our catalogue:

A Face like Glass by Frances Hardinge
$15.95
ISBN#: 4455443

A Room with a View by E.M. Forster
$7.50
ISBN#: 1177889

Bleak House by Charles Dickens
$8.99
ISBN#: 3567897

Fangirl by Rainbow Rowell
$10.79
ISBN#: 2413725

Harry Potter by J.K Rowling
$8.99
ISBN#: 4222222

Jane Eyre by Charlotte Bronte
$7.90
ISBN#: 2345674

Lady Audley's Secret by Mary Elizabeth Braddon
$5.50
ISBN#: 1212134

Middlemarch by George Elliot
$12.50
ISBN#: 1256743

Murder on the Orient Express by Agatha Christie
$2.99
ISBN#: 9837583

Our Souls at Night by Kent Haruf
$11.99
ISBN#: 7847489

Outlander by Diana Galbadon
$19.95
ISBN#: 5466565

Ramona Blue by Julie Murphy
$9.99
ISBN#: 9328311

Rebecca by Daphe Dumaurier
$5.50
ISBN#: 3242382

The Hunger Games by Suzanne Collins
$6.90
ISBN#: 4232322

The Time in Between by Maria Duenas
$9.86
ISBN#: 4345344

The Woman in White by Wilkie Collins
$10.75
ISBN#: 3256789


What would you like to do?
1. Browse catalogue by title
2. Insert a new book
3. Remove a book
4. Search for a book
5. Quit

Enter your choice: 3

Enter the title of the book to remove: Murder on the Orient Express
Enter the author: Agatha Christie

Murder on the Orient Express has been removed from the catalogue

What would you like to do?
1. Browse catalogue by title
2. Insert a new book
3. Remove a book
4. Search for a book
5. Quit

Enter your choice: 1

Here is an alphabetical list of the books in our catalogue:

A Face like Glass by Frances Hardinge
$15.95
ISBN#: 4455443

A Room with a View by E.M. Forster
$7.50
ISBN#: 1177889

Bleak House by Charles Dickens
$8.99
ISBN#: 3567897

Fangirl by Rainbow Rowell
$10.79
ISBN#: 2413725

Harry Potter by J.K Rowling
$8.99
ISBN#: 4222222

Jane Eyre by Charlotte Bronte
$7.90
ISBN#: 2345674

Lady Audley's Secret by Mary Elizabeth Braddon
$5.50
ISBN#: 1212134

Middlemarch by George Elliot
$12.50
ISBN#: 1256743

Our Souls at Night by Kent Haruf
$11.99
ISBN#: 7847489

Outlander by Diana Galbadon
$19.95
ISBN#: 5466565

Ramona Blue by Julie Murphy
$9.99
ISBN#: 9328311

Rebecca by Daphe Dumaurier
$5.50
ISBN#: 3242382

The Hunger Games by Suzanne Collins
$6.90
ISBN#: 4232322

The Time in Between by Maria Duenas
$9.86
ISBN#: 4345344

The Woman in White by Wilkie Collins
$10.75
ISBN#: 3256789


What would you like to do?
1. Browse catalogue by title
2. Insert a new book
3. Remove a book
4. Search for a book
5. Quit

Enter your choice: 4

Enter the title of the book: Murder on the Orient Express
Enter the author: Agatha Christie

Murder on the Orient Express is not in the catalogue

What would you like to do?
1. Browse catalogue by title
2. Insert a new book
3. Remove a book
4. Search for a book
5. Quit

Enter your choice: 4

Enter the title of the book: Harry Potter
Enter the author: J.K Rowling

Harry Potter is in the catalogue

What would you like to do?
1. Browse catalogue by title
2. Insert a new book
3. Remove a book
4. Search for a book
5. Quit

Enter your choice: 5

Happy Reading!

*/



