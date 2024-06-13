#include <stdio.h>
#include <stdlib.h>

int comp(int *a, int *b) {
    return *a - *b;
}

int main() {
    int t, n, m;
    scanf("%d", &t);
    //input, make sum arr
    scanf("%d", &n);
    int A[n + 1];
    A[0] = 0;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        int tmp;
        scanf("%d", &tmp);
        sum += tmp;
        A[i] = sum;
    }
    scanf("%d", &m);
    int B[m + 1];
    B[0] = 0;
    sum = 0;
    for (int i = 1; i <= m; i++) {
        int tmp;
        scanf("%d", &tmp);
        sum += tmp;
        B[i] = sum;
    }
    
    //make subset sum arr
    int a_subset[n * (n + 1) / 2];
    int a_subset_size = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            a_subset[a_subset_size] = A[i] - A[j];
            a_subset_size++;
        }
    }
    int b_subset[m * (m + 1) / 2];
    int b_subset_size = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < i; j++) {
            b_subset[b_subset_size] = B[i] - B[j];
            b_subset_size++;
        }
    }
    qsort(a_subset, a_subset_size, sizeof(int), comp);
    qsort(b_subset, b_subset_size, sizeof(int), comp);

    // solve
    long long cnt = 0;
    for (int i = 0, j = b_subset_size - 1; i < a_subset_size && j >= 0;) {
        if (a_subset[i] + b_subset[j] == t) {
            int a_cnt = 0, b_cnt = 0;
            while (a_subset[a_cnt + i] == a_subset[i] && a_cnt + i < a_subset_size) a_cnt++;
            while (b_subset[j - b_cnt] == b_subset[j] && j - b_cnt >= 0) b_cnt++;
            cnt += (long long)a_cnt * b_cnt;
            i += a_cnt, j -= b_cnt;
        } else if(a_subset[i] + b_subset[j] < t) i++;
        else j--;
    }
    printf("%lld", cnt);
}
