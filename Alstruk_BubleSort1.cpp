// nama file : Alstruk_BubleSort1

#include <stdio.h>

void asc(int arr[], int n){
  int i, j, k, tmp;
  for(i = 0; i < n; i++){
    printf("Proses pengurutan ke-%d \n", i+1);
    for(j=0; j < n-i-1; j++){
      if(arr[j] > arr[j+1]){
        tmp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = tmp;
        
        for(k = 0; k < n; k++){
            printf("%d ", arr[k]);
        }
        printf("\n");
      }
    }
  }
}

void dsc(int arr[], int n){
  int i, j, k, tmp;
  for(i = 0; i < n; i++){
    printf("Proses pengurutan ke-%d \n", i+1);
    for(j=0; j < n-i-1; j ++){
      if(arr[j] < arr[j+1]){
        tmp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = tmp;

        for(k = 0; k < n; k++){
            printf("%d ", arr[k]);
        }
        printf("\n");
      }
    }
  }
}

int main() {
  int array[100], n, i, j;
  printf("Masukkan banyak elemen: ");
  scanf("%d", &n);

  printf("Masukkan nilai: \n");

  for(i = 0; i < n; i++){
    scanf("%d", &array[i]);
  }

  asc(array, n);

  printf("Hasil pengurutan ascending sebagai berikut:\n");
  for(i = 0; i < n; i++){
    printf("%d ", array[i]);
  }
  printf("\n\n\n");

  dsc(array, n);

  printf("Hasil pengurutan descending sebagai berikut:\n");
  for(i = 0; i < n; i++){
    printf("%d ", array[i]);
  }
  printf("\n");
}