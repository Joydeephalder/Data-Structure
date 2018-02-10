#include<stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* link;
};

struct Node* head;


void Insert(int x){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->link=NULL;

    if(head!=NULL)temp->link=head;
    head=temp;
}

void Display(){
    struct Node* temp=head;
    printf("your list is: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->link;
    }

    printf("\n");
}
int main(){

    head=NULL;

    int n,i,x;
    printf("how many numbers: ");

    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("enter the number: ");
        scanf("%d",&x);
        Insert(x);
        Display();
    }
}
