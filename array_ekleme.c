#include <stdio.h>

void dizi_yazdir(int dizi[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", dizi[i]);
    }
    printf("\n");
}

int main() {
    int dizi[100] = {10, 20, 30, 40, 50};
    int boyut = 5;
    int i, indis, yeni_eleman;

    printf("Mevcut Dizi: ");
    dizi_yazdir(dizi, boyut);


    indis = 2;
    yeni_eleman = 25;

    for (i = boyut; i > indis; i--) {
        dizi[i] = dizi[i - 1];
    }
    dizi[indis] = yeni_eleman;
    boyut++;

    printf("Ekleme Sonrasi (Indis %d, Deger %d): ", indis, yeni_eleman);
    dizi_yazdir(dizi, boyut);


    indis = 3;

    for (i = indis; i < boyut - 1; i++) {
        dizi[i] = dizi[i + 1];
    }
    boyut--;

    printf("Silme Sonrasi (Indis %d silindi): ", indis);
    dizi_yazdir(dizi, boyut);

    return 0;
}
