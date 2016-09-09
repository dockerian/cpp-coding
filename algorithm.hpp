/*
 * Algorithms in C++ / by Robert Sedgewick
 * 672 p. 24 cm. ISBN 0-210-51059-6
 * Copyright (c) 1992 Addison-Wesley
 *
 */



/*
 *********************************************************************
 * Euclid's method to solve the greatest common divisor of 2 numbers
 * If (u) is greater than (v) then the greatest common divisor of (u) and (v) is the same as the greatest common divisor of v and (u-v).
 * A fraction is reduced to lowest terms by dividing both numerator and denominator by their greates common divisor.
 *********************************************************************
 */

int egcd(int u, int v)
{
	while (u > 0)
	{
		if (u < v) { int t = u; u = v; v = t; }

		u -= v;
	}

	return v;
}

//
//	program euclid (input, output);
//	var x, y: integer;
//		function gcd(u, v: integer): integer;
//		var t: integer;
//		begin
//		repeat
//			if u < v then
//				begin t:=u; u:=v; v:=t; end;
//			u:=u-v;
//		until u=0;
//		gcd:=v
//		end;
//	begin
//	while not eof do
//		begin
//			readln(x, y);
//			if (x>0) and (y>0) then writeln (x, y, gcd(x,y))
//		end;
//	end.
//


/*
 *********************************************************************
 * "Sieve of Eratosthenes": Print out prime numbers less than a given range:
 *********************************************************************
 */

#include <iostream>

void printPrimeNumbers (const &int N)
{
	int i, j;
	int *a;

	a = new int[N+1];

	for(a[1]=0, i=2; i<=N; i++) a[i]=[1];

	for(i=2; i<=N/2; i++)
		for(j=2; j<=N/i; j++)
			a[i*j]=0;

	for(i=1; i<=N; i++)
		if(a[i]) cout << i << ' ';

	cout << '\n';
}


/*
 *********************************************************************
 * B-tree traverse
 *********************************************************************
 */

void preorder_traverse(struct node *t)
{
	stack.push(t);

	while(!stack.empty())
	{
		t = stack.pop(); visit(t);
		if (t->r != z) stack.push(t->r);
		if (t->l != z) stack.push(t->l);
	}
}

void levelorder_traverse(struct node *t)
{
	queue.put(t);

	while (!queue.empty())
	{
		t = queue.get(); visit(t);
		if (t->l != z) queue.put(t->l);
		if (t->r != z) queue.put(t->r);
	}
}

void recursive_traverse(struct node *t)
{
	if (t != z)
	{
		recursive_traverse(t->l);
		visit(t);
		recursive_traverse(t->r);
	}
}


/*
 *********************************************************************
 * Recursion: devide-and-conquer
 *********************************************************************
 */

void rule(int l, int r, int height)
{
	int m = (l + r) / 2;
	if (height > 0)
	{
		mark(m, height);
		rule(l, m, height-1);
		rule(m, r, height-1);
	}
}

//
//	non-recursion solution:
//
//	void rule(int l, int r, int height)
//	{
//		int i, j, t;
//		for(i=1, j=1; i <= height; i++, j++)
//			for(t=0; t <= (l+r)/j; t++)
//				mark(l+j+t*(j+j), i);
//	}
//


/*
 *********************************************************************
 * Sorting
 *********************************************************************
 */

inline void swap(itemType a[], init i, int j) { itemType t = a[i]; a[i] = a[j]; a[j] = t; }

void selection_sort(itemType a[], int N)
{
	int i, j, min;
	for(i=1; i<N; i++)
	{
		min = i;
		for(j=i+1; j<=N; j++)
			if(a[j] < a[min]) min=j;
		swap(a, min, i);
	}
}

void insertion_sort(itemType a[], int N)
{
	int i, j; itemType v;
	for(i=2; i <= N; i++)
	{
		v = a[i]; j = i;

		while(a[j-1] > v)
		{
			a[j] = a[j-1]; j--;
		}
		a[j] = v;
	}
}

void bubble_sort(itemType a[], int N)
{
	int i, j;
	for(i=N; i >= 1; i--)
		for(j=2; j <= i; j++)
			if(a[j-1] > a[j]) swap(a, j-1, j);
}



