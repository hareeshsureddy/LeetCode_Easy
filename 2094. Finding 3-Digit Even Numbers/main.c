#include <stdio.h>
#include <stdlib.h>

//2094. Finding 3-Digit Even Numbers
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 /*quick sort*/
int partition(int *nums,int start,int end){
    int pivot=nums[start];
    int i=start;
    int j=end;
    while(i<j){
        while(nums[i]<=pivot && i<end){
            i++;
        }
        while(nums[j]>pivot && j>start){
            j--;
        }
        if(i<j){
            int temp=nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
        }
    }
            int temp=nums[j];
            nums[j]=pivot;
            nums[start]=temp;
    return j;
}
void quickSort(int *nums,int start,int end){
        if(start<end){
            int pi=partition(nums,start,end);
            quickSort(nums,start,pi-1);
            quickSort(nums,pi+1,end);
        }
}
int* findEvenNumbers(int* digits, int digitsSize, int* returnSize) {
    int *result=(int*)malloc(720*sizeof(int));
    int index=0;
    *returnSize=0;
    for( int i=0;i<digitsSize;i++){
        for( int j=0;j<digitsSize;j++){
            for( int k=0;k<digitsSize;k++){
                if(i==k||k==j||j==i)
                continue;
                int num=digits[i]*100+digits[j]*10+digits[k];
                if(num>=100 && (!(num&1)))
                {
                /*Duplicate remove*/
                    int l=0;
                for( ;l<index;l++){
                    if(num==result[l]) break;
                }
                    if(l==index){
                    result[index++]=num;
                    printf(" %d  %d\n",num,index);
                    }
                }
            }
        }
    }
    if(!index) return result;
    quickSort(result,0,index-1);
    /*
    int i=0;
    for( int j=0;j<index;j++){
        if(result[i]==result[j])
        continue;
        i++;
        result[i]=result[j];
    }
    *returnSize=i+1;
    */
    *returnSize=index;
    return result;
}
int* findEvenNumbers_org(int* digits, int digitsSize, int* returnSize) {
     int *result=(int*)malloc(720*sizeof(int));
    int index=0;
    *returnSize=0;
    int map[10]={0};
    for (int i=0;i<digitsSize;i++){
        map[digits[i]]++;
    }
    for (int i=1;i<=9;i++){
        if (map[i]==0) continue;
        map[i]--;
        for (int j=0;j<=9;j++){
            if (map[j]==0) continue;
            map[j]--;
            for (int k=0;k<=8;k+=2){
                if (map[k]==0) continue;
                map[k]--;
                result[index++]=100*i+10*j+k;
                map[k]++;
            }
            map[j]++;
        }
        map[i]++;
    }
    *returnSize=index;
    return result;
}
int main()
{
    //int nums[]={2,1,3,0};
    //int nums[]={3,7,5};
    //int nums[]={5,7,2,4,8,2,6,6,0,9};
    //int nums[]={2,8,4,8,0,2,8,8,3,8,3,6,6,7,9};
    int nums[]={4,0,5,4,5,7,9,6,4,7,6,9,5,9,1,4,7,8,0,3,2,5,3,1,5,9,3,4,8,8,4,2,7,5,8,2,1,5,5,1,0,7,8,1,0,3,6,3,6,6,7,5,2,1,2,2,8,9,9,1,8,6,8,6,4,7,9,8,9,2,0,7,0,6,2,4,5,4,8,7,3,4,1,9,0,1,0,3,0,2,6,2,3,7,6,1,3,9,3,0};
    int numsSize=sizeof(nums)/sizeof(nums[0]);
    int result_size;
    //int *ptr= findEvenNumbers(nums,numsSize,&result_size);
     int *ptr= findEvenNumbers_org(nums,numsSize,&result_size);
    printf("sorted array with size of %d:\n",result_size);
    for (int i=0;i<result_size;i++)
    {
      printf("%d ",ptr[i]);
    }
    return 0;
}
