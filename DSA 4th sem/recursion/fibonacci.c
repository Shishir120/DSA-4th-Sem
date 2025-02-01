//Fibonacci Series

#include<stdio.h>
#include<math.h>

int fib(int n) {
    if (n==0)   
    {
        return 0;
    } else if (n==1 || n==2) {
        return 1;
    } else {
        return (fib(n-1) + fib(n-2));
    }
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        printf("%d\t", fib(i));
    }
    return 0;
}