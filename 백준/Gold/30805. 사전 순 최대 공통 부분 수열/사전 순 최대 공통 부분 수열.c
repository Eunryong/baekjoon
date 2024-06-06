#include <stdio.h>
#include <memory.h>
#define max(x, y) (x) > (y) ? (x) : (y)
int main() {
    int n, m;
    int a[101][101], b[101][101];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    scanf("%d", &n);
    int a_size[101];
    memset(a_size, 0, sizeof(a_size));
    for (int i = 1; i <= n; i++) {
        int tmp;
        scanf("%d", &tmp);
        a[tmp][a_size[tmp]] = i;
        a_size[tmp]++;
    }
    int b_size[101];
    memset(b_size, 0, sizeof(b_size));
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        int tmp;
        scanf("%d", &tmp);
        b[tmp][b_size[tmp]] = i;
        b_size[tmp]++;
    }
    int cnt = 0;
    int ans[101];
    memset(ans, 0, sizeof(ans));
    int cur_a = 0;
    int cur_b = 0;
    for (int i = 100; i > 0; i--) {
        if (a_size[i] && b_size[i]) {
            if (cnt == 0) {
                for (int j = 0; j < a_size[i] && j < b_size[i]; j++) {
                    ans[cnt] = i;
                    cnt++;
                    cur_a = a[i][j];
                    cur_b = b[i][j];
                }
            } else {
                int tmp_cnt = 0;
                int tmp_a = cur_a;
                int tmp_b = cur_b;
                for (int j = a_size[i] - 1, k = b_size[i] - 1; j >= 0 && k >= 0 && cur_a < a[i][j] && cur_b < b[i][k]; j--, k--) {
                    tmp_cnt++;
                    tmp_a = max(tmp_a, a[i][j]);
                    tmp_b = max(tmp_b, b[i][k]);
                }
                for (int j = 0; j < tmp_cnt; j++) {
                    ans[cnt] = i;
                    cnt++;
                }
                cur_a = tmp_a;
                cur_b = tmp_b;
            }
        }
    }
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++) {
        printf("%d ", ans[i]);
    }
}