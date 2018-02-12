#include <stdio.h>

int main(){
    int n,x,i,j,e,b,index,num,m,choice;
    printf("how many numbers? ");
    scanf("%d",&n);
    int array[100];
    for(i=0;i<n;i++){
        printf("enter the number: ");
        scanf("%d",&x);
        array[i]=x;
        printf("your array is: ");
        for(j=0;j<=i;j++){
            printf("%d ",array[j]);
        }

        printf("\n");
    }


    printf("choose from menu: \n");
    printf("1. Insertion at end.\n");
    printf("2. Insertion at beginning.\n");
    printf("3. Insertion at any position.\n");
    printf("4. Deletion at any position.\n");

    scanf("%d",&choice);

    // Insertion at end.
    if(choice==1) {
        printf("enter the number you want to insert at end: ");
        scanf("%d", &e);
        array[n] = e;
        printf("your new array is: ");
        for (i = 0; i <= n; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");
    }

    // Insertion at beginning.
    if(choice==2) {
        printf("enter the number you want to insert at beginning: ");
        scanf("%d", &b);
        for (i = n; i >= 0; i--) {
            array[i + 1] = array[i];
        }
        array[0] = b;
        printf("your new array is: ");
        for (i = 0; i <= n; i++) {
            printf("%d ", array[i]);
        }
    }


    // Insertion at any position
    if(choice==3) {
        printf("\nenter the index at where you want to insert a number: ");
        scanf("%d", &index);
        if(index>n){
            printf("index is out of limit.Please enter another index.\n");
            scanf("%d", &index);
            if(index>n){
                printf("index is again out of limit.Sorry \n");
            }else {
                printf("enter the number: ");
                scanf("%d", &num);

                for (i = n; i >= index; i--) {
                    array[i + 1] = array[i];
                }
                array[index] = num;
                printf("your new array is: ");
                for (i = 0; i <= n; i++) {
                    printf("%d ", array[i]);
                }
            }
        }else {
            printf("enter the number: ");
            scanf("%d", &num);

            for (i = n; i >= index; i--) {
                array[i + 1] = array[i];
            }
            array[index] = num;
            printf("your new array is: ");
            for (i = 0; i <= n; i++) {
                printf("%d ", array[i]);
            }
        }
    }

    //deletion at any position
    if(choice==4) {
        printf("\nenter the index you want to delete an element:");
        scanf("%d", &m);
        if(m>=n){
            printf("index is out of limit.Please enter another index\n");
            scanf("%d", &m);
            if(m>=n){
                printf("index is again out of limit.Sorry\n");
            }else {

                for (i = m; i < n; i++) {
                    array[i] = array[i + 1];
                }
                printf("your new array is: ");
                for (i = 0; i < n - 1; i++) {
                    printf("%d ", array[i]);
                }
            }
        }else {

            for (i = m; i < n; i++) {
                array[i] = array[i + 1];
            }
            printf("your new array is: ");
            for (i = 0; i < n - 1; i++) {
                printf("%d ", array[i]);
            }
        }
    }
}

