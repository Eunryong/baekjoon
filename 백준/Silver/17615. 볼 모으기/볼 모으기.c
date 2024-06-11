#include <stdio.h>
#include <stdbool.h>
#define min(x, y) (x) < (y) ? (x) : (y)
int main() {
    int n;
    scanf("%d", &n);
    char buf[n + 1];
    scanf("%s", &buf);
    int ans = n + 1;
    int r = 0, b = 0;
    int st = 0, en = 0;
    bool r_st = 0, b_st = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            if (buf[i] == 'R') r_st = 1;
            else b_st = 1;
        }
        if (!r_st || !b_st) {
            if (r_st == 0 && buf[i] == 'B') st++;
            else if (b_st == 0 && buf[i] == 'R') st++;
            else if (r_st && buf[i] == 'B') {
                b_st = 1;
            }
            else if (b_st && buf[i] == 'R') {
                r_st = 1;
            }
        }
        if (buf[i] == 'R') r++;
        if (buf[i] == 'B') b++;
    }
    r_st = 0; b_st = 0;
    for (int i = n - 1; i >= 0 && (!r_st || !b_st); i--) {
        if (i == n - 1) {
            if (buf[i] == 'R') r_st = 1;
            else b_st = 1;
        }
        if (!r_st || !b_st) {
            if (r_st == 0 && buf[i] == 'B') en++;
            else if (b_st == 0 && buf[i] == 'R') en++;
            else if (r_st && buf[i] == 'B') {
                b_st = 1;
            }
            else if (b_st && buf[i] == 'R') {
                r_st = 1;
            }
        }
    }
    if (buf[0] == 'R') {
        ans = min(ans, r - st);
        ans = min(ans, b);
    } else {
        ans = min(ans, r);
        ans = min(ans, b - st);
    }
    if (buf[n - 1] == 'R') {
        ans = min(ans, r - en);
        ans = min(ans, b);
    } else {
        ans = min(ans, r);
        ans = min(ans, b - en);
    }
    printf("%d", ans);
}