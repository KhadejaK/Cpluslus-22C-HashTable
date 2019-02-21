////============================================================================
//// Name        : HashTest.cpp
//// Author      : Khadeja Khalid & Tiffany Tran
//// Version     : Tuesday, February 27, 2018
////============================================================================
//
//#include <string>
//#include "List.h"
//#include "Book.h"
//#include "HashTable.h"
//
//using namespace std;
//
//int main()
//{
//	HashTable ht;
//	Book pp("Pride and Prejudice", "Jane Austen", 4.95, 1234567);
//	Book c("Contact", "Carl Sagan", 9.95, 99993339);
//	Book hg("The Hunger Games", "Suzanne Collins", 13.55, 12388888);
//	Book hp("Harry Potter", "J.K. Rowlings", 12.99, 55555678);
//	Book mhc("The Man in the High Castle", "Philip K Dick", 15.95, 95959595);
//	Book bh("Bleak House", "Charles Dickens", 8.00, 473890238);
//
//	ht.insert(pp);
//	ht.insert(c);
//	ht.insert(hg);
//	ht.insert(mhc);
//	ht.insert(bh);
//
//	cout << "Should print the 9th index: \n";
//	ht.printBucket(cout, 9);
//
//	cout << "=============================================\n";
//	ht.printTable(cout);
//	cout << "=============================================\n";
//
//	cout << "Should remove 'The Hunger Games' from 9th index: \n\n";
//	cout << "Before: \n";
//	ht.printBucket(cout, 9);
//	ht.remove(hg);
//	cout << "After: \n";
//	ht.printBucket(cout, 9);
//
//	cout << "=============================================\n";
//	ht.printTable(cout);
//
//	cout << "=============================================\n";
//	if (ht.search(hg) == -1) // should be no
//		cout << "no" << endl;
//	else
//		cout << "yes" << endl;
//
//	if (ht.search(mhc) == -1) // should be yes
//		cout << "no" << endl;
//	else
//		cout << "yes" << endl;
//
//
//
//	return 0;
//}
//
//
///*
//Should print the 9th index:
//The Hunger Games by Suzanne Collins
//$13.55
//ISBN#: 12388888
//
//The Man in the High Castle by Philip K Dick
//$15.95
//ISBN#: 95959595
//
//
//=============================================
//Books in the Catalogue:
//
//Group 1
//Bleak House by Charles Dickens
//$8.00
//ISBN#: 473890238
//
//+0 similar book(s)
//
//
//Group 3
//Pride and Prejudice by Jane Austen
//$4.95
//ISBN#: 1234567
//
//+0 similar book(s)
//
//
//Group 5
//Contact by Carl Sagan
//$9.95
//ISBN#: 99993339
//
//+0 similar book(s)
//
//
//Group 10
//The Hunger Games by Suzanne Collins
//$13.55
//ISBN#: 12388888
//
//+1 similar book(s)
//
//
//=============================================
//Should remove 'The Hunger Games' from 9th index:
//
//Before:
//The Hunger Games by Suzanne Collins
//$13.55
//ISBN#: 12388888
//
//The Man in the High Castle by Philip K Dick
//$15.95
//ISBN#: 95959595
//
//
//After:
//The Man in the High Castle by Philip K Dick
//$15.95
//ISBN#: 95959595
//
//
//=============================================
//Books in the Catalogue:
//
//Group 1
//Bleak House by Charles Dickens
//$8.00
//ISBN#: 473890238
//
//+0 similar book(s)
//
//
//Group 3
//Pride and Prejudice by Jane Austen
//$4.95
//ISBN#: 1234567
//
//+0 similar book(s)
//
//
//Group 5
//Contact by Carl Sagan
//$9.95
//ISBN#: 99993339
//
//+0 similar book(s)
//
//
//Group 10
//The Man in the High Castle by Philip K Dick
//$15.95
//ISBN#: 95959595
//
//+0 similar book(s)
//*/
