#include <stdio.h>
#include <stdlib.h>

void outputArray(int Arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", Arr[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int bubbleSort(int Arr[], int n, int i) {
    if (i == n - 1) return 0;
    for (int j = i; j < n; j++) {
        if (Arr[j] < Arr[i]) {
            swap(&Arr[i], &Arr[j]);
        }
    }
    return bubbleSort(Arr, n, i + 1);
}

int selectionSort(int Arr[], int n, int i) {
    if (i == n) return 0;
    int min = Arr[i];
    int index = i;
    for (int j = i + 1; j < n; j++) {
        if (Arr[j] < min) {
            min = Arr[j];
            index = j;
        }
    }
    swap(&Arr[index], &Arr[i]);
    return selectionSort(Arr, n, i + 1);
}

int insertionSort(int Arr[], int n, int i) {
    if (i == n) return 0;
    int key = Arr[i];
    int j = i - 1;
    while (j >= 0 && Arr[j] > key) {
        Arr[j + 1] = Arr[j];
        j--;
    }
    Arr[j + 1] = key;
    return insertionSort(Arr, n, i + 1);
}

void merge(int Arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = Arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = Arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            Arr[k++] = L[i++];
        else
            Arr[k++] = R[j++];
    }

    while (i < n1)
        Arr[k++] = L[i++];
    while (j < n2)
        Arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int Arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(Arr, l, m);
        mergeSort(Arr, m + 1, r);
        merge(Arr, l, m, r);
    }
}

int partition(int Arr[], int low, int high) {
    int pivot = Arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (Arr[j] < pivot) {
            i++;
            swap(&Arr[i], &Arr[j]);
        }
    }
    swap(&Arr[i + 1], &Arr[high]);
    return i + 1;
}

void quickSort(int Arr[], int low, int high) {
    if (low < high) {
        int pi = partition(Arr, low, high);
        quickSort(Arr, low, pi - 1);
        quickSort(Arr, pi + 1, high);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int *Arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &Arr[i]);
    }

    printf("Before: ");
    outputArray(Arr, n);

    int temp = bubbleSort(Arr, n, 0);
    //int temp = selectionSort(Arr, n, 1);
    //int temp = insertionSort(Arr, n, 0);
    //quickSort(Arr, 0, n - 1);
    //mergeSort(Arr, 0, n - 1);

    printf("After: ");
    outputArray(Arr, n);

    free(Arr);
    return 0;
}
