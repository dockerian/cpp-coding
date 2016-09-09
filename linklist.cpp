#include<iostream>
using namespace std;

struct list{
	char	ch;
	list	*next;
};

typedef	list *listptr;

void	insert(listptr *lst, char value)
{
	list	*newptr, *preptr=NULL, *currptr;

	newptr = new list;
	newptr->ch = value;
	newptr->next = NULL;

	currptr = *lst;
	while(currptr != NULL)
	{
		preptr = currptr;
		currptr = currptr->next;
	}

	if(preptr == NULL)
	{
		cout<<"lst is empty"<<endl;
		newptr->next = *lst;
		*lst = newptr;
	}
	else
	{
		cout<<"list is not empty"<<endl;
		preptr->next = newptr;
		newptr->next = currptr;
	}
}

int	main()
{
	listptr lst = NULL;
	char	value;
	
	for(int i = 0; i < 4; i++)
	{
		cin>>value;
		if(lst == NULL)
		cout<<"???"<<value;
		insert(&lst, value);
	}

	while(lst != NULL)
	{
		cout<<lst->ch<<"--";
		lst = lst->next;
	}

	return 0;
}
	

	