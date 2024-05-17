#include <stdio.h>

int main() {
    int m;
    scanf("%d", &m);
    m = 1000 - m;
    int ans = 0;
    while (m) {
        if (m >= 500) m -=500;
        else if (m >= 100) m -= 100;
        else if (m >= 50) m -= 50;
        else if (m >= 10) m -= 10;
        else if (m >= 5) m -= 5;
        else if (m >= 1) m -= 1;
        ans++;
    }
    printf("%d", ans);
}