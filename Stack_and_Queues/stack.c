#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 3

int stack[MAX_SIZE], top = -1;

void push(int number) {
    if(top == MAX_SIZE-1)
        printf("Stack overflow!\n");
    else
        stack[++top] = number;
}

void pop() {
    if(top == -1)
        printf("Stack underflow!\n");
    else   
        printf("Popped %d from stack.\n",stack[top--]);
}

void main() {

    int option,number;
    printf("--Stack--\n1.PUSH\t2.POP\t3.EXIT\n");

    while(1) {
        printf("\nChoose an option: ");
        scanf("%d",&option);

        switch(option) {
            case 1:
                printf("Enter the number: ");
                scanf("%d",&number);
                push(number);
                break;

            case 2:
                pop();
                break;

            case 3:
                printf("Program exited.");
                exit(0);

            default:
                printf("Invalid option");
        }
    }
}