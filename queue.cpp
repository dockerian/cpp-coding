#include<iostream.h>
#include<stdlib.h>
using namespace std;

template <class T>
class AbsQueue
{
	public:
		AbsQueue() {}
		virtual ~AbsQueue() {}

		virtual void Enqueue(const T &X) = 0;
		virtual void Dequeue() = 0;
		virtual const T &GetFront() const = 0;
		virtual int IsEmpty() const = 0;
		virtual void MakeEmpty() = 0;

	private:
		AsbQueue(const AbsQueue &) {}
};

template <class T>
class Queue : public AbsQueue<T>
{
	public:
		Queue() : Front(NULL), Back(NULL) {}
		~Queue() {MakeEmpty();}

		const Queue &operator=(const Queue &Rhs);

		void Enqueue(const T &X);
		void Dequeue();
		const T &GetFront() const;
		int IsEmpty() const {return Front == NULL;}
		void MakeEmpty();

	private:
		struct QueueNode
		{
			T Item;
			QueueNode *Next;

			QueueNode():Next(NULL){}
			QueueNode(const T &E, QueueNode *N = NULL):
				Item(E), Next(N) {}
		};
		QueueNode *Front, *Back;
};

template <class T>
const Queue<T> &
Queue<T>::operator=(const Queue<T> &Rhs)
{
	if(this == &Rhs)
		return Rhs;

	MakeEmpty();
	if(Rhs.IsEmpty())
		return *this;

	QueueNode *Ptr = new QueueNode(Rhs.Fron->Item);
	QueueNode *RhsPtr = Rhs.Front->Next;

	Frint = Ptr;
	while(RhsPtr != NULL)
	{
		Ptr->Next = new QueueNode(RhsPtr->Item);
		RhsPtr = RhsPtr->Next;
		Ptr = Ptr->Next;
	}
	Back = Ptr;
	
	return *this;
}	

template <class T>
void Queue<T>::Enqueue(const T &X)
{
	if(IsEmpty())
		Back = Front = new QueueNode(X);
	else
		Back = Back->Next = new QueueNode(X);
}

template <class T>
void Queue<T>::Dequeue()
{
	if(IsEmpty())
		cout<<"Queue is Empty.\n";
	else
	{
		QueueNode *Old = Front;
		Front = Front->Next;
		delete Old;
	}
}

template <class T>
const T &Queue<T>::GetFront() const
{
	if(IsEmpty())
		cout<<"Queue is Empty.\n";
	else
	 	return Front->Item;
}

template <class T>
void Queue<T>::MakeEmpty()
{
	while(!IsEmpty())
	 	Dequeue();
}


int main()
{
	Queue<int> Q;

	for(int i = 0; i < 5; i++)
		Q.Enqueue(i);

	cout<<"Contents:";
	do
	{
		cout<<" "<<Q.GetFront();
		Q.Dequeue();
	}while(!Q.IsEmpty());
	cout<<endl;

	return 0;
}