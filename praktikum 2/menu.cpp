#include <stdio.h>
#include <stdlib.h>

int menu() {
    int choice;
    printf("Menu Pilihan Sorting");
    printf("1. Quick Sort\n");
    printf("2. Merge Sort\n");
    printf("3. Bubble Sort\n");
    printf("4. Selection Sort\n");
    printf("5. Insertion Sort\n");
    printf("6. Exit\n");
    printf("Pilih: ");
    scanf("%d", &choice);
    return choice;
}

int getOrder() {
    int order;
    printf("\nPilih Urutan:\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("Pilih: ");
    scanf("%d", &order);
    return order;
}

// Fungsi untuk menukar dua angka
void swap(int* a, int* b) {
	int temp = *a;
	
	*a = *b;
	*b = temp;
} 

void bubbleSort(int arr[], int n, int ascending) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (ascending) {
                if (arr[j] > arr[j+1])
                    swap(&arr[j], &arr[j+1]);
            } else {
                if (arr[j] < arr[j+1])
                    swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void selectionSort(int arr[], int n, int ascending) {
    int i, j, extremum;
    for (i = 0; i < n-1; i++) {
        extremum = i;
        for (j = i+1; j < n; j++) {
            if (ascending) {
                if (arr[j] < arr[extremum])
                    extremum = j;
            } else {
                if (arr[j] > arr[extremum])
                    extremum = j;
            }
        }
        swap(&arr[extremum], &arr[i]);
    }
}

void insertionSort(int arr[], int n, int ascending) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        if (ascending) {
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
        } else {
            while (j >= 0 && arr[j] < key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
        }
        arr[j + 1] = key;
    }
}

int partition(int arr[], int low, int high, int ascending) {
    int pivot = arr[high];
    int i = (low - 1);
    
    for (int j = low; j <= high - 1; j++) {
        if (ascending) {
            if (arr[j] < pivot) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        } else {
            if (arr[j] > pivot) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high, int ascending) {
    if (low < high) {
        int pi = partition(arr, low, high, ascending);
        quickSort(arr, low, pi - 1, ascending);
        quickSort(arr, pi + 1, high, ascending);
    }
}

void printArray(int arr[], int size) {
    
    for (int i = 0; i < size; i++)
    
        printf("%d ", arr[i]);
        printf("\n");

}


void merge(int arr[], int left, int mid, int right, int ascending) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArr[n1], rightArr[n2];

    for (i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (ascending) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k] = leftArr[i];
                i++;
            } else {
                arr[k] = rightArr[j];
                j++;
            }
        } else {
            if (leftArr[i] >= rightArr[j]) {
                arr[k] = leftArr[i];
                i++;
            } else {
                arr[k] = rightArr[j];
                j++;
            }
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right, int ascending) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, ascending);
        mergeSort(arr, mid + 1, right, ascending);
        merge(arr, left, mid, right, ascending);
    }
}

int main() {
    while (1) {
        int choice = menu();
        if (choice == 6) break;
        
        if (choice < 1 || choice > 6) {
            printf("Pilihan tidak valid!\n");
            continue;
        }
        
        int n;
        printf("Masukan jumlah elemen: ");
        scanf("%d", &n);
        
        int arr[n];
        printf("Masukan angka: ");
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        
        int order = getOrder();
        int ascending = (order == 1);
        
        printf("\nArray sebelum sorting: ");
        printArray(arr, n);
        
        switch (choice) {
            case 1:
                quickSort(arr, 0, n - 1, ascending);
                break;
            case 2:
                mergeSort(arr, 0, n - 1, ascending);
                break;
            case 3:
                bubbleSort(arr, n, ascending);
                break;
            case 4:
                selectionSort(arr, n, ascending);
                break;
            case 5:
                insertionSort(arr, n, ascending);
                break;
        }
        
        printf("Hasil pengurutan: ");
        printArray(arr, n);
    }
    return 0;
}