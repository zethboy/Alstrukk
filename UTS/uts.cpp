#include <stdio.h>

// YOGI NUGRAHA
// 247006111067
// Kelas C

// Fungsi untuk pencarian biner 
int binarySearch(int arr[], int size, int key) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
            return mid; 
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; 
}

// Fungsi untuk pencarian sekuensial
int sequentialSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key)
            return i; 
    }
    return -1; 
}


void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Fungsi untuk mencetak array
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
      printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
    int pilihan, key, size;

    // Input ukuran array
    printf("Masukkan jumlah elemen array: ");
    scanf("%d", &size);

    int arr[size];

    // Input elemen array
    printf("Masukkan %d angka: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, size);

    // Menampilkan angka yang telah diurutkan
    printf("\nAngka setelah diurutkan: ");
    printArray(arr, size);

    printf("\nPilih metode pencarian:\n");
    printf("1. Pencarian Biner\n");
    printf("2. Pencarian Sekuensial\n");
    printf("3. Tidak Ada\n");
    printf("Masukkan pilihan (1/2/3): ");
    scanf("%d", &pilihan);

    if (pilihan == 3) {
        printf("Tidak Ada\n");
        return 0; 
    }

    printf("Masukkan angka yang ingin dicari: ");
    scanf("%d", &key);

    int hasil;

    if (pilihan == 1) {
        // Karena binary search membutuhkan array yang terurut, jadi saya urutkan dulu
        bubbleSort(arr, size);
        hasil = binarySearch(arr, size, key);
    } else if (pilihan == 2) {
        hasil = sequentialSearch(arr, size, key);
    } else {
        printf("Pilihan tidak valid!\n");
        return 1;
    }

    if (hasil != -1)
        printf("Angka %d ditemukan pada indeks %d.\n", key, hasil);
    else
        printf("Angka %d tidak ditemukan.\n", key);

    return 0;
}
