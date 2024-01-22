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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    while (1) {
        cin >> s;
        if (s == "0") return 0;
        string ans = "yes";
        for (int i = 0; i< s.size() / 2; i++) {
            if (s[i] != s[s.size() - 1 - i]) {
                ans = "no";
                continue;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}