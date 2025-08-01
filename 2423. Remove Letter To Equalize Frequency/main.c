#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
bool equalFrequency(char* word) {
    uint8_t map[26]={0};
    int i=0,j=0;
    while(word[j]){
        map[word[j]-'a']++;
        j++;
    }
    j=25;
    while(i<j){
        while(i<26 && map[i]) i++;
        while(j>=0 && !map[j]) j--;
        if(i<j){
            map[i++]=map[j];
            map[j--]=0;
        }
    }
    int len=i;
     for(i=0;i<len;i++){
         printf("%d ",map[i]);
     }
    for(i=0;i<len;i++){
        map[i]--;
        for(j=0;j<len-1;j++){
            if(!map[j]) continue;
            if((map[j])!=map[j+1])
            break;
        }
        if(j==len-1) return true;
        map[i]++;
    }
    return false;
}
int main()
{
    char *s="abcc";
    if(equalFrequency(s)) printf("True");
    else
    printf("false");
    return 0;
}
