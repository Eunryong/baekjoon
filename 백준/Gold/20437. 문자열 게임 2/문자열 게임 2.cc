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
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
using namespace std;
string s;
int g, T, K;
vector<int> v[26];
int max_ans, min_ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        max_ans = 0;
        min_ans = 10001;
        cin >> s >> K;
        for (int i = 0; i < 26; i++) v[i].clear();
        for (int i = 0; i < s.size(); i++) {
            v[s[i] - 'a'].push_back(i);
        }
        for (int i = 0; i < 26; i++) {
            if (v[i].size() >= K) {
                for (int j = 0; j + K <= v[i].size(); j++) {
                    max_ans = max(max_ans, v[i][j + K - 1] - v[i][j] + 1);
                    min_ans = min(min_ans, v[i][j + K - 1] - v[i][j] + 1);
                }
            }
        }
        if (max_ans == 0) cout << "-1\n";
        else cout << min_ans << " " << max_ans << "\n";

    }

    return 0;
}