#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PITA 101

int main() {
    char pita[MAX_PITA];
    int posisi_angka[10][MAX_PITA];
    int posisi_huruf[26][MAX_PITA];
    int jumlah_angka[10] = {0};
    int jumlah_huruf[26] = {0};

    printf("Masukkan pita karakter (maks 100 karakter, akhiri dengan titik):\n");
    fgets(pita, sizeof(pita), stdin);

    int posisi = 1;
    int ada_isi = 0;

    
    if ((pita[0] == '.' && (pita[1] == '\n' || pita[1] == '\0'))) {
        printf("Pita kosong, tidak ada isinya\n");
        return 0;
    }

    for (int i = 0; pita[i] != '\0'; i++) {
        char c = pita[i];

        if (c == '.') {
            break;
        }

        if (islower(c)) {
            int idx = c - 'a';
            posisi_huruf[idx][jumlah_huruf[idx]] = posisi;
            jumlah_huruf[idx]++;
            ada_isi = 1;
        } else if (isdigit(c)) {
            int idx = c - '0';
            posisi_angka[idx][jumlah_angka[idx]] = posisi;
            jumlah_angka[idx]++;
            ada_isi = 1;
        }

        posisi++;
    }

    if (!ada_isi) {
        return 0; // tidak print apa-apa
    }

    // Cetak angka
    for (int i = 0; i < 10; i++) {
        if (jumlah_angka[i] > 0) {
            printf("%d :\n", i);
            for (int j = 0; j < jumlah_angka[i]; j++) {
                printf(" %d\n", posisi_angka[i][j]);
            }
            printf("Muncul %d kali\n", jumlah_angka[i]);
        }
    }

    // Cetak huruf
    for (int i = 0; i < 26; i++) {
        if (jumlah_huruf[i] > 0) {
            printf("%c :\n", i + 'a');
            for (int j = 0; j < jumlah_huruf[i]; j++) {
                printf(" %d\n", posisi_huruf[i][j]);
            }
            printf("Muncul %d kali\n", jumlah_huruf[i]);
        }
    }

    return 0;
}
