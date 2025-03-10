#include <stdio.h>
#include <conio.h>
#include <process.h>
int main(){ 
    int A[10],index[10], i,j=0,k;
    //proses penginputan data
    for(i=0;i<10;i++){
        printf("Data ke-%d:",i+1);
        scanf("%d",&A[i]);
    }
    //memasukkan data yang akan dicari ke dalam K
    printf("Masukkan data yang akan anda cari:");
    scanf("%d",&k);
    
    //proses pencarian data
    j=0;
    for (i=0;i<10;i++){
        if(A[i]==k){
        index[j]=i;
        j++;
        }
    }
    //jika data ditemukan dalam array
    if (j>0){
        printf("Data %d yang dicari ada %d buah\n",k,j);
        printf("Data tersebut terdapat dalam index ke :");
        for(i=0;i<j;i++){

            printf(" %d ",index[i]);
            printf("\n");
        }
    }
    //jika tidak ditemukan
    else{
    printf("Data tidak ditemukan dalam array\n");
    }
    getchar();
} //akhir program