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
vector<int> v[51];
int ans;
void dfs(int n) {
    if ((v[n].empty() && n != M) || (v[n].size() == 1 && v[n][0] == M)) {
        ans++;
        return ;
    }
    for (int i = 0; i < v[n].size(); i++) {
        if (v[n][i] != M && n != M) {
            dfs(v[n][i]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    int st;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (x == -1) {st = i; continue;}
        v[x].push_back(i);
    }
    cin >> M;
    dfs(st);
    cout << ans;
    return 0;
}