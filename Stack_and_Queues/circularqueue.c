#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 3

int cqueue[MAX_SIZE],front=-1,rear=-1;

void enqueue(int number) {
    if((rear+1)%MAX_SIZE == front)
        printf("Queue overflow\n");
    else {
        if(front == -1)
            front++;
        rear = (rear+1) % MAX_SIZE;
        cqueue[rear] = number;
    }
}

void dequeue() {
    if(front == -1 )
        printf("Queue underflow\n");
    else {
        printf("Removed %d from cqueue\n",cqueue[front]);
        if(front == rear) {
            front = rear = -1;
        } else {
            front = (front+1) % MAX_SIZE;
        }
    }
}

void main() {

    int option,number;
    printf("--Circular Queue--\n1.Enqueue\t2.Dequeue\t3.Exit\n");

    while(1) {
        printf("\nChoose an option: ");
        scanf("%d",&option);

        switch(option) {
            case 1: 
                printf("Enter the number: ");
                scanf("%d",&number);
                enqueue(number);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                printf("Program exited.");
                exit(0);

            default:
                printf("Invalid option");
        }
    }
}