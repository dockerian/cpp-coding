#include	<iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

#define BOOL int
#define TRUE 1
#define FALSE 0
 
BOOL foo(char *);
 
void main( int argc, char *argv[]) { 
 
BOOL retval;     // not used
if (argc == 1){
    printf("no input string\n");
    exit(1);
}
 
if (foo(argv[1])) {  
    printf("foo returns true\n");
}
else {
    printf("foo returns false\n");
}
 
}    // added
 
 
BOOL foo(char *str) {
     char *strLastChar;
     int  len;
    
 
     len = strlen(str);
     if(len%2 == 0)
        return FALSE;  // added,  if the string length is
                       //  even,  the following while loop
                       // will be infinite
                       // and/or machine will be crash.
 
     strLastChar = str+strlen(str)-1; //it should be str+strlen(str)-1
 
     while (*str++ == *strLastChar--) {
         if (str == strLastChar) {   // it should be comparison(==), not assignment
            return TRUE;
         }
     }
     return FALSE;
}




