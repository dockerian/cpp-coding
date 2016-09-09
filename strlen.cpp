#include<iostream>
using namespace std;

template<class Etype>

int strln(Etype* str)
{
    int i;
    Etype   *p;

    p = str;
    while(*p++)
        ;

    return p-str-1;
}

int main()
{
    char *string = "love you";
    int len;

    len = strln(string);
    cout<<"The length is: "<<len;

    return 0;
}