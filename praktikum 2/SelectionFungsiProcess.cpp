#include <stdio.h>


void selectionSort(int arr[], int n) {
    int i, j, posisi, swap;
    for(i = 0; i < (n-1); i++) {
        posisi = i;
        printf("\nIterasi ke-%d:\n", i + 1);
        printf("Data saat ini: ");
        for(int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
        
        for(j = i + 1; j < n; j++) {
            if(arr[posisi] > arr[j]) {
                posisi = j;
            }
        }
        if(posisi != i) {
            swap = arr[i];
            arr[i] = arr[posisi];
            arr[posisi] = swap;
            
            printf("\nSetelah swap: ");
            for(int k = 0; k < n; k++) {
                printf("%d ", arr[k]);
            }
        }
        printf("\n");
    }
    
}

int main() {
    int array[100], n, i;

    printf("Masukkan banyaknya jumlah data: ");
    scanf("%d", &n);

    printf("Masukkan data sebanyak %d :\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    
    selectionSort(array, n);

    printf("Hasil pengurutan sebagai berikut:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    return 0;
}