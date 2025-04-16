#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PITA 101

int main() {
    char pita[MAX_PITA];
    int posisi_karakter[26][MAX_PITA]; // Menyimpan posisi huruf a-z
    int jumlah[26] = {0}; // Menyimpan jumlah kemunculan tiap huruf

    printf("Masukkan pita karakter (maks 100 karakter, akhiri dengan titik):\n");
    fgets(pita, sizeof(pita), stdin);

    int posisi = 1; // Menghitung semua karakter, termasuk spasi

    for (int i = 0; pita[i] != '\0'; i++) {
        char c = pita[i];

        if (c == '.') {
            break; // Akhiri di titik
        }

        if (islower(c)) {
            int index = c - 'a';
            posisi_karakter[index][jumlah[index]] = posisi;
            jumlah[index]++;
        }

        posisi++; // Hitung SEMUA karakter (termasuk spasi)
    }

    int kosong = 1;
    for (int i = 0; i < 26; i++) {
        if (jumlah[i] > 0) {
            kosong = 0;
            printf("%c :\n", i + 'a');
            for (int j = 0; j < jumlah[i]; j++) {
                printf(" %d\n", posisi_karakter[i][j]);
            }
            printf("Muncul %d kali\n", jumlah[i]);
        }
    }

    if (kosong) {
        printf("Pita kosong, tidak ada isinya\n");
    }

    return 0;
}
