

#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int Arr[], int n, int i,int type) {
    switch (type) {
        case 1: //chẵn
            if (i == n - 1) return;
            for (int j = i; j < n; j++) {
                if (Arr[j] < Arr[i]) {
                    swap(&Arr[i], &Arr[j]);
                }
            }
            bubbleSort(Arr, n, i + 1,type);
            break;
        case 2: // lẻ
            if (i == n - 1) return;
            for (int j = i; j < n; j++) {
                if (Arr[j] > Arr[i]) {
                    swap(&Arr[i], &Arr[j]);
                }
            }
            bubbleSort(Arr, n, i + 1,type);
            break;

    }
}

int main() {
    int n;
    scanf("%d",&n);
    int arr[n];
    int c=0,l=0;
    int *Crr = (int*)malloc(0*sizeof(int));
    int *Lrr = (int*)malloc(0*sizeof(int));
    for (int i=0; i<n; i++) {
        scanf("%d",&arr[i]);
        if (arr[i]%2==0) {
            c++;
            Crr = realloc(Crr, c * sizeof(int));
            Crr[c - 1] = arr[i];

        }else {
            l++;
            Lrr = realloc(Lrr, l * sizeof(int));
            Lrr[l - 1] = arr[i];
        }
    }

    bubbleSort(Crr,c,0,1);
    bubbleSort(Lrr,l,0,2);

    int k= c+l;
    int *Krr = (int*)malloc(k*sizeof(int));
    for (int i=0; i<n; i++) {
        Krr[i]=Crr[i];
    }
    for (int i=0; i<l; i++) {
        Krr[c+i]=Lrr[i];
    }

    printf("after: ");
    for (int i=0; i<k; i++) {
        printf("%d ",Krr[i]);
    }

    return 0;
}
