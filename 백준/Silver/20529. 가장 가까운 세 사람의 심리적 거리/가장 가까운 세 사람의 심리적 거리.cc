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

int T, N;

int solve(string a, string b) {
    int ret = 0;
    for (int i = 0; i < 4; i++) {
        if (a[i] != b[i]) {
            ret++;
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        vector<string> v;
        for (int j = 0; j < N; j++) {
            string tmp;
            cin >> tmp;
            v.push_back(tmp);
        }
        if (N > 32) {
            cout << "0\n";
            continue;
        }
        int ans = 12;
        for (int j = 0; j < N - 2; j++) {
            for (int k = j + 1; k < N - 1; k++) {
                for (int l = k + 1; l < N; l++) {
                    ans = min(ans, solve(v[j], v[k]) + solve(v[k], v[l]) + solve(v[l], v[j]));
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}