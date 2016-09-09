
/**
 * C++ Template: The Complete Guide / David Vandevoorde, Nicolai M. Josuttis.
 * Addison-Wesley, (c) 2003 by Pearson Education, Inc. ISBN 0-201-73484-2
 * http://www.josuttis.com/tmplbook/
 */


// maximum of 2 values:
	template <typename T>
	inline T const& max (T const& a, T const& b) { return (a>b)?a:b; }

// usage: max(static_cast<double>(4), 4.2);
// usage: max<double>(4, 4.2);


// maximum of 3 values:
	template <typename T>
	inline T const& max (T const& a, T const& b, T const& c) { return max(max(a,b),c); }

// maximum of 2 pointers:
	template <typename T>
	inline T* const& max (T* const& a, T* const& b) { return (*a>*b)?a:b; }

// maximum of 2 c-strings:
	template <typename T>
	inline char const* const& max (char const* const& a, char const* const& b)
	{
		return std::strcmp(a,b) > 0 ? a : b;
	}



#include <vector>
#include <stdexcept>

template <typename T>

class Stack
{
private:
	std::vector<T> elems;	// elements

public:
	Stack();		// constructor
	Stack(Stack<T> const&);	// copy constructor
	Stack<T>& operator=(Stack<T> const&);	// assignment operator
	void push (T const&);	// push elements
	void pop ();		// pop elements
	T top() const;		// return top element
	bool isEmpty() const
	{
		return elems.empty();
	}
};

template <typename T>
void Stack<T>::push(T const& elem)
{
	elems.push_back(elem);	// append copy of passed elem
}

template <typename T>
void Stack<T>::pop()
{
	if (elems.isEmpty())
	{
		throw std::out_of_range("Stack<>::pop(): empty stack");
	}
	T elem = elems.back();	// save copy of last element
	elems.pop_back();	// remove last element
	return elem;
}

template <typename T>
T Stack<T>::top() const
{
	if (elems.isEmpty())
	{
		throw std::out_of_range("Stack<>::top(): empty stack");
	}
	return elems.back();	// return copy of last element
}








