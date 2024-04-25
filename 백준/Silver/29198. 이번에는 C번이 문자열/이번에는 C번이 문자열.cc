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
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
using namespace std;
set<string> s;
int n, m, k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    priority_queue<string, vector<string>, greater<string> > q;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        q.push(str);
    }
    int j = 0;
    string str = "";
    while (!q.empty() && j < k) {
        str += q.top();
        q.pop();
        j++;
    }
    sort(str.begin(), str.end());
    cout << str;
    return 0;
}