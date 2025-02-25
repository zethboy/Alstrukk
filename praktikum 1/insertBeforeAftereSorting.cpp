#include <stdio.h>

int angka[10] = {7, 7, 3, 6, 9, 2, 8, 4, 5, 2};

main(){
  printf("angka sebelum di sorting :\n");
  for (int i = 0; i < 10; i++){
    printf("%d ", angka[i]);
  }
  printf("\n");

  for(int i=1; i<10; i++){
		for(int j=i; j>0 && angka[j] < angka[j-1]; j--){
			int temp = angka[j-1];
			angka[j-1]=angka[j];
			angka[j]=temp;
		}
	}

	printf("angka setelah di sorting\n ");
	for(int i=0; i<10; i++){
		printf("%d ", angka[i]);
	}

}