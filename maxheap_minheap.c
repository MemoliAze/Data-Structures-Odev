#include <stdio.h>

void degistir(int *a, int *b) {
    int gecici = *a;
    *a = *b;
    *b = gecici;
}

void max_heapify(int dizi[], int n, int i) {
    int en_buyuk = i;
    int sol = 2 * i + 1;
    int sag = 2 * i + 2;

    if (sol < n && dizi[sol] > dizi[en_buyuk])
        en_buyuk = sol;

    if (sag < n && dizi[sag] > dizi[en_buyuk])
        en_buyuk = sag;

    if (en_buyuk != i) {
        degistir(&dizi[i], &dizi[en_buyuk]);
        max_heapify(dizi, n, en_buyuk);
    }
}

void min_heapify(int dizi[], int n, int i) {
    int en_kucuk = i;
    int sol = 2 * i + 1;
    int sag = 2 * i + 2;

    if (sol < n && dizi[sol] < dizi[en_kucuk])
        en_kucuk = sol;

    if (sag < n && dizi[sag] < dizi[en_kucuk])
        en_kucuk = sag;

    if (en_kucuk != i) {
        degistir(&dizi[i], &dizi[en_kucuk]);
        min_heapify(dizi, n, en_kucuk);
    }
}

void heap_olustur(int dizi[], int n, int tip) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        if (tip == 1) // Max Heap
            max_heapify(dizi, n, i);
        else          // Min Heap
            min_heapify(dizi, n, i);
    }
}

void yazdir(int dizi[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", dizi[i]);
    printf("\n");
}

int main() {
    int dizi1[] = {12, 11, 13, 5, 6, 7};
    int n1 = sizeof(dizi1) / sizeof(dizi1[0]);

    printf("Orijinal Dizi: ");
    yazdir(dizi1, n1);

    heap_olustur(dizi1, n1, 1);
    printf("Max Heap Yapisi: ");
    yazdir(dizi1, n1);

    int dizi2[] = {12, 11, 13, 5, 6, 7};
    int n2 = sizeof(dizi2) / sizeof(dizi2[0]);

    heap_olustur(dizi2, n2, 0);
    printf("Min Heap Yapisi: ");
    yazdir(dizi2, n2);

    return 0;
}
