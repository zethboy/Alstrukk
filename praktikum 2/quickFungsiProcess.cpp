#include <stdio.h>

// Fungsi untuk menukar dua angka
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fungsi untuk mencetak array
void printArray(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

// Fungsi partisi untuk mengatur ulang array di sekitar pivot
int partition(int arr[], int low, int high, int step) {
    int pivot = arr[high];  // Pivot adalah elemen terakhir
    int i = (low - 1);  // Indeks elemen yang lebih kecil

    printf("\nTahap %d: Memilih pivot = %d\n", step, pivot);
    printf("Sebelum partisi: ");
    printArray(arr, high - low + 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {  
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);

    printf("Setelah partisi: ");
    printArray(arr, high - low + 1);
    
    return (i + 1);
}

// Fungsi rekursif untuk Quick Sort
void quickSort(int arr[], int low, int high, int *step) {
    if (low < high) {
        (*step)++;
        int pi = partition(arr, low, high, *step);

        quickSort(arr, low, pi - 1, step);
        quickSort(arr, pi + 1, high, step);
    }
}

int main() {
    int n;

    // Input jumlah elemen array
    printf("Masukkan jumlah elemen: ");
    scanf("%d", &n);

    int arr[n];

    // Input elemen array
    printf("Masukkan elemen array:\n");
    for (int i = 0; i < n; i++) {
        printf("Elemen ke-%d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int step = 0;

    printf("\nArray sebelum diurutkan: ");
    printArray(arr, n);

    // Panggil fungsi Quick Sort
    quickSort(arr, 0, n - 1, &step);

    printf("\nArray setelah diurutkan: ");
    printArray(arr, n);

    return 0;
}