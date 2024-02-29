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
int N, T;
int sum[100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        sum[i] = tmp + (i != 0 ? sum[i - 1] : 0);
    }
    cin >> T;
    while (T--) {
        int x, y;
        cin >> x >> y;
        cout << sum[y - 1] - (x > 1 ? sum[x - 2] : 0) << "\n";
    }
    return 0;
}