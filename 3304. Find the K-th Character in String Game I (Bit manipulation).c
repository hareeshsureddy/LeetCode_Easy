/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include "stdio.h"
#include "stdint.h"
#include "string.h"
#include "math.h"
#include "stdlib.h"
char kthCharacter(int k) {
    char *char_ptr=(char*)malloc(sizeof(char)*k);
    int i=1;
    char_ptr[0]='a';
    while(i<k){
        int end=i;
        for (int j=0;j<end;j++){
            char_ptr[i++]=(char_ptr[j]=='z')?'a':char_ptr[j]+1;
            if(i==k) break;
        }
    }
    return char_ptr[k-1];
}
int main()
{
    int k=5;
    printf("\nkthCharacter is %c",kthCharacter(k));
    return 0;
}
