#include "stdio.h"
#include "stdint.h"
#include "string.h"
#include "math.h"
#include "stdlib.h"
#include "stdbool.h"
int minOperations(char* s) {
    int16_t len=strlen(s);
    int16_t result=0;
    for (int i=1;i<len;i++){
        if(s[i]==s[i-1]){
            s[i] = (s[i] == '0') ? '1' : '0';
            result++;
        }
        printf("%s\n",s);
    }
    return result;
}
//1496. Path Crossing
bool isPathCrossing(char* path) {
    int16_t len=strlen(path);
    int16_t x=0,y=0;
    int16_t (*map)[2]=calloc(len+1,sizeof(int16_t*));
    for(int i=0;i<len;i++){
        if(path[i]=='N')
        y++;
        else if(path[i]=='S')
        y--;
        else if(path[i]=='E')
        x++;
        else
        x--;
        for(int j=0;j<=i;j++){
            if(x==map[j][0] && y==map[j][1])
            return true;
        }
        map[i+1][0]=x;
        map[i+1][1]=y;
    }
    return false;
}
//1160. Find Words That Can Be Formed by Characters
int countCharacters(char** words, int wordsSize, char* chars) {
    int map[26]={0};
    int len=strlen(chars);
    for (int i=0;i<len;i++){
        map[chars[i]-'a']++;
    }
    int result=0;
    for (int i=0;i<wordsSize;i++){
        bool ok=true;
        int map1[26]={0};
        char *s=words[i];
        int len=strlen(s);
     for (int k=0;k<len;k++){
        map1[s[k]-'a']++;
    }
    for (int j=0;j<26;j++ ){
        if(map1[i]>map[i]){
            ok=false;
            break;
        }
    }
    if(ok==true)  result+=len;
    }
    return result;
}
int main()
{
    {
    char *s1="101010100101010101011";
    printf("minOperations %d",minOperations(s1));
    return 0;
    }
    char *path="NES";
    if(isPathCrossing(path))
        printf("True\n");
    else
        printf("False\n");
    char *s[]={"cat","bt","hat","tree"};
    /*{
    int *ptr[10];
     printf("\nSizeof int *ptr[10]--> %lld",sizeof(ptr));
     printf(" In this case ptr is a array of 10 pointers pointing to intgers ");
    }*/
    char *c="atach";
    printf("countCharacters %d\n",countCharacters(s,4,c));
    return 0;
}
