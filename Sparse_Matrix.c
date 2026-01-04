#include <stdio.h>

int main() {
    int matris[4][5] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };

    int satir = 4;
    int sutun = 5;
    int sayac = 0;

    for (int i = 0; i < satir; i++) {
        for (int j = 0; j < sutun; j++) {
            if (matris[i][j] != 0) {
                sayac++;
            }
        }
    }

    int sonuc[sayac + 1][3];

    sonuc[0][0] = satir;
    sonuc[0][1] = sutun;
    sonuc[0][2] = sayac;

    int k = 1;
    for (int i = 0; i < satir; i++) {
        for (int j = 0; j < sutun; j++) {
            if (matris[i][j] != 0) {
                sonuc[k][0] = i;
                sonuc[k][1] = j;
                sonuc[k][2] = matris[i][j];
                k++;
            }
        }
    }

    printf("Seyrek Matris (Satir - Sutun - Deger):\n");
    for (int i = 0; i <= sayac; i++) {
        printf("%d %d %d\n", sonuc[i][0], sonuc[i][1], sonuc[i][2]);
    }

    return 0;
}
