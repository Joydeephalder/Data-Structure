#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* link;
};

void insert(struct Node** pointertohead,int x){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=x;
    newNode->link=*pointertohead;
    *pointertohead=newNode;
}

void Print(struct Node* temp){
    printf("your list is: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->link;
    }printf("\n");
}
int main(){
    struct Node* head=NULL;
    int n,x,i;
    printf("How many numbers: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("enter the number: ");
        scanf("%d",&x);
        insert(&head,x);
        Print(head);
    }
}
