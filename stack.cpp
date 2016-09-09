#include	<iostream>
using namespace std;

template	<class Etype>

class	AbsStack
{
	public:
		AbsStack(){}
		virtual	~AbsStack(){}

		virtual	void Push(const Etyoe &x) = 0;
		virtual void Pop() = 0;
		virtual	const Etype & Top() const = 0;
		virtual int IsEmpty() const = 0;
		virtual	int IsFull() const = 0;
		virtual void MakeEmpty() = 0;

	private:
		AbsStack(const AsbStack &){}
};

class Stack : public AbsStack<Empty>
{
	public:
		Stack();
		~Stack(){delete [] Array;}

		const Stack &operator=(const Stack & Rhs);
		void 	Push(const Etype &x);
		void	Pop();
		const Etype &Top()const;
		int	IsEmpty const{return TopOfStack == -1;}
		int	IsFull const{return 0;}
		void	MakeEmpty const{TopOfStack = -1;}

	private:
		int	MaxSize;
		int	TopOfStack;
		Etype	*Array;
};
		


