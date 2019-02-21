//============================================================================
// Name        : HashTable.cpp
// Author      : Khadeja Khalid & Tiffany Tran
// Version     : Tuesday, February 27, 2018
//============================================================================

#include <string>
#include "List.h"
#include "Book.h"
#include "HashTable.h"


//*********************** Access Functions *****************************

//returns the hash value for the given key
//the hash value is the sum of
//of the ASCII values of each char in the key
//% the size the of the table
//Key for this table: title + author
int HashTable::hash(string key) const
{
    int index, sum = 0;
    int length = key.length();
    for(int i = 0; i < length; i++)
        sum += (int) key[i];      //summing the ASCII values for each character in the string
    index = sum % SIZE;           //dividing the summed ASCII values by 10 && storing remainder as my index
    return index;
}

//counts the number of Books at this index
//returns the count
//pre: 0<= index < SIZE
int HashTable::countBucket(int index) const
{
	assert (0 <= index && index < SIZE);

	int count = 0; //Start from 0 books
	while(count < Table[index].getLength())
		count++;

	return count;
}

//Searches for b in the table
//returns the index at which b is located
//returns -1 if b is not in the table
int HashTable::search(Book b) const
{

	int index = hash(b.get_title() + b.get_author());

	if (Table[index].linearSearch(b) == -1) //Search through values to until we find b
		return -1;
	else
		return index;                       //If true, return the index of the location
}


//*********************** Manipulation Procedures ************************

//inserts a new book into the table
//calls the hash function on the key to determine
//the correct bucket
void HashTable::insert(Book b)
{
	int index = hash(b.get_title() + b.get_author());

	Table[index].insertLast(b); //Insert book to the end of the chain

}

//removes b from the table
//calls the hash function on the key to determine
//the correct bucket
//pre: b is in the table
void HashTable::remove(Book b)
{
	assert (search(b) != -1); //Precondition

	int index = hash(b.get_title() + b.get_author());

	//You want to iterate through the list
	Table[index].startIterator();

	//Get the numerical spot of where the book is in the chain
	int chainLocation = Table[index].linearSearch(b);

	//Move the iterator to the book's location in the chain
	Table[index].advanceToIndex(chainLocation);

	//Remove it
	Table[index].removeIterator();
}


//*********************** Additional Functions ***************************

//Prints all the books at index
//pre: 0<= index < SIZE
//Should print according to the following formula:
//Prints each book at that index in the format:
//<title> by <author>
//$<X.XX>
//ISBN#: <isbn>
//followed by a blank line
void HashTable::printBucket(ostream& out, int index) const
{
	assert (0 <= index && index < SIZE);
	Table[index].printList(out);
}

//Prints the first book at each index
//along with a count of the total books
//at each index by calling count_bucket
//as a helper function
//Prints in the format:
//Books in the Catalogue:
//<new line>
//Group <bucket>
//<title> by <author>
//$<X.XX>
//ISBN: <isbn>
//+<number of elements at this index> -1 more similar book(s)
//<new line><new line> <new line>
void HashTable::printTable(ostream& out) const
{
	out << "Books in the Catalogue: " << endl << endl;
	for (int i = 0; i < SIZE; i++)
	{
		if (!Table[i].isEmpty()) //Check if it's empty so it doesnt print empty
		{
			out << "Group " << i+1 << endl;
			out << Table[i].getFirst(); //This prints out entire list though
			out << "\n+" << countBucket(i) - 1 << " similar book(s) \n\n\n";
		}
	}
}
