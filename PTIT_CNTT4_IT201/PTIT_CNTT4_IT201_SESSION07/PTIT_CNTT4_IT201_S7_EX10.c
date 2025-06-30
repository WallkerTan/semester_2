#include <stdio.h>
#include <stdlib.h>

#define maxindex 2001
#define offset 1000

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int B[], int n, int i) {
    if (i == n - 1) return;
    for (int j = i + 1; j < n; j++) {
        if (B[arr[i] + offset] > B[arr[j] + offset]) {
            swap(&arr[i], &arr[j]);
        } else if (B[arr[i] + offset] == B[arr[j] + offset]) {
            if (arr[i] > arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
    bubbleSort(arr, B, n, i + 1);
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int k;
    scanf("%d", &k);

    int B[maxindex] = {0};
    for (int i = 0; i < n; i++) {
        B[arr[i] + offset] = abs(arr[i] - k);
    }

    bubbleSort(arr, B, n, 0);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
