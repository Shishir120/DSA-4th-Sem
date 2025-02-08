// Bubble sort
#include<stdio.h>

int main(){
    int temp, n;
    printf("Enter how many numbers: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d numbers: ", n);
    for(int i=0; i<n; i++) {
        scanf("%d",&arr[i]);
    }
    
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for(int i=0; i<n; i++) {
        printf("%d\t",arr[i]);
    }
    return 0;
}