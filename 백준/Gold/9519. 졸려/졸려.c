#include <stdio.h>
#include <string.h>
int idx[1001];
int size;

int check() {
    for (int i = 0; i < size; i++) {
        if (idx[i] != i) return 0;
    }
    return 1;
}

void simulation() {
    int tmp[1001];
    for (int j = 0; j < size; j++) 
        tmp[j] = idx[j];
    for (int j = 1; j <= size / 2; j++) {
        idx[j * 2] = tmp[j];
    }
    for (int j = 1; j <= size / 2; j++) {
        idx[(j - 1) * 2 + 1] = tmp[size - j];
    }
}

int main() {
    int n;
    scanf("%d", &n);
    char buf[1001];
    scanf("%s", buf);
    size = strlen(buf);
    int cnt = 1;
    for (int i = 0; i < size; i++) idx[i] = i;
    simulation();
    while (check() == 0) {
        simulation();
        cnt++;
    }
    n %= cnt;
    for (int i = 0; i < cnt - n; i++) {
        simulation();
    }
    for (int i = 0; i < size; i++) {
        printf("%c", buf[idx[i]]);
    }
}