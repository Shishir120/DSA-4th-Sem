// Factorial

#include<stdio.h>
#include<math.h>

int fact(int n) {
    if (n==0 || n==1)   
    {
        return 1;
    } else {
        return n*fact(n-1);
    }
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("The factorial is: %d", fact(n));
    return 0;
}