#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 3

int queue[MAX_SIZE],front=-1,rear=-1;

void enqueue(int number) {
    if(rear == MAX_SIZE-1)
        printf("Queue overflow\n");
    else {
        if(front == -1)
            front++;
        queue[++rear] = number;
    }
}

void dequeue() {
    if(front == -1 || front > rear)
        printf("Queue underflow\n");
    else {
        printf("Removed %d from queue\n",queue[front++]);
        if(front > rear && rear == MAX_SIZE-1) {
            front = rear = -1;
            printf("Queue reset\n");
        }
    }
}

void main() {

    int option,number;
    printf("--Queue--\n1.Enqueue\t2.Dequeue\t3.Exit\n");

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