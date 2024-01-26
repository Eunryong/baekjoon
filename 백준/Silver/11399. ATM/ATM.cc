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

int N;
vector<int> v;
int dp[1000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    int ans = 0;
    int sum = 0;
    int cur = 0;
    for (int i = 0; i < N; i++) {
        sum = cur + v[i];
        cur = sum;
        ans += sum;
    }
    cout << ans;
    return 0;
}
