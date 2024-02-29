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
int N, Q;
long long sum[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        long long t;
        cin >> t;
        sum[i] = sum[i - 1] ^ t;
    }
    long long ans = 0;
    for (int i = 0; i < Q; i++) {
        int s, e;
        cin >> s >> e;
        long long tmp = sum[e] ^ sum[s - 1];
        ans ^= tmp;
    }
    cout << ans;

    return 0;
}