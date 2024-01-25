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

int N, M, B;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> B;

    vector<int> v[N];
    int m = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int tmp;
            cin >> tmp;
            v[i].push_back(tmp);
            m = max(tmp, m);
        }
    }
    int ans = 2147483647, f = 0;
    for (int i = 0; i <= 256; i++) {
        int b = B;
        int sum = 0;
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if(v[j][k] < i) {
                    sum += i - v[j][k];
                    b -= i - v[j][k];
                } else if (v[j][k] > i) {
                    sum += 2 * (v[j][k] - i);
                    b += v[j][k] - i;
                }
            }
        }
        if (b < 0) continue;
        if (ans >= sum) {
            ans = sum;
            f = i;
        }
    }
    cout << ans << " " << f;
    return 0;
}