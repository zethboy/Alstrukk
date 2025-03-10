#include <stdio.h>

void asc(int n,int arr[]){
  int tmp;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n - i - 1; j++){
      if (arr[j] > arr [j + 1]){
        tmp = arr [j];
        arr [j] = arr [j+1];
        arr [j+1] = tmp;
      }
    }
  }
}

int main(){
  int array[100], i, n, j;
  printf("Masukkan jumlah angka yang mau di ascending :");
  scanf("%d", &n);
  
  printf("masukkan nilainya :");
  for(i =0 ; i< n; i++){
    scanf("%d", &array[i]);
  }

  asc(n, array);

  printf("Hasil pengurutan descending sebagai berikut:\n");
  for(i = 0; i < n; i++){
    printf("%d ", array[i]);
}
}