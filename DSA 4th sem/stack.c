#include<stdio.h>
#define maxSize 5

int top = -1;
int stack[maxSize];

int isFull() {
    if (top == maxSize-1)
    {
        return 1;
    } else {
        return 0;
    } 
}

int isEmpty() {
    if (top < 0)
    {
        return 1;
    } else {
        return 0;
    }
    
}

void display() {
    printf("The elements in stack is: \n");
    for (int i = 0; i <= top; i++)
    {
        printf("%d \t", stack[i]);
    }
    
}

void push(int data) {
    
    if (isFull())
    {
        printf("The stack is full...");
        return;
    }
    top++;
    stack[top] = data;
    display();
}

void pop() {
    
    if (isEmpty())
    {
        printf("Stack is empty");
        return;
    }

    printf("The popped data is: %d \n", stack[top]);
    top--;
    display();
}

int main() {
    int choice, data, continues=0;
    do {
        printf("Enter 1 to push | 2 to pop: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to push: ");
            scanf("%d", &data);
            push(data);
            break;

        case 2:
            pop();
            break;
        
        default:
            break;
        }
        printf("\nDo you wish to continue | 1 for yes : ");
        scanf("%d", &continues);
    } while(continues == 1);
    return 0;
}