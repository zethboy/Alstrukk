#include <stdio.h>
#include <conio.h>

int main(){
    int Ar[] = {2, 5, 6, 9, 10, 12, 15, 18, 20, 22}; // untuk proses ascending
    int n = sizeof(Ar) / sizeof(Ar[0]); // menghitung panjang array
    int i,tar, awal=0, akhir=n, tengah;
    
    printf("Array awal: ");
    for(i=0; i<10; i++){
        printf("%d ", Ar[i]);
    }
    
    printf("\n\nMasukkan angka yang ingin dicari: ");
    scanf("%d", &tar);
    
    while(awal <= akhir){
        tengah = (awal + akhir) / 2;
        
        if(Ar[tengah] == tar){
            printf("\nAngka %d ditemukan pada indeks ke-%d", tar, tengah);
            break;
        }
        else if(Ar[tengah] < tar){
            awal = tengah + 1;
        }
        else{
            akhir = tengah - 1;
        }
    }
}