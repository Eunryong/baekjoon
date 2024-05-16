#include<stdio.h>

int main() {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    if (x + y <= z) {
        z = x + y - 1;
    } else if (y + z <= x) {
        x = y + z - 1;
    } else if (x + z <= y) {
        y = x + z - 1;
    }
    printf("%d", x + y + z);
}