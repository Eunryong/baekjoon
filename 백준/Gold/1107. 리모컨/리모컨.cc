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
#include <set>
using namespace std;
int N, M;
bool c[1000001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    char button[11];
    for (int i = 0; i < M; i++) {
        cin >> button[i];
    }
    int min_n = -100000;
    int min_len = 0;
    int max_n = -100000;
    int max_len = 0;
    for (int i = 0; i < 1000001; i++) {
        c[i] = 1;
        string n = to_string(i);
        for (int j = 0; j < M; j++) {
            if (n.find(button[j]) != string::npos)
                c[i] = 0;
        }
        if (i <= N && c[i]) {
            min_n = i;
            min_len = n.size();
        }
        if (i >= N && c[i] && max_n == -100000) {
            max_n = i;
            max_len = n.size();
        }
    }
    int ans;
    if (max_n == N) {
        ans = min(abs(100 - N), max_len);
    } else {
        ans = min(abs(100 - N), min(abs(N - min_n) + min_len, abs(N - max_n) + max_len));
    }
    cout << ans;
    return 0;
}