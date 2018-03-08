//
// Created by Joydeep Halder on 08-03-2018.
//

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* link;
};

struct Node* insert(struct Node* head,int x){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=x;
    newNode->link=head;
    head=newNode;
    return head;
}

Print(struct Node* temp){
    printf("your list is: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->link;
    }
    printf("\n");
}
int main(){
    struct Node* head=NULL;
    int n,x,i;
    printf("How many numbers: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("enter the number: ");
        scanf("%d",&x);
        head=insert(head,x);
        Print(head);
    }
}
