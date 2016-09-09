#include<iostream.h>
#include<stdlib.h>
using namespace std;

#define NotFound -1
#define Cutoff 10

template <class T>
int BinarySearch(T A[], const T &X, int N)
{
	int low = 0, high = N-1, mid;

	while(low <= high)
	{
		mid = (low + high) / 2;
		if(A[mid] < X)
			low = mid + 1;
		else if(A[mid] > X)
			high = mid - 1;
		else
			return mid;
	}

	return NotFound;
}

template <class T>
int SeqSearch(T A[], const T &X, int N)
{
	for(int i = 0; i < N; i++)
	{
		if(A[i] == X)
			return i;
	}

	return NotFound;
}

template <class T>
void InsertionSort(T A[], int N)
{
	for(int i = 1; 1 < N; i++)
	{
		T tmp = A[i];
		int j;

		for(j = i; j > 0 && tmp < A[j-1]; j--)
			A[j] = A[j-1];
		A[j] = tmp;
	}
}

template <class T>
void MergeSort(T A[], T tmp[], int left, int right)
{
	if(left < right)
	{
		int center = (left + right) / 2;
		MergeSort(A, tmp, left, center);
		MergeSort(A, tmp, center+1, right);
		Merge(A, tmp, left, center+1, right);
	}
}

template <class T>
void MergeSort(T A[], int N)
{
	try
	{
		T *tmp = new T[N];
		MergeSort(A, tmp, 0, N-1);
		delete [] tmp;
	}
	catch(...)
	{
		cerr<<"Out of Memory!! Sort fails."<<endl;
	}
}

template <class T>
void Merge(T A[], T tmp[], int leftPos, int rightPos, int rightEnd)
{
	int leftEnd = rightPos-1;
	int tmpPos = leftPos;
	int NumElememts = rightEnd - leftPos + 1;
	
	while(leftPos <= leftEnd && rightPos <= rightEnd)
		if(A[leftPos] <= A[rightPos])
			tmp[tmpPos++] = A[leftPos++];
		else
			tmp[tmpPos++] = A[rightPos++];

	while(leftPos <= leftEnd)
		tmp[tmpPos++] = A[leftPos++];

	while(rightPos <= rightEnd)
		tmp[tmpPos++] = A[rightPos++];

	for(int i = 0; i <NumElements; i++, rightEnd--)
		A[rightEnd] = tmp[rightEnd];
}

template <class T>
void Swap(T &A, T &B)
{
	T tmp = A;
	
	A = B;
	B = tmp;
}


template <class T>
void QuickSort(T A[], int low, int high)
{
	if(low + Cutoff > high)
		InsertionSort(&A[low], high - low + 1);
	else
	{
		int mid = (low + high) / 2;
		
		T Pivot = A[mid];
		Swap(A[mid], A[high-1]);
		int i, j;
		for(i = low, j = high-1; ;)
		{
			while(A[++i] < Pivot)
				;
			while(Pivot < A[--j])
				;
			if(i < j)
				Swap(A[i], A[j]);
			else
				break;
		}
		Swap(A[i], A[high - 1]);

		QuickSort(A, low, i-1);
		QuickSort(A, i+1, high);
	}
}

template <class T>
void QuickSort1(T A[], int N)
{
		QuickSort(A, 0, N-1);
}


int main()
{
	int array[100];
	
	for(int i = 0; i < 100; i++)
	{
		array[i] = rand()%1000;
		cout<<array[i]<<" ";
	}

	QuickSort1(array, 100);
	cout<<"after sorted: ";
	for(int i = 0; i <100; i++)
 		cout<<array[i]<<" ";

	return 0;
}

