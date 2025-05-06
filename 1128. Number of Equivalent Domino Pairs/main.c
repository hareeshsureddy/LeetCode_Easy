/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
int numEquivDominoPairs(int dominoes[][2], int dominoesSize) {
    int pair_cnt=0;
    for (int i=0;i<dominoesSize-1;i++){
        for (int j=i+1;j<dominoesSize;j++){
            pair_cnt+=(dominoes[i][0]==dominoes[j][0])?(dominoes[i][1]==dominoes[j][1]):(dominoes[i][1]==dominoes[j][0])?(dominoes[i][0]==dominoes[j][1]):0;
        }
    }
    return pair_cnt;
}
int main()
{
    //int nums[5][2]={{1,2},{1,2},{1,1},{1,2},{2,2}};
    int nums[6][2]={{1,1},{2,2},{1,1},{1,2},{1,2},{1,1}};
    printf("%d",numEquivDominoPairs(nums,6));

    return 0;
}
