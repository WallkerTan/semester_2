#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int** arr, int n, int m,int k) {
    for (int j=0; j<n-1; j++) {
        for (int i=j+1; i<n; i++) {
            if (arr[j][k] > arr[i][k]) {
                swap(&arr[j][k], &arr[i][k]);
            }
        }
    }
}

int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    int **Arr = (int**)malloc(n*sizeof(int*));
    for (int i = 0; i < n; i++) {
        Arr[i] = (int*)malloc(m*sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d",&Arr[i][j]);
        }
    }
    int k;
    scanf("%d",&k);
    if (k<1 || k>n) {
        printf("khong hop le\n");
    }
    bubbleSort(Arr,n,m,k-1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ",Arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
