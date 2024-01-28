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
int arr[100010];
int dp[100010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    // vector<int> v;
    // for (int i = 0; i < N; i++) {
    //     int tmp;
    //     cin >> tmp;
    //     v.push_back(tmp);
    // }
    // for (int i = 0; i < M; i++) {
    //     int x, y;
    //     cin >> x >> y;
    //     int sum = 0;
    //     for (int j = x - 1; j < y; j++) {
    //         sum += v[j];
    //     }
    //     cout << sum << "\n";
    // }

    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    dp[1] = arr[1];
    for (int i = 2; i <= N; i++)
        dp[i] = dp[i - 1] + arr[i];
    

    for (int i = 1; i <= M; i++) {
        int x, y; cin>>x>>y;
        cout << dp[y] - dp[x-1] <<'\n';
    }
    return 0;
}