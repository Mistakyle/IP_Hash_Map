
class SLList
{
	//private vars
private:
    SLLCell* head;
    SLLCell* tail;
    int size;

public:
	
	//methods
    SLList();
    bool find(const string &target);
    void insertAtEnd(string temp);
    SLLCell* getHead() const;
    int getSize();
    
};



