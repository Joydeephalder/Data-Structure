#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* link;
};

struct Node* head,*newNode;
int size;

struct Node* createNode(){
    int x;
    printf("enter the number: ");
    scanf("%d",&x);
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=x;
    newNode->link=NULL;
    return newNode;
}
void insertBeginning(){
    newNode=createNode();
    newNode->link=head;
    head=newNode;
    size++;

}

void insertEnd(){
    newNode=createNode();
    if(head==NULL){
        head=newNode;
        size++;
        return;
    }
    struct Node* temp=head;
    while(temp->link!=NULL){
        temp=temp->link;
    }
    temp->link=newNode;
    size++;
}

void insertAny(){
    int nodeNo;
    printf("enter the node no: ");
    scanf("%d",&nodeNo);

    if(nodeNo>size+1 || nodeNo<1){
        printf("||||||||||UNABLE TO INSERT||||||||||||||\n");
        return;
    }
    newNode=createNode();
    struct Node* temp=head;

    if(nodeNo==1){
        newNode->link=head;
        head=newNode;
        size++;
        return;
    }

    for(int i=1;i<=nodeNo-2;i++){
        temp=temp->link;
    }newNode->link=temp->link;
    temp->link=newNode;
    size++;
}

void deleteBeginning(){
    if(head==NULL){
        printf("|||||||||NOTHING TO DELETE||||||||||\n");
        return;
    }
    struct Node* temp=head;
    head=temp->link;
    free(temp);
    size--;
}

void deleteEnd(){
    if(head==NULL){
        printf("|||||||||NOTHING TO DELETE||||||||||\n");
        return;
    }
    struct Node* temp=head;
    struct Node* prev=NULL;
    if(size==1){
        head=NULL;
        free(temp);
        size--;
        return;
    }
    while(temp->link!=NULL){
        prev=temp;
        temp=temp->link;
    }
    prev->link=NULL;
    free(temp);
    size--;
}

void deleteAny(){

    if(head==NULL){
        printf("|||||||||NOTHING TO DELETE|||||||||||\n");
        return;
    }

    int nodeNo,i;
    printf("enter the node no: ");
    scanf("%d",&nodeNo);
    if(nodeNo<1 || nodeNo>size){
        printf("|||||||UNABLE TO DELETE||||||||||\n");
        return;
    }

    struct Node* temp=head;
    struct Node* nextTemp;

    if(nodeNo==1){
        head=temp->link;
        free(temp);
        size--;
        return;
    }
    for(i=1;i<=nodeNo-2;i++){
        temp=temp->link;
    }
    nextTemp=temp->link;
    temp->link=temp->link->link;
    free(nextTemp);
    size--;

}

void display(){
    if(size==0){
        printf("your list is empty.\n");
        return;
    }
    struct Node* temp=head;
    printf("your list is: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->link;
    }
    printf("\n");
}

// display using recursive

void display2(struct Node* p){
    if(size==0){
        printf("your list is empty.\n");
        return;
    }

    if(p==NULL)
        return;
    printf("%d ",p->data);
    display2(p->link);
}


void displayReverse(struct Node* p){
    if(size==0){
        printf("your list is empty.\n");
        return;
    }
    if(p==NULL)
        return;
    displayReverse(p->link);
    printf("%d ",p->data);

}

void reverse(){
    struct Node *current,*prev,*next;
    prev=NULL;
    current=head;
    while(current!=NULL){
        next=current->link;
        current->link=prev;
        prev=current;
        current=next;
    }
    head=prev;
}
// reverse using recursive

void reverse2(struct Node* p){
    if(p->link==NULL){
        head=p;
        return;
    }
    reverse2(p->link);
    p->link->link=p;
    p->link=NULL;
}
int main(){
    head=NULL;
    int choice;
    int exit=1;
    while(exit==1){
        printf("------------------------MENU--------------------------\n");
        printf("1.insert at beginning.\n");
        printf("2.insert at end.\n");
        printf("3.insert at any position.\n");
        printf("4.delete from beginning.\n");
        printf("5.delete from end.\n");
        printf("6.delete from any position.\n");
        printf("7.display the list.\n");
        printf("8.reversely display the list.\n");
        printf("9.reverse the list.\n");
        printf("10.check the size of list.\n");
        printf("11.exit.\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: insertBeginning();
                break;
            case 2: insertEnd();
                break;
            case 3: insertAny();
                break;
            case 4: deleteBeginning();
                break;
            case 5: deleteEnd();
                break;
            case 6: deleteAny();
                break;
            case 7: display();
                break;
            case 8:
                printf("your list in reverse order is: ");
                displayReverse(head);
                printf("\n");
                break;
            case 9: reverse();
                break;
            case 10: printf("size of the list is: %d.\n",size);
                break;
            case 11: exit=0;
                break;
            default: printf("|||||||||||INVALID CHOICE||||||||||||||\n");
        }
    }
}
