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
int N, M;
long long sum[1000001];
int m[1001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        int t;
        cin >> t;
        sum[i] = ((i != 0 ? sum[i - 1] : 0) + t);
        m[sum[i] % M]++;
    }
    ans = m[0];
    for (int i = 0; i < M; i++) {
        int tmp = m[i];
        if (tmp > 0) {
            while (--tmp) ans += tmp;
        }
    }
    cout << ans;
    return 0;
}