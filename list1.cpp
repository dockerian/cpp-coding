#include<iostream>
using namespace std;

class linkedList
{
	public:
		linkedList() {current = 0; header = 0;}
		~linkedList(){makeEmpty();}

		void insert(const int &X);
		//int remove(const int &X);
		//int find(const int &X);
		void makeEmpty();
		void print();

	private:
		struct listNode
		{
			int	item;
			listNode *next;
		};

		listNode *header;
		listNode *current;
};


void linkedList::makeEmpty()
{
	listNode *ptr;
	listNode *nextNode;

	for(ptr = header; ptr != NULL; ptr = nextNode)
	{
		nextNode = ptr->next;
		delete ptr;
	}
	header = NULL;
}

void linkedList::insert(const int &X)
{
	listNode *prePtr = NULL;
	listNode *ptr = new listNode;

	ptr->item = X;
	ptr->next = NULL;
	
	current = header;
	while(current != NULL && X > current->item)
	{
		prePtr = current;
		current = current->next; 
	}
		
	if(prePtr == NULL)
	{
		ptr->next = header;
		header = ptr;
	}
	else
	{
	 	prePtr->next = ptr;
		ptr->next = current;
	}	
}

void linkedList::print()
{
	listNode *ptr;

	ptr = header;
	while(ptr != NULL)
	{
		cout << ptr->item << "\n";
		ptr = ptr->next;
	}
}

int	main()
{
	linkedList L;
	int	value;
	
	for(int i = 0; i < 4; i++)
	{
		cin>>value;
		L.insert(value);
	}

	L.print();

	return 0;
}
	