


class SLLCell 
{

//private vars
private:
    SLLCell *next;
    string ipaddress;
    int numTimes;
public:


	//default cons
    SLLCell() 
    {
        next = NULL;
        ipaddress = " ";
        numTimes = 1;
    }


	//methods 
    void setNext(SLLCell *newName);
    SLLCell* getNext();
    void setIP(string tempIP);
    string getIP();
    void incNum();
    int getNum();

};

