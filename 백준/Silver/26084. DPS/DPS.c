#include <stdio.h>
#include <memory.h>
int main() {
    char str[4];
    int n;
    scanf("%s\n%d", str, &n);
    long long cnt[26];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) {
        char tmp[11];
        scanf("%s", tmp);
        cnt[tmp[0] - 'A']++;
    }
    long long tmp[26];
    memset(tmp, 0, sizeof(tmp));
    long long ans = 1;
    for (int i = 0; i < 3; i++) {
        tmp[str[i] - 'A']++;
        ans *= cnt[str[i] - 'A'];
        cnt[str[i] - 'A']--;
    }
    for (int i = 0; i < 3; i++) {
        ans /= tmp[str[i] - 'A'];
        tmp[str[i] - 'A']--;
    }
    printf("%lld", ans);
}