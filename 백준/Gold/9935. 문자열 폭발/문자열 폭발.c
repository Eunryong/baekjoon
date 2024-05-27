#include <stdio.h>
#include <string.h>

int check(char* ans, char* c4, int top, int c4_len) {
    if (top + 1 < c4_len) return 0;
    for (int i = 0; i < c4_len; i++) {
        if (ans[top - i] != c4[c4_len - i - 1]) return 0;
    }
    return 1;
}

int main() {
    int top = 0;
    char s[1000001];
    char c4[36];
    scanf("%s", s);
    scanf("%s", c4);
    int s_len = strlen(s);
    int c4_len = strlen(c4);
    char ans[s_len];
    memset(ans, 0, s_len);
    for (int i = 0; i < s_len; i++) {
        ans[top] = s[i];
        ans[top + 1] = 0;
        if (check(ans, c4, top, c4_len)) {
            top -= c4_len;
            ans[top + 1] = 0;
        }
        top++;
    }
    printf("%s", top == 0 && ans[top] == 0 ? "FRULA" : ans);
}