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
bool A;
int st = -1;
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
            if (A == 0) {
                st = i;
                A = 1;
            }
        }
    }

    if (s.size() == 1) {
        if (cnt[1]) cnt[1] = 0;
        if (cnt[2]) cnt[2] = 0;
    } else if (s.size() == 2) {
        if (cnt[1] == 2) cnt[1] -= 1;
        if (cnt[2]) cnt[2] = 0;
    } else {
        if (cnt[1] == s.size()) cnt[1] -= 1;
        if (cnt[2] == s.size()) cnt[2] -= 1;
        else if (cnt[2] + 2 > s.size() && st < 2) {
            cnt[2] -= st + 1;
        }
    }
    int tmp = max({cnt[0], cnt[1], cnt[2]});
    cout << (s.size() - tmp) * 2;
    return 0;
}

