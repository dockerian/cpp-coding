#include<iostream>
using namespace std;

template<class Etype>

void    strcopy(Etype* strin, Etype* strout)
{

    while(*strout++ = *strin++)
        ;
}

int main()
{
    char *strin = "**** you";
    int len = strlen(strin);
    char *strout = new char[len+1];

    strcopy(strin, strout);
    cout<<"The string is: "<<strout;

    return 0;
}