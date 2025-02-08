// Selection sort
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
    int *min = &arr[0];
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if(*min > arr[j]) {
                temp = arr[j];
                arr[j] = *min;
                *min = temp;
            }
        }
        min = &arr[i];
    }

    for(int i=0; i<n; i++) {
        printf("%d\t",arr[i]);
    }
    return 0;
}