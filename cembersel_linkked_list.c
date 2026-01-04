#include <stdio.h>
#include <stdlib.h>

struct Dugum {
    int veri;
    struct Dugum* sonraki;
};

void listele(struct Dugum* ilk) {
    struct Dugum* gecici = ilk;
    if (ilk != NULL) {
        do {
            printf("%d -> ", gecici->veri);
            gecici = gecici->sonraki;
        } while (gecici != ilk);
    }
    printf("(Baslangic)\n");
}

void araya_ekle(struct Dugum* onceki_dugum, int yeni_veri) {
    if (onceki_dugum == NULL) return;

    struct Dugum* yeni_dugum = (struct Dugum*)malloc(sizeof(struct Dugum));
    yeni_dugum->veri = yeni_veri;
    yeni_dugum->sonraki = onceki_dugum->sonraki;
    onceki_dugum->sonraki = yeni_dugum;
}

void dugum_sil(struct Dugum** ilk_referans, int anahtar) {
    if (*ilk_referans == NULL) return;

    struct Dugum *gecici = *ilk_referans, *onceki;

    if (gecici->veri == anahtar && gecici->sonraki == *ilk_referans) {
        free(gecici);
        *ilk_referans = NULL;
        return;
    }

    if (gecici->veri == anahtar) {
        onceki = *ilk_referans;
        while (onceki->sonraki != *ilk_referans) {
            onceki = onceki->sonraki;
        }
        *ilk_referans = gecici->sonraki;
        onceki->sonraki = *ilk_referans;
        free(gecici);
        return;
    }

    while (gecici->sonraki != *ilk_referans && gecici->veri != anahtar) {
        onceki = gecici;
        gecici = gecici->sonraki;
    }

    if (gecici->veri == anahtar) {
        onceki->sonraki = gecici->sonraki;
        free(gecici);
    }
}

int main() {
    struct Dugum* ilk = (struct Dugum*)malloc(sizeof(struct Dugum));
    struct Dugum* ikinci = (struct Dugum*)malloc(sizeof(struct Dugum));

    ilk->veri = 10;
    ilk->sonraki = ikinci;

    ikinci->veri = 30;
    ikinci->sonraki = ilk;

    printf("Liste ilk hali: ");
    listele(ilk);


    araya_ekle(ilk, 20);
    printf("Ekleme sonrasi: ");
    listele(ilk);


    dugum_sil(&ilk, 30);
    printf("Silme sonrasi: ");
    listele(ilk);

    return 0;
}
