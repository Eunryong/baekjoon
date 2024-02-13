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
int N, K;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    queue<int> q[21]; 
    long ans = 0;
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        int l = s.size();
        while (!q[l].empty() && i - q[l].front() > K) {
            q[l].pop();
        }
        ans += q[l].size();
        q[l].push(i);
    }
    cout << ans;
    return 0;
}