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
string check[3] = {"KSA", "SAK", "AKS"};
int cnt[3];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> s;
    int x = 0, y = 0, z = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == check[0][x]) {
            x = (x + 1) % 3;
            cnt[0]++;
        }
        if (s[i] == check[1][y]) {
            y = (y + 1) % 3;
            cnt[1]++;
        }
        if (s[i] == check[2][z]) {
            z = (z + 1) % 3;
            cnt[2]++;
        }
    }
    if (s.size() == cnt[1]) {
        cnt[1] -= 1;
    }
    if (s.size() == cnt[2]) {
        cnt[2] -= 2;
    } else if (s.size() <= 3 && cnt[2] + 1 == s.size()) {
        cnt[2] -= 1;
    }
    int tmp = max({cnt[0], cnt[1], cnt[2]});
    if (s.size() > tmp) {
        cout << (s.size() - tmp) * 2;
    } else {
        cout << 0;
    }
    return 0;
}
