#include<iostream.h>
using namespace std;

template <class T>
T MaxSeqSum(T A[], int N, int &SeqStart, int &SeqEnd)
{
	T MaxSum = 0;
	T ThisSum = 0;

	for(int i = 0, j = 0; j < N; j++)
	{
		ThisSum += A[j];

		if(ThisSum > MaxSum)
		{
			MaxSum = ThisSum;
			SeqStart = i;
			SeqEnd = j;
		}
		else if(ThisSum < 0)
		{
			i = j+1;
			ThisSum = 0;
		}
	}
	
	return MaxSum;
}

int main()
{
	int array[] = {-2, 11, -4, 13, -5, 2};
	int max_sum, start, end;
	
	max_sum = MaxSeqSum(array, 6, start, end);
	cout<<"MaxSeqSum: "<<max_sum<<endl;
	cout<<"SeqStart: "<<start<<endl;
	cout<<"SeqEnd: "<<end<<endl;

	return 0;
}
