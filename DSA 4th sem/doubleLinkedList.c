// Doubly Linked List
// Position index starts from 0

#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *head = NULL;

void display()
{
    printf("\nThe data in double linked list is: \n");
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d \t", ptr->data);
        ptr = ptr->next;
    }
}

void insertionAtBeginning() {
    int data;
    printf("\nEnter data to insert: ");
    scanf("%d", &data);

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->prev = NULL;
    newNode->next = NULL;
    newNode->data = data;

    if (head == NULL)
    {
        head = newNode;
    } else{
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    display();
}

void insertionAtEnd() {
    int data;
    printf("\nEnter data to insert: ");
    scanf("%d", &data);

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->prev = NULL;
    newNode->next = NULL;
    newNode->data = data;

    if (head == NULL)
    {
        head = newNode;
    } else{

        struct node *ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }

        newNode->prev = ptr;
        ptr->next = newNode;
    }
    display();
}

void insertionAtPosition() {
    int pos;
    printf("\nEnter position you want to insert data on: ");
    scanf("%d", &pos);
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    newNode->prev = NULL;
    newNode->next = NULL;

    if(head == NULL && pos > 0) {
        printf("\nList is empty and data cannot be inserted");
        free(newNode);
        return;
    }

    int data;
    printf("\nEnter data to insert: ");
    scanf("%d", &data);
    newNode->data = data;
 
    if (pos == 0)
    {
        if (head == NULL)
        {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        
    } else {
        struct node *ptr = head;
        for (int i = 0; i < pos-1; i++)
        {
            ptr = ptr->next;
            if (ptr==NULL)
            {
                printf("\nPosition not found");
                free(newNode);
                return;
            }
        }
        printf("\nExited for loop");
        if (ptr == head)
        {
            newNode->next = ptr->next;
            newNode->prev = ptr;
            ptr->next = newNode;

        } else {
            newNode->prev = ptr;
            newNode->next = ptr->next;
            ptr->next->prev = newNode;
            ptr->next = newNode;

        }
    }
    display();
}

void deletionAtBeginning() {
    if (head == NULL)
    {
        printf("\nList is empty");
        return;
    }
    
    int deletedData = head->data;
    struct node* ptr = head;
    head = head->next;
    free(ptr);

    printf("\n The deleted data is: %d", deletedData);
    display();
}

void deletionAtEnd() {
    if (head == NULL) {
        printf("\nList is empty");
        return;
    }

    struct node *ptr = head;

    if (head->next == NULL) {
        int deletedData = ptr->data;
        head = NULL;
        printf("\nThe deleted data is: %d", deletedData);
        free(ptr);
    } else {
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
    
        int deletedData = ptr->data;
        printf("\nThe deleted data is: %d", deletedData);
        
        ptr->prev->next = NULL;
        free(ptr);
    }

    display();
}

void deletionAtPosition() {
    if(head == NULL){
    printf("\nList is empty.");
    return;
    }  

    int pos;
    printf("\nEnter position you want to delete the data of: ");
    scanf("%d", &pos);

    struct node *ptr;
    ptr = head;
    if(pos == 0){
        head = head->next;
    } else{
        for(int i=0; i<=pos-1; i++) {
            ptr = ptr->next; 
            if(ptr == NULL) {
                printf("Position not found. \n");
                return;
            }
        }
        if (ptr->next == NULL)
        {
            ptr->prev->next = NULL;
        } else {
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
        }
        
        printf("\nDeleted data is: %d", ptr->data);
    }
    free(ptr);
    display();
}

int main()
{
    int choice, choice_ins, choice_del, data, continues=1;
    do{

        printf("\n1 for insertion || 2 for deletion:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n1 for insertion at beginning || 2 for insertion at end || 3 for insertion at specified position:");
            scanf("%d", &choice_ins);

            switch (choice_ins)
            {
            case 1:
                insertionAtBeginning();
                break;

            case 2:
                insertionAtEnd();
                break;

            case 3:
                insertionAtPosition();
                break;

            default:
                printf("\nInvalid input");
            }
            break;

        case 2:
            printf("\n1 for deletion at beginning || 2 for deletion at end || 3 for deletion at specified position: ");
            scanf("%d", &choice_del);

            switch (choice_del)
            {
            case 1:
                deletionAtBeginning();
                break;

            case 2:
                deletionAtEnd();
                break;

            case 3:
                deletionAtPosition();
                break;
            }
            break;

        default:
            printf("\nInvalid Input");
            break;
        }

        printf("\n1 to continue || 0 to exit: ");
        scanf("%d", &continues);
    } while (continues==1);
    
}
