/*
 ************************************************************
 * Source:	Exercises.cpp
 * System:	Microsoft Windows with .NET Framework
 * Author:	Jason Zhu (425) 369-1853; jason_zhuyx@hotmail.com
 * Update:	2003-11-28
 ************************************************************
 */


/// <summary>
/// LinkedNode class (c)2003, jason_zhuyx@hotmail.com
/// </summary>

class LinkedNode
{
  private:
	char	*Data;
	LinkedNode	*Next;
  public:
	bool	hasCirclarLink(LinkedNode **ppHead);
	bool	swap(LinkedNode **ppHead, LinkedNode *pA, LinkedNode *pB);
};

bool LinkedNode::hasCircularLink(LinkedNode **ppHead)
{
	LinkedNode	*p1, *p2;
	p1 = p2 = *ppHead;
	while( p1 != NULL && p2 != NULL)
	{
		p1 = p1->Next;
		p2 = p2->Next; 
		if( p2 != NULL ) p2 = p2->Next;
		if( p1 == p2 ) return true;
	}
	return false;
}

bool LinkedNode::swap(LinkedNode **ppHead, LinkedNode *pA, LinkedNode *pB)
{
	if( *ppHead == NULL || pA == NULL || pB == NULL ) return false;
	if( pA == pB ) return true;

	LinkedNode	*pANext = pA->Next,	*pAPrev = *ppHead;
	LinkedNode	*pBNext = pB->Next,	*pBPrev = *ppHead;

	while( pAPrev != NULL && pAPrev != pA && pAPrev->Next != pA ) pAPrev = pAPrev->Next;
	while( pBPrev != NULL && pBPrev != pB && pBPrev->Next != pB ) pBPrev = pBPrev->Next;

	if( pAPrev == NULL || pBPrev == NULL ) return false;

	if( pAPrev != pA ) pAPrev->Next = pB;
	if( pBPrev != pB ) pBPrev->Next = pA;

	pA->Next = pBNext;
	pB->Next = pANext;

	return true;
}


//LinkedNode * GetNthElement(LinkedNode *pHead, int n); // from the begin of the list
//LinkedNode * GetReversedNthElement(LinkedNode *pHead, int n); // from the end of the list
//LinkedNode * MakeCopy(LinkedNode *pHead); // create a new copy of the list
//LinkedNode * Reverse(LinkedNode *pHead);

