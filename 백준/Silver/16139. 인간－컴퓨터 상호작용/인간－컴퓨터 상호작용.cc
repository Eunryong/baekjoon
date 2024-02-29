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
int T;
int arr[26][200001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s;
    cin >> s;
    cin >> T;
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < 26; j++) {
            if (j == s[i] - 'a') {
                arr[j][i] = (i != 0 ? arr[j][i - 1]: 0) + 1;
            } else {
                arr[j][i] = (i != 0 ? arr[j][i - 1]: 0);
            }
        }
    }
    while (T--) {
        char c;
        int x, y;
        cin >> c >> x >> y;
        cout << arr[c - 'a'][y] - (x > 0 ? arr[c - 'a'][x - 1]: 0) << "\n";
    }
    return 0;
}