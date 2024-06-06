#include<stdio.h>
#include<memory.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int ans = 100001;
    int q[300001];
    int vis[100001];
    int q_size = 1;
    int cnt = 0;
    int ans_cnt = 0;
    memset(q, 0, sizeof(q));
    memset(vis, 0, sizeof(vis));
    q[0] = n;
    while (q_size) {
        int size = 0;
        int tmp[q_size * 3];
        for (int i = 0; i < q_size; i++) {
            int x = q[i];
            if (x == k) {
                ans = cnt;
                ans_cnt++;
                continue;
            }
            vis[x] = 1;
            if (x > 0 && vis[x - 1] == 0) {
                tmp[size] = x - 1;
                size++;
            }
            if (x < 100000 && vis[x + 1] == 0) {
                tmp[size] = x + 1;
                size++;
            }
            if (x * 2 <= 100000 && vis[x * 2] == 0) {
                tmp[size] = x * 2;
                size++;
            }
        }
        if (ans != 100001) break;
        for (int i = 0; i < size; i++) {
            q[i] = tmp[i];
        }
        cnt++;
        q_size = size;
    }
    printf("%d\n", ans);
    printf("%d\n", ans_cnt);
}