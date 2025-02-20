#include <stdio.h>

void asc(int arr[],int n){
  int i, j, k, tmp;
  for(i = 1; i < n; i++){
    printf("proses ke: %d\n", i);
    for( j = i; j > 0 && arr[j] < arr[j-1]; j--){
      tmp = arr[j-1];
      arr[j-1] = arr[j];
      arr[j] = tmp;

      for(k = 0; k < n; k++){
        printf("%d ", arr[k]);
      }
      printf("\n");
    }
  }
};

void dsc(int arr[],int n){
  int i, j, k, tmp;
  for(i = 1; i < n; i++){
    printf("proses ke: %d\n", i);
    for( j = i; j > 0 && arr[j] > arr[j-1]; j--){
      tmp = arr[j-1];
      arr[j-1] = arr[j];
      arr[j] = tmp;

      for(k = 0; k < n; k++){
        printf("%d ", arr[k]);
      }
      printf("\n");
    }
  }
};

int main () {
  int arr[100], i, j, n;
  printf("Masukkan banyak elemen : ");
  scanf("%d", &n);

  printf("Masukkan nilai :");
  for(i = 0; i < n; i++){
    scanf("%d", &arr[i]);
  }

  asc(arr, n);

  printf("hasil pengurutan asc adalah : \n ");
  for(i = 0; i < n; i++){
    printf("%d ", arr[i]);
  }

  printf("\n\n");

  dsc(arr, n);

  printf("hasil pengurutan asc adalah : \n ");
  for(i = 0; i < n; i++){
    printf("%d ", arr[i]);
  }

}