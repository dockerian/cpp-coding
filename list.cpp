#include<iostream>
using namespace std;

template <class T>
class linkedList
{
	public:
		linkedList() {current = 0; header = 0;}
		~linkedList(){makeEmpty();}

		void insert(const T &X);
		//int remove(const T &X);
		//int find(const T &X);
		void makeEmpty();
		void print();

	private:
		struct listNode
		{
			T	item;
			listNode *next;
		};

		listNode *current, *header;
};

template <class T>
void linkedList<T>::makeEmpty()
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

template <class T>
void linkedList<T>::insert(const T &X)
{
	listNode *prePtr;
	listNode *ptr = new listNode;

	ptr->item = X;
	current = header;
	while(current != NULL && current->item < X)
	{
		prePtr = current;
		current = current->next; 
	}
	prePtr->next = ptr;
	ptr->next = current;
}

template <class T>
void linkedList<T>::print()
{
	listNode *ptr;

	ptr = header;
	while(ptr != NULL)
	{
		cout << ptr->item << "@@";
		ptr = ptr->next;
	}
}

int	main()
{
	linkedList<int> L;
	char	value;
	
	for(int i = 0; i < 4; i++)
	{
		cin>>value;
		L.insert(value);
	}

	L.print();

	return 0;
}
	