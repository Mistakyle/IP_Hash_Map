
#include <iostream>
#include  <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;

#include "hash.h"

//The below function reads from a file and constructs our hash table 
void hash :: read()
{
	//working variables
	char* fname = "hack_attempts.txt";
	ifstream inFile;
	string tempIP;
	int totIP = 0;
	int sum = 0;
	bool isFound;
	
	
	inFile.open(fname);
	
	//Checking to make sure the file actually opened
	if(!inFile.is_open())
	{
		cout<<"File failed to open"<<endl;
		exit(3);
	}
	
	//While there is still stuff in the file
	while(inFile>>tempIP)
	{
	
	//computes the hash func, then checks if that ip is already there.
	//In the event that the IP is already there, it will not be inserted
	sum = hashFunc(tempIP, arrSize);
	isFound = hashArray[sum].find(tempIP);
	
	
	//The ip was not in the list to lets add it!
	if(!isFound)
	{
	hashArray[sum].insertAtEnd(tempIP);
	totIP++;
	}
	}
	
	
}


//Calculates the five IP adresses that occur most frequent and reports them to the user.  
void hash :: calctopFive()
{
	int size = 5;
	int topFiveArr[size];
	int minInd =0;
	
	//filling the array with 0s
	for(int i=0;i<size;i++)
	{
		topFiveArr[i]=0;
	}
	
	
	//Loops through the whole array, then through each list checking if
	//the number of times each IP is there is more than the least most 
	//in the current max array
	for(int i=0; i<arrSize; i++)
	{
		for(SLLCell* ptr = hashArray[i].getHead(); ptr!=NULL; ptr = ptr->getNext())
		{
			
				if( ptr->getNum() > topFiveArr[minInd])
				{
					topFiveArr[minInd] = ptr->getNum();
					minInd = computeMin(topFiveArr, size);
				}
		}
	}
	
	cout<<"And the most common IPs occur..."<<endl;
	//Printing to the user the final product 
	for(int i=0; i<size;i++)
	{
		
		cout<<topFiveArr[i]<<endl;
	}
	cout<<"times!"<<endl;
}

//computes the minimum value in the top five array and returns it's index
int hash :: computeMin(int topFive[], int size)
{
	int minVal = topFive[0];
	int minInd = 0;
	
	for(int i=0; i<size; i++)
	{
		if(minVal>topFive[i])
		{
			minVal = topFive[i];
			minInd = i;
		}
	}
	
	return minInd;
}
		
		
	
			
//hash function based on the sum of the ascii values in the ip address 
int hash :: hashFunc(string IP,int N)
{
	int sum = 0;
	for(int i=0; i<IP.length(); i++)
	{
		sum = sum+IP[i];
		
		return sum%N;
	}
}


	
