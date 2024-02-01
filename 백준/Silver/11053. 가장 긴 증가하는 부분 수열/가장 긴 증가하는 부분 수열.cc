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

int dp[1001];
int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    vector<int> v;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    for (int i = 0; i < N; i++) {
        int m = -1;
        for (int j = 0; j < i; j++) {
            if (v[i] > v[j]) {
                m = max(m, dp[j]);
            }
        }
        if (m == -1)
            dp[i] = 1;
        else
            dp[i] = m + 1;
    }
    cout << *max_element(dp, dp + N);

    return 0;
}