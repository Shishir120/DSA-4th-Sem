#include<stdio.h>
#define maxSize 3

int rear = -1;
int front = -1;
int queue[maxSize];

int isFull() {
    if (rear == maxSize-1) {
        return 1;
    } else {
        return 0;
    }
}

int isEmpty() {
    if (front == -1) {
        return 1;
    } else {
        return 0;
    }
}

void display() {
    printf("The data in queue is: \n");
    for (int i = front; i <= rear; i++)
    {
        printf("%d \t", queue[i]);
    }
}

void enqueue(int data) {
    if(isFull()) {
        printf("Queue is full...");
        return;
    }

    if (isEmpty())
    {
        front = 0;
        rear = 0;
    } else {
        rear++;
    }
    queue[rear] = data;
    display();
}

void dequeue() {
    if (isEmpty())
    {
        printf("Queue is empty...");
        return;
    }

    printf("The dequeued element is: %d\n", queue[front]);

    if (front == rear)
    {
        front = -1;
        rear = -1;
    } else {
        front++;
    }
    display();  
}

int main() {
    int choice, data, continues=0;
    do {
        printf("Enter 1 to enqueue | 2 to dequeue: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to enqueue: ");
            scanf("%d", &data);
            enqueue(data);
            break;

        case 2:
            dequeue();
            break;
        
        default:
            break;
        }
        printf("\nDo you wish to continue | 1 for yes : ");
        scanf("%d", &continues);
    } while(continues == 1);
    return 0;
}