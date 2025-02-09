#include<stdio.h>
#define maxSize 4

int front = -1;
int rear = -1;
int queue[maxSize];

int isFull() {
    if (front == (rear+1)%maxSize) {
        return 1;
    } else {
        return 0;
    }
}

int isEmpty() {
    if (front == -1)
    {
        return 1;
    } else {
        return 0;
    }
}

void display() {
    if (isEmpty())
    {
        printf("List is empty...");
        return;
    }
    
    printf("The data in queue is: \n");

    if (front > rear)
    {
        for (int i = front; i < maxSize; i++)
        {
            printf("%d \t", queue[i]);
        }
        for (int i = 0; i <= rear; i++)
        {
            printf("%d \t", queue[i]);
        }
    } else {
        for (int i = front; i <= rear; i++)
        {
            printf("%d \t", queue[i]);
        }
    }
    
}


void enqueue(int data) {
    if (isFull())
    {
        printf("Queue is full...");
        return;
    } else {
        if (front == -1)
        {
            front = 0;
            rear = 0;
        } else {
            rear = (rear+1)%maxSize;
        }
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
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front+1)%maxSize;
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