#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXSIZE 20

char postfix[30] = ""; 
char opStack[MAXSIZE]; 
int top = -1;          

int isOperand(char n) {
    return isdigit(n) || isalpha(n);
}

int isFull() {
    return top == MAXSIZE - 1;
}

int isEmpty() {
    return top == -1;
}

void push(char operator) {
    if (!isFull()) {
        top++;
        opStack[top] = operator;
    }
}

char pop() {
    if (!isEmpty()) {
        char poppedData = opStack[top];
        top = top - 1;
        return poppedData;
    }
    return -1; // Return -1 if the stack is empty
}

int getPrecedence(char operator) {
    switch (operator) {
        // case '(': case ')': return 4;
        case '^': return 3;
        case '*': case '/': case '%': return 2;
        case '+': case '-': return 1;
        default: return -1; 
    }
}


int isHigherPrecedence(char operator) {
    if (!isEmpty())
    {
        return getPrecedence(operator) > getPrecedence(opStack[top]) ? 1 : 0;
    }
    
}

void convert(const char* infix) {
    for (int i = 0; i < strlen(infix); i++) {

        char current = infix[i];

        if (isOperand(current)) {
            char temp[2] = {current, '\0'};
            strcat(postfix, temp); // Correctly append a single character
        }
        
        else if (current == '(') {
            push(current);
        }

        else if (current == ')') {
            while (!isEmpty() && opStack[top] != ('(')) {
                char poppedData = pop();
                char temp[2] = {poppedData, '\0'};
                strcat(postfix, temp);
            }
            if(opStack[top] == ('('))
                top--; // Remove '(' from the stack
        }
        
        else {
            while (!isEmpty() && !isHigherPrecedence(current)) {
                char poppedData = pop();
                char temp[2] = {poppedData, '\0'};
                strcat(postfix, temp);
            }
            push(current);
        }
    }

    while (!isEmpty() ) {
        if (opStack[top] == '(' || opStack[top] == ')')
        {
            top--;
            continue;
        }
        
        char poppedData = pop();
        char temp[2] = {poppedData, '\0'};
        strcat(postfix, temp);
    }
}

int main() {
    char infix[30];

    printf("Enter infix expression: ");
    fgets(infix, sizeof(infix), stdin);

    infix[strcspn(infix, "\n")] = '\0';

    convert(infix);  // Convert to postfix

    printf("Postfix expression is: %s\n", postfix);  // Print the postfix expression

    return 0;
}

// (A + B) * (C - D) / E

// A + B * (C - D) / E