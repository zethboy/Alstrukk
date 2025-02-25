#include <stdio.h>

void asc (char arr[], int n){
  char tmp;
  for(int i = 0; i < n - 1; i++){
    for(int j = 0; j < n-i-1; j++){
      if(arr[j] > arr[j+1]){
        tmp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = tmp;
      }
    }
  }
}

int main() {
  char array[100];
  int n;
  printf("Masukkan banyak elemen: ");
  scanf("%d", &n);
  getchar();

  printf("Masukkan karakter: \n");

  for(int i = 0; i < n; i++){
    printf("karakter %d: ", i+1);
    scanf(" %c", &array[i]);
  }

  asc(array, n);

  printf("Hasil pengurutan ascending sebagai berikut:\n");
  for(int i = 0; i < n; i++){
    printf("%c ", array[i]);
  }
  return 0;
}