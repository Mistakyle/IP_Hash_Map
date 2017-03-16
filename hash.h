#include "SLLCell.h"
#include "SLList.h"

class hash
{
	
	//private vars
	private:
	SLList* hashArray;
	SLList hashList;
	int arrSize = 0;
	
	
	public:
	
	//default constructor that does nothing
	hash()
	{
		//ayy
	}
	
	//Actual constructor that allocates our hash array
	hash(int size)
    {
	hashArray = new SLList[size];
	arrSize = size;
	
	}
	
	//methods
	void read();
	int hashFunc(string IP,int N);
	int computeMin(int arr[], int size);
	void calctopFive();

	
};
	
