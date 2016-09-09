#include<iostream.h>
using namespace std;


class Mystring{
	private:
		int len;
		char *str;
	public:
		Mystring(char *);
		~Mystring();
		void print();
};

Mystring::Mystring(char *s)
{
	len = strlen(s);
	str = new char[len+1];
	strcpy(str, s);
}

void Mystring::print()
{
	Mystring n("yyy");
	
	cout<<"String:"<<n.str<<endl;
}

int main()
{
	Mystring m("xxx");

	cout<<m.print()<<endl;

	return 0;
}
