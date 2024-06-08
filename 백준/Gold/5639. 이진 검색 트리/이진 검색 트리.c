#include <stdio.h>
#include <memory.h>
#include <stdbool.h>
int arr[10001];

void print(int st, int en) {
    if (st >= en) return;
    int mid = st + 1;
    while (mid < en) {
        if (arr[st] < arr[mid]) break;
        mid++;
    }
    print(st + 1, mid);
    print(mid, en);
    printf("%d\n", arr[st]);
}

int main() {
    int i = 0;
    while (scanf("%d", &arr[i++]) != EOF) ;
    print(0, i - 1);
}