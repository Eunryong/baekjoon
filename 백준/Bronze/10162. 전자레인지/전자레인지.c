#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    int button[3] = {300, 60, 10};
    if (t % 10) {printf("-1"); return 0;}
    for (int i = 0; i < 3; i++) {
        printf("%d ", t / button[i]);
        t %= button[i];
    }
}