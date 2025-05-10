#include <stdio.h>
#include <stdlib.h>
/*Function Declerations*/
struct ListNode* AddingNode_atEnd_1(struct ListNode *,int );

// Definition for singly-linked list.
 struct ListNode {
     int val;
     struct ListNode *next;
 };
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int num1=0,num2=0;
    int i=1;
    do{
        num1+=((l1->val)*i);
        i*=10;
        l1=l1->next;
    }while(l1);
    i=1;
    do{
        num2+=((l2->val)*i);
        i*=10;
        l2=l2->next;
    }while(l2);
    int sum=num1+num2;
    struct ListNode* Temp=malloc(sizeof(struct ListNode));
    Temp->val=sum%10;
    Temp->next=NULL;
    sum/=10;
    struct ListNode* Temp1=Temp;
    while(sum){
        Temp1=AddingNode_atEnd_1(Temp1,sum%10);
        sum/=10;
    }
    return Temp;
}
/* Adding a node at the end of the given linked list in an efficient way*/
struct ListNode* AddingNode_atEnd_1(struct ListNode *ptr,int data){
    struct ListNode *temp=malloc(sizeof(struct ListNode));
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=temp;
    temp->val=data;
    temp->next=NULL;
    return temp;
}
void Print_linkedlist(struct ListNode *head)
{
     printf("Printing the data in the nodes:\n");
      /*Printing the data in a Given linked list*/
     struct ListNode *ptr=head;
     do{
      printf(" %d",ptr->val);
      ptr=ptr->next;
     }while(ptr);
}

int main()
{
    struct ListNode* temp=NULL;
    struct ListNode* result;
    struct ListNode* Head2=malloc(sizeof(struct ListNode));
    struct ListNode* Head1=malloc(sizeof(struct ListNode));
{/*
    Head1->val=2;
    Head1->next=NULL;
    Head2->val=5;
    Head2->next=NULL;
    temp=AddingNode_atEnd_1(Head1,4);
    temp=AddingNode_atEnd_1(temp,3);
    temp=AddingNode_atEnd_1(Head2,6);
    temp=AddingNode_atEnd_1(temp,4);
   // Print_linkedlist(Head1);
   // Print_linkedlist(Head2);
*/}
    Head1->val=9;
    Head1->next=NULL;
    /*[1,9,9,9,9,9,9,9,9,9]*/
    Head2->val=1;
    Head2->next=NULL;
    temp=AddingNode_atEnd_1(Head2,9);
        temp=AddingNode_atEnd_1(Head2,9);
          temp=AddingNode_atEnd_1(Head2,9);
            temp=AddingNode_atEnd_1(Head2,9);
                temp=AddingNode_atEnd_1(Head2,9);
                    temp=AddingNode_atEnd_1(Head2,9);
                        temp=AddingNode_atEnd_1(Head2,9);
                            temp=AddingNode_atEnd_1(Head2,9);
                                temp=AddingNode_atEnd_1(Head2,9);
    result=addTwoNumbers(Head1,Head2);
    Print_linkedlist(result);
    return 0;
}
