#include <stdio.h>
#include <conio.h>
int main(){ 
    int Ar[10] = {1,2,3,4,5,6,7,8,9,10}; // untuk proses ascending
    int i,tar, awal=0, akhir=10, tengah;
    // clrscr(); 
    printf("Datanya adalah = ");
    for(i=0;i<10;i++){
        printf("%d ", Ar[i]);
    } 
    printf("\nMasukan data yang dicari : "); scanf("%d",&tar);
    while (awal <= akhir){
        tengah = (awal + akhir)/2; 
        if (tar > Ar[tengah] ) {// descending ubah tanda > menjadi <
            awal = tengah + 1; 
        }else if (tar < Ar[tengah]){ // descending ubah tanda < menjadi >
            akhir= tengah - 1;
        }else{
            awal = akhir +1;
        }
    }
    if (tar == Ar[tengah]){
    printf(" Data ditemukan pada index ke-%d",tengah);
    }else{
    printf("Data tidak ditemukan…! ");
    }
    getchar();
  }