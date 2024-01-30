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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        int k = 0;
        if (s[i] == 'I') {
            while (s[i + 1] == 'O' && s[i + 2] == 'I') {
                k++;
                if (N == k) {
                    k--;
                    ans++;
                }
                i += 2;
            }
        }
    }
    cout << ans;

    return 0;
}