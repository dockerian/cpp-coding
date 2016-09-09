#include<iostream>
using namespace std;

template <class Etype>
class	AbsList
{
	public:
		AbsList() {}
		virtual	~AbsList() {}

		virtual int IsEmpty() const = 0;
		virtual int Is Full() const = 0;
		virtual void MakeEmpty() = 0;

		friend class AbsListItr<Etype>;

	private:
		AbsList(const AbsList &) {}
};

template <class Etype>
class	AbsListItr
{
	public:
		AbsListItr(const AbsList &L) {}
		AbsListItr(const AbsListItr &) {}
		virtual ~AbsListItr() {}

		virtual void Insert(const Etype &X) = 0;
		virtual int	Find(const Etype &X) = 0;
		virtual int Remove(const Etype &X) = 0;
		
	protected:
		AbsListItr(){}
};

template <class Etype>
class	List : public AbsList<Etype>
{
	public:
		List() {Header = new ListNode;}
		~List() {MakeEmpty(); delete Header;}

		const List &operator=(const List &Rhs);

		int IsEmpty() const {return Header->Next == NULL;}
		int IsFull() const {return 0;}
		void MakeEmpty();

		friend class ListItr<Etype>;

	private:
		struct ListNode
		{
			Etypy Element;
			ListNode Next;
			
			ListNode() : Next(NULL) {}
			ListNode(const Etype &E, ListNode *N = NULL) :
				Element(E), Next(N) {}
		};
		
		ListNode *Header;
};

void List<Etype>::MakeEmpty()
{
	ListNode *Ptr;
	ListNode *NextNode;

	for(ptr = Header->Next; Ptr != NULL; Ptr = NextNode)
	{
		NextNode = Ptr->Next;
		delete Ptr;
	}
	Header->Next = NULL;
}

template <class Etype>
class ListItr : AbsListItr<Etype>
{
	public:
		ListItr(const List<Etype> &L):Header(L.Header) {
			Current = L.IsEmpty() ? Header : Header->Next;}
		~ListItr() {}

		void Insert(const Etype &X);
		int Find(const Etype &X);
		int	IsFound(const Etype &X);
		int	Remove(const Etype &X);
		int operator+() const{
			return Current && Current != Header;}
		const Etype &operator()() const;
		void Zeroth(){Current = Header;}
		void First();
		void operator++();
		void operator(int) {operator++();}
	
	private:
		List<Etype>::ListNode * const Header;
		List<Etype>::ListNode *Current;
		friend class SortListItr<Etype>;
};

const List

			
int main()
{
	List<int> L;
	ListItr<int> P = L;

	for(int i = 0; i < 5; i++)
	{
		P.Insert(i);
		P.Zeroth();
	}

	cout << "Contents:";
	for(P.First(); +P; ++P)
		cout << ' ' << P();
	cout << "end\n";

	return 0;
}