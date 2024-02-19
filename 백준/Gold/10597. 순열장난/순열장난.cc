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
string s;
vector<string> v;
bool e;
int ss = 0;
bool vis[51];
bool check() {
    for (int i = 1; i <= v.size(); i++) {
        if (!vis[i]) return false;
    }
    return true;
}

void solve(int n) {
    if (e || v.size() > 50) return;
    if (n == ss && check()) {
        e = 1;
        return;
    }
    for (int i = 1; i <= 2 && i + n <= ss; i++) {
        string tmp = s.substr(n, i);
        if (tmp[0] == '0') continue;
        int t = stoi(tmp);
        if (!vis[t] && t <= 50) {
            vis[t] = 1;
            v.push_back(tmp);
            solve(n + i);
            if (e) return;
            vis[t] = 0;
            v.pop_back();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> s;
    ss = s.size();
    solve(0);
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    return 0;
}