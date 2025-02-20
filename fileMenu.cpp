#include <stdio.h>
#include <stdlib.h>

int main() {
  int pilihan;
  
  printf("=== Menu Pilihan ===\n");
  printf("1.  Buble\n");
  printf("2. Merger\n");
  printf("Masukkan pilihan Anda (1 atau 2): ");
  scanf("%d", &pilihan);
  
  switch (pilihan) {
      case 1:
          break;
      case 2:
          printf("Anda memilih pilihan 2.\n");
          break;
      default:
          printf("Pilihan tidak valid!\n");
  }
  
  return 0;
}