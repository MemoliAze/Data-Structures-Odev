#include <stdio.h>
#include <stdlib.h>

struct Dugum {
    int veri;
    struct Dugum* sonraki;
    struct Dugum* onceki;
};

void listele(struct Dugum* kafa) {
    struct Dugum* gecici = kafa;
    printf("Liste: ");
    while (gecici != NULL) {
        printf("%d <-> ", gecici->veri);
        gecici = gecici->sonraki;
    }
    printf("NULL\n");
}

void araya_ekle(struct Dugum* onceki_dugum, int yeni_veri) {
    if (onceki_dugum == NULL) return;

    struct Dugum* yeni_dugum = (struct Dugum*)malloc(sizeof(struct Dugum));
    yeni_dugum->veri = yeni_veri;

    yeni_dugum->sonraki = onceki_dugum->sonraki;
    onceki_dugum->sonraki = yeni_dugum;
    yeni_dugum->onceki = onceki_dugum;

    if (yeni_dugum->sonraki != NULL) {
        yeni_dugum->sonraki->onceki = yeni_dugum;
    }
}

void sil(struct Dugum** kafa_referansi, struct Dugum* silinecek) {
    if (*kafa_referansi == NULL || silinecek == NULL) return;

    if (*kafa_referansi == silinecek) {
        *kafa_referansi = silinecek->sonraki;
    }

    if (silinecek->sonraki != NULL) {
        silinecek->sonraki->onceki = silinecek->onceki;
    }

    if (silinecek->onceki != NULL) {
        silinecek->onceki->sonraki = silinecek->sonraki;
    }

    free(silinecek);
}

int main() {
    struct Dugum* kafa = (struct Dugum*)malloc(sizeof(struct Dugum));
    kafa->veri = 10;
    kafa->onceki = NULL;
    kafa->sonraki = NULL;


    araya_ekle(kafa, 20);
    araya_ekle(kafa->sonraki, 30);

    listele(kafa);


    sil(&kafa, kafa->sonraki);

    printf("Silme isleminden sonra ");
    listele(kafa);

    return 0;
}
