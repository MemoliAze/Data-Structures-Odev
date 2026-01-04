#include <stdio.h>

#define MAX 15

char tree[MAX];

void init() {
    for (int i = 0; i < MAX; i++) {
        tree[i] = '-';
    }
}

void root(char key) {
    tree[0] = key;
}

void set_left(char key, int parent) {
    if (tree[parent] == '-') {
        printf("Hata: %d indisli ebeveyn bulunamadi!\n", parent);
    } else {
        tree[(2 * parent) + 1] = key;
    }
}

void set_right(char key, int parent) {
    if (tree[parent] == '-') {
        printf("Hata: %d indisli ebeveyn bulunamadi!\n", parent);
    } else {
        tree[(2 * parent) + 2] = key;
    }
}

void print_tree() {
    printf("Agac Yapisi: ");
    for (int i = 0; i < MAX; i++) {
        if (tree[i] != '-')
            printf("%c ", tree[i]);
        else
            printf("- ");
    }
    printf("\n");
}

int main() {
    init();
    
    root('A');
    set_left('B', 0);
    set_right('C', 0);
    set_left('D', 1);
    set_right('E', 1);
    set_right('F', 2);

    print_tree();

    return 0;
}