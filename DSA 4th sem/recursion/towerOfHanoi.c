// Tower of Hanoi

#include<stdio.h>
#include<stdlib.h>

int steps = 0;
void toh(int n, char from, char to, char aux){
    if(n<=0) return;
    steps = steps + 1;
    toh(n-1,from,aux,to);
    printf("Move Disk %d from %c to %c\n",n,from,to);
    toh(n-1,aux,to,from);
}

int main(){
    int n;
    printf("how many disks?");
    scanf("%d",&n);
    toh(n, 'a', 'c', 'b');
    return 0;
}