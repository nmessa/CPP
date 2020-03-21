//Lab Exercise 3/26/2020
//Author: nmessa
// Program to determine the longest non-decreasing sequence in a
// list of randomly generated integers								

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#define SIZE 1000

int main( )
{
	int intarry[SIZE];
	int count;
	int oldmost=1, newmost=1;
	int *oldptr, *newptr;

	srand(time(NULL));

// initialize array with random integers from 1 to 1000
	for(count = 0; count < SIZE; count++)
		intarry[count] = rand()%1000 + 1;

//Initialize pointers by setting them to the beginning of the array
	oldptr = intarry;
	newptr = intarry;

// Search array for non-decreasing numbers
	for(count = 0; count < SIZE; count++)
	{
		if(intarry[count+1] >= intarry[count]) // non-decreasing
			newmost++;  // increment count
		else 
		{   // elements decreasing
			if(newmost > oldmost)  // new king-of-the-hill
			{
				oldmost = newmost; // new max count
				newmost = 1; // reset list counter
				oldptr = newptr; // set pointer to new champ
				newptr = &intarry[count+1]; // move pointer to new sequence
			}
			else  // no new kin-of-hill
			{
				newptr = &intarry[count + 1]; // move pointer to new sequence
				newmost = 1;
			}
		}
	}  // array search completed

	if(newmost > oldmost) // last sequence is king-of-the-hill
	{
		oldmost = newmost;
		oldptr = newptr;
	}

// print out the sequence
	for(count=0; count < SIZE; count++)
		cout << intarry[count] << endl;

// print out the max list (value, address, and length of list)

	cout << "\n\n\nThe longest sequence was " << oldmost << endl;
	cout << "Value\t\tAddress\n";
	for(count = 0; count < oldmost; count++)
	{
		cout << *oldptr << "\t\t" << oldptr << endl;
		oldptr++;
	}
	return 0;
}

//Sample Output
//The longest sequence was 6
//Value           Address
//128             0043EBC4
//363             0043EBC8
//396             0043EBCC
//630             0043EBD0
//769             0043EBD4
//993             0043EBD8