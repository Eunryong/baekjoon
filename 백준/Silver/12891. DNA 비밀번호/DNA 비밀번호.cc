#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#include <cmath>
using namespace std;
int cnt[4];
int n, p;
int a, c, g, t;
enum acgt {
    A,
    C,
    G,
    T
};

void count(char c, bool a) {
    switch (c) {
            case 'A':
                a ? cnt[A]++ : cnt[A]--;
                break ;
            case 'C':
                a ? cnt[C]++ : cnt[C]--;
                break ;
            case 'G':
                a ? cnt[G]++ : cnt[G]--;
                break ;
            case 'T':
                a ? cnt[T]++ : cnt[T]--;
                break ;
        }
}

bool check() {
    if (cnt[A] >= a && cnt[C] >= c && cnt[G] >= g && cnt[T] >= t) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> p;
    string s;
    cin >> s;
    cin >> a >> c >> g >> t;
    for (int i = 0; i < p; i++) {
        count(s[i], 1);
    }
    int ans = check();
    for (int i = 1; i + p <= n; i++) {
        count(s[i - 1], 0);
        count(s[i + p - 1], 1);
        ans += check();
    }
    cout << ans;
    return 0;
}