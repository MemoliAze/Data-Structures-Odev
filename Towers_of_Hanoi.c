#include <stdio.h>

void kuleleri_tasi(int disk_sayisi, char baslangic, char bitis, char yedek) {
    if (disk_sayisi == 1) {
        printf("1. Disk: %c -> %c\n", baslangic, bitis);
        return;
    }

    kuleleri_tasi(disk_sayisi - 1, baslangic, yedek, bitis);
    printf("%d. Disk: %c -> %c\n", disk_sayisi, baslangic, bitis);
    kuleleri_tasi(disk_sayisi - 1, yedek, bitis, baslangic);
}

int main() {
    int n;

    printf("Disk sayisini girin: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Lutfen gecerli bir sayi giriniz.\n");
        return 1;
    }

    printf("\nCozum Adimlari:\n");
    kuleleri_tasi(n, 'A', 'C', 'B');

    return 0;
}
