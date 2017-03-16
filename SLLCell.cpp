#include <string>
using namespace std ;
#include "SLLCell.h"


//The below method changes the next member of the cell sent in as a parameter
void SLLCell :: setNext(SLLCell* newName)
{
    next=newName;
}

//The below method returns the next member of the cell
SLLCell* SLLCell :: getNext()
{
    return next;

}

//basic setter
void SLLCell :: setIP(string tempIP)
{
	ipaddress = tempIP;
}

//basic getter
string SLLCell :: getIP()
{
	return ipaddress;
}

//basic method used to add one to the number of times an IP address shows up 
void SLLCell :: incNum()
{
	numTimes++;
}

//basic getter
int SLLCell :: getNum()
{
	return numTimes;
}
