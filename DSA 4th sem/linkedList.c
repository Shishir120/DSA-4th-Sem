// linked list 
// Position starts from index 0

#include <stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head;

// To display
void display() {
    printf("\nData in linked list is: \n");
    struct node *ptr = head;
    while(ptr != NULL) {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
}

// Insertion at beginning
void insertionBeginning(int data) {
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if(head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    printf("\nInserted data is: %d", data);
    display();
}

// To insert new node at end
void insertionEnd(int data) {
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
    } else {
        struct node *ptr = head;
        while(ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
    printf("\nInserted data is: %d", newNode->data);
    display();
}

// Insert at nth position
void insertAtPosition(int data) {
    int pos;
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    printf("\nEnter position you want to insert data on: ");
    scanf("%d", &pos);

    if(head == NULL && pos > 0){
        printf("\nPosition not found and list is empty.");
        return;
    }

    if (pos == 0) {
        newNode->next = head;
        head = newNode;

    } else {
        struct node *ptr = head;
        for(int i=0; i<pos-1; i++) {
            ptr = ptr->next; 
            if(ptr == NULL) {
                printf("Position not found. \n");
                free(newNode);
                return;
            }
        }
        newNode->next = ptr->next;
        ptr->next = newNode;
    }
    display();
}

// Deletion at beginning
void deleteBeginning() {
    if(head == NULL) {
        printf("\nList is empty.");
        return;
    }
    struct node *tempPtr;
    tempPtr = head;
    head = head->next;
    printf("\nDeleted data: %d", tempPtr->data);
    free(tempPtr);
    display();
}

// Deletion at end
void deleteEnd() {
    if(head == NULL) {
        printf("\nList is empty.");
        return;
    } else if(head->next == NULL) {
        free(head);
        head = NULL;
    }

    struct node *ptr;
    struct node *temp;
    ptr = head;
    while(ptr->next != NULL) {
        temp = ptr;
        ptr = ptr->next;
    }
    temp->next = NULL;
    printf("\nDeleted data  is: %d", ptr->data);
    free(ptr);
    display();
}

// Deletion at Specified Position
void deleteSpecifiedPosition() {
    if(head == NULL){
        printf("\nList is empty.");
        return;
    }

    int pos;
    printf("\nEnter position you want to delete the data of: ");
    scanf("%d", &pos);

    struct node *ptr, *temp;
    ptr = head;
    if(pos == 0){
        head = head->next;
    } else{

        for(int i=0; i<=pos-1; i++) {
            temp = ptr;
            ptr = ptr->next; 
            if(ptr == NULL) {
                printf("Position not found. \n");
                return;
            }
        }
        temp->next = ptr->next;
        printf("\nDeleted data is: %d", ptr->data);
    }
    free(ptr);
    display();
}

int main() {
    insertionBeginning(1);
    insertionEnd(3);
    insertAtPosition(2);
    deleteBeginning();
    deleteEnd();
    deleteSpecifiedPosition();

    // int data, continues, ins_del, choice;

    // do {
    //     printf("\nEnter 1 for insetion | 2 for deletion: ");
    //     scanf("%d", &ins_del);
    //     switch(ins_del) {

    //         case 1:
    //             printf("\nEnter 1 for insertion at beginnig | 2 for end | 3 for at nth position: ");
    //             scanf("%d", &choice);
    //             printf("\nEnter data to insert:");
    //             scanf("%d", &data);
                
    //             switch(choice) {
    //                 case 1:
    //                     insertionBeginning(data);
    //                     break;
    //                 case 2:
    //                     insertionEnd(data);
    //                     break;
    //                 case 3:
    //                     insertAtPosition(data);
    //                     break;
    //                 default:
    //                     printf("\nInvalid input");
    //                     break;
    //             }
    //             break;
                                                           
    //         case 2:
    //             printf("\nEnter 1 for deletion at beginnig | 2 for end | 3 for at nth position: ");
    //             scanf("%d", &choice);

    //             switch(choice) {
    //                 case 1:
    //                     deleteBeginning();
    //                     break;
    //                 case 2:
    //                     deleteEnd();
    //                     break;
    //                 case 3:
    //                     deleteSpecifiedPosition();
    //                     break;
    //                 default:
    //                     printf("\nInvalid input");
    //                     break;
    //             }
    //             break;
    //     }
    //     printf("\nDo you want to continue: 1 to continue | 0 to exit: ");
    //     scanf("%d", &continues);
    // } while(continues == 1);
    // return 0;
}