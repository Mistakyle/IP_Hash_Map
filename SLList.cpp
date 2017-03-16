
#include <string>
using namespace std;
#include "SLLCell.h"
#include "SLList.h"

		//default constructor
    SLList::SLList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    
    //find method that loops through the list searching for the passed IP address
 bool SLList ::find (const string &target)
    {
		bool found = false;

        for (SLLCell *ptr = head; ptr != NULL; ptr = ptr->getNext())
        {
            if (ptr->getIP() == target)
            {
				ptr->incNum();
                found=true;
            }

        }

        return found;
    }
  
    

    //getter method for the head
    SLLCell* SLList :: getHead() const
    {
        return head;
    }

    //The below method takes as imput an ipaddress and allocates a cell with the given IP
    //That cell is then added to the end of the list 
    void SLList::insertAtEnd(string ipaddress)
    {
		SLLCell* temp = new SLLCell();
		temp->setIP(ipaddress);

        //If the SLList is not empty...
        if (tail != NULL)
        {
            tail->setNext(temp);
        }
        //Otherwise set the head to the new cell since it will be the first
        else
        {
            head = temp;
        }
        //set the tail equal to the cell we just entered at the end
        tail = temp;
        size++;
    }


