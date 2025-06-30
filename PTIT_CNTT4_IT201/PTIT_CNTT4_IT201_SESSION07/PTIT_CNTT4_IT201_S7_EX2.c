#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

void outputArray(int Arr[],int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", Arr[i]);
    }
    printf("\n");
}

void swap(int  *a , int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int bubbleSort(int Arr[], int n,int i) {
    if (i == n-1) return 0;
    for (int j = i; j < n; j++) {
        if (Arr[j] < Arr[i]) {
            swap(&Arr[i],&Arr[j]);
        }
    }
    return bubbleSort(Arr,n,i+1);
}

int selectionSort(int Arr[], int n,int i) {
    if (i == n) return 0;
    int min = Arr[i];
    int index = i;
    for (int j = i+1; j < n; j++) {
        if (Arr[j] < min) {
            min = Arr[j];
            index = j;
        }
    }
    swap(&Arr[index], &Arr[i]);
    return selectionSort(Arr,n,i+1);
}

int main() {
    int n;
    scanf("%d", &n);
    int *Arr=(int *)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d",&Arr[i]);
    }
    printf("before: ");
    outputArray(Arr, n);
    //int temp = bubbleSort(Arr, n,0);
    int temp = selectionSort(Arr, n,1);
    printf("After: ");
    outputArray(Arr, n);
    free(Arr);
    return 0;
}
