#include<iostream>
using namespace std;

/*template <class T>
class AbsHTable
{
	public:
		AbsHTable() {}
		~AbsHTable() {}
		
		virtual int Hash(const T &X) = 0;
		virtual void Insert(const T &X) = 0;
		virtual void Remove(const T &X) = 0;
		virtual const T &Find(const T &X) = 0;

	private:
		AbsHTable(const AbsHTable &) {}
};*/


class hashTable
{
	public:
		hashTable(int size, int prime);
		~hashTable();

		int hash(const char* &X);
		void insert(char* X);
		//void delete(const char* &X);
		char* find(char* X); //if chainNode more complicated, should return 
									// the chainNode to get other infomation
	private:
		struct chainNode
		{
			char *name;	// as key and data_item
			chainNode *next;
		};
 
		int Size;
		int Prime;
		chainNode **array;
};

hashTable::hashTable(int size, int prime)
{
	Prime = prime;
	Size = size;
	array = new chainNode*[Size];
	int j = Size;
	while(j >= 0)
	{
		array[j] = NULL;
		j--;
	}
}

hashTable::~hashTable()
{
	chainNode *header, *nextPtr;

	for(int i = 0; i <Size; i++)
	{
		header = array[i];
		while(header != NULL)
		{
			nextPtr = header->next;
			delete header;
			header = nextPtr;
		}
	}
	delete [] array;
}
	
int hashTable::hash(const char* &name)
{
	const char *p = name;
	unsigned h = 0, g;
	while(*p++)
	{
		h = (h << 4) +(*p);
		if(g = h & 0xf000000)
		{
			h = h ^ (g >> 24);
			h = h ^ g;
		}
	}
	return h%Prime;
}

void hashTable::insert(char* X)
{
	chainNode *header, *newPtr;

	newPtr = new chainNode;
	newPtr->name = X;
	newPtr->next = NULL;
	int array_no = hash(X);
	header = array[array_no];
	newPtr->next = header;
	array[array_no] = newPtr;
}

char* hashTable::find(char* X)
{
	chainNode *header;

	int array_no = hash(X);
	header = array[array_no];
	if(header == NULL)
	{
		cout<<"empty chain\n";
		return NULL;
	}
	while(header != NULL)
		if(header->name == X)
		{
			cout<<header->name;
			return header->name;
		}
		else
			header = header->next;

	cout <<X <<" was not found in the hash table\n";
	return NULL;
}


int main()
{
	hashTable H(10, 211);

	H.insert("Becky");
	char *result1 = H.find("Mark");
	char *result2 = H.find("Becky");

	return 0;
}