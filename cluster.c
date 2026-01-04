#include <stdio.h>

#define DUGUM_SAYISI 6

int matris[DUGUM_SAYISI][DUGUM_SAYISI] = {
    {0, 1, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 0},
    {0, 0, 1, 0, 1, 0},
    {0, 0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0}
};

int ziyaret_edildi[DUGUM_SAYISI] = {0};

void dfs(int dugum) {
    ziyaret_edildi[dugum] = 1;
    printf("%d ", dugum);

    for (int i = 0; i < DUGUM_SAYISI; i++) {
        if (matris[dugum][i] == 1 && !ziyaret_edildi[i]) {
            dfs(i);
        }
    }
}

int main() {
    int cluster_sayisi = 0;

    printf("Graph icindeki cluster yapilari:\n");

    for (int i = 0; i < DUGUM_SAYISI; i++) {
        if (!ziyaret_edildi[i]) {
            cluster_sayisi++;
            printf("Cluster %d: ", cluster_sayisi);
            dfs(i);
            printf("\n");
        }
    }

    printf("\nToplam bulunan cluster sayisi: %d\n", cluster_sayisi);

    return 0;
}